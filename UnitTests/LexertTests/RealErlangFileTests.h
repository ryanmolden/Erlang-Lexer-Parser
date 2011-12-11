#pragma once
#include <boost/test/unit_test.hpp>
#include "TestUtil.h"
#include <ErlangTokens.h>
#include <string>
#include <utility>

BOOST_AUTO_TEST_SUITE( RealErlangFileTests )

using namespace TestUtil;
using std::wstring;
using std::pair;
using std::make_pair;
using std::transform;

BOOST_AUTO_TEST_CASE( PermutationsFileTest )
{
    wstring permutations = ReadFileIntoString("ErlangFiles\\permutations.erl");

    pair<unsigned int, wstring> expectedTokensArr[] = { /*-module(permutations).*/
                                                       make_pair(MODULEATTRIBUTEHEAD, L"-module"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"permutations"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*-export([perms/1]).*/
                                                       make_pair(EXPORTATTRIBUTEHEAD, L"-export"), make_pair(LEFTPAREN, L"("), make_pair(LEFTBRACKET, L"["), make_pair(ATOM, L"perms"), make_pair(FORWARDSLASH, L"/"), make_pair(DECIMALLITERAL, L"1"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*perms([])->[[]];*/
                                                       make_pair(ATOM, L"perms"), make_pair(LEFTPAREN, L"("), make_pair(LEFTBRACKET, L"["), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), make_pair(LEFTBRACKET, L"["), make_pair(LEFTBRACKET, L"["), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTBRACKET, L"]"), make_pair(SEMICOLON, L";"),
                                                       /*perms(L)->[[H|T] || H <- L, T <- perms(L--[H])].*/
                                                       make_pair(ATOM, L"perms"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"L"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), make_pair(LEFTBRACKET, L"["), make_pair(LEFTBRACKET, L"["), make_pair(VARIABLE, L"H"), make_pair(BAR, L"|"), make_pair(VARIABLE, L"T"), make_pair(RIGHTBRACKET, L"]"), make_pair(DOUBLEBAR, L"||"), make_pair(VARIABLE, L"H"), make_pair(OPGENERATE, L"<-"), make_pair(VARIABLE, L"L"), make_pair(COMMA, L","), make_pair(VARIABLE, L"T"), make_pair(OPGENERATE, L"<-"), make_pair(ATOM, L"perms"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"L"), make_pair(OPLISTSUBTRACT, L"--"), make_pair(LEFTBRACKET, L"["), make_pair(VARIABLE, L"H"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(RIGHTBRACKET, L"]"), make_pair(TERMINATOR, L".") };

    TokenVector expectedTokensVec(&expectedTokensArr[0], expectedTokensArr + _countof(expectedTokensArr));
    VerifyLex(permutations, expectedTokensVec);
}


BOOST_AUTO_TEST_CASE( QSortFileTest )
{
    wstring qsort = ReadFileIntoString("ErlangFiles\\qsort.erl");

    pair<unsigned int, wstring> expectedTokensArr[] = { /*-module(qsort).*/
                                                       make_pair(MODULEATTRIBUTEHEAD, L"-module"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"qsort"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*-export([qsort/1]).*/
                                                       make_pair(EXPORTATTRIBUTEHEAD, L"-export"), make_pair(LEFTPAREN, L"("), make_pair(LEFTBRACKET, L"["), make_pair(ATOM, L"qsort"), make_pair(FORWARDSLASH, L"/"), make_pair(DECIMALLITERAL, L"1"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*qsort([]) -> [];*/
                                                       make_pair(ATOM, L"qsort"), make_pair(LEFTPAREN, L"("), make_pair(LEFTBRACKET, L"["), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), make_pair(LEFTBRACKET, L"["), make_pair(RIGHTBRACKET, L"]"), make_pair(SEMICOLON, L";"), 
                                                       /*qsort([Pivot|T]) ->*/
                                                       make_pair(ATOM, L"qsort"), make_pair(LEFTPAREN, L"("), make_pair(LEFTBRACKET, L"["), make_pair(VARIABLE, L"Pivot"), make_pair(BAR, L"|"), make_pair(VARIABLE, L"T"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*qsort([X || X <- T, X < Pivot])*/
                                                       make_pair(ATOM, L"qsort"), make_pair(LEFTPAREN, L"("), make_pair(LEFTBRACKET, L"["), make_pair(VARIABLE, L"X"), make_pair(DOUBLEBAR, L"||"), make_pair(VARIABLE, L"X"), make_pair(OPGENERATE, L"<-"), make_pair(VARIABLE, L"T"), make_pair(COMMA, L","), make_pair(VARIABLE, L"X"), make_pair(OPLESSTHAN, L"<"), make_pair(VARIABLE, L"Pivot"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), 
                                                       /*++ [Pivot] ++*/
                                                       make_pair(OPLISTCONCAT, L"++"), make_pair(LEFTBRACKET, L"["), make_pair(VARIABLE, L"Pivot"), make_pair(RIGHTBRACKET, L"]"), make_pair(OPLISTCONCAT, L"++"), 
                                                       /*qsort([X || X <- T, X >= Pivot]).*/
                                                       make_pair(ATOM, L"qsort"), make_pair(LEFTPAREN, L"("), make_pair(LEFTBRACKET, L"["), make_pair(VARIABLE, L"X"), make_pair(DOUBLEBAR, L"||"), make_pair(VARIABLE, L"X"), make_pair(OPGENERATE, L"<-"), make_pair(VARIABLE, L"T"), make_pair(COMMA, L","), make_pair(VARIABLE, L"X"), make_pair(OPGREATERTHANEQUAL, L">="), make_pair(VARIABLE, L"Pivot"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L".") };

    TokenVector expectedTokensVec(&expectedTokensArr[0], expectedTokensArr + _countof(expectedTokensArr));
    VerifyLex(qsort, expectedTokensVec);
}

BOOST_AUTO_TEST_CASE( RingFileTest )
{
    wstring ring = ReadFileIntoString("ErlangFiles\\ring.erl");

    pair<unsigned int, wstring> expectedTokensArr[] = { /*-module(ring).*/
                                                       make_pair(MODULEATTRIBUTEHEAD, L"-module"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"ring"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*-export([start/1, start/2]).*/
                                                       make_pair(EXPORTATTRIBUTEHEAD, L"-export"), make_pair(LEFTPAREN, L"("), make_pair(LEFTBRACKET, L"["), make_pair(ATOM, L"start"), make_pair(FORWARDSLASH, L"/"), make_pair(DECIMALLITERAL, L"1"), make_pair(COMMA, L","), make_pair(ATOM, L"start"), make_pair(FORWARDSLASH, L"/"), make_pair(DECIMALLITERAL, L"2"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*%% Time (seconds)                          Description*/
                                                       make_pair(COMMENT, L"%% Time (seconds)                          Description\n"),
                                                       /*%%----------------------------------------------------------------------------------------------------------*/
                                                       make_pair(COMMENT, L"%%----------------------------------------------------------------------------------------------------------\n"), 
                                                       /*%%    179              Original - Passing message 'hello' to PID returned from ring:start(128,1048576).*/
                                                       make_pair(COMMENT, L"%%    179              Original - Passing message 'hello' to PID returned from ring:start(128,1048576).\n"), 
                                                       /*%%    174              Take off (when Head =:= self()) in Msg -> clause.*/
                                                       make_pair(COMMENT, L"%%    174              Take off (when Head =:= self()) in Msg -> clause.\n"), 
                                                       /*%%    167              Name tuple in receive_loop args.*/
                                                       make_pair(COMMENT, L"%%    167              Name tuple in receive_loop args.\n"), 
                                                       /*%%    135              Drastically simplify messages and receive_loop args.*/
                                                       make_pair(COMMENT, L"%%    135              Drastically simplify messages and receive_loop args.\n"), 
                                                       /*%%    137              Move the case of TTL =:= 0 into its own pattern.*/
                                                       make_pair(COMMENT, L"%%    137              Move the case of TTL =:= 0 into its own pattern.\n"), 
                                                       /*%%    134              Move from case to if (after reverting above change) for testing TTL against 0.*/
                                                       make_pair(COMMENT, L"%%    134              Move from case to if (after reverting above change) for testing TTL against 0.\n"), 
                                                       /*start(NodeCount) ->*/
                                                       make_pair(ATOM, L"start"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"NodeCount"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*start(NodeCount, 1).*/
                                                       make_pair(ATOM, L"start"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"NodeCount"), make_pair(COMMA, L","), make_pair(DECIMALLITERAL, L"1"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."),
                                                       /*start(NodeCount, LoopCount) ->*/
                                                       make_pair(ATOM, L"start"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"NodeCount"), make_pair(COMMA, L","), make_pair(VARIABLE, L"LoopCount"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*spawn(fun() -> create_ring(NodeCount, LoopCount) end).*/
                                                       make_pair(ATOM, L"spawn"), make_pair(LEFTPAREN, L"("), make_pair(FUN, L"fun"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), make_pair(ATOM, L"create_ring"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"NodeCount"), make_pair(COMMA, L","), make_pair(VARIABLE, L"LoopCount"), make_pair(RIGHTPAREN, L")"), make_pair(END, L"end"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*%%First spawned node, this becomes the de-facto head of the ring.*/
                                                       make_pair(COMMENT, L"%%First spawned node, this becomes the de-facto head of the ring.\n"), 
                                                       /*create_ring(NodeCount, LoopCount) ->*/
                                                       make_pair(ATOM, L"create_ring"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"NodeCount"), make_pair(COMMA, L","), make_pair(VARIABLE, L"LoopCount"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*Next = spawn(fun() -> create_ring({NodeCount, NodeCount - 1}, LoopCount, self()) end),*/
                                                       make_pair(VARIABLE, L"Next"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"spawn"), make_pair(LEFTPAREN, L"("), make_pair(FUN, L"fun"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), make_pair(ATOM, L"create_ring"), make_pair(LEFTPAREN, L"("), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(VARIABLE, L"NodeCount"), make_pair(COMMA, L","), make_pair(VARIABLE, L"NodeCount"), make_pair(OPMINUS, L"-"), make_pair(DECIMALLITERAL, L"1"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(COMMA, L","), make_pair(VARIABLE, L"LoopCount"), make_pair(COMMA, L","), make_pair(ATOM, L"self"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(RIGHTPAREN, L")"), make_pair(END, L"end"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*  receive_loop(Next, NodeCount * LoopCount).*/
                                                       make_pair(ATOM, L"receive_loop"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Next"), make_pair(COMMA, L","), make_pair(VARIABLE, L"NodeCount"), make_pair(OPMULT, L"*"), make_pair(VARIABLE, L"LoopCount"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*%%Last spawned node (RemainingNodeCount =:= 1), this becomes the tail and needs to forward its messages */
                                                       make_pair(COMMENT, L"%%Last spawned node (RemainingNodeCount =:= 1), this becomes the tail and needs to forward its messages \n"), 
                                                       /*%%to the head (RingHead)*/
                                                       make_pair(COMMENT, L"%%to the head (RingHead)\n"), 
                                                       /*create_ring({NodeCount, 1}, LoopCount, RingHead) ->*/
                                                       make_pair(ATOM, L"create_ring"), make_pair(LEFTPAREN, L"("), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(VARIABLE, L"NodeCount"), make_pair(COMMA, L","), make_pair(DECIMALLITERAL, L"1"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(COMMA, L","), make_pair(VARIABLE, L"LoopCount"), make_pair(COMMA, L","), make_pair(VARIABLE, L"RingHead"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*receive_loop(RingHead, NodeCount * LoopCount);*/
                                                       make_pair(ATOM, L"receive_loop"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"RingHead"), make_pair(COMMA, L","), make_pair(VARIABLE, L"NodeCount"), make_pair(OPMULT, L"*"), make_pair(VARIABLE, L"LoopCount"), make_pair(RIGHTPAREN, L")"), make_pair(SEMICOLON, L";"), 
                                                       /*%%'Normal' node, it simply spawns the next node in the chain passing along the id of the head as given to it*/
                                                       make_pair(COMMENT, L"%%'Normal' node, it simply spawns the next node in the chain passing along the id of the head as given to it\n"), 
                                                       /*create_ring({NodeCount, RemainingNodeCount}, LoopCount, RingHead) ->*/
                                                       make_pair(ATOM, L"create_ring"), make_pair(LEFTPAREN, L"("), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(VARIABLE, L"NodeCount"), make_pair(COMMA, L","), make_pair(VARIABLE, L"RemainingNodeCount"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(COMMA, L","), make_pair(VARIABLE, L"LoopCount"), make_pair(COMMA, L","), make_pair(VARIABLE, L"RingHead"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*Next = spawn(fun() -> create_ring({NodeCount, RemainingNodeCount-1}, LoopCount, RingHead) end),*/
                                                       make_pair(VARIABLE, L"Next"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"spawn"), make_pair(LEFTPAREN, L"("), make_pair(FUN, L"fun"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), make_pair(ATOM, L"create_ring"), make_pair(LEFTPAREN, L"("), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(VARIABLE, L"NodeCount"), make_pair(COMMA, L","), make_pair(VARIABLE, L"RemainingNodeCount"), make_pair(OPMINUS, L"-"), make_pair(DECIMALLITERAL, L"1"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(COMMA, L","), make_pair(VARIABLE, L"LoopCount"), make_pair(COMMA, L","), make_pair(VARIABLE, L"RingHead"), make_pair(RIGHTPAREN, L")"), make_pair(END, L"end"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*receive_loop(Next, NodeCount * LoopCount).*/
                                                       make_pair(ATOM, L"receive_loop"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Next"), make_pair(COMMA, L","), make_pair(VARIABLE, L"NodeCount"), make_pair(OPMULT, L"*"), make_pair(VARIABLE, L"LoopCount"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*%%Main message loop for each ring node (except the head)*/
                                                       make_pair(COMMENT, L"%%Main message loop for each ring node (except the head)\n"), 
                                                       /*receive_loop(Next, TotalMessageCount) ->*/
                                                       make_pair(ATOM, L"receive_loop"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Next"), make_pair(COMMA, L","), make_pair(VARIABLE, L"TotalMessageCount"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*receive*/
                                                       make_pair(RECEIVE, L"receive"), 
                                                       /*%%If the message has a TTL section then it had to have come to us from our ancestor node, if its TTL is */
                                                       make_pair(COMMENT, L"%%If the message has a TTL section then it had to have come to us from our ancestor node, if its TTL is \n"), 
                                                       /*%%0 it means this is the receipt of the last of the N*M messages (TTL = N*M), otherwise we just pass it*/
                                                       make_pair(COMMENT, L"%%0 it means this is the receipt of the last of the N*M messages (TTL = N*M), otherwise we just pass it\n"), 
                                                       /*%%along like any other message.*/
                                                       make_pair(COMMENT, L"%%along like any other message.\n"), 
                                                       /*{Msg, TTL} ->*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(VARIABLE, L"Msg"), make_pair(COMMA, L","), make_pair(VARIABLE, L"TTL"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(ARROW, L"->"), 
                                                       /*if (TTL =:= 0) ->*/
                                                       make_pair(IF, L"if"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"TTL"), make_pair(OPIDENTICALTO, L"=:="), make_pair(DECIMALLITERAL, L"0"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*{_, CPUTime} = statistics(runtime),*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(UNIVERSALPATTERN, L"_"), make_pair(COMMA, L","), make_pair(VARIABLE, L"CPUTime"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"statistics"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"runtime"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*{_, WallClockTime} = statistics(wall_clock),*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(UNIVERSALPATTERN, L"_"), make_pair(COMMA, L","), make_pair(VARIABLE, L"WallClockTime"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"statistics"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"wall_clock"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*AvgCPUMS = CPUTime / TotalMessageCount,*/
                                                       make_pair(VARIABLE, L"AvgCPUMS"), make_pair(OPMATCH, L"="), make_pair(VARIABLE, L"CPUTime"), make_pair(FORWARDSLASH, L"/"), make_pair(VARIABLE, L"TotalMessageCount"), make_pair(COMMA, L","), 
                                                       /*AvgWallClockMS = WallClockTime / TotalMessageCount,*/
                                                       make_pair(VARIABLE, L"AvgWallClockMS"), make_pair(OPMATCH, L"="), make_pair(VARIABLE, L"WallClockTime"), make_pair(FORWARDSLASH, L"/"), make_pair(VARIABLE, L"TotalMessageCount"), make_pair(COMMA, L","), 
                                                       /*io:format("Circuit took ~p (~p) total milliseconds to complete ~p hops which is an average of ~p (~p) milliseconds per hop.~n", [CPUTime, WallClockTime, TotalMessageCount, AvgCPUMS, AvgWallClockMS]),*/
                                                       make_pair(ATOM, L"io"), make_pair(COLON, L":"), make_pair(ATOM, L"format"), make_pair(LEFTPAREN, L"("), make_pair(STRINGLITERAL, L"\"Circuit took ~p (~p) total milliseconds to complete ~p hops which is an average of ~p (~p) milliseconds per hop.~n\""), make_pair(COMMA, L","), make_pair(LEFTBRACKET, L"["), make_pair(VARIABLE, L"CPUTime"), make_pair(COMMA, L","), make_pair(VARIABLE, L"WallClockTime"), make_pair(COMMA, L","), make_pair(VARIABLE, L"TotalMessageCount"), make_pair(COMMA, L","), make_pair(VARIABLE, L"AvgCPUMS"), make_pair(COMMA, L","), make_pair(VARIABLE, L"AvgWallClockMS"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*receive_loop(Next, TotalMessageCount);*/
                                                       make_pair(ATOM, L"receive_loop"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Next"), make_pair(COMMA, L","), make_pair(VARIABLE, L"TotalMessageCount"), make_pair(RIGHTPAREN, L")"), make_pair(SEMICOLON, L";"), 
                                                       /*true ->  %%Erlang equivalent of else for the if construct*/
                                                       make_pair(ATOM, L"true"), make_pair(ARROW, L"->"), make_pair(COMMENT, L"%%Erlang equivalent of else for the if construct\n"), 
                                                       /*%%io:format("~p> Passing along ~p to ~p with a remaining hop count (TTL) of ~p~n", [self(), Msg, Next, TTL-1]),*/
                                                       make_pair(COMMENT, L"%%io:format(\"~p> Passing along ~p to ~p with a remaining hop count (TTL) of ~p~n\", [self(), Msg, Next, TTL-1]),\n"), 
                                                       /*Next ! {Msg, TTL - 1},*/
                                                       make_pair(VARIABLE, L"Next"), make_pair(OPSEND, L"!"), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(VARIABLE, L"Msg"), make_pair(COMMA, L","), make_pair(VARIABLE, L"TTL"), make_pair(OPMINUS, L"-"), make_pair(DECIMALLITERAL, L"1"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(COMMA, L","), 
                                                       /*receive_loop(Next, TotalMessageCount)*/
                                                       make_pair(ATOM, L"receive_loop"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Next"), make_pair(COMMA, L","), make_pair(VARIABLE, L"TotalMessageCount"), make_pair(RIGHTPAREN, L")"), 
                                                       /*end;*/
                                                       make_pair(END, L"end"), make_pair(SEMICOLON, L";"), 
                                                       /*%%If the message has no node id identifying who it is from then it must be direct from the user so either*/
                                                       make_pair(COMMENT, L"%%If the message has no node id identifying who it is from then it must be direct from the user so either\n"), 
                                                       /*%%kick off the tear down sequence (if it is the 'stop' message) or start our timing and pass it on.*/
                                                       make_pair(COMMENT, L"%%kick off the tear down sequence (if it is the 'stop' message) or start our timing and pass it on.\n"), 
                                                       /*Msg ->*/
                                                       make_pair(VARIABLE, L"Msg"), make_pair(ARROW, L"->"), 
                                                       /*if Msg =:= stop ->*/
                                                       make_pair(IF, L"if"), make_pair(VARIABLE, L"Msg"), make_pair(OPIDENTICALTO, L"=:="), make_pair(ATOM, L"stop"), make_pair(ARROW, L"->"), 
                                                       /*%%io:format("~p> Shutting down node~n", [self()]),*/
                                                       make_pair(COMMENT, L"%%io:format(\"~p> Shutting down node~n\", [self()]),\n"), 
                                                       /*Next ! stop;*/
                                                       make_pair(VARIABLE, L"Next"), make_pair(OPSEND, L"!"), make_pair(ATOM, L"stop"), make_pair(SEMICOLON, L";"), 
                                                       /*true ->*/
                                                       make_pair(ATOM, L"true"), make_pair(ARROW, L"->"), 
                                                       /*%%io:format("~p> Starting ~p at head with remaining hop count (TTL) of ~p~n", [self(), Msg, TotalMessageCount - 1]),*/
                                                       make_pair(COMMENT, L"%%io:format(\"~p> Starting ~p at head with remaining hop count (TTL) of ~p~n\", [self(), Msg, TotalMessageCount - 1]),\n"), 
                                                       /*statistics(runtime),*/
                                                       make_pair(ATOM, L"statistics"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"runtime"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*statistics(wall_clock),*/
                                                       make_pair(ATOM, L"statistics"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"wall_clock"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*Next ! {Msg, TotalMessageCount - 1},*/
                                                       make_pair(VARIABLE, L"Next"), make_pair(OPSEND, L"!"), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(VARIABLE, L"Msg"), make_pair(COMMA, L","), make_pair(VARIABLE, L"TotalMessageCount"), make_pair(OPMINUS, L"-"), make_pair(DECIMALLITERAL, L"1"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(COMMA, L","), 
                                                       /*receive_loop(Next, TotalMessageCount)*/
                                                       make_pair(ATOM, L"receive_loop"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Next"), make_pair(COMMA, L","), make_pair(VARIABLE, L"TotalMessageCount"), make_pair(RIGHTPAREN, L")"), 
                                                       /*end*/
                                                       make_pair(END, L"end"), 
                                                       /*end.*/
                                                       make_pair(END, L"end"), make_pair(TERMINATOR, L".") };

    TokenVector expectedTokensVec(&expectedTokensArr[0], expectedTokensArr + _countof(expectedTokensArr));
    VerifyLex(ring, expectedTokensVec);
}

BOOST_AUTO_TEST_CASE( VFSFileTest )
{
    wstring vfs = ReadFileIntoString("ErlangFiles\\vfs.erl");

    pair<unsigned int, wstring> expectedTokensArr[] = { /*%% ---*/
                                                       make_pair(COMMENT, L"%% ---\n"),
                                                       /*%%  Excerpted from L"Programming Erlang",*/
                                                       make_pair(COMMENT, L"%%  Excerpted from \"Programming Erlang\",\n"), 
                                                       /*%%  published by The Pragmatic Bookshelf.*/
                                                       make_pair(COMMENT, L"%%  published by The Pragmatic Bookshelf.\n"), 
                                                       /*%%  Copyrights apply to this code. It may not be used to create training material,*/
                                                       make_pair(COMMENT, L"%%  Copyrights apply to this code. It may not be used to create training material, \n"), 
                                                       /*%%  courses, books, articles, and the like. Contact us if you are in doubt.*/
                                                       make_pair(COMMENT, L"%%  courses, books, articles, and the like. Contact us if you are in doubt.\n"), 
                                                       /*%%  We make no guarantees that this code is fit for any purpose.*/
                                                       make_pair(COMMENT, L"%%  We make no guarantees that this code is fit for any purpose. \n"),
                                                       /*%%  Visit http://www.pragmaticprogrammer.com/titles/jaerlang for more book information.*/
                                                       make_pair(COMMENT, L"%%  Visit http://www.pragmaticprogrammer.com/titles/jaerlang for more book information.\n"), 
                                                       /*%%---*/
                                                       make_pair(COMMENT, L"%%---\n"), 
                                                       /*-module(vfs).*/
                                                       make_pair(MODULEATTRIBUTEHEAD, L"-module"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"vfs"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*-compile(export_all).*/
                                                       make_pair(COMPILEATTRIBUTEHEAD, L"-compile"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"export_all"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."),
                                                       /*-import(lib_misc, [downcase_str/1]).*/
                                                       make_pair(IMPORTATTRIBUTEHEAD, L"-import"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"lib_misc"), make_pair(COMMA, L","), make_pair(LEFTBRACKET, L"["), make_pair(ATOM, L"downcase_str"), make_pair(FORWARDSLASH, L"/"), make_pair(DECIMALLITERAL, L"1"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*-import(lists, [member/2]).*/
                                                       make_pair(IMPORTATTRIBUTEHEAD, L"-import"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"lists"), make_pair(COMMA, L","), make_pair(LEFTBRACKET, L"["), make_pair(ATOM, L"member"), make_pair(FORWARDSLASH, L"/"), make_pair(DECIMALLITERAL, L"2"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*big_text() -> L"./lib_misc.erl".*/
                                                       make_pair(ATOM, L"big_text"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), make_pair(STRINGLITERAL, L"\"./lib_misc.erl\""), make_pair(TERMINATOR, L"."), 
                                                       /*big_media() -> L"track030.mp3".*/
                                                       make_pair(ATOM, L"big_media"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), make_pair(STRINGLITERAL, L"\"track030.mp3\""), make_pair(TERMINATOR, L"."), 
                                                       /*%% @spec read_file(string()) -> {Compressed:bool(), int(), binary()}.*/
                                                       make_pair(COMMENT, L"%% @spec read_file(string()) -> {Compressed:bool(), int(), binary()}.\n"), 
                                                       /*read_file(File) ->*/
                                                       make_pair(ATOM, L"read_file"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"File"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*{ok, Bin} = file:read_file(File),*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"ok"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Bin"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"file"), make_pair(COLON, L":"), make_pair(ATOM, L"read_file"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"File"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*{Flag, Size, Data} = case is_media_file(File) of*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(VARIABLE, L"Flag"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Size"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Data"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(OPMATCH, L"="), make_pair(CASE, L"case"), make_pair(ATOM, L"is_media_file"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"File"), make_pair(RIGHTPAREN, L")"), make_pair(OF, L"of"), 
                                                       /*true -> {false, size(Bin), Bin};*/
                                                       make_pair(ATOM, L"true"), make_pair(ARROW, L"->"), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"false"), make_pair(COMMA, L","), make_pair(ATOM, L"size"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Bin"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Bin"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(SEMICOLON, L";"), 
                                                       /*false -> Bin1 = term_to_binary(Bin, [compressed]),*/
                                                       make_pair(ATOM, L"false"), make_pair(ARROW, L"->"), make_pair(VARIABLE, L"Bin1"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"term_to_binary"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Bin"), make_pair(COMMA, L","), make_pair(LEFTBRACKET, L"["), make_pair(ATOM, L"compressed"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*{true, size(Bin1), Bin1}*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"true"), make_pair(COMMA, L","), make_pair(ATOM, L"size"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Bin1"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Bin1"), make_pair(RIGHTCURLYBRACKET, L"}"), 
                                                       /*end,*/
                                                       make_pair(END, L"end"), make_pair(COMMA, L","), 
                                                       /*Md5 = lib_md5:binAsBin(Data),*/
                                                       make_pair(VARIABLE, L"Md5"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"lib_md5"), make_pair(COLON, L":"), make_pair(ATOM, L"binAsBin"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Data"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*{Flag, Size, Md5, Data}.*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(VARIABLE, L"Flag"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Size"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Md5"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Data"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(TERMINATOR, L"."), 
                                                       /*is_media_file(File) ->*/
                                                       make_pair(ATOM, L"is_media_file"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"File"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*member(downcase_str(filename:extension(File)),*/
                                                       make_pair(ATOM, L"member"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"downcase_str"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"filename"), make_pair(COLON, L":"), make_pair(ATOM, L"extension"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"File"), make_pair(RIGHTPAREN, L")"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*[".jpg", L".mp3", L".mpg"]).*/
                                                       make_pair(LEFTBRACKET, L"["), make_pair(STRINGLITERAL, L"\".jpg\""), make_pair(COMMA, L","), make_pair(STRINGLITERAL, L"\".mp3\""), make_pair(COMMA, L","), make_pair(STRINGLITERAL, L"\".mpg\""), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*write_file_to_store(Pid, File, Md5, Compressed, Data) ->*/
                                                       make_pair(ATOM, L"write_file_to_store"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Pid"), make_pair(COMMA, L","), make_pair(VARIABLE, L"File"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Md5"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Compressed"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Data"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*case rpc(Pid, {should_i_store, File, Md5}) of*/
                                                       make_pair(CASE, L"case"), make_pair(ATOM, L"rpc"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Pid"), make_pair(COMMA, L","), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"should_i_store"), make_pair(COMMA, L","), make_pair(VARIABLE, L"File"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Md5"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(RIGHTPAREN, L")"), make_pair(OF, L"of"), 
                                                       /*{yes, Vsn} ->*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"yes"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Vsn"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(ARROW, L"->"),
                                                       /*Data = term_to_binary({File,Vsn,Md5,Compressed,Data}),*/
                                                       make_pair(VARIABLE, L"Data"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"term_to_binary"), make_pair(LEFTPAREN, L"("), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(VARIABLE, L"File"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Vsn"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Md5"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Compressed"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Data"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*Size = size(Data) + 32,*/
                                                       make_pair(VARIABLE, L"Size"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"size"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Data"), make_pair(RIGHTPAREN, L")"), make_pair(OPPLUS, L"+"), make_pair(DECIMALLITERAL, L"32"), make_pair(COMMA, L","), 
                                                       /*case rpc(Pid, {need_some_space, File, Vsn, Md5, Size}) of*/
                                                       make_pair(CASE, L"case"), make_pair(ATOM, L"rpc"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Pid"), make_pair(COMMA, L","), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"need_some_space"), make_pair(COMMA, L","), make_pair(VARIABLE, L"File"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Vsn"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Md5"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Size"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(RIGHTPAREN, L")"), make_pair(OF, L"of"), 
                                                       /*{yes, Handle, _Start} ->*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"yes"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Handle"), make_pair(COMMA, L","), make_pair(VARIABLE, L"_Start"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(ARROW, L"->"),
                                                       /*file:pwrite(Handle,*/
                                                       make_pair(ATOM, L"file"), make_pair(COLON, L":"), make_pair(ATOM, L"pwrite"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Handle"), make_pair(COMMA, L","), 
                                                       /*[<<16#111111111:32, Size:32>>,Data/binary,*/
                                                       make_pair(LEFTBRACKET, L"["), make_pair(BITSTRINGHEAD, L"<<"), make_pair(EXPLICITRADIXLITERAL, L"16#111111111"), make_pair(COLON, L":"), make_pair(DECIMALLITERAL, L"32"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Size"), make_pair(COLON, L":"), make_pair(DECIMALLITERAL, L"32"), make_pair(BITSTRINGTAIL, L">>"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Data"), make_pair(FORWARDSLASH, L"/"), make_pair(ATOM, L"binary"), make_pair(COMMA, L","), 
                                                       /*<<16#222222222:32>>]);*/
                                                       make_pair(BITSTRINGHEAD, L"<<"), make_pair(EXPLICITRADIXLITERAL, L"16#222222222"), make_pair(COLON, L":"), make_pair(DECIMALLITERAL, L"32"), make_pair(BITSTRINGTAIL, L">>"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(SEMICOLON, L";"), 
                                                       /*no ->*/
                                                       make_pair(ATOM, L"no"), make_pair(ARROW, L"->"), 
                                                       /*exit(internal)*/
                                                       make_pair(ATOM, L"exit"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"internal"), make_pair(RIGHTPAREN, L")"), 
                                                       /*end;*/
                                                       make_pair(END, L"end"), make_pair(SEMICOLON, L";"), 
                                                       /*no ->*/
                                                       make_pair(ATOM, L"no"), make_pair(ARROW, L"->"), 
                                                       /*true*/
                                                       make_pair(ATOM, L"true"), 
                                                       /*end.*/
                                                       make_pair(END, L"end"), make_pair(TERMINATOR, L"."), 
                                                       /*rpc(Pid, Q) ->*/
                                                       make_pair(ATOM, L"rpc"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Pid"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Q"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*Pid ! {self(), Q},*/
                                                       make_pair(VARIABLE, L"Pid"), make_pair(OPSEND, L"!"), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"self"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Q"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(COMMA, L","), 
                                                       /*receive*/
                                                       make_pair(RECEIVE, L"receive"), 
                                                       /*{Pid, Reply} ->*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(VARIABLE, L"Pid"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Reply"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(ARROW, L"->"), 
                                                       /*Reply*/
                                                       make_pair(VARIABLE, L"Reply"), 
                                                       /*end.*/
                                                       make_pair(END, L"end"), make_pair(TERMINATOR, L"."), 
                                                       /*loop(Env) ->*/
                                                       make_pair(ATOM, L"loop"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Env"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*receive*/
                                                       make_pair(RECEIVE, L"receive"), 
                                                       /*{From, {should_i_store, File, Md5}} ->*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(VARIABLE, L"From"), make_pair(COMMA, L","), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"should_i_store"), make_pair(COMMA, L","), make_pair(VARIABLE, L"File"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Md5"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(ARROW, L"->"), 
                                                       /*case should_i_store(File, Md5, Env) of*/
                                                       make_pair(CASE, L"case"), make_pair(ATOM, L"should_i_store"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"File"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Md5"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Env"), make_pair(RIGHTPAREN, L")"), make_pair(OF, L"of"),
                                                       /*{yes, Vsn, Env1} ->*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"yes"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Vsn"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Env1"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(ARROW, L"->"),
                                                       /*From ! {self(), {yes, Vsn}},*/
                                                       make_pair(VARIABLE, L"From"), make_pair(OPSEND, L"!"), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"self"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"yes"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Vsn"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(COMMA, L","), 
                                                       /*loop(Env1);*/
                                                       make_pair(ATOM, L"loop"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Env1"), make_pair(RIGHTPAREN, L")"), make_pair(SEMICOLON, L";"), 
                                                       /*no ->*/
                                                       make_pair(ATOM, L"no"), make_pair(ARROW, L"->"), 
                                                       /*From ! {self(), no},*/
                                                       make_pair(VARIABLE, L"From"), make_pair(OPSEND, L"!"), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"self"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), make_pair(ATOM, L"no"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(COMMA, L","), 
                                                       /*loop(Env)*/
                                                       make_pair(ATOM, L"loop"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Env"), make_pair(RIGHTPAREN, L")"), 
                                                       /*end;*/
                                                       make_pair(END, L"end"), make_pair(SEMICOLON, L";"), 
                                                       /*Any ->*/
                                                       make_pair(VARIABLE, L"Any"), make_pair(ARROW, L"->"), 
                                                       /*io:format("Any=~p~n",[Any])*/
                                                       make_pair(ATOM, L"io"), make_pair(COLON, L":"), make_pair(ATOM, L"format"), make_pair(LEFTPAREN, L"("), make_pair(STRINGLITERAL, L"\"Any=~p~n\""), make_pair(COMMA, L","), make_pair(LEFTBRACKET, L"["), make_pair(VARIABLE, L"Any"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), 
                                                       /*end.*/
                                                       make_pair(END, L"end"), make_pair(TERMINATOR, L"."), 
                                                       /*should_i_store(_File, _Md5, _Dict) ->*/
                                                       make_pair(ATOM, L"should_i_store"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"_File"), make_pair(COMMA, L","), make_pair(VARIABLE, L"_Md5"), make_pair(COMMA, L","), make_pair(VARIABLE, L"_Dict"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*true.*/
                                                       make_pair(ATOM, L"true"), make_pair(TERMINATOR, L"."), 
                                                       /*%%  case dict:find(File, Dict) ->*/
                                                       make_pair(COMMENT, L"%%  case dict:find(File, Dict) ->\n"), 
                                                       /*%%    end.*/
                                                       make_pair(COMMENT, L"%%    end.\n"), 
                                                       /*%%   11111111*/
                                                       make_pair(COMMENT, L"%%   11111111\n"), 
                                                       /*%%   Size*/
                                                       make_pair(COMMENT, L"%%   Size\n"), 
                                                       /*%%     Data = term_to_binary({File,Compressed,Vsn,Data}}*/
                                                       make_pair(COMMENT, L"%%     Data = term_to_binary({File,Compressed,Vsn,Data}}\n"), 
                                                       /*%%   22222222*/
                                                       make_pair(COMMENT, L"%%   22222222\n"), 
                                                       /*%% Globals*/
                                                       make_pair(COMMENT, L"%% Globals\n"), 
                                                       /*-record(env,*/
                                                       make_pair(RECORDATTRIBUTEHEAD, L"-record"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"env"), make_pair(COMMA, L","), 
                                                       /*{maxSize,*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"maxSize"), make_pair(COMMA, L","), 
                                                       /*allocated,*/
                                                       make_pair(ATOM, L"allocated"), make_pair(COMMA, L","), 
                                                       /*index,*/
                                                       make_pair(ATOM, L"index"), make_pair(COMMA, L","), 
                                                       /*dirty,*/
                                                       make_pair(ATOM, L"dirty"), make_pair(COMMA, L","), 
                                                       /*maxVersions,*/
                                                       make_pair(ATOM, L"maxVersions"), make_pair(COMMA, L","), 
                                                       /*freeList}).*/
                                                       make_pair(ATOM, L"freeList"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*%% Freelist = [{Address, Space}, ...]*/
                                                       make_pair(COMMENT, L"%% Freelist = [{Address, Space}, ...]\n"), 
                                                       /*%% sorted by address*/
                                                       make_pair(COMMENT, L"%% sorted by address\n"), 
                                                       /*%% MaxSize is in MB*/
                                                       make_pair(COMMENT, L"%% MaxSize is in MB\n"), 
                                                       /*new_vfs(FileName, MaxSize, MaxVersions) ->*/
                                                       make_pair(ATOM, L"new_vfs"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"FileName"), make_pair(COMMA, L","), make_pair(VARIABLE, L"MaxSize"), make_pair(COMMA, L","), make_pair(VARIABLE, L"MaxVersions"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*case filelib:is_regular(FileName) of*/
                                                       make_pair(CASE, L"case"), make_pair(ATOM, L"filelib"), make_pair(COLON, L":"), make_pair(ATOM, L"is_regular"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"FileName"), make_pair(RIGHTPAREN, L")"), make_pair(OF, L"of"),
                                                       /*true ->*/
                                                       make_pair(ATOM, L"true"), make_pair(ARROW, L"->"), 
                                                       /*exit(eFileExists);*/
                                                       make_pair(ATOM, L"exit"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"eFileExists"), make_pair(RIGHTPAREN, L")"), make_pair(SEMICOLON, L";"),
                                                       /*false ->*/
                                                       make_pair(ATOM, L"false"), make_pair(ARROW, L"->"), 
                                                       /*FreeList = [{1, MaxSize}],*/
                                                       make_pair(VARIABLE, L"FreeList"), make_pair(OPMATCH, L"="), make_pair(LEFTBRACKET, L"["), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(DECIMALLITERAL, L"1"), make_pair(COMMA, L","), make_pair(VARIABLE, L"MaxSize"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(RIGHTBRACKET, L"]"), make_pair(COMMA, L","), 
                                                       /*Env = #env{allocated=0,*/
                                                       make_pair(VARIABLE, L"Env"), make_pair(OPMATCH, L"="), make_pair(HASH, L"#"), make_pair(ATOM, L"env"), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"allocated"), make_pair(OPMATCH, L"="), make_pair(DECIMALLITERAL, L"0"), make_pair(COMMA, L","), 
                                                       /*index = dict:new(),*/
                                                       make_pair(ATOM, L"index"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"dict"), make_pair(COLON, L":"), make_pair(ATOM, L"new"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","),
                                                       /*dirty=false,*/
                                                       make_pair(ATOM, L"dirty"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"false"), make_pair(COMMA, L","), 
                                                       /*maxSize=MaxSize*1000000,*/
                                                       make_pair(ATOM, L"maxSize"), make_pair(OPMATCH, L"="), make_pair(VARIABLE, L"MaxSize"), make_pair(OPMULT, L"*"), make_pair(DECIMALLITERAL, L"1000000"), make_pair(COMMA, L","), 
                                                       /*freeList=FreeList,*/
                                                       make_pair(ATOM, L"freeList"), make_pair(OPMATCH, L"="), make_pair(VARIABLE, L"FreeList"), make_pair(COMMA, L","), 
                                                       /*maxVersions = MaxVersions},*/
                                                       make_pair(ATOM, L"maxVersions"), make_pair(OPMATCH, L"="), make_pair(VARIABLE, L"MaxVersions"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(COMMA, L","), 
                                                       /*B = term_to_binary(Env),*/
                                                       make_pair(VARIABLE, L"B"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"term_to_binary"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Env"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*Size = size(B),*/
                                                       make_pair(VARIABLE, L"Size"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"size"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"B"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*file:write_file(FileName,*/
                                                       make_pair(ATOM, L"file"), make_pair(COLON, L":"), make_pair(ATOM, L"write_file"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"FileName"), make_pair(COMMA, L","), 
                                                       /*[<<16#01010101:32,*/
                                                       make_pair(LEFTBRACKET, L"["), make_pair(BITSTRINGHEAD, L"<<"), make_pair(EXPLICITRADIXLITERAL, L"16#01010101"), make_pair(COLON, L":"), make_pair(DECIMALLITERAL, L"32"), make_pair(COMMA, L","), 
                                                       /*Size:32,*/
                                                       make_pair(VARIABLE, L"Size"), make_pair(COLON, L":"), make_pair(DECIMALLITERAL, L"32"), make_pair(COMMA, L","), 
                                                       /*B/binary,*/
                                                       make_pair(VARIABLE, L"B"), make_pair(FORWARDSLASH, L"/"), make_pair(ATOM, L"binary"), 
                                                       /*16#02020202:32,*/
                                                       make_pair(COMMA, L","), make_pair(EXPLICITRADIXLITERAL, L"16#02020202"), make_pair(COLON, L":"), make_pair(DECIMALLITERAL, L"32"), make_pair(COMMA, L","), 
                                                       /*Size:32,*/
                                                       make_pair(VARIABLE, L"Size"), make_pair(COLON, L":"), make_pair(DECIMALLITERAL, L"32"), make_pair(COMMA, L","), 
                                                       /*16#003030303:32>>])*/
                                                       make_pair(EXPLICITRADIXLITERAL, L"16#003030303"), make_pair(COLON, L":"), make_pair(DECIMALLITERAL, L"32"), make_pair(BITSTRINGTAIL, L">>"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), 
                                                       /*end.*/
                                                       make_pair(END, L"end"), make_pair(TERMINATOR, L"."),
                                                       /*del() ->*/
                                                       make_pair(ATOM, L"del"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*file:delete("./test1.vfs").*/
                                                       make_pair(ATOM, L"file"), make_pair(COLON, L":"), make_pair(ATOM, L"delete"), make_pair(LEFTPAREN, L"("), make_pair(STRINGLITERAL, L"\"./test1.vfs\""), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*test() ->*/
                                                       make_pair(ATOM, L"test"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*new_vfs("./test1.vfs", 20, 3).*/
                                                       make_pair(ATOM, L"new_vfs"), make_pair(LEFTPAREN, L"("), make_pair(STRINGLITERAL, L"\"./test1.vfs\""), make_pair(COMMA, L","), make_pair(DECIMALLITERAL, L"20"), make_pair(COMMA, L","), make_pair(DECIMALLITERAL, L"3"), make_pair(RIGHTPAREN, L")"), make_pair(TERMINATOR, L"."), 
                                                       /*start(File) ->*/
                                                       make_pair(ATOM, L"start"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"File"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*Self = self(),*/
                                                       make_pair(VARIABLE, L"Self"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"self"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*Pid = spawn_link(fun() -> start(Self, File) end),*/
                                                       make_pair(VARIABLE, L"Pid"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"spawn_link"), make_pair(LEFTPAREN, L"("), make_pair(FUN, L"fun"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), make_pair(ATOM, L"start"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Self"), make_pair(COMMA, L","), make_pair(VARIABLE, L"File"), make_pair(RIGHTPAREN, L")"), make_pair(END, L"end"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*receive*/
                                                       make_pair(RECEIVE, L"receive"), 
                                                       /*{Pid, Result} ->*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(VARIABLE, L"Pid"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Result"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(ARROW, L"->"), 
                                                       /*Result*/
                                                       make_pair(VARIABLE, L"Result"), 
                                                       /*end.*/
                                                       make_pair(END, L"end"), make_pair(TERMINATOR, L"."), 
                                                       /*start(Parent, File) ->*/
                                                       make_pair(ATOM, L"start"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Parent"), make_pair(COMMA, L","), make_pair(VARIABLE, L"File"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*case (catch try_to_open(File)) of*/
                                                       make_pair(CASE, L"case"), make_pair(LEFTPAREN, L"("), make_pair(CATCH, L"catch"), make_pair(ATOM, L"try_to_open"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"File"), make_pair(RIGHTPAREN, L")"), make_pair(RIGHTPAREN, L")"), make_pair(OF, L"of"), 
                                                       /*{ok, Handle, Env} ->*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"ok"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Handle"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Env"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(ARROW, L"->"), 
                                                       /*Parent ! {self(), {ok, Handle}},*/
                                                       make_pair(VARIABLE, L"Parent"), make_pair(OPSEND, L"!"), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"self"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"ok"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Handle"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(COMMA, L","), 
                                                       /*loop(Env);*/
                                                       make_pair(ATOM, L"loop"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Env"), make_pair(RIGHTPAREN, L")"), make_pair(SEMICOLON, L";"), 
                                                       /*{'EXIT', Why} ->*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"'EXIT'"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Why"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(ARROW, L"->"),
                                                       /*Parent ! {self(), {error, Why}}*/
                                                       make_pair(VARIABLE, L"Parent"), make_pair(OPSEND, L"!"), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"self"), make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"error"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Why"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(RIGHTCURLYBRACKET, L"}"), 
                                                       /*end.*/
                                                       make_pair(END, L"end"), make_pair(TERMINATOR, L"."), 
                                                       /*try_to_open(File) ->*/
                                                       make_pair(ATOM, L"try_to_open"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"File"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*true = filelib:is_regular(File),*/
                                                       make_pair(ATOM, L"true"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"filelib"), make_pair(COLON, L":"), make_pair(ATOM, L"is_regular"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"File"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*Size = filelib:file_size(File),*/
                                                       make_pair(VARIABLE, L"Size"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"filelib"), make_pair(COLON, L":"), make_pair(ATOM, L"file_size"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"File"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","),
                                                       /*{ok, Handle} = file:open(File, [binary, raw, read, write]),*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"ok"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Handle"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"file"), make_pair(COLON, L":"), make_pair(ATOM, L"open"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"File"), make_pair(COMMA, L","), make_pair(LEFTBRACKET, L"["), make_pair(ATOM, L"binary"), make_pair(COMMA, L","), make_pair(ATOM, L"raw"), make_pair(COMMA, L","), make_pair(ATOM, L"read"), make_pair(COMMA, L","), make_pair(ATOM, L"write"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*{ok, Bin} = doread(Handle, Size - 12, 12),*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"ok"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Bin"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"doread"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Handle"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Size"), make_pair(OPMINUS, L"-"), make_pair(DECIMALLITERAL, L"12"), make_pair(COMMA, L","), make_pair(DECIMALLITERAL, L"12"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*case Bin of*/
                                                       make_pair(CASE, L"case"), make_pair(VARIABLE, L"Bin"), make_pair(OF, L"of"), 
                                                       /*<<16#02020202:32, EnvSize:32,16#03030303:32>> ->*/
                                                       make_pair(BITSTRINGHEAD, L"<<"), make_pair(EXPLICITRADIXLITERAL, L"16#02020202"), make_pair(COLON, L":"), make_pair(DECIMALLITERAL, L"32"), make_pair(COMMA, L","), make_pair(VARIABLE, L"EnvSize"), make_pair(COLON, L":"), make_pair(DECIMALLITERAL, L"32"), make_pair(COMMA, L","), make_pair(EXPLICITRADIXLITERAL, L"16#03030303"), make_pair(COLON, L":"), make_pair(DECIMALLITERAL, L"32"), make_pair(BITSTRINGTAIL, L">>"), make_pair(ARROW, L"->"), 
                                                       /*Pos = Size - EnvSize - 12,*/
                                                       make_pair(VARIABLE, L"Pos"), make_pair(OPMATCH, L"="), make_pair(VARIABLE, L"Size"), make_pair(OPMINUS, L"-"), make_pair(VARIABLE, L"EnvSize"), make_pair(OPMINUS, L"-"), make_pair(DECIMALLITERAL, L"12"), make_pair(COMMA, L","), 
                                                       /*{ok, B1} = doread(Handle, Pos, Size),*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"ok"), make_pair(COMMA, L","), make_pair(VARIABLE, L"B1"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"doread"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Handle"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Pos"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Size"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*Env = binary_to_term(B1),*/
                                                       make_pair(VARIABLE, L"Env"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"binary_to_term"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"B1"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*io:format("recovered:~p~n",[Env]),*/
                                                       make_pair(ATOM, L"io"), make_pair(COLON, L":"), make_pair(ATOM, L"format"), make_pair(LEFTPAREN, L"("), make_pair(STRINGLITERAL, L"\"recovered:~p~n\""), make_pair(COMMA, L","), make_pair(LEFTBRACKET, L"["), make_pair(VARIABLE, L"Env"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*{ok, Handle, Env};*/
                                                       make_pair(LEFTCURLYBRACKET, L"{"), make_pair(ATOM, L"ok"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Handle"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Env"), make_pair(RIGHTCURLYBRACKET, L"}"), make_pair(SEMICOLON, L";"), 
                                                       /*_Other ->*/
                                                       make_pair(VARIABLE, L"_Other"), make_pair(ARROW, L"->"), 
                                                       /*io:format("Bin=~p~n",[Bin]),*/
                                                       make_pair(ATOM, L"io"), make_pair(COLON, L":"), make_pair(ATOM, L"format"), make_pair(LEFTPAREN, L"("), make_pair(STRINGLITERAL, L"\"Bin=~p~n\""), make_pair(COMMA, L","), make_pair(LEFTBRACKET, L"["), make_pair(VARIABLE, L"Bin"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*exit(eCorruptArchive)*/
                                                       make_pair(ATOM, L"exit"), make_pair(LEFTPAREN, L"("), make_pair(ATOM, L"eCorruptArchive"), make_pair(RIGHTPAREN, L")"), 
                                                       /*end.*/
                                                       make_pair(END, L"end"), make_pair(TERMINATOR, L"."), 
                                                       /*%% write as if it will work -- no error checking*/
                                                       make_pair(COMMENT, L"%% write as if it will work -- no error checking\n"), 
                                                       /*doread(Handle, Start, Size) ->*/
                                                       make_pair(ATOM, L"doread"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Handle"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Start"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Size"), make_pair(RIGHTPAREN, L")"), make_pair(ARROW, L"->"), 
                                                       /*io:format("pread:~p ~p~n",[Start, Size]),*/
                                                       make_pair(ATOM, L"io"), make_pair(COLON, L":"), make_pair(ATOM, L"format"), make_pair(LEFTPAREN, L"("), make_pair(STRINGLITERAL, L"\"pread:~p ~p~n\""), make_pair(COMMA, L","), make_pair(LEFTBRACKET, L"["), make_pair(VARIABLE, L"Start"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Size"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*Bin = file:pread(Handle, Start, Size),*/
                                                       make_pair(VARIABLE, L"Bin"), make_pair(OPMATCH, L"="), make_pair(ATOM, L"file"), make_pair(COLON, L":"), make_pair(ATOM, L"pread"), make_pair(LEFTPAREN, L"("), make_pair(VARIABLE, L"Handle"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Start"), make_pair(COMMA, L","), make_pair(VARIABLE, L"Size"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*io:format("Bin=~p~n",[Bin]),*/
                                                       make_pair(ATOM, L"io"), make_pair(COLON, L":"), make_pair(ATOM, L"format"), make_pair(LEFTPAREN, L"("), make_pair(STRINGLITERAL, L"\"Bin=~p~n\""), make_pair(COMMA, L","), make_pair(LEFTBRACKET, L"["), make_pair(VARIABLE, L"Bin"), make_pair(RIGHTBRACKET, L"]"), make_pair(RIGHTPAREN, L")"), make_pair(COMMA, L","), 
                                                       /*Bin.*/
                                                       make_pair(VARIABLE, L"Bin"), make_pair(TERMINATOR, L".") };

    TokenVector expectedTokensVec(&expectedTokensArr[0], expectedTokensArr + _countof(expectedTokensArr));

    VerifyLex(vfs, expectedTokensVec);
}

BOOST_AUTO_TEST_SUITE_END()