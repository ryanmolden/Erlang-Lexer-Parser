#include "StdAfx.h"
#include <boost/test/unit_test.hpp>
#include "TestUtil.h"
#include <ErlangTokens.h>

BOOST_AUTO_TEST_SUITE( StringLiteralTests )

using namespace TestUtil;
using namespace std;

BOOST_AUTO_TEST_CASE( StringLiteralRecognizedEscapeSequencesTest )
{
    wstring recogizedEscapeSequences[] = { wstring(L"\\b"), wstring(L"\\d"), wstring(L"\\e"), wstring(L"\\f"), wstring(L"\\n"), wstring(L"\\r"),
                                           wstring(L"\\s"), wstring(L"\\t"), wstring(L"\\v"), wstring(L"\\\\"), wstring(L"\\'"), wstring(L"\\\"") };  

    for_each(&recogizedEscapeSequences[0], recogizedEscapeSequences + _countof(recogizedEscapeSequences),
             [](const wstring& refString) -> void
             {
                 wstring toLex = wstring(L"\"") + refString + wstring(L"\"");

                 TokenVector expectedTokens;
                 expectedTokens.push_back(make_pair(ERLANGTOKEN_STRINGLITERAL, toLex));

                 VerifyLex(toLex, expectedTokens);
             });
}

BOOST_AUTO_TEST_CASE( ControlEscapeStringLiteralsTest )
{
    VerifyEscapedControlCodes(ERLANGTOKEN_STRINGLITERAL, wstring(L"\""), wstring(L"\""));
}

BOOST_AUTO_TEST_CASE( OctalEscapeStringLiteralsTest )
{
    VerifyEscapedOctalDigits(ERLANGTOKEN_STRINGLITERAL, wstring(L"\""), wstring(L"\""));
}

BOOST_AUTO_TEST_CASE( InvalidStringLiteralsTest )
{
    vector<wstring> invalidStringLiteralItems;

    //backslashes and quotes are not allowed inside a string literal (the latter makes some sense as it ENDS the string literal...not sure about the former,
    //but it is what the grammar says). The erlang shell seems to be okay as long as the back slash isn't the last character in the string...maybe I should model
    //that instead of strictly what the grammar says.
    invalidStringLiteralItems.push_back(L"\\");
    invalidStringLiteralItems.push_back(L"\"");

    //0-31 of the asci character table are considered control codes in erlang and NOT valid inside a string literal. 
    PopulateASCIICharacterCodes(invalidStringLiteralItems, make_pair(0,32));

    for_each(invalidStringLiteralItems.begin(), invalidStringLiteralItems.end(),
             [](const wstring& refStringLit) -> void
             {
                 TokenVector expectedTokens;
                 wstring toLex = wstring(L"\"") + refStringLit + wstring(L"\"");

                 VerifyLex(toLex, expectedTokens, false /*shouldSucceed*/);
             });
}

BOOST_AUTO_TEST_SUITE_END()