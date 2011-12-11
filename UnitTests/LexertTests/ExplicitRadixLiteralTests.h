#pragma once
#include <boost/test/unit_test.hpp>
#include "TestUtil.h"
#include <ErlangTokens.h>
#include <string>
#include <utility>

BOOST_AUTO_TEST_SUITE( ExplicitRadixLiteralTests )

using namespace TestUtil;
using std::string;
using std::pair;
using std::make_pair;
using std::transform;
using std::for_each;

namespace
{
    void TestBaseX(int radix)
    {
        wchar_t digits[] = {L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9'};
        wchar_t upperCaseCharDigits[] = {L'A', L'B', L'C', L'D', L'E', L'F'};
        wchar_t lowerCaseCharDigits[] = {L'a', L'b', L'c', L'd', L'e', L'f'};

        wchar_t buffer[5] = {0};
        _itow_s(radix, buffer, 10);

        const int radixLength = static_cast<int>(std::log10(static_cast<double>(radix)) + 1);
        buffer[radixLength] = L'#';

        for(int i = 0 ; i < radix ; ++i)
        {
            TokenVector expectedTokens;
            if(i > 9)
            {
                int adjustedIndex = i % 10;

                buffer[radixLength+1] = upperCaseCharDigits[adjustedIndex];
                buffer[radixLength+2] = L'\0';
                expectedTokens.push_back(make_pair(EXPLICITRADIXLITERAL, wstring(buffer)));

                VerifyLex(wstring(buffer), expectedTokens);

                expectedTokens.clear();

                buffer[radixLength+1] = lowerCaseCharDigits[adjustedIndex];
                expectedTokens.push_back(make_pair(EXPLICITRADIXLITERAL, wstring(buffer)));

                VerifyLex(wstring(buffer), expectedTokens);
            }
            else
            {
                buffer[radixLength+1] = digits[i];
                buffer[radixLength+2] = L'\0';
                expectedTokens.push_back(make_pair(EXPLICITRADIXLITERAL, wstring(buffer)));

                VerifyLex(wstring(buffer), expectedTokens);
            }
        }
    }
}

BOOST_AUTO_TEST_CASE( Base2ExplicitRadixLiteralTest )
{
    TestBaseX(2);
}

BOOST_AUTO_TEST_CASE( Base3ExplicitRadixLiteralTest )
{
    TestBaseX(3);
}

BOOST_AUTO_TEST_CASE( Base4ExplicitRadixLiteralTest )
{
    TestBaseX(4);
}

BOOST_AUTO_TEST_CASE( Base5ExplicitRadixLiteralTest )
{
    TestBaseX(5);
}

BOOST_AUTO_TEST_CASE( Base6ExplicitRadixLiteralTest )
{
    TestBaseX(6);
}

BOOST_AUTO_TEST_CASE( Base7ExplicitRadixLiteralTest )
{
    TestBaseX(7);
}

BOOST_AUTO_TEST_CASE( Base8ExplicitRadixLiteralTest )
{
    TestBaseX(8);
}

BOOST_AUTO_TEST_CASE( Base9ExplicitRadixLiteralTest )
{
    TestBaseX(9);
}

BOOST_AUTO_TEST_CASE( Base10ExplicitRadixLiteralTest )
{
    TestBaseX(10);
}

BOOST_AUTO_TEST_CASE( Base11ExplicitRadixLiteralTest )
{
    TestBaseX(11);
}

BOOST_AUTO_TEST_CASE( Base12ExplicitRadixLiteralTest )
{
    TestBaseX(12);
}

BOOST_AUTO_TEST_CASE( Base13ExplicitRadixLiteralTest )
{
    TestBaseX(13);
}

BOOST_AUTO_TEST_CASE( Base14ExplicitRadixLiteralTest )
{
    TestBaseX(14);
}

BOOST_AUTO_TEST_CASE( Base15ExplicitRadixLiteralTest )
{
    TestBaseX(15);
}

BOOST_AUTO_TEST_CASE( Base16ExplicitRadixLiteralTest )
{
    TestBaseX(16);
}

BOOST_AUTO_TEST_SUITE_END()