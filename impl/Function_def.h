#pragma once
#include "Function.h"

template <typename Iterator, typename Lexer, typename SkipperType>
ErlangFunction<Iterator, Lexer, SkipperType>::ErlangFunction(const Lexer& lexer, 
                                                             const ErlangTerminals<Iterator, Lexer, SkipperType>& terminals,
                                                             const ErlangExpression<Iterator, Lexer, SkipperType>& expression) : ErlangFunction::base_type(m_functionClauses),
                                                                                                                                 m_lexer(lexer),
                                                                                                                                 m_terminals(terminals),
                                                                                                                                 m_expression(expression)
{
    //function_clause -> atom clause_args clause_guard clause_body (elided clause_args as it is simply m_argumentList)
    m_functionClause = m_lexer.atom >> m_expression.ArgumentList >> m_expression.ClauseGuard >> m_expression.ClauseBody;

    //function_clauses -> function_clause
    //function_clauses -> function_clause ';' function_clauses
    m_functionClauses = m_functionClause >> -(qi::hold[m_lexer.semiColon >> m_functionClauses]);

    #pragma region Debug Support

    BOOST_SPIRIT_DEBUG_NODES(
        (m_functionClause)
        (m_functionClauses));

    //debug(m_functionClause);
    //debug(m_functionClauses);

    #pragma endregion
}