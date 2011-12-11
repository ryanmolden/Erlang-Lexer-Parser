#pragma once
#include <boost/test/unit_test.hpp>
#include "TestUtil.h"
#include <ErlangTokens.h>
#include <string>
#include <utility>
#include <iterator>

BOOST_AUTO_TEST_SUITE( VariableTests )

using namespace TestUtil;
using std::wstring;
using std::pair;
using std::make_pair;
using std::transform;
using std::back_inserter;

BOOST_AUTO_TEST_CASE( LeadingUnderscoreVariablesTest )
{
    vector<wstring> variables;

    //0-9
    PopulateASCIICharacterCodes(variables, make_pair(static_cast<int>(L'0'), static_cast<int>(L'9') + 1), wstring(L"_"));

    //A-Z
    PopulateASCIICharacterCodes(variables, make_pair(static_cast<int>(L'A'), static_cast<int>(L'Z') + 1), wstring(L"_"));

    //a-z
    PopulateASCIICharacterCodes(variables, make_pair(static_cast<int>(L'a'), static_cast<int>(L'z') + 1), wstring(L"_"));

    variables.push_back(wstring(L"__"));
    variables.push_back(wstring(L"_@"));

    vector<pair<unsigned int, const wchar_t *>> pairs;
    transform(variables.begin(), variables.end(), back_inserter(pairs),
              [](const wstring& refItem) { return make_pair(VARIABLE, refItem.c_str()); });

    VerifyPairs(pairs.begin(), pairs.end());
}

BOOST_AUTO_TEST_CASE( LeadingUppercaseSingleCharacterVariablesTest )
{
    vector<wstring> variables;
    for(int i = 65 ; i < 91 ; ++i)
    {
        wstring str;
        str += static_cast<wchar_t>(i);

        variables.push_back(str);
    }

    vector<pair<unsigned int, const wchar_t*>> pairs;
    transform(variables.begin(), variables.end(), back_inserter(pairs),
              [](const wstring& refItem) { return make_pair(VARIABLE, refItem.c_str()); });

    VerifyPairs(pairs.begin(), pairs.end());
}

BOOST_AUTO_TEST_CASE( LeadingUppercaseMultiCharacterVariablesTest )
{
    vector<wstring> variables;

    //0-9
    PopulateASCIICharacterCodes(variables, make_pair(static_cast<int>(L'0'), static_cast<int>(L'9') + 1), wstring(L"A"));

    //A-Z
    PopulateASCIICharacterCodes(variables, make_pair(static_cast<int>(L'A'), static_cast<int>(L'Z') + 1), wstring(L"A"));

    //a-z
    PopulateASCIICharacterCodes(variables, make_pair(static_cast<int>(L'a'), static_cast<int>(L'z') + 1), wstring(L"A"));

    variables.push_back(wstring(L"A_"));
    variables.push_back(wstring(L"A@"));

    vector<pair<unsigned int, const wchar_t *>> pairs;
    transform(variables.begin(), variables.end(), back_inserter(pairs),
              [](const wstring& refItem) { return make_pair(VARIABLE, refItem.c_str()); });

    VerifyPairs(pairs.begin(), pairs.end());
}

BOOST_AUTO_TEST_SUITE_END()