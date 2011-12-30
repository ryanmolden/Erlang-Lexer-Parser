#ifndef EXPRESSION_21DD23C1
#define EXPRESSION_21DD23C1

#include <boost/spirit/include/qi.hpp>
#include <string>
#include "Terminals.h"

namespace qi = boost::spirit::qi;

template <typename Iterator, typename Lexer, typename SkipperType>
struct ErlangExpression : qi::grammar<Iterator, std::wstring(), SkipperType>
{
    ErlangExpression(const Lexer& lexer, 
                     const ErlangTerminals<Iterator, Lexer, SkipperType> & terminals);

    //TODO:  Should these be exposed from here?  They are used in some rules that are used by other rule classes (like ErlangFunction)...maybe there 
    //is a third rule class shared between this class and the rules that need the stuff below...need to see how 'entangled' these rules are with 
    //private rules in this class.
    qi::rule<Iterator, std::wstring(), SkipperType> ArgumentList;
    qi::rule<Iterator, std::wstring(), SkipperType> ClauseGuard;
    qi::rule<Iterator, std::wstring(), SkipperType> ClauseBody;
    qi::rule<Iterator, std::wstring(), SkipperType> ListComprehensionExpressions;

private:
    const Lexer& m_lexer;
    const ErlangTerminals<Iterator, Lexer, SkipperType>& m_terminals;

    qi::rule<Iterator, std::wstring(), SkipperType> m_atomic;

    qi::rule<Iterator, std::wstring(), SkipperType> m_tail;
    qi::rule<Iterator, std::wstring(), SkipperType> m_list;

    qi::rule<Iterator, std::wstring(), SkipperType> m_bitType;
    qi::rule<Iterator, std::wstring(), SkipperType> m_bitTypeList;
    qi::rule<Iterator, std::wstring(), SkipperType> m_bitExpression;
    qi::rule<Iterator, std::wstring(), SkipperType> m_binaryElement;
    qi::rule<Iterator, std::wstring(), SkipperType> m_binaryElements;
    qi::rule<Iterator, std::wstring(), SkipperType> m_binary;

    qi::rule<Iterator, std::wstring(), SkipperType> m_listComprehensionExpression;
    qi::rule<Iterator, std::wstring(), SkipperType> m_listComprehension;

    qi::rule<Iterator, std::wstring(), SkipperType> m_binaryComprehension;   
    
    qi::rule<Iterator, std::wstring(), SkipperType> m_tuple;

    qi::rule<Iterator, std::wstring(), SkipperType> m_guard;

    qi::rule<Iterator, std::wstring(), SkipperType> m_ifClause;
    qi::rule<Iterator, std::wstring(), SkipperType> m_ifClauses;
    qi::rule<Iterator, std::wstring(), SkipperType> m_ifExpression;

    qi::rule<Iterator, std::wstring(), SkipperType> m_caseExpression;
    qi::rule<Iterator, std::wstring(), SkipperType> m_crClause;
    qi::rule<Iterator, std::wstring(), SkipperType> m_crClauses;
    
    qi::rule<Iterator, std::wstring(), SkipperType> m_receiveExpression;

    qi::rule<Iterator, std::wstring(), SkipperType> m_tryCatch;
    qi::rule<Iterator, std::wstring(), SkipperType> m_tryClauses;
    qi::rule<Iterator, std::wstring(), SkipperType> m_tryClause;
    qi::rule<Iterator, std::wstring(), SkipperType> m_tryExpression;

    qi::rule<Iterator, std::wstring(), SkipperType> m_funClause;
    qi::rule<Iterator, std::wstring(), SkipperType> m_funClauses;
    qi::rule<Iterator, std::wstring(), SkipperType> m_funExpression;

    qi::rule<Iterator, std::wstring(), SkipperType> m_queryExpression;

    qi::rule<Iterator, std::wstring(), SkipperType> m_functionCall;
    
    qi::rule<Iterator, std::wstring(), SkipperType> m_recordTuple;
    qi::rule<Iterator, std::wstring(), SkipperType> m_recordField;
    qi::rule<Iterator, std::wstring(), SkipperType> m_recordFields;
    
    qi::rule<Iterator, std::wstring(), SkipperType> m_nlrRecordExpression;
    qi::rule<Iterator, std::wstring(), SkipperType> m_recordExpression;

    qi::rule<Iterator, std::wstring(), SkipperType> m_expression100;
    qi::rule<Iterator, std::wstring(), SkipperType> m_expression150;
    qi::rule<Iterator, std::wstring(), SkipperType> m_expression160;
    qi::rule<Iterator, std::wstring(), SkipperType> m_expression200;
    qi::rule<Iterator, std::wstring(), SkipperType> m_expression300;
    qi::rule<Iterator, std::wstring(), SkipperType> m_nlrExpression400;
    qi::rule<Iterator, std::wstring(), SkipperType> m_expression400;
    qi::rule<Iterator, std::wstring(), SkipperType> m_nlrExpression500;
    qi::rule<Iterator, std::wstring(), SkipperType> m_expression500;
    qi::rule<Iterator, std::wstring(), SkipperType> m_expression600;
    qi::rule<Iterator, std::wstring(), SkipperType> m_expression700;
    qi::rule<Iterator, std::wstring(), SkipperType> m_expression800;
    qi::rule<Iterator, std::wstring(), SkipperType> m_nlrExpression900;    
    qi::rule<Iterator, std::wstring(), SkipperType> m_expression900;
    qi::rule<Iterator, std::wstring(), SkipperType> m_expressionMax;
    qi::rule<Iterator, std::wstring(), SkipperType> m_hashAtom;
    qi::rule<Iterator, std::wstring(), SkipperType> m_dotAtom;

    qi::rule<Iterator, std::wstring(), SkipperType> m_expression;
    qi::rule<Iterator, std::wstring(), SkipperType> m_expressions;
};

#endif