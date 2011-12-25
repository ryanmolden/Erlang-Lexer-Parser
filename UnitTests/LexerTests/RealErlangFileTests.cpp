#include "StdAfx.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( RealErlangFileTests )

using namespace TestUtil;
using namespace std;

BOOST_AUTO_TEST_CASE( PermutationsFileTest )
{
    wstring permutations = ReadFileIntoString("ErlangFiles\\permutations.erl");

    pair<unsigned int, wstring> expectedTokensArr[] = { /*-module(permutations).*/
                                                       make_pair(ERLANGTOKEN_GENERICATTRIBUTEHEAD, L"-module"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"permutations"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*-export([perms/1]).*/
                                                       make_pair(ERLANGTOKEN_GENERICATTRIBUTEHEAD, L"-export"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_ATOM, L"perms"), make_pair(ERLANGTOKEN_FORWARDSLASH, L"/"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"1"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*perms([])->[[]];*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"perms"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_SEMICOLON, L";"),
                                                       /*perms(L)->[[H|T] || H <- L, T <- perms(L--[H])].*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"perms"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"L"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_VARIABLE, L"H"), make_pair(ERLANGTOKEN_BAR, L"|"), make_pair(ERLANGTOKEN_VARIABLE, L"T"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_DOUBLEBAR, L"||"), make_pair(ERLANGTOKEN_VARIABLE, L"H"), make_pair(ERLANGTOKEN_OPGENERATE, L"<-"), make_pair(ERLANGTOKEN_VARIABLE, L"L"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"T"), make_pair(ERLANGTOKEN_OPGENERATE, L"<-"), make_pair(ERLANGTOKEN_ATOM, L"perms"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"L"), make_pair(ERLANGTOKEN_OPLISTSUBTRACT, L"--"), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_VARIABLE, L"H"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L".") };

    TokenVector expectedTokensVec(&expectedTokensArr[0], expectedTokensArr + _countof(expectedTokensArr));
    VerifyLex(permutations, expectedTokensVec);
}


BOOST_AUTO_TEST_CASE( QSortFileTest )
{
    wstring qsort = ReadFileIntoString("ErlangFiles\\qsort.erl");

    pair<unsigned int, wstring> expectedTokensArr[] = { /*-module(qsort).*/
                                                       make_pair(ERLANGTOKEN_GENERICATTRIBUTEHEAD, L"-module"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"qsort"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*-export([qsort/1]).*/
                                                       make_pair(ERLANGTOKEN_GENERICATTRIBUTEHEAD, L"-export"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_ATOM, L"qsort"), make_pair(ERLANGTOKEN_FORWARDSLASH, L"/"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"1"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*qsort([]) -> [];*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"qsort"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_SEMICOLON, L";"), 
                                                       /*qsort([Pivot|T]) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"qsort"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_VARIABLE, L"Pivot"), make_pair(ERLANGTOKEN_BAR, L"|"), make_pair(ERLANGTOKEN_VARIABLE, L"T"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*qsort([X || X <- T, X < Pivot])*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"qsort"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_VARIABLE, L"X"), make_pair(ERLANGTOKEN_DOUBLEBAR, L"||"), make_pair(ERLANGTOKEN_VARIABLE, L"X"), make_pair(ERLANGTOKEN_OPGENERATE, L"<-"), make_pair(ERLANGTOKEN_VARIABLE, L"T"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"X"), make_pair(ERLANGTOKEN_OPLESSTHAN, L"<"), make_pair(ERLANGTOKEN_VARIABLE, L"Pivot"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), 
                                                       /*++ [Pivot] ++*/
                                                       make_pair(ERLANGTOKEN_OPLISTCONCAT, L"++"), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_VARIABLE, L"Pivot"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_OPLISTCONCAT, L"++"), 
                                                       /*qsort([X || X <- T, X >= Pivot]).*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"qsort"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_VARIABLE, L"X"), make_pair(ERLANGTOKEN_DOUBLEBAR, L"||"), make_pair(ERLANGTOKEN_VARIABLE, L"X"), make_pair(ERLANGTOKEN_OPGENERATE, L"<-"), make_pair(ERLANGTOKEN_VARIABLE, L"T"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"X"), make_pair(ERLANGTOKEN_OPGREATERTHANEQUAL, L">="), make_pair(ERLANGTOKEN_VARIABLE, L"Pivot"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L".") };

    TokenVector expectedTokensVec(&expectedTokensArr[0], expectedTokensArr + _countof(expectedTokensArr));
    VerifyLex(qsort, expectedTokensVec);
}

BOOST_AUTO_TEST_CASE( RingFileTest )
{
    wstring ring = ReadFileIntoString("ErlangFiles\\ring.erl");

    pair<unsigned int, wstring> expectedTokensArr[] = { /*-module(ring).*/
                                                       make_pair(ERLANGTOKEN_GENERICATTRIBUTEHEAD, L"-module"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"ring"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*-export([start/1, start/2]).*/
                                                       make_pair(ERLANGTOKEN_GENERICATTRIBUTEHEAD, L"-export"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_ATOM, L"start"), make_pair(ERLANGTOKEN_FORWARDSLASH, L"/"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"1"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_ATOM, L"start"), make_pair(ERLANGTOKEN_FORWARDSLASH, L"/"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"2"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*%% Time (seconds)                          Description*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%% Time (seconds)                          Description\n"),
                                                       /*%%----------------------------------------------------------------------------------------------------------*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%----------------------------------------------------------------------------------------------------------\n"), 
                                                       /*%%    179              Original - Passing message 'hello' to PID returned from ring:start(128,1048576).*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%    179              Original - Passing message 'hello' to PID returned from ring:start(128,1048576).\n"), 
                                                       /*%%    174              Take off (when Head =:= self()) in Msg -> clause.*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%    174              Take off (when Head =:= self()) in Msg -> clause.\n"), 
                                                       /*%%    167              Name tuple in receieve_loop args.*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%    167              Name tuple in receive_loop args.\n"), 
                                                       /*%%    135              Drastically simplify messages and receive_loop args.*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%    135              Drastically simplify messages and receive_loop args.\n"), 
                                                       /*%%    137              Move the case of TTL =:= 0 into its own pattern.*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%    137              Move the case of TTL =:= 0 into its own pattern.\n"), 
                                                       /*%%    134              Move from case to if (after reverting above change) for testing TTL against 0.*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%    134              Move from case to if (after reverting above change) for testing TTL against 0.\n"), 
                                                       /*start(NodeCount) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"start"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"NodeCount"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*start(NodeCount, 1).*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"start"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"NodeCount"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"1"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."),
                                                       /*start(NodeCount, LoopCount) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"start"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"NodeCount"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"LoopCount"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*spawn(fun() -> create_ring(NodeCount, LoopCount) end).*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"spawn"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_FUN, L"fun"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), make_pair(ERLANGTOKEN_ATOM, L"create_ring"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"NodeCount"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"LoopCount"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*%%First spawned node, this becomes the de-facto head of the ring.*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%First spawned node, this becomes the de-facto head of the ring.\n"), 
                                                       /*create_ring(NodeCount, LoopCount) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"create_ring"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"NodeCount"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"LoopCount"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*Next = spawn(fun() -> create_ring({NodeCount, NodeCount - 1}, LoopCount, self()) end),*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Next"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"spawn"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_FUN, L"fun"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), make_pair(ERLANGTOKEN_ATOM, L"create_ring"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_VARIABLE, L"NodeCount"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"NodeCount"), make_pair(ERLANGTOKEN_OPMINUS, L"-"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"1"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"LoopCount"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_ATOM, L"self"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*  receive_loop(Next, NodeCount * LoopCount).*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"receive_loop"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Next"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"NodeCount"), make_pair(ERLANGTOKEN_OPMULT, L"*"), make_pair(ERLANGTOKEN_VARIABLE, L"LoopCount"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*%%Last spawned node (RemainingNodeCount =:= 1), this becomes the tail and needs to forward its messages */
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%Last spawned node (RemainingNodeCount =:= 1), this becomes the tail and needs to forward its messages \n"), 
                                                       /*%%to the head (RingHead)*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%to the head (RingHead)\n"), 
                                                       /*create_ring({NodeCount, 1}, LoopCount, RingHead) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"create_ring"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_VARIABLE, L"NodeCount"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"1"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"LoopCount"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"RingHead"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*receive_loop(RingHead, NodeCount * LoopCount);*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"receive_loop"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"RingHead"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"NodeCount"), make_pair(ERLANGTOKEN_OPMULT, L"*"), make_pair(ERLANGTOKEN_VARIABLE, L"LoopCount"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_SEMICOLON, L";"), 
                                                       /*%%'Normal' node, it simply spawns the next node in the chain passing along the id of the head as given to it*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%'Normal' node, it simply spawns the next node in the chain passing along the id of the head as given to it\n"), 
                                                       /*create_ring({NodeCount, RemainingNodeCount}, LoopCount, RingHead) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"create_ring"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_VARIABLE, L"NodeCount"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"RemainingNodeCount"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"LoopCount"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"RingHead"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*Next = spawn(ERLANGTOKEN_FUN() -> create_ring({NodeCount, RemainingNodeCount-1}, LoopCount, RingHead) ERLANGTOKEN_END),*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Next"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"spawn"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_FUN, L"fun"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), make_pair(ERLANGTOKEN_ATOM, L"create_ring"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_VARIABLE, L"NodeCount"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"RemainingNodeCount"), make_pair(ERLANGTOKEN_OPMINUS, L"-"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"1"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"LoopCount"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"RingHead"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*receive_loop(Next, NodeCount * LoopCount).*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"receive_loop"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Next"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"NodeCount"), make_pair(ERLANGTOKEN_OPMULT, L"*"), make_pair(ERLANGTOKEN_VARIABLE, L"LoopCount"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*%%Main message loop for each ring node (except the head)*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%Main message loop for each ring node (except the head)\n"), 
                                                       /*receive_loop(Next, TotalMessageCount) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"receive_loop"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Next"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"TotalMessageCount"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*receive*/
                                                       make_pair(ERLANGTOKEN_RECEIVE, L"receive"), 
                                                       /*%%If the message has a TTL section then it had to have come to us from our ancestor node, if its TTL is */
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%If the message has a TTL section then it had to have come to us from our ancestor node, if its TTL is \n"), 
                                                       /*%%0 it means this is the receipt of the last of the N*M messages (TTL = N*M), otherwise we just pass it*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%0 it means this is the receipt of the last of the N*M messages (TTL = N*M), otherwise we just pass it\n"), 
                                                       /*%%along like any other message.*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%along like any other message.\n"), 
                                                       /*{Msg, TTL} ->*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_VARIABLE, L"Msg"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"TTL"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*if (TTL =:= 0) ->*/
                                                       make_pair(ERLANGTOKEN_IF, L"if"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"TTL"), make_pair(ERLANGTOKEN_OPIDENTICALTO, L"=:="), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"0"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*{_, CPUTime} = statistics(runtime),*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_UNIVERSALPATTERN, L"_"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"CPUTime"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"statistics"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"runtime"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*{_, WallClockTime} = statistics(wall_clock),*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_UNIVERSALPATTERN, L"_"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"WallClockTime"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"statistics"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"wall_clock"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*AvgCPUMS = CPUTime / TotalMessageCount,*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"AvgCPUMS"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_VARIABLE, L"CPUTime"), make_pair(ERLANGTOKEN_FORWARDSLASH, L"/"), make_pair(ERLANGTOKEN_VARIABLE, L"TotalMessageCount"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*AvgWallClockMS = WallClockTime / TotalMessageCount,*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"AvgWallClockMS"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_VARIABLE, L"WallClockTime"), make_pair(ERLANGTOKEN_FORWARDSLASH, L"/"), make_pair(ERLANGTOKEN_VARIABLE, L"TotalMessageCount"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*io:format("Circuit took ~p (~p) total milliseconds to complete ~p hops which is an average of ~p (~p) milliseconds per hop.~n", [CPUTime, WallClockTime, TotalMessageCount, AvgCPUMS, AvgWallClockMS]),*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"io"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"format"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_STRINGLITERAL, L"\"Circuit took ~p (~p) total milliseconds to complete ~p hops which is an average of ~p (~p) milliseconds per hop.~n\""), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_VARIABLE, L"CPUTime"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"WallClockTime"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"TotalMessageCount"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"AvgCPUMS"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"AvgWallClockMS"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*receive_loop(Next, TotalMessageCount);*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"receive_loop"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Next"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"TotalMessageCount"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_SEMICOLON, L";"), 
                                                       /*true ->  %%Erlang equivalent of else for the if construct*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"true"), make_pair(ERLANGTOKEN_ARROW, L"->"), make_pair(ERLANGTOKEN_COMMENT, L"%%Erlang equivalent of else for the if construct\n"), 
                                                       /*%%io:format("~p> Passing along ~p to ~p with a remaining hop count (TTL) of ~p~n", [self(), Msg, Next, TTL-1]),*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%io:format(\"~p> Passing along ~p to ~p with a remaining hop count (TTL) of ~p~n\", [self(), Msg, Next, TTL-1]),\n"), 
                                                       /*Next ! {Msg, TTL - 1},*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Next"), make_pair(ERLANGTOKEN_OPSEND, L"!"), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_VARIABLE, L"Msg"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"TTL"), make_pair(ERLANGTOKEN_OPMINUS, L"-"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"1"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*receive_loop(Next, TotalMessageCount)*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"receive_loop"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Next"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"TotalMessageCount"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), 
                                                       /*end;*/
                                                       make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_SEMICOLON, L";"), 
                                                       /*%%If the message has no node id identifying who it is from then it must be direct from the user so either*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%If the message has no node id identifying who it is from then it must be direct from the user so either\n"), 
                                                       /*%%kick off the tear down sequence (if it is the 'stop' message) or start our timing and pass it on.*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%kick off the tear down sequence (if it is the 'stop' message) or start our timing and pass it on.\n"), 
                                                       /*Msg ->*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Msg"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*if Msg =:= stop ->*/
                                                       make_pair(ERLANGTOKEN_IF, L"if"), make_pair(ERLANGTOKEN_VARIABLE, L"Msg"), make_pair(ERLANGTOKEN_OPIDENTICALTO, L"=:="), make_pair(ERLANGTOKEN_ATOM, L"stop"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*%%io:format("~p> Shutting down node~n", [self()]),*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%io:format(\"~p> Shutting down node~n\", [self()]),\n"), 
                                                       /*Next ! stop;*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Next"), make_pair(ERLANGTOKEN_OPSEND, L"!"), make_pair(ERLANGTOKEN_ATOM, L"stop"), make_pair(ERLANGTOKEN_SEMICOLON, L";"), 
                                                       /*true ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"true"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*%%io:format("~p> Starting ~p at head with remaining hop count (TTL) of ~p~n", [self(), Msg, TotalMessageCount - 1]),*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%io:format(\"~p> Starting ~p at head with remaining hop count (TTL) of ~p~n\", [self(), Msg, TotalMessageCount - 1]),\n"), 
                                                       /*statistics(runtime),*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"statistics"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"runtime"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*statistics(wall_clock),*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"statistics"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"wall_clock"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*Next ! {Msg, TotalMessageCount - 1},*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Next"), make_pair(ERLANGTOKEN_OPSEND, L"!"), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_VARIABLE, L"Msg"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"TotalMessageCount"), make_pair(ERLANGTOKEN_OPMINUS, L"-"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"1"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*receive_loop(Next, TotalMessageCount)*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"receive_loop"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Next"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"TotalMessageCount"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), 
                                                       /*end*/
                                                       make_pair(ERLANGTOKEN_END, L"end"), 
                                                       /*end.*/
                                                       make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L".") };

    TokenVector expectedTokensVec(&expectedTokensArr[0], expectedTokensArr + _countof(expectedTokensArr));
    VerifyLex(ring, expectedTokensVec);
}

BOOST_AUTO_TEST_CASE( VFSFileTest )
{
    wstring vfs = ReadFileIntoString("ErlangFiles\\vfs.erl");

    pair<unsigned int, wstring> expectedTokensArr[] = { /*%% ---*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%% ---\n"),
                                                       /*%%  Excerpted from L"Programming Erlang",*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%  Excerpted from \"Programming Erlang\",\n"), 
                                                       /*%%  published by The Pragmatic Bookshelf.*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%  published by The Pragmatic Bookshelf.\n"), 
                                                       /*%%  Copyrights apply to this code. It may not be used to create training material,*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%  Copyrights apply to this code. It may not be used to create training material, \n"), 
                                                       /*%%  courses, books, articles, and the like. Contact us if you are in doubt.*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%  courses, books, articles, and the like. Contact us if you are in doubt.\n"), 
                                                       /*%%  We make no guarantees that this code is fit for any purpose.*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%  We make no guarantees that this code is fit for any purpose. \n"),
                                                       /*%%  Visit http://www.pragmaticprogrammer.com/titles/jaerlang for more book information.*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%  Visit http://www.pragmaticprogrammer.com/titles/jaerlang for more book information.\n"), 
                                                       /*%%---*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%---\n"), 
                                                       /*-module(vfs).*/
                                                       make_pair(ERLANGTOKEN_GENERICATTRIBUTEHEAD, L"-module"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"vfs"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*-compile(export_all).*/
                                                       make_pair(ERLANGTOKEN_GENERICATTRIBUTEHEAD, L"-compile"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"export_all"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."),
                                                       /*-import(lib_misc, [downcase_str/1]).*/
                                                       make_pair(ERLANGTOKEN_GENERICATTRIBUTEHEAD, L"-import"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"lib_misc"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_ATOM, L"downcase_str"), make_pair(ERLANGTOKEN_FORWARDSLASH, L"/"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"1"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*-import(lists, [member/2]).*/
                                                       make_pair(ERLANGTOKEN_GENERICATTRIBUTEHEAD, L"-import"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"lists"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_ATOM, L"member"), make_pair(ERLANGTOKEN_FORWARDSLASH, L"/"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"2"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*big_text() -> L"./lib_misc.erl".*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"big_text"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), make_pair(ERLANGTOKEN_STRINGLITERAL, L"\"./lib_misc.erl\""), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*big_media() -> L"track030.mp3".*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"big_media"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), make_pair(ERLANGTOKEN_STRINGLITERAL, L"\"track030.mp3\""), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*%% @spec read_file(string()) -> {Compressed:bool(), int(), binary()}.*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%% @spec read_file(string()) -> {Compressed:bool(), int(), binary()}.\n"), 
                                                       /*read_file(File) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"read_file"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*{ok, Bin} = file:read_file(File),*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"ok"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Bin"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"file"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"read_file"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*{Flag, Size, Data} = case is_media_file(File) of*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_VARIABLE, L"Flag"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Data"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_CASE, L"case"), make_pair(ERLANGTOKEN_ATOM, L"is_media_file"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_OF, L"of"), 
                                                       /*true -> {false, size(Bin), Bin};*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"true"), make_pair(ERLANGTOKEN_ARROW, L"->"), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"false"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_ATOM, L"size"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Bin"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Bin"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_SEMICOLON, L";"), 
                                                       /*false -> Bin1 = term_to_binary(Bin, [compressed]),*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"false"), make_pair(ERLANGTOKEN_ARROW, L"->"), make_pair(ERLANGTOKEN_VARIABLE, L"Bin1"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"term_to_binary"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Bin"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_ATOM, L"compressed"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*{true, size(Bin1), Bin1}*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"true"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_ATOM, L"size"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Bin1"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Bin1"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), 
                                                       /*ERLANGTOKEN_END,*/
                                                       make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*Md5 = lib_md5:binAsBin(Data),*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Md5"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"lib_md5"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"binAsBin"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Data"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*{Flag, Size, Md5, Data}.*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_VARIABLE, L"Flag"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Md5"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Data"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*is_media_file(File) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"is_media_file"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*member(downcase_str(filename:extension(File)),*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"member"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"downcase_str"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"filename"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"extension"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*[".jpg", L".mp3", L".mpg"]).*/
                                                       make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_STRINGLITERAL, L"\".jpg\""), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_STRINGLITERAL, L"\".mp3\""), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_STRINGLITERAL, L"\".mpg\""), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*write_file_to_store(Pid, File, Md5, Compressed, Data) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"write_file_to_store"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Pid"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Md5"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Compressed"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Data"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*case rpc(Pid, {should_i_store, File, Md5}) of*/
                                                       make_pair(ERLANGTOKEN_CASE, L"case"), make_pair(ERLANGTOKEN_ATOM, L"rpc"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Pid"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"should_i_store"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Md5"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_OF, L"of"), 
                                                       /*{yes, Vsn} ->*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"yes"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Vsn"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_ARROW, L"->"),
                                                       /*Data = term_to_binary({File,Vsn,Md5,Compressed,Data}),*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Data"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"term_to_binary"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Vsn"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Md5"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Compressed"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Data"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*Size = size(Data) + 32,*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"size"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Data"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_OPPLUS, L"+"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"32"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*case rpc(Pid, {need_some_space, File, Vsn, Md5, Size}) of*/
                                                       make_pair(ERLANGTOKEN_CASE, L"case"), make_pair(ERLANGTOKEN_ATOM, L"rpc"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Pid"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"need_some_space"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Vsn"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Md5"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_OF, L"of"), 
                                                       /*{yes, Handle, _Start} ->*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"yes"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Handle"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"_Start"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_ARROW, L"->"),
                                                       /*file:pwrite(Handle,*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"file"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"pwrite"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Handle"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*[<<16#111111111:32, Size:32>>,Data/binary,*/
                                                       make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_BITSTRINGHEAD, L"<<"), make_pair(ERLANGTOKEN_EXPLICITRADIXLITERAL, L"16#111111111"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"32"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"32"), make_pair(ERLANGTOKEN_BITSTRINGTAIL, L">>"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Data"), make_pair(ERLANGTOKEN_FORWARDSLASH, L"/"), make_pair(ERLANGTOKEN_ATOM, L"binary"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*<<16#222222222:32>>]);*/
                                                       make_pair(ERLANGTOKEN_BITSTRINGHEAD, L"<<"), make_pair(ERLANGTOKEN_EXPLICITRADIXLITERAL, L"16#222222222"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"32"), make_pair(ERLANGTOKEN_BITSTRINGTAIL, L">>"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_SEMICOLON, L";"), 
                                                       /*no ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"no"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*exit(internal)*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"exit"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"internal"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), 
                                                       /*ERLANGTOKEN_END;*/
                                                       make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_SEMICOLON, L";"), 
                                                       /*no ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"no"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*true*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"true"), 
                                                       /*ERLANGTOKEN_END.*/
                                                       make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*rpc(Pid, Q) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"rpc"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Pid"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Q"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*Pid ! {self(), Q},*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Pid"), make_pair(ERLANGTOKEN_OPSEND, L"!"), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"self"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Q"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*receive*/
                                                       make_pair(ERLANGTOKEN_RECEIVE, L"receive"), 
                                                       /*{Pid, Reply} ->*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_VARIABLE, L"Pid"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Reply"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*Reply*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Reply"), 
                                                       /*ERLANGTOKEN_END.*/
                                                       make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*loop(Env) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"loop"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Env"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*receive*/
                                                       make_pair(ERLANGTOKEN_RECEIVE, L"receive"), 
                                                       /*{From, {should_i_store, File, Md5}} ->*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_VARIABLE, L"From"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"should_i_store"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Md5"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*case should_i_store(File, Md5, Env) of*/
                                                       make_pair(ERLANGTOKEN_CASE, L"case"), make_pair(ERLANGTOKEN_ATOM, L"should_i_store"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Md5"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Env"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_OF, L"of"),
                                                       /*{yes, Vsn, Env1} ->*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"yes"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Vsn"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Env1"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_ARROW, L"->"),
                                                       /*From ! {self(), {yes, Vsn}},*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"From"), make_pair(ERLANGTOKEN_OPSEND, L"!"), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"self"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"yes"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Vsn"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*loop(Env1);*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"loop"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Env1"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_SEMICOLON, L";"), 
                                                       /*no ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"no"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*From ! {self(), no},*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"From"), make_pair(ERLANGTOKEN_OPSEND, L"!"), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"self"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_ATOM, L"no"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*loop(Env)*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"loop"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Env"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), 
                                                       /*ERLANGTOKEN_END;*/
                                                       make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_SEMICOLON, L";"), 
                                                       /*Any ->*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Any"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*io:format("Any=~p~n",[Any])*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"io"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"format"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_STRINGLITERAL, L"\"Any=~p~n\""), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_VARIABLE, L"Any"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), 
                                                       /*end.*/
                                                       make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*should_i_store(_File, _Md5, _Dict) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"should_i_store"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"_File"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"_Md5"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"_Dict"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*true.*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"true"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*%%  case dict:find(File, Dict) ->*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%  case dict:find(File, Dict) ->\n"), 
                                                       /*%%    end.*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%    end.\n"), 
                                                       /*%%   11111111*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%   11111111\n"), 
                                                       /*%%   Size*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%   Size\n"), 
                                                       /*%%     Data = term_to_binary({File,Compressed,Vsn,Data}}*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%     Data = term_to_binary({File,Compressed,Vsn,Data}}\n"), 
                                                       /*%%   22222222*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%%   22222222\n"), 
                                                       /*%% Globals*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%% Globals\n"), 
                                                       /*-record(env,*/
                                                       make_pair(ERLANGTOKEN_GENERICATTRIBUTEHEAD, L"-record"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"env"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*{maxSize,*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"maxSize"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*allocated,*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"allocated"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*index,*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"index"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*dirty,*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"dirty"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*maxVersions,*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"maxVersions"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*freeList}).*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"freeList"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*%% Freelist = [{Address, Space}, ...]*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%% Freelist = [{Address, Space}, ...]\n"), 
                                                       /*%% sorted by address*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%% sorted by address\n"), 
                                                       /*%% MaxSize is in MB*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%% MaxSize is in MB\n"), 
                                                       /*new_vfs(FileName, MaxSize, MaxVersions) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"new_vfs"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"FileName"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"MaxSize"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"MaxVersions"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*case filelib:is_regular(FileName) of*/
                                                       make_pair(ERLANGTOKEN_CASE, L"case"), make_pair(ERLANGTOKEN_ATOM, L"filelib"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"is_regular"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"FileName"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_OF, L"of"),
                                                       /*true ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"true"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*exit(eFileExists);*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"exit"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"eFileExists"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_SEMICOLON, L";"),
                                                       /*false ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"false"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*FreeList = [{1, MaxSize}],*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"FreeList"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"1"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"MaxSize"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*Env = #env{allocated=0,*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Env"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_HASH, L"#"), make_pair(ERLANGTOKEN_ATOM, L"env"), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"allocated"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"0"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*index = dict:new(),*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"index"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"dict"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"new"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","),
                                                       /*dirty=false,*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"dirty"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"false"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*maxSize=MaxSize*1000000,*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"maxSize"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_VARIABLE, L"MaxSize"), make_pair(ERLANGTOKEN_OPMULT, L"*"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"1000000"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*freeList=FreeList,*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"freeList"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_VARIABLE, L"FreeList"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*maxVersions = MaxVersions},*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"maxVersions"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_VARIABLE, L"MaxVersions"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*B = term_to_binary(Env),*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"B"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"term_to_binary"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Env"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*Size = size(B),*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"size"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"B"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*file:write_file(FileName,*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"file"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"write_file"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"FileName"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*[<<16#01010101:32,*/
                                                       make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_BITSTRINGHEAD, L"<<"), make_pair(ERLANGTOKEN_EXPLICITRADIXLITERAL, L"16#01010101"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"32"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*Size:32,*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"32"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*B/binary,*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"B"), make_pair(ERLANGTOKEN_FORWARDSLASH, L"/"), make_pair(ERLANGTOKEN_ATOM, L"binary"), 
                                                       /*16#02020202:32,*/
                                                       make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_EXPLICITRADIXLITERAL, L"16#02020202"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"32"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*Size:32,*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"32"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*16#003030303:32>>])*/
                                                       make_pair(ERLANGTOKEN_EXPLICITRADIXLITERAL, L"16#003030303"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"32"), make_pair(ERLANGTOKEN_BITSTRINGTAIL, L">>"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), 
                                                       /*ERLANGTOKEN_END.*/
                                                       make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."),
                                                       /*del() ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"del"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*file:delete("./test1.vfs").*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"file"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"delete"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_STRINGLITERAL, L"\"./test1.vfs\""), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*test() ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"test"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*new_vfs("./test1.vfs", 20, 3).*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"new_vfs"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_STRINGLITERAL, L"\"./test1.vfs\""), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"20"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"3"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*start(File) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"start"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*Self = self(),*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Self"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"self"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*Pid = spawn_link(fun() -> start(Self, File) end),*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Pid"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"spawn_link"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_FUN, L"fun"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), make_pair(ERLANGTOKEN_ATOM, L"start"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Self"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*receive*/
                                                       make_pair(ERLANGTOKEN_RECEIVE, L"receive"), 
                                                       /*{Pid, Result} ->*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_VARIABLE, L"Pid"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Result"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*Result*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Result"), 
                                                       /*end.*/
                                                       make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*start(Parent, File) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"start"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Parent"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*case (catch try_to_open(File)) of*/
                                                       make_pair(ERLANGTOKEN_CASE, L"case"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_CATCH, L"catch"), make_pair(ERLANGTOKEN_ATOM, L"try_to_open"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_OF, L"of"), 
                                                       /*{ok, Handle, Env} ->*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"ok"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Handle"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Env"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*Parent ! {self(), {ok, Handle}},*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Parent"), make_pair(ERLANGTOKEN_OPSEND, L"!"), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"self"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"ok"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Handle"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*loop(Env);*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"loop"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Env"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_SEMICOLON, L";"), 
                                                       /*{'EXIT', Why} ->*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"'EXIT'"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Why"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_ARROW, L"->"),
                                                       /*Parent ! {self(), {error, Why}}*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Parent"), make_pair(ERLANGTOKEN_OPSEND, L"!"), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"self"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"error"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Why"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), 
                                                       /*ERLANGTOKEN_END.*/
                                                       make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*try_to_open(File) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"try_to_open"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*true = filelib:is_regular(File),*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"true"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"filelib"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"is_regular"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*Size = filelib:file_size(File),*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"filelib"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"file_size"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","),
                                                       /*{ok, Handle} = file:open(File, [binary, raw, read, write]),*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"ok"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Handle"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"file"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"open"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"File"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_ATOM, L"binary"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_ATOM, L"raw"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_ATOM, L"read"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_ATOM, L"write"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*{ok, Bin} = doread(Handle, Size - 12, 12),*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"ok"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Bin"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"doread"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Handle"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_OPMINUS, L"-"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"12"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"12"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*case Bin of*/
                                                       make_pair(ERLANGTOKEN_CASE, L"case"), make_pair(ERLANGTOKEN_VARIABLE, L"Bin"), make_pair(ERLANGTOKEN_OF, L"of"), 
                                                       /*<<16#02020202:32, EnvSize:32,16#03030303:32>> ->*/
                                                       make_pair(ERLANGTOKEN_BITSTRINGHEAD, L"<<"), make_pair(ERLANGTOKEN_EXPLICITRADIXLITERAL, L"16#02020202"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"32"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"EnvSize"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"32"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_EXPLICITRADIXLITERAL, L"16#03030303"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"32"), make_pair(ERLANGTOKEN_BITSTRINGTAIL, L">>"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*Pos = Size - EnvSize - 12,*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Pos"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_OPMINUS, L"-"), make_pair(ERLANGTOKEN_VARIABLE, L"EnvSize"), make_pair(ERLANGTOKEN_OPMINUS, L"-"), make_pair(ERLANGTOKEN_DECIMALLITERAL, L"12"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*{ok, B1} = doread(Handle, Pos, Size),*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"ok"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"B1"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"doread"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Handle"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Pos"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*Env = binary_to_term(B1),*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Env"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"binary_to_term"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"B1"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*io:format("recovered:~p~n",[Env]),*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"io"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"format"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_STRINGLITERAL, L"\"recovered:~p~n\""), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_VARIABLE, L"Env"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*{ok, Handle, Env};*/
                                                       make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"), make_pair(ERLANGTOKEN_ATOM, L"ok"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Handle"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Env"), make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"), make_pair(ERLANGTOKEN_SEMICOLON, L";"), 
                                                       /*_Other ->*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"_Other"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*io:format("Bin=~p~n",[Bin]),*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"io"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"format"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_STRINGLITERAL, L"\"Bin=~p~n\""), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_VARIABLE, L"Bin"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*exit(eCorruptArchive)*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"exit"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_ATOM, L"eCorruptArchive"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), 
                                                       /*ERLANGTOKEN_END.*/
                                                       make_pair(ERLANGTOKEN_END, L"end"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L"."), 
                                                       /*%% write as if it will work -- no error checking*/
                                                       make_pair(ERLANGTOKEN_COMMENT, L"%% write as if it will work -- no error checking\n"), 
                                                       /*doread(Handle, Start, Size) ->*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"doread"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Handle"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Start"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                       /*io:format("pread:~p ~p~n",[Start, Size]),*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"io"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"format"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_STRINGLITERAL, L"\"pread:~p ~p~n\""), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_VARIABLE, L"Start"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*Bin = file:pread(Handle, Start, Size),*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Bin"), make_pair(ERLANGTOKEN_OPMATCH, L"="), make_pair(ERLANGTOKEN_ATOM, L"file"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"pread"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_VARIABLE, L"Handle"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Start"), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_VARIABLE, L"Size"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*io:format("Bin=~p~n",[Bin]),*/
                                                       make_pair(ERLANGTOKEN_ATOM, L"io"), make_pair(ERLANGTOKEN_COLON, L":"), make_pair(ERLANGTOKEN_ATOM, L"format"), make_pair(ERLANGTOKEN_LEFTPAREN, L"("), make_pair(ERLANGTOKEN_STRINGLITERAL, L"\"Bin=~p~n\""), make_pair(ERLANGTOKEN_COMMA, L","), make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), make_pair(ERLANGTOKEN_VARIABLE, L"Bin"), make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"), make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), make_pair(ERLANGTOKEN_COMMA, L","), 
                                                       /*Bin.*/
                                                       make_pair(ERLANGTOKEN_VARIABLE, L"Bin"), make_pair(ERLANGTOKEN_DOTTERMINATOR, L".") };

    TokenVector expectedTokensVec(&expectedTokensArr[0], expectedTokensArr + _countof(expectedTokensArr));

    VerifyLex(vfs, expectedTokensVec);
}

BOOST_AUTO_TEST_SUITE_END()