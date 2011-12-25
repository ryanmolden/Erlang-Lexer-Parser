#include "stdafx.h"
#include <fstream>
#include <regex>
#include <boost/test/unit_test.hpp>

namespace
{
    typedef lex::lexertl::token<const wchar_t*> TokenType;
    typedef lex::lexertl::actor_lexer<TokenType> BaseLexerType;
    typedef ErlangLexer<BaseLexerType> LexerType;
    typedef LexerType::iterator_type LexerIteratorType;
    typedef ErlangParser<LexerIteratorType, LexerType> ParserType;

    //TODO:  Pass these into test cases instead of having these globals, but this speeds up runtime MASSIVELY over constantly 
    //reconstructing them.
    LexerType g_lexer;

    ParserType g_parser(g_lexer);

    ParserType::CommentSkipperType g_skipper(g_lexer.comment);
}

namespace TestUtil
{
    using namespace std;

    void PopulateASCIICharacterCodes(vector<wstring>& toPopulate, const pair<int,int>& characterCodeRange, wstring prefix /* = string()*/) 
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

        auto cur = g_lexer.begin(first, last);
        auto end = g_lexer.end();

        for( ; cur != end && cur->is_valid() ; ++cur)
        {
            callback(make_pair(cur->id(), wstring(cur->value().begin(), cur->value().end())));
        }
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
        const wchar_t *enumNameArr[] = { L"ERLANGTOKEN_LEFTPAREN", L"ERLANGTOKEN_RIGHTPAREN", L"ERLANGTOKEN_COMMA", L"ERLANGTOKEN_ARROW", L"ERLANGTOKEN_RULESEPARATOR", 
                                         L"ERLANGTOKEN_LEFTCURLYBRACKET", L"ERLANGTOKEN_RIGHTCURLYBRACKET", L"ERLANGTOKEN_LEFTBRACKET", L"ERLANGTOKEN_RIGHTBRACKET",
                                         L"ERLANGTOKEN_BITSTRINGHEAD", L"ERLANGTOKEN_BITSTRINGTAIL", L"ERLANGTOKEN_BAR", L"ERLANGTOKEN_DOUBLEBAR", L"ERLANGTOKEN_SEMICOLON", L"ERLANGTOKEN_COLON", 
                                         L"ERLANGTOKEN_FORWARDSLASH", L"ERLANGTOKEN_HASH", L"ERLANGTOKEN_TYPESEPARATOR", L"ERLANGTOKEN_TYPEVALUERANGE", L"ERLANGTOKEN_UNSPECIFIEDTYPE", 
                                         L"ERLANGTOKEN_DOT", L"ERLANGTOKEN_DOTTERMINATOR",

                                         L"ERLANGTOKEN_AFTER", L"ERLANGTOKEN_BEGIN", L"ERLANGTOKEN_CASE", L"ERLANGTOKEN_TRY", L"ERLANGTOKEN_CATCH", L"ERLANGTOKEN_END", 
                                         L"ERLANGTOKEN_FUN", L"ERLANGTOKEN_IF", L"ERLANGTOKEN_OF", L"ERLANGTOKEN_RECEIVE", L"ERLANGTOKEN_WHEN", L"ERLANGTOKEN_ANDALSO", 
                                         L"ERLANGTOKEN_ORELSE", L"ERLANGTOKEN_QUERY", L"ERLANGTOKEN_SPEC", L"ERLANGTOKEN_CALLBACK", 

                                         L"ERLANGTOKEN_OPBNOT", L"ERLANGTOKEN_OPNOT", L"ERLANGTOKEN_OPMULT", L"ERLANGTOKEN_OPINTDIV", L"ERLANGTOKEN_OPREM", 
                                         L"ERLANGTOKEN_OPBAND", L"ERLANGTOKEN_OPAND", L"ERLANGTOKEN_OPLISTCONCAT", L"ERLANGTOKEN_OPLISTSUBTRACT", 
                                         L"ERLANGTOKEN_OPPLUS", L"ERLANGTOKEN_OPMINUS", L"ERLANGTOKEN_OPBOR", L"ERLANGTOKEN_OPBXOR", L"ERLANGTOKEN_OPBSL", 
                                         L"ERLANGTOKEN_OPBSR", L"ERLANGTOKEN_OPOR", L"ERLANGTOKEN_OPXOR", L"ERLANGTOKEN_OPEQUALTO", L"ERLANGTOKEN_OPNOTEQUALTO", 
                                         L"ERLANGTOKEN_OPLESSTHANEQUAL", L"ERLANGTOKEN_OPLESSTHAN", L"ERLANGTOKEN_OPGREATERTHANEQUAL", L"ERLANGTOKEN_OPGREATERTHAN", 
                                         L"ERLANGTOKEN_OPIDENTICALTO", L"ERLANGTOKEN_OPNOTIDENTICALTO", 
                                         L"ERLANGTOKEN_OPGENERATE", L"ERLANGTOKEN_OPBITGENERATE", L"ERLANGTOKEN_OPSEND", L"ERLANGTOKEN_OPMATCH", 

                                         L"ERLANGTOKEN_UNIVERSALPATTERN", L"ERLANGTOKEN_ATOM", L"ERLANGTOKEN_COMMENT", L"ERLANGTOKEN_VARIABLE", 

                                         L"ERLANGTOKEN_CHARACTERLITERAL", L"ERLANGTOKEN_DECIMALLITERAL", L"ERLANGTOKEN_EXPLICITRADIXLITERAL", L"ERLANGTOKEN_FLOATLITERAL", L"ERLANGTOKEN_STRINGLITERAL",

                                         L"ERLANGTOKEN_SPECATTRIBUTEHEAD", L"ERLANGTOKEN_CALLBACKATTRIBUTEHEAD", L"ERLANGTOKEN_GENERICATTRIBUTEHEAD" };

        return enumNameArr[tokenId - ERLANGTOKEN_LEFTPAREN];
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
        auto cur = g_lexer.begin(first, last);
        auto end = g_lexer.end();

        for(; cur != end && cur->is_valid() ; ++cur)
        {
            try
            {
                actualTokens.push_back(make_pair(cur->id(), wstring(cur->value().begin(), cur->value().end())));
            }
            catch(const std::bad_alloc&)
            {
                break;
            }
        }

        const bool lexingSucceeded = (cur == end);

        const bool lexResultAsExpected = lexingSucceeded == shouldSucceed;

        //Kind of goofy to have to do it this way but the unit test stuff is not set up to output wstrings :(
        if(!lexResultAsExpected)
        {
            wcout << endl << L"Lexing was expected to " << (shouldSucceed ? L"pass" : L"fail") << L"but it " << (shouldSucceed ? L"failed" : L"passed") << L" with input '" << refToLex << L"'" << endl;
        }
        BOOST_CHECK( lexResultAsExpected );

        if(shouldSucceed)
        {            
            const bool sizeMatches = actualTokens.size() == expectedTokens.size();
            if(!sizeMatches)
            {
                wcout << endl << L"Expected lexing to result in " << expectedTokens.size() << L" but it actually resulted in " << actualTokens.size() << L" tokens." << endl;
            }
            BOOST_CHECK( sizeMatches );

            //avoid annoying signed/unsigned mismatch or relying on the fact that ::size_type is == size_t
            typedef decltype(actualTokens.size()) IndexType;

            for(IndexType i = 0 ; i < actualTokens.size() ; ++i)
            {
                auto actual = actualTokens[i];
                auto expected = expectedTokens[i];

                const bool areEqual = (actual == expected);
                if(!areEqual)
                {
                    wcout << endl << L"Expected token '" << expected.second + L"' (" << expected.first << "), but got '" << actual.second << L"' (" << actual.first << L") at token index " << i << endl;
                }

                BOOST_CHECK( areEqual );
            }
        }
    }

    void VerifyParse(const std::wstring& refToParse, const std::vector<wstring>& expectedResults)
    {
        const wchar_t *pStart = refToParse.c_str();
        const wchar_t *pEnd = pStart + refToParse.size();

        vector<wstring> actualResults;
        bool parseSucceeded = lex::tokenize_and_phrase_parse(pStart, pEnd, g_lexer, g_parser, g_skipper, actualResults);
        if(!parseSucceeded)
        {
            wcout << L"Parsing failed with '" << refToParse << L"'." << endl;
        }
        BOOST_CHECK( parseSucceeded );

        const bool resultCountMatchesExpectedCount = (expectedResults.size() == actualResults.size());
        if(!resultCountMatchesExpectedCount)
        {
            wcout << L"Different number of results than expected." << endl << endl << L"Expected:" << endl;
            copy(expectedResults.begin(), expectedResults.end(), ostream_iterator<wstring, wchar_t>(wcout, L"\n"));

            wcout << endl << endl << L"Actual:" << endl;
            copy(actualResults.begin(), actualResults.end(), ostream_iterator<wstring, wchar_t>(wcout, L"\n"));
        }
        BOOST_CHECK( resultCountMatchesExpectedCount );

        //avoid annoying signed/unsigned mismatch or relying on the fact that ::size_type is == size_t
        typedef decltype(actualResults.size()) IndexType;

        for(IndexType i = 0 ; i < actualResults.size() ; ++i)
        {
            const wstring& actual = actualResults[i];
            const wstring& expected = expectedResults[i];

            const bool areEqual = (actual == expected);
            if(!areEqual)
            {
                wcout << L"Expected '" << expected << L"', but got '" << actual << L"'." << endl;
            }
            BOOST_CHECK( areEqual );
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