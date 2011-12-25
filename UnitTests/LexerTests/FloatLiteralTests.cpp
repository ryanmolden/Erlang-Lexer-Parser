#include "StdAfx.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( FloatLiteralTests )

using namespace TestUtil;
using namespace std;

BOOST_AUTO_TEST_CASE( FloatLiteralTest )
{
    vector<wstring> asciiDigits;
    PopulateASCIICharacterCodes(asciiDigits, make_pair(static_cast<int>(L'0'), static_cast<int>(L'9') + 1));

    for_each(asciiDigits.begin(), asciiDigits.end(), [](wstring& refItem) { refItem += L".0"; });

    vector<pair<unsigned int, const wchar_t*>> pairs;
    transform(asciiDigits.begin(), asciiDigits.end(), back_inserter(pairs),
              [](const wstring& refItem) { return make_pair(ERLANGTOKEN_FLOATLITERAL, refItem.c_str()); });

    VerifyPairs(pairs.begin(), pairs.end());
}

BOOST_AUTO_TEST_CASE( FloatLiteralWithExponentTest )
{
    vector<wstring> asciiDigits;
    PopulateASCIICharacterCodes(asciiDigits, make_pair(static_cast<int>(L'0'), static_cast<int>(L'9') + 1));

    for_each(asciiDigits.begin(), asciiDigits.end(), [](wstring& refItem) { refItem += L".0E2"; });

    PopulateASCIICharacterCodes(asciiDigits, make_pair(static_cast<int>(L'0'), static_cast<int>(L'9') + 1));
    
    //Make sure we recognize both e and E as valid exponent signifiers
    auto newItemsStart = asciiDigits.begin();
    advance(newItemsStart, 10);

    for_each(newItemsStart, asciiDigits.end(), [](wstring& refItem) { refItem += L".0e2"; });

    vector<pair<unsigned int, const wchar_t*>> pairs;
    transform(asciiDigits.begin(), asciiDigits.end(), back_inserter(pairs),
              [](const wstring& refItem) { return make_pair(ERLANGTOKEN_FLOATLITERAL, refItem.c_str()); });

    VerifyPairs(pairs.begin(), pairs.end());
}

BOOST_AUTO_TEST_CASE( FloatLiteralWithSignedExponentTest )
{
    vector<wstring> asciiDigits;
    PopulateASCIICharacterCodes(asciiDigits, make_pair(static_cast<int>(L'0'), static_cast<int>(L'9') + 1));

    for_each(asciiDigits.begin(), asciiDigits.end(), [](wstring& refItem) { refItem += L".0E+2"; });

    PopulateASCIICharacterCodes(asciiDigits, make_pair(static_cast<int>(L'0'), static_cast<int>(L'9') + 1));
    
    //Make sure we recognize both + and - as valid exponent signs
    auto newItemsStart = asciiDigits.begin();
    advance(newItemsStart, 10);

    for_each(newItemsStart, asciiDigits.end(), [](wstring& refItem) { refItem += L".0e-2"; });

    vector<pair<unsigned int, const wchar_t*>> pairs;
    transform(asciiDigits.begin(), asciiDigits.end(), back_inserter(pairs),
              [](const wstring& refItem) { return make_pair(ERLANGTOKEN_FLOATLITERAL, refItem.c_str()); });

    VerifyPairs(pairs.begin(), pairs.end());
}

BOOST_AUTO_TEST_SUITE_END()