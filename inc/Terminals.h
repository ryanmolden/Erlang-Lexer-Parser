#ifndef TERMINALS_21DD23C1
#define TERMINALS_21DD23C1

#include <boost/spirit/include/qi.hpp>
#include <string>

namespace qi = boost::spirit::qi;

template <typename Iterator, typename Lexer, typename SkipperType>
struct ErlangTerminals
{
    ErlangTerminals(Lexer const& l);

    qi::rule<Iterator, std::wstring(), SkipperType> PrefixOperator;
    qi::rule<Iterator, std::wstring(), SkipperType> ComparisonOperator;
    qi::rule<Iterator, std::wstring(), SkipperType> ListOperator;
    qi::rule<Iterator, std::wstring(), SkipperType> AddOperator;
    qi::rule<Iterator, std::wstring(), SkipperType> MultOperator;
    qi::rule<Iterator, std::wstring(), SkipperType> AtomOrVariable;
    qi::rule<Iterator, std::wstring(), SkipperType> Integer;
    qi::rule<Iterator, std::wstring(), SkipperType> IntegerOrVariable;

private:
    const Lexer& m_lexer;
};

#endif