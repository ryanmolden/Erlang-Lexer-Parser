#include "StdAfx.h"
#include <boost/test/unit_test.hpp>
#include "TestUtil.h"
#include <ErlangTokens.h>

BOOST_AUTO_TEST_SUITE( AtomTests )

using namespace TestUtil;
using std::wstring;
using std::pair;
using std::make_pair;

BOOST_AUTO_TEST_CASE( TrueFalseAtomTest )
{
    TokenVector expectedTokens;
    expectedTokens.push_back(make_pair(ERLANGTOKEN_ATOM, L"true"));

    VerifyLex(expectedTokens[0].second, expectedTokens);

    expectedTokens.clear();
    expectedTokens.push_back(make_pair(ERLANGTOKEN_ATOM, L"false"));

    VerifyLex(expectedTokens[0].second, expectedTokens);
}

BOOST_AUTO_TEST_CASE( SimpleAtomsTest )
{
    TokenVector expectedTokens;
    expectedTokens.push_back(make_pair(ERLANGTOKEN_ATOM, L"x"));

    VerifyLex(expectedTokens[0].second, expectedTokens);

    expectedTokens.clear();
    expectedTokens.push_back(make_pair(ERLANGTOKEN_ATOM, L"testAtom"));

    VerifyLex(expectedTokens[0].second, expectedTokens);

    expectedTokens.clear();
    expectedTokens.push_back(make_pair(ERLANGTOKEN_ATOM, L"tEsTaToM"));

    VerifyLex(expectedTokens[0].second, expectedTokens);

    expectedTokens.clear();
    expectedTokens.push_back(make_pair(ERLANGTOKEN_ATOM, L"tESTATOM"));

    VerifyLex(expectedTokens[0].second, expectedTokens);
}

BOOST_AUTO_TEST_CASE( QuotedAtomsTest )
{
    TokenVector expectedTokens;

    //keywords can be atoms if they are quoted
    expectedTokens.push_back(make_pair(ERLANGTOKEN_ATOM, L"'case'"));

    VerifyLex(expectedTokens[0].second, expectedTokens);

    //operators can be atoms if they are quoted
    expectedTokens.clear();
    expectedTokens.push_back(make_pair(ERLANGTOKEN_ATOM, L"'and'"));

    VerifyLex(expectedTokens[0].second, expectedTokens);
}

BOOST_AUTO_TEST_CASE( OctalEscapeQuotedAtomsTest )
{
    VerifyEscapedOctalDigits(ERLANGTOKEN_ATOM, wstring(L"'"), wstring(L"'"));
}

BOOST_AUTO_TEST_CASE( EscapedControlCodesQuotedAtomTest )
{
    VerifyEscapedControlCodes(ERLANGTOKEN_ATOM, wstring(L"'"), wstring(L"'"));
}

BOOST_AUTO_TEST_SUITE_END()