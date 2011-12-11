#pragma once
#include <ErlangLexer.h>
#include <string>
#include <algorithm>
#include <utility>

namespace TestUtil
{
    using std::vector;
    using std::pair;
    using std::wstring;
    using std::make_pair;
    using std::for_each;

    typedef vector<pair<unsigned int, wstring>> TokenVector;

    struct TokenProcessor
    {
        TokenProcessor(TokenVector& tokens) : m_tokens(tokens) 
        {}

        template <typename Token>
        bool operator()(const Token& t)
        {
            m_tokens.push_back(make_pair(t.id(), wstring(t.value().begin(), t.value().end())));

            return true;
        }    

    private:
        TokenVector& m_tokens;
    };

    void PopulateASCIICharacterCodes(vector<wstring>& toPopulate, const pair<int,int>& characterCodeRange, wstring prefix = wstring());
    void VerifyLex(const wstring& refToLex, const TokenVector& expectedTokens, bool shouldSucceed = true);
    void VerifyEscapedControlCodes(unsigned int expectedToken, wstring codeStringPrefix, wstring codeStringSuffix);
    void VerifyEscapedOctalDigits(unsigned int expectedToken, wstring octalDigitStringPrefix, wstring octalDigitStringSuffix);

    void DumpLexedTokens(const wstring& refToLex, std::function<void(const std::pair<unsigned int, wstring>&)> callback);
    std::wstring ReadFileIntoString(const char *pFilePath);
    std::wstring EscapeQuotes(const std::wstring& refToEscape);
    std::wstring EscapeNewLines(const std::wstring& refToEscape);
    std::wstring MapIntToEnumName(unsigned int tokenId);
    std::wstring CreatePairInitializerListFromString(const std::wstring& refIn);

    template<typename Iter>
    void VerifyPairs(Iter start, Iter end)
    {
        for_each(start, end,
                 [](const pair<unsigned int, const wchar_t*>& refPair) -> void 
                 {
                     wstring toLex = wstring(refPair.second);
                  
                     TokenVector expectedTokens;
                     expectedTokens.push_back(make_pair(refPair.first, toLex));
                  
                     VerifyLex(toLex, expectedTokens);
                 });
    }
}