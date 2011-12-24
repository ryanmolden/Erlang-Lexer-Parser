#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

namespace TestUtil
{
    typedef std::vector<std::pair<unsigned int, std::wstring>> TokenVector;

    void PopulateASCIICharacterCodes(std::vector<std::wstring>& toPopulate, const std::pair<int,int>& characterCodeRange, std::wstring prefix = std::wstring());
    void VerifyLex(const std::wstring& refToLex, const TokenVector& expectedTokens, bool shouldSucceed = true);
    void VerifyEscapedControlCodes(unsigned int expectedToken, std::wstring codeStringPrefix, std::wstring codeStringSuffix);
    void VerifyEscapedOctalDigits(unsigned int expectedToken, std::wstring octalDigitStringPrefix, std::wstring octalDigitStringSuffix);

    void DumpLexedTokens(const std::wstring& refToLex, std::function<void(const std::pair<unsigned int, std::wstring>&)> callback);
    std::wstring ReadFileIntoString(const char *pFilePath);
    std::wstring EscapeQuotes(const std::wstring& refToEscape);
    std::wstring EscapeNewLines(const std::wstring& refToEscape);
    std::wstring MapIntToEnumName(unsigned int tokenId);
    std::wstring CreatePairInitializerListFromString(const std::wstring& refIn);

    template<typename Iter>
    void VerifyPairs(Iter start, Iter end)
    {
        std::for_each(start, end,
                      [](const std::pair<unsigned int, const wchar_t*>& refPair) -> void 
                      {
                          std::wstring toLex = std::wstring(refPair.second);
                       
                          TokenVector expectedTokens;
                          expectedTokens.push_back(make_pair(refPair.first, toLex));
                       
                          VerifyLex(toLex, expectedTokens);
                      });
    }
}