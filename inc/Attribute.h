#ifndef ATTRIBUTE_21DD23C1
#define ATTRIBUTE_21DD23C1

#include <boost/spirit/include/qi.hpp>
#include <string>
#include "Terminals.h"
#include "Expression.h"

namespace qi = boost::spirit::qi;

template <typename Iterator, typename Lexer, typename SkipperType>
struct ErlangAttribute : qi::grammar<Iterator, std::wstring(), SkipperType>
{
    ErlangAttribute(const Lexer& lexer, 
                    const ErlangTerminals<Iterator, Lexer, SkipperType>& terminals,
                    const ErlangExpression<Iterator, Lexer, SkipperType>& expression);

private:
    const Lexer& m_lexer;
    const ErlangTerminals<Iterator, Lexer, SkipperType>& m_terminals;
    const ErlangExpression<Iterator, Lexer, SkipperType>& m_expression;

    qi::rule<Iterator, std::wstring(), SkipperType> m_hashAtom;

    qi::rule<Iterator, std::wstring(), SkipperType> m_specFun;
    qi::rule<Iterator, std::wstring(), SkipperType> m_typeGuard;
    qi::rule<Iterator, std::wstring(), SkipperType> m_typeGuards;
    qi::rule<Iterator, std::wstring(), SkipperType> m_typeSig;
    qi::rule<Iterator, std::wstring(), SkipperType> m_typeSigs;
    qi::rule<Iterator, std::wstring(), SkipperType> m_typeSpec;

    qi::rule<Iterator, std::wstring(), SkipperType> m_expressions;
    qi::rule<Iterator, std::wstring(), SkipperType> m_attributeValue;

    qi::rule<Iterator, std::wstring(), SkipperType> m_topTypes;
    qi::rule<Iterator, std::wstring(), SkipperType> m_topType;
    qi::rule<Iterator, std::wstring(), SkipperType> m_type100;
    qi::rule<Iterator, std::wstring(), SkipperType> m_type200;
    qi::rule<Iterator, std::wstring(), SkipperType> m_nlrType300;
    qi::rule<Iterator, std::wstring(), SkipperType> m_type300;
    qi::rule<Iterator, std::wstring(), SkipperType> m_nlrType400;
    qi::rule<Iterator, std::wstring(), SkipperType> m_type400;
    qi::rule<Iterator, std::wstring(), SkipperType> m_type500;
    qi::rule<Iterator, std::wstring(), SkipperType> m_type;
    qi::rule<Iterator, std::wstring(), SkipperType> m_binaryType;
    qi::rule<Iterator, std::wstring(), SkipperType> m_binaryBaseType;
    qi::rule<Iterator, std::wstring(), SkipperType> m_binaryUnitType;
    qi::rule<Iterator, std::wstring(), SkipperType> m_funType100;
    qi::rule<Iterator, std::wstring(), SkipperType> m_funType;
    qi::rule<Iterator, std::wstring(), SkipperType> m_fieldTypes;
    qi::rule<Iterator, std::wstring(), SkipperType> m_fieldType;

    qi::rule<Iterator, std::wstring(), SkipperType> m_typedExpressions;
    qi::rule<Iterator, std::wstring(), SkipperType> m_typedExpression;
    qi::rule<Iterator, std::wstring(), SkipperType> m_typedRecordFields;
    qi::rule<Iterator, std::wstring(), SkipperType> m_typedAttributeValue;

    qi::rule<Iterator, std::wstring(), SkipperType> m_attribute;
};

#endif