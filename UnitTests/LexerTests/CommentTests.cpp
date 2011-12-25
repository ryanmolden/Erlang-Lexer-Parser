#include "StdAfx.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( CommentTests )

using namespace TestUtil;
using namespace std;

BOOST_AUTO_TEST_CASE( EmptyCommentTest )
{
    TokenVector expectedTokens;
    expectedTokens.push_back(make_pair(ERLANGTOKEN_COMMENT, L"%\n"));

    VerifyLex(expectedTokens[0].second, expectedTokens);

    expectedTokens.clear();
    expectedTokens.push_back(make_pair(ERLANGTOKEN_COMMENT, L"%\r"));

    VerifyLex(expectedTokens[0].second, expectedTokens);

    expectedTokens.clear();
    expectedTokens.push_back(make_pair(ERLANGTOKEN_COMMENT, L"%\r\n"));

    VerifyLex(expectedTokens[0].second, expectedTokens);

    expectedTokens.clear();
    expectedTokens.push_back(make_pair(ERLANGTOKEN_COMMENT, L"%\n\r"));

    VerifyLex(expectedTokens[0].second, expectedTokens);
}

BOOST_AUTO_TEST_CASE( SimpleCommentTest )
{
    TokenVector expectedTokens;
    expectedTokens.push_back(make_pair(ERLANGTOKEN_COMMENT, L"%This is an Erlang comment!\n"));

    VerifyLex(expectedTokens[0].second, expectedTokens);
}

BOOST_AUTO_TEST_CASE( SimpleDoubledUpCommentCharTest )
{
    TokenVector expectedTokens;
    expectedTokens.push_back(make_pair(ERLANGTOKEN_COMMENT, L"%%This is an Erlang comment with too!\n"));

    VerifyLex(expectedTokens[0].second, expectedTokens);
}

BOOST_AUTO_TEST_CASE( SimpleCommentWithNoLineTerminatorTest )
{
    TokenVector expectedTokens;
    expectedTokens.push_back(make_pair(ERLANGTOKEN_COMMENT, L"%This is an Erlang comment!"));

    VerifyLex(expectedTokens[0].second, expectedTokens);
}

BOOST_AUTO_TEST_CASE( FullCharacterRangeTest )
{
    wstring comment(L"%");

    //Any ASCII character code between 32 and 126 should be acceptable in a comment string.
    for(int i = 32 ; i < 127 ; ++i)
    {
        comment += static_cast<char>(i);
    }

    comment += L"\n";

    TokenVector expectedTokens;
    expectedTokens.push_back(make_pair(ERLANGTOKEN_COMMENT, comment));

    VerifyLex(expectedTokens[0].second, expectedTokens);
}

BOOST_AUTO_TEST_CASE( InvalidCharacterRangeTest )
{
    //No characters in the range 0 - 31 (except line feed and carriage return) should be allowed in a comment string.
    //
    //(NOTE:  What about horizontal-tabs?  Seems like they likely should be.)
    vector<wstring> invalidCommentCharacters;
    for(int i = 0 ; i < 32 ; ++i)
    {
        //Tab, LF & CR
        if(i == 9 || i == 10 || i == 13)
            continue;

        wstring str;
        str+=static_cast<wchar_t>(i);

        invalidCommentCharacters.push_back(str);
    }

    for_each(invalidCommentCharacters.begin(), invalidCommentCharacters.end(),
             [](const wstring& refItem) -> void 
             {
                 wstring toLex = wstring(L"%") + refItem + wstring(L"\n");

                 TokenVector expectedTokens;
                 VerifyLex(toLex, expectedTokens, false /*shouldSucceed*/);
             });
}

BOOST_AUTO_TEST_SUITE_END()