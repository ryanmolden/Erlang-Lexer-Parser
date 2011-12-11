#pragma once
#include <boost/test/unit_test.hpp>
#include "TestUtil.h"
#include <ErlangTokens.h>
#include <string>
#include <utility>

BOOST_AUTO_TEST_SUITE( AtomTests )

using namespace TestUtil;
using std::wstring;
using std::pair;
using std::make_pair;

BOOST_AUTO_TEST_CASE( TrueFalseAtomTest )
{
    TokenVector expectedTokens;
    expectedTokens.push_back(make_pair(ATOM, L"true"));

    VerifyLex(expectedTokens[0].second, expectedTokens);

    expectedTokens.clear();
    expectedTokens.push_back(make_pair(ATOM, L"false"));

    VerifyLex(expectedTokens[0].second, expectedTokens);
}

BOOST_AUTO_TEST_CASE( SimpleAtomsTest )
{
    TokenVector expectedTokens;
    expectedTokens.push_back(make_pair(ATOM, L"x"));

    VerifyLex(expectedTokens[0].second, expectedTokens);

    expectedTokens.clear();
    expectedTokens.push_back(make_pair(ATOM, L"testAtom"));

    VerifyLex(expectedTokens[0].second, expectedTokens);

    expectedTokens.clear();
    expectedTokens.push_back(make_pair(ATOM, L"tEsTaToM"));

    VerifyLex(expectedTokens[0].second, expectedTokens);

    expectedTokens.clear();
    expectedTokens.push_back(make_pair(ATOM, L"tESTATOM"));

    VerifyLex(expectedTokens[0].second, expectedTokens);
}

BOOST_AUTO_TEST_CASE( QuotedAtomsTest )
{
    TokenVector expectedTokens;

    //keywords can be atoms if they are quoted
    expectedTokens.push_back(make_pair(ATOM, L"'case'"));

    VerifyLex(expectedTokens[0].second, expectedTokens);

    //operators can be atoms if they are quoted
    expectedTokens.clear();
    expectedTokens.push_back(make_pair(ATOM, L"'and'"));

    VerifyLex(expectedTokens[0].second, expectedTokens);
}

BOOST_AUTO_TEST_CASE( OctalEscapeQuotedAtomsTest )
{
    VerifyEscapedOctalDigits(ATOM, wstring(L"'"), wstring(L"'"));
}

BOOST_AUTO_TEST_CASE( EscapedControlCodesQuotedAtomTest )
{
    VerifyEscapedControlCodes(ATOM, wstring(L"'"), wstring(L"'"));
}

BOOST_AUTO_TEST_SUITE_END()