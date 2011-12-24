#include "StdAfx.h"
#include <boost/test/unit_test.hpp>
#include "TestUtil.h"
#include <ErlangTokens.h>

BOOST_AUTO_TEST_SUITE( KeywordTests )

using namespace TestUtil;
using namespace std;

BOOST_AUTO_TEST_CASE( KeywordsTest )
{
    pair<unsigned int, const wchar_t *> toTest[] = { make_pair(ERLANGTOKEN_AFTER, L"after"),
                                                     make_pair(ERLANGTOKEN_BEGIN, L"begin"), 
                                                     make_pair(ERLANGTOKEN_CASE, L"case"), 
                                                     make_pair(ERLANGTOKEN_TRY, L"try"),
                                                     make_pair(ERLANGTOKEN_CATCH, L"catch"), 
                                                     make_pair(ERLANGTOKEN_END, L"end"),
                                                     make_pair(ERLANGTOKEN_FUN, L"fun"), 
                                                     make_pair(ERLANGTOKEN_IF, L"if"), 
                                                     make_pair(ERLANGTOKEN_OF, L"of"), 
                                                     make_pair(ERLANGTOKEN_RECEIVE, L"receive"), 
                                                     make_pair(ERLANGTOKEN_WHEN, L"when"),
                                                     make_pair(ERLANGTOKEN_ANDALSO, L"andalso"), 
                                                     make_pair(ERLANGTOKEN_ORELSE, L"orelse"),
                                                     make_pair(ERLANGTOKEN_QUERY, L"query") };
    
    VerifyPairs(&toTest[0], toTest + _countof(toTest));
}

BOOST_AUTO_TEST_SUITE_END()