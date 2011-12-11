#include "StdAfx.h"
#include <boost/test/unit_test.hpp>
#include "TestUtil.h"
#include <fstream>
#include <regex>

namespace
{
    //TODO:  Pass this into test cases instead of having this global, but this speeds up runtime MASSIVELY over constantly reconstructing it.
    ErlangLexer<lex::lexertl::actor_lexer<lex::lexertl::token<const wchar_t*>>> g_lexer;
}

using std::pair;
using std::string;
using std::function;
using std::for_each;
using std::wregex;
using std::regex_replace;

namespace TestUtil
{
    void PopulateASCIICharacterCodes(vector<wstring>& toPopulate, const pair<int,int>& characterCodeRange, wstring prefix/* = string()*/) 
    {
        for(int i = characterCodeRange.first ; i < characterCodeRange.second ; ++i)
        {
            wstring prefixCopy = prefix;
            prefixCopy += static_cast<wchar_t>(i);

            toPopulate.push_back(prefixCopy);
        }
    }

    void DumpLexedTokens(const wstring& refToLex, function<void(const pair<unsigned int, wstring>&)> callback)
    {
        wchar_t const* first = refToLex.c_str();
        wchar_t const* last = first + refToLex.size();

        TokenVector actualTokens;
        TokenProcessor tokenProcessor(actualTokens);
        bool res = lex::tokenize(first, last, g_lexer, tokenProcessor);

        for_each(actualTokens.begin(), actualTokens.end(), callback);
    }

    wstring EscapeQuotes(const wstring& refToEscape)
    {
        return regex_replace(refToEscape, wregex(L"\""), wstring(L"\\\""));
    }

    wstring EscapeNewLines(const wstring& refToEscape)
    {
        wstring temp = regex_replace(refToEscape, wregex(L"\\n"), wstring(L"\\n"));
        return regex_replace(temp, wregex(L"\\r"), wstring(L"\\r"));
    }

    wstring MapIntToEnumName(unsigned int tokenId)
    {
        const wchar_t *enumNameArr[] = { L"LEFTPAREN", L"RIGHTPAREN", L"COMMA", L"ARROW", L"RULETHINGY", 
                                         L"LEFTCURLYBRACKET", L"RIGHTCURLYBRACKET", L"LEFTBRACKET", L"RIGHTBRACKET",
                                         L"BITSTRINGHEAD", L"BITSTRINGTAIL", L"BAR", L"DOUBLEBAR", L"SEMICOLON", L"COLON", 
                                         L"FORWARDSLASH", L"HASH", L"TYPESEPARATOR", L"TYPEVALUERANGE", L"UNSPECIFIEDTYPE", L"TERMINATOR",

                                         L"AFTER", L"BEGIN", L"CASE", L"TRY", L"CATCH", L"END", L"FUN", L"IF", L"OF", L"RECEIVE", 
                                         L"WHEN", L"ANDALSO", L"ORELSE", L"QUERY", L"SPEC", L"CALLBACK" 

                                         L"OPBNOT", L"OPNOT", L"OPMULT", L"OPINTDIV", L"OPREM", L"OPBAND", L"OPAND", L"OPPLUS", L"OPMINUS", 
                                         L"OPBOR", L"OPBXOR", L"OPBSL", L"OPBSR", L"OPOR", L"OPXOR", L"OPLISTCONCAT", L"OPLISTSUBTRACT", 
                                         L"OPEQUALTO", L"OPNOTEQUALTO", L"OPLESSTHANEQUAL", L"OPLESSTHAN", L"OPGREATERTHANEQUAL", L"OPGREATERTHAN", 
                                         L"OPIDENTICALTO", L"OPNOTIDENTICALTO", L"OPGENERATE", L"OPBITGENERATE", L"OPSEND", L"OPMATCH", 

                                         L"UNIVERSALPATTERN", L"ATOM", L"COMMENT", L"VARIABLE", 

                                         L"CHARACTERLITERAL", L"DECIMALLITERAL", L"EXPLICITRADIXLITERAL", L"FLOATLITERAL", L"STRINGLITERAL",

                                         L"FILEATTRIBUTEHEAD", L"MODULEATTRIBUTEHEAD", L"EXPORTTYPEATTRIBUTEHEAD", L"EXPORTATTRIBUTEHEAD", 
                                         L"IMPORTATTRIBUTEHEAD", L"COMPILEATTRIBUTEHEAD", L"MACRODEFINITIONHEAD", L"TYPEDEFINITIONHEAD", 
                                         L"FUNCTIONSPECHEAD", L"RECORDATTRIBUTEHEAD", L"WILDATTRIBUTEHEAD" };

        return enumNameArr[tokenId - LEFTPAREN];
    }

    wstring CreatePairInitializerListFromString(const wstring& refIn)
    {
        wstring initializerList;
        DumpLexedTokens(refIn, [&initializerList]
                               (const pair<unsigned int, wstring>& refItem) 
                               {
                                   initializerList += wstring(L"make_pair(") + MapIntToEnumName(refItem.first) + L", L\"" + EscapeNewLines(EscapeQuotes(refItem.second)) + L"\"), ";
                               });

        return initializerList;
    }

    void VerifyLex(const wstring& refToLex, const TokenVector& expectedTokens, bool shouldSucceed /*= true*/)
    {
        wchar_t const* first = refToLex.c_str();
        wchar_t const* last = first + refToLex.size();

        TokenVector actualTokens;
        TokenProcessor tokenProcessor(actualTokens);
        bool lexingSucceeded = lex::tokenize(first, last, g_lexer, tokenProcessor);
        
        BOOST_CHECK( lexingSucceeded == shouldSucceed );

        if(shouldSucceed)
        {
            BOOST_CHECK( actualTokens.size() == expectedTokens.size() );

            //avoid annoying signed/unsigned mismatch or relying on the fact that ::size_type is == size_t
            typedef decltype(actualTokens.size()) IndexType;

            for(IndexType i = 0 ; i < actualTokens.size() ; ++i)
            {
                auto actual = actualTokens[i];
                auto expected = expectedTokens[i];
                const bool res = (actual == expected);

                BOOST_CHECK( actual == expected );
            }
        }
    }

    void VerifyEscapedControlCodes(unsigned int expectedToken, wstring codeStringPrefix, wstring codeStringSuffix)
    {
        vector<wstring> controlEscapeStringLiteralItems;
        PopulateASCIICharacterCodes(controlEscapeStringLiteralItems, make_pair(64, 96), wstring(L"\\^"));

        for_each(controlEscapeStringLiteralItems.begin(), controlEscapeStringLiteralItems.end(),
                 [expectedToken, &codeStringPrefix, &codeStringSuffix]
                 (const wstring& refStringLit) -> void
                 {
                     wstring toLex = codeStringPrefix + refStringLit + codeStringSuffix;
                 
                     TokenVector expectedTokens;
                     expectedTokens.push_back(make_pair(expectedToken, toLex));
                 
                     VerifyLex(toLex, expectedTokens);
                 });
    }

    void VerifyEscapedOctalDigits(unsigned int expectedToken, wstring octalDigitStringPrefix, wstring octalDigitStringSuffix)
    {
        vector<wstring> escapedOctalItems;

        //Test we recognize the basic set of Octal digits (0-7) (we use '8' below in make_pair as the range is the standard STL style range where it is
        //up to, but not including, the 'end' position).
        PopulateASCIICharacterCodes(escapedOctalItems, make_pair(static_cast<int>(L'0'), static_cast<int>(L'8')), wstring(L"\\"));

        //Test we recognize 1, 2 and 3 digit octal strings (obvioulsy exhustive tests for all possible octal numbers from 0-777 would take forever to run
        escapedOctalItems.push_back(wstring(L"\\1"));
        escapedOctalItems.push_back(wstring(L"\\11"));
        escapedOctalItems.push_back(wstring(L"\\111"));

        for_each(escapedOctalItems.begin(), escapedOctalItems.end(),
                 [expectedToken, &octalDigitStringPrefix, &octalDigitStringSuffix]
                 (const wstring& refStringLit) -> void
                 {
                     wstring toLex = octalDigitStringPrefix + refStringLit + octalDigitStringSuffix;

                     TokenVector expectedTokens;
                     expectedTokens.push_back(make_pair(expectedToken, toLex));

                     VerifyLex(toLex, expectedTokens);
                 });
    }

    wstring ReadFileIntoString(const char *pFilePath)
    {
        std::wifstream instream(pFilePath);
        if (!instream.is_open()) {
            std::cerr << "Couldn't open file: " << pFilePath << std::endl;
            exit(-1);
        }

        instream.unsetf(std::ios::skipws);      // No white space skipping!
        return std::wstring(std::istreambuf_iterator<wchar_t>(instream.rdbuf()),
                            std::istreambuf_iterator<wchar_t>());

    }
}