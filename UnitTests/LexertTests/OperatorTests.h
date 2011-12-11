#pragma once
#include <boost/test/unit_test.hpp>
#include "TestUtil.h"
#include <ErlangTokens.h>
#include <utility>

BOOST_AUTO_TEST_SUITE( OperatorTests )

using namespace TestUtil;
using std::make_pair;
using std::pair;

BOOST_AUTO_TEST_CASE( OperatorsTest )
{
    pair<unsigned int, const wchar_t *> toTest[] = { make_pair(OPPLUS, L"+"), make_pair(OPMINUS, L"-"), 
                                                     make_pair(OPMULT, L"*"), make_pair(OPINTDIV, L"div"),
                                                     make_pair(OPREM, L"rem"), make_pair(OPOR, L"or"),
                                                     make_pair(OPXOR, L"xor"), make_pair(OPBOR, L"bor"),
                                                     make_pair(OPBXOR, L"bxor"), make_pair(OPBSL, L"bsl"),
                                                     make_pair(OPBSR, L"bsr"), make_pair(OPAND, L"and"),
                                                     make_pair(OPBAND, L"band"), make_pair(OPEQUALTO, L"=="),
                                                     make_pair(OPNOTEQUALTO, L"/="), make_pair(OPIDENTICALTO, L"=:="),
                                                     make_pair(OPNOTIDENTICALTO, L"=/="), make_pair(OPLESSTHAN, L"<"),
                                                     make_pair(OPLESSTHANEQUAL, L"=<"), make_pair(OPGREATERTHAN, L">"),
                                                     make_pair(OPGREATERTHANEQUAL, L">="), make_pair(OPNOT, L"not"),
                                                     make_pair(OPBNOT, L"bnot"), make_pair(OPLISTCONCAT, L"++"),
                                                     make_pair(OPLISTSUBTRACT, L"--"), make_pair(OPMATCH, L"="),
                                                     make_pair(OPSEND, L"!"), make_pair(OPGENERATE, L"<-"),
                                                     make_pair(OPBITGENERATE, L"<=")};

    VerifyPairs(&toTest[0], toTest + _countof(toTest));
}

BOOST_AUTO_TEST_SUITE_END()