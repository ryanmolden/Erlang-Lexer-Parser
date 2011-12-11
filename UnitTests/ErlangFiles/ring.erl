-module(ring).
-export([start/1, start/2]).

%% Time (seconds)                          Description
%%----------------------------------------------------------------------------------------------------------
%%    179              Original - Passing message 'hello' to PID returned from ring:start(128,1048576).
%%    174              Take off (when Head =:= self()) in Msg -> clause.
%%    167              Name tuple in receive_loop args.
%%    135              Drastically simplify messages and receive_loop args.
%%    137              Move the case of TTL =:= 0 into its own pattern.
%%    134              Move from case to if (after reverting above change) for testing TTL against 0.

start(NodeCount) ->
  start(NodeCount, 1).
start(NodeCount, LoopCount) ->
  spawn(fun() -> create_ring(NodeCount, LoopCount) end).

%%First spawned node, this becomes the de-facto head of the ring.
create_ring(NodeCount, LoopCount) ->
  Next = spawn(fun() -> create_ring({NodeCount, NodeCount - 1}, LoopCount, self()) end),
  receive_loop(Next, NodeCount * LoopCount).

%%Last spawned node (RemainingNodeCount =:= 1), this becomes the tail and needs to forward its messages 
%%to the head (RingHead)
create_ring({NodeCount, 1}, LoopCount, RingHead) ->
  receive_loop(RingHead, NodeCount * LoopCount);

%%'Normal' node, it simply spawns the next node in the chain passing along the id of the head as given to it
create_ring({NodeCount, RemainingNodeCount}, LoopCount, RingHead) ->
  Next = spawn(fun() -> create_ring({NodeCount, RemainingNodeCount-1}, LoopCount, RingHead) end),
  receive_loop(Next, NodeCount * LoopCount).

%%Main message loop for each ring node (except the head)
receive_loop(Next, TotalMessageCount) ->
  receive
    %%If the message has a TTL section then it had to have come to us from our ancestor node, if its TTL is 
    %%0 it means this is the receipt of the last of the N*M messages (TTL = N*M), otherwise we just pass it
    %%along like any other message.
    {Msg, TTL} ->
      if (TTL =:= 0) ->
        {_, CPUTime} = statistics(runtime),
        {_, WallClockTime} = statistics(wall_clock),
        AvgCPUMS = CPUTime / TotalMessageCount,
        AvgWallClockMS = WallClockTime / TotalMessageCount,
        io:format("Circuit took ~p (~p) total milliseconds to complete ~p hops which is an average of ~p (~p) milliseconds per hop.~n", [CPUTime, WallClockTime, TotalMessageCount, AvgCPUMS, AvgWallClockMS]),
        receive_loop(Next, TotalMessageCount);

      true ->  %%Erlang equivalent of else for the if construct
        %%io:format("~p> Passing along ~p to ~p with a remaining hop count (TTL) of ~p~n", [self(), Msg, Next, TTL-1]),
        Next ! {Msg, TTL - 1},
        receive_loop(Next, TotalMessageCount)
      end;

    %%If the message has no node id identifying who it is from then it must be direct from the user so either
    %%kick off the tear down sequence (if it is the 'stop' message) or start our timing and pass it on.
    Msg ->
      if Msg =:= stop ->
        %%io:format("~p> Shutting down node~n", [self()]),
        Next ! stop;
      true ->
        %%io:format("~p> Starting ~p at head with remaining hop count (TTL) of ~p~n", [self(), Msg, TotalMessageCount - 1]),
        statistics(runtime),
        statistics(wall_clock),
        Next ! {Msg, TotalMessageCount - 1},
        receive_loop(Next, TotalMessageCount)
      end
  end.