#pragma once
#include <boost/test/unit_test.hpp>
#include "TestUtil.h"
#include <ErlangTokens.h>
#include <utility>

BOOST_AUTO_TEST_SUITE( SeparatorTests )

using namespace TestUtil;
using std::pair;
using std::make_pair;

BOOST_AUTO_TEST_CASE( SeparatorTest )
{
    pair<unsigned int, const wchar_t *> toTest[] = { make_pair(LEFTPAREN, L"("), make_pair(RIGHTPAREN, L")"), 
                                                     make_pair(LEFTBRACKET, L"["), make_pair(RIGHTBRACKET, L"]"),
                                                     make_pair(LEFTCURLYBRACKET, L"{"), make_pair(RIGHTCURLYBRACKET, L"}"),
                                                     make_pair(FORWARDSLASH, L"/"), make_pair(TYPESEPARATOR, L"::"),
                                                     make_pair(COLON, L":"), make_pair(SEMICOLON, L";"), 
                                                     make_pair(COMMA, L","), make_pair(RULETHINGY, L":-"),
                                                     make_pair(ARROW, L"->"), make_pair(TERMINATOR, L"."), 
                                                     make_pair(BAR, L"|"), make_pair(DOUBLEBAR, L"||"), 
                                                     make_pair(HASH, L"#"), make_pair(BITSTRINGHEAD, L"<<"), 
                                                     make_pair(BITSTRINGTAIL, L">>") };

    VerifyPairs(&toTest[0], toTest + _countof(toTest));
}

BOOST_AUTO_TEST_SUITE_END()