#pragma once

#include <boost/spirit/include/qi.hpp>
#include <string>
#include "Terminals.h"
#include "Expression.h"

namespace qi = boost::spirit::qi;

template <typename Iterator, typename Lexer, typename SkipperType>
struct ErlangRule : qi::grammar<Iterator, std::wstring(), SkipperType>
{
    ErlangRule(const Lexer& lexer, 
               const ErlangTerminals<Iterator, Lexer, SkipperType>& terminals,
               const ErlangExpression<Iterator, Lexer, SkipperType>& expression);

private:
    const Lexer& m_lexer;
    const ErlangTerminals<Iterator, Lexer, SkipperType>& m_terminals;
    const ErlangExpression<Iterator, Lexer, SkipperType>& m_expression;

    qi::rule<Iterator, std::wstring(), SkipperType> m_ruleClause;
    qi::rule<Iterator, std::wstring(), SkipperType> m_ruleClauses;
    qi::rule<Iterator, std::wstring(), SkipperType> m_ruleBody;
};