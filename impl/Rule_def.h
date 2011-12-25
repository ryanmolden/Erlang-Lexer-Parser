#pragma once
#include "Rule.h"

template <typename Iterator, typename Lexer, typename SkipperType>
ErlangRule<Iterator, Lexer, SkipperType>::ErlangRule(const Lexer& lexer, 
                                                     const ErlangTerminals<Iterator, Lexer, SkipperType>& terminals,
                                                     const ErlangExpression<Iterator, Lexer, SkipperType>& expression) : ErlangRule::base_type(m_ruleClauses),
                                                                                                                         m_lexer(lexer),
                                                                                                                         m_terminals(terminals),
                                                                                                                         m_expression(expression)
{
    //rule_body -> ':-' lc_exprs
    m_ruleBody = m_lexer.ruleSeparator >> m_expression.ListComprehensionExpressions;

    //rule_clause -> atom clause_args clause_guard rule_body  (elided clause_args as it is simply m_argumentList)
    m_ruleClause = m_lexer.atom >> m_expression.ArgumentList >> m_expression.ClauseGuard >> m_ruleBody;

    //rule_clauses -> rule_clause
    //rule_clauses -> rule_clause ';' rule_clauses
    m_ruleClauses = m_ruleClause >> -(qi::hold[m_lexer.semiColon >> m_ruleClauses]);

    #pragma region Debug Support

    BOOST_SPIRIT_DEBUG_NODES(
        (m_ruleBody)
        (m_ruleClause)
        (m_ruleClauses));

    //debug(m_ruleBody);
    //debug(m_ruleClause);
    //debug(m_ruleClauses);

    #pragma endregion
}