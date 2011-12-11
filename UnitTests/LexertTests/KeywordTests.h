#pragma once
#include <boost/test/unit_test.hpp>
#include "TestUtil.h"
#include <ErlangTokens.h>
#include <utility>

BOOST_AUTO_TEST_SUITE( KeywordTests )

using namespace TestUtil;
using std::pair;
using std::make_pair;

BOOST_AUTO_TEST_CASE( KeywordsTest )
{
    pair<unsigned int, const wchar_t *> toTest[] = { make_pair(AFTER, L"after"), make_pair(BEGIN, L"begin"), 
                                                     make_pair(CASE, L"case"), make_pair(TRY, L"try"),
                                                     make_pair(CATCH, L"catch"), make_pair(END, L"end"),
                                                     make_pair(FUN, L"fun"), make_pair(IF, L"if"), make_pair(OF, L"of"), 
                                                     make_pair(RECEIVE, L"receive"), make_pair(WHEN, L"when"),
                                                     make_pair(ANDALSO, L"andalso"), make_pair(ORELSE, L"orelse"),
                                                     make_pair(QUERY, L"query"), make_pair(SPEC, L"spec"),
                                                     make_pair(CALLBACK, L"callback")};
    
    VerifyPairs(&toTest[0], toTest + _countof(toTest));
}

BOOST_AUTO_TEST_SUITE_END()