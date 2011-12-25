#include "StdAfx.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( OperatorTests )

using namespace TestUtil;
using namespace std;

BOOST_AUTO_TEST_CASE( OperatorsTest )
{
    pair<unsigned int, const wchar_t *> toTest[] = { make_pair(ERLANGTOKEN_OPPLUS, L"+"), 
                                                     make_pair(ERLANGTOKEN_OPMINUS, L"-"), 
                                                     make_pair(ERLANGTOKEN_OPMULT, L"*"),
                                                     make_pair(ERLANGTOKEN_OPINTDIV, L"div"),
                                                     make_pair(ERLANGTOKEN_OPREM, L"rem"),
                                                     make_pair(ERLANGTOKEN_OPOR, L"or"),
                                                     make_pair(ERLANGTOKEN_OPXOR, L"xor"), 
                                                     make_pair(ERLANGTOKEN_OPBOR, L"bor"),
                                                     make_pair(ERLANGTOKEN_OPBXOR, L"bxor"), 
                                                     make_pair(ERLANGTOKEN_OPBSL, L"bsl"),
                                                     make_pair(ERLANGTOKEN_OPBSR, L"bsr"), 
                                                     make_pair(ERLANGTOKEN_OPAND, L"and"),
                                                     make_pair(ERLANGTOKEN_OPBAND, L"band"),
                                                     make_pair(ERLANGTOKEN_OPEQUALTO, L"=="),
                                                     make_pair(ERLANGTOKEN_OPNOTEQUALTO, L"/="), 
                                                     make_pair(ERLANGTOKEN_OPIDENTICALTO, L"=:="),
                                                     make_pair(ERLANGTOKEN_OPNOTIDENTICALTO, L"=/="), 
                                                     make_pair(ERLANGTOKEN_OPLESSTHAN, L"<"),
                                                     make_pair(ERLANGTOKEN_OPLESSTHANEQUAL, L"=<"), 
                                                     make_pair(ERLANGTOKEN_OPGREATERTHAN, L">"),
                                                     make_pair(ERLANGTOKEN_OPGREATERTHANEQUAL, L">="), 
                                                     make_pair(ERLANGTOKEN_OPNOT, L"not"),
                                                     make_pair(ERLANGTOKEN_OPBNOT, L"bnot"), 
                                                     make_pair(ERLANGTOKEN_OPLISTCONCAT, L"++"),
                                                     make_pair(ERLANGTOKEN_OPLISTSUBTRACT, L"--"), 
                                                     make_pair(ERLANGTOKEN_OPMATCH, L"="),
                                                     make_pair(ERLANGTOKEN_OPSEND, L"!"), 
                                                     make_pair(ERLANGTOKEN_OPGENERATE, L"<-"),
                                                     make_pair(ERLANGTOKEN_OPBITGENERATE, L"<=")};

    VerifyPairs(&toTest[0], toTest + _countof(toTest));
}

BOOST_AUTO_TEST_SUITE_END()