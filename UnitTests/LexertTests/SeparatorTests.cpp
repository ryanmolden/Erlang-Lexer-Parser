#include "StdAfx.h"
#include <boost/test/unit_test.hpp>
#include "TestUtil.h"
#include <ErlangTokens.h>

BOOST_AUTO_TEST_SUITE( SeparatorTests )

using namespace TestUtil;
using namespace std;

BOOST_AUTO_TEST_CASE( SeparatorTest )
{
    pair<unsigned int, const wchar_t *> toTest[] = { make_pair(ERLANGTOKEN_LEFTPAREN, L"("), 
                                                     make_pair(ERLANGTOKEN_RIGHTPAREN, L")"), 
                                                     make_pair(ERLANGTOKEN_LEFTBRACKET, L"["), 
                                                     make_pair(ERLANGTOKEN_RIGHTBRACKET, L"]"),
                                                     make_pair(ERLANGTOKEN_LEFTCURLYBRACKET, L"{"),
                                                     make_pair(ERLANGTOKEN_RIGHTCURLYBRACKET, L"}"),
                                                     make_pair(ERLANGTOKEN_FORWARDSLASH, L"/"), 
                                                     make_pair(ERLANGTOKEN_TYPESEPARATOR, L"::"),
                                                     make_pair(ERLANGTOKEN_COLON, L":"),
                                                     make_pair(ERLANGTOKEN_SEMICOLON, L";"), 
                                                     make_pair(ERLANGTOKEN_COMMA, L","), 
                                                     make_pair(ERLANGTOKEN_RULESEPARATOR, L":-"),
                                                     make_pair(ERLANGTOKEN_ARROW, L"->"), 
                                                     make_pair(ERLANGTOKEN_DOTTERMINATOR, L".\t"),
                                                     make_pair(ERLANGTOKEN_DOTTERMINATOR, L". "),
                                                     make_pair(ERLANGTOKEN_DOTTERMINATOR, L".\r"),
                                                     make_pair(ERLANGTOKEN_BAR, L"|"), 
                                                     make_pair(ERLANGTOKEN_DOUBLEBAR, L"||"), 
                                                     make_pair(ERLANGTOKEN_HASH, L"#"),
                                                     make_pair(ERLANGTOKEN_BITSTRINGHEAD, L"<<"), 
                                                     make_pair(ERLANGTOKEN_BITSTRINGTAIL, L">>") };

    VerifyPairs(&toTest[0], toTest + _countof(toTest));
}

BOOST_AUTO_TEST_SUITE_END()