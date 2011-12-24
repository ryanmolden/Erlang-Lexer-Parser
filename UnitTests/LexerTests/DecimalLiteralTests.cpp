#include "StdAfx.h"
#include <boost/test/unit_test.hpp>
#include "TestUtil.h"
#include <ErlangTokens.h>

BOOST_AUTO_TEST_SUITE( DecimalLiteralTests )

using namespace TestUtil;
using namespace std;

BOOST_AUTO_TEST_CASE( SingleDigitDecimalLiteralTest )
{
    vector<wstring> asciiDigits;
    PopulateASCIICharacterCodes(asciiDigits, make_pair(static_cast<int>(L'0'), static_cast<int>(L'9')+1));

    vector<pair<unsigned int, const wchar_t*>> pairs;
    transform(asciiDigits.begin(), asciiDigits.end(), back_inserter(pairs),
              [](const wstring& refItem) { return make_pair(ERLANGTOKEN_DECIMALLITERAL, refItem.c_str()); });

    VerifyPairs(pairs.begin(), pairs.end());
}

BOOST_AUTO_TEST_CASE( MultiDigitDecimalLiteralTest )
{
    //Erlang supports arbitrarily large integers...so we can't really test all possible ranges, though our 
    //regex is just [0-9]+ so just ensuring we can handle 2 digits decimals should ensure we can handle 
    //arbitrarily large ones as well.

    wstring toLex(L"42");
    TokenVector expectedTokens;
    expectedTokens.push_back(make_pair(ERLANGTOKEN_DECIMALLITERAL, toLex));

    VerifyLex(toLex, expectedTokens);
}

BOOST_AUTO_TEST_SUITE_END()