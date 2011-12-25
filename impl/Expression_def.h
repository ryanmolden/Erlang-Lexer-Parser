#pragma once
#include "Expression.h"

template <typename Iterator, typename Lexer, typename SkipperType>
ErlangExpression<Iterator, Lexer, SkipperType>::ErlangExpression(const Lexer& lexer, 
                                                                 const ErlangTerminals<Iterator, Lexer, SkipperType> & terminals) : ErlangExpression::base_type(m_expression),
                                                                                                                                    m_lexer(lexer),
                                                                                                                                    m_terminals(terminals)
{
    //All left recursive productions in the original  grammar were transformed to equivalent, non-left recursive productions using the 
    //simple algorithm from Compilers: Principles, Techniques, & Tools (Aho,Lam,Sethi,Ullman) - 2007.  Specifically as described in 
    //section 2.4.5 (page 67).

    //atomic -> char
    //atomic -> integer
    //atomic -> float
    //atomic -> atom
    //atomic -> strings (elided this non-terminal as it is simply +m_lexer.stringLiteral)
    m_atomic =  m_lexer.characterLiteral |
                m_terminals.Integer      |
                m_lexer.floatLiteral     |
                m_lexer.atom             |
                +m_lexer.stringLiteral;

    //tail -> ']'
    //tail -> '|' expr ']'
    //tail -> ',' expr tail
    m_tail = qi::hold[-(qi::hold[m_lexer.bar >> m_expression]) >> m_lexer.rightBracket] |
             m_lexer.comma >> m_expression >> m_tail;

    //list -> '[' ']'
    //list -> '[' expr tail
    m_list = qi::hold[m_lexer.leftBracket >> m_lexer.rightBracket] |
             m_lexer.leftBracket >> m_expression >> m_tail;

        //bit_type -> atom
    //bit_type -> atom ':' integer
    m_bitType = m_lexer.atom >> -(qi::hold[m_lexer.colon >> m_terminals.Integer]);

    //bit_type_list -> bit_type '-' bit_type_list
    //bit_type_list -> bit_type
    m_bitTypeList = m_bitType >> -(qi::hold[m_lexer.operatorMinus >> m_bitTypeList]);

    //bit_expr -> prefix_op expr_max
    //bit_expr -> expr_max
    m_bitExpression = -(m_terminals.PrefixOperator) >> m_expressionMax;

    //bit_size_expr -> expr_max
    //opt_bit_size_expr -> ':' bit_size_expr
    //opt_bit_size_expr -> '$empty'
    //
    //opt_bit_type_list -> '/' bit_type_list
    //opt_bit_type_list -> '$empty'
    //
    //bin_element -> bit_expr opt_bit_size_expr opt_bit_type_list
    m_binaryElement = m_bitExpression >> -(qi::hold[m_lexer.colon >> m_expressionMax]) >> -(qi::hold[m_lexer.forwardSlash >> m_bitTypeList]);

    //bin_elements -> bin_element
    //bin_elements -> bin_element ',' bin_elements
    m_binaryElements =  m_binaryElement >> -(qi::hold[m_lexer.comma >> m_binaryElements]);

    //binary -> '<<' '>>'
    //binary -> '<<' bin_elements '>>'
    m_binary = m_lexer.bitstringHead >> -(qi::hold[m_binaryElements]) >> m_lexer.bitstringTail;

    //lc_expr -> expr
    //lc_expr -> expr '<-' expr
    //lc_expr -> binary '<=' expr
    m_listComprehensionExpression = qi::hold[m_expression >> -(qi::hold[m_lexer.operatorGenerate >> m_expression])] |
                                    m_binary >> m_lexer.operatorBitGenerate >> m_expression;

    //lc_exprs -> lc_expr
    //lc_exprs -> lc_expr ',' lc_exprs
    ListComprehensionExpressions = m_listComprehensionExpression >> -(qi::hold[m_lexer.comma >> ListComprehensionExpressions]);

    //list_comprehension -> '[' expr '||' lc_exprs ']'
    m_listComprehension = m_lexer.leftBracket >> m_expression >> m_lexer.doubleBar >> ListComprehensionExpressions >> m_lexer.rightBracket;

    //binary_comprehension -> '<<' binary '||' lc_exprs '>>'
    m_binaryComprehension = m_lexer.bitstringHead >> m_binary >> m_lexer.doubleBar >> ListComprehensionExpressions >> m_lexer.bitstringTail;

    //tuple -> '{' '}'
    //tuple -> '{' exprs '}'
    m_tuple = m_lexer.leftCurlyBracket >> -(qi::hold[m_expressions]) >> m_lexer.rightCurlyBracket;

    //guard -> exprs
    //guard -> exprs ';' guard
    m_guard = m_expressions >> -(qi::hold[m_lexer.semiColon >> m_guard]);

    //clause_body -> '->' exprs
    ClauseBody = m_lexer.arrow >> m_expressions;

    //if_clause -> guard clause_body
    m_ifClause = m_guard >> ClauseBody;

    //if_clauses -> if_clause
    //if_clauses -> if_clause ';' if_clauses
    m_ifClauses = m_ifClause >> -(qi::hold[m_lexer.semiColon >> m_ifClauses]);

    //if_expr -> 'if' if_clauses 'end'
    m_ifExpression = m_lexer.keywordIf >> m_ifClauses >> m_lexer.keywordEnd;

    //TODO:  This is duplicated here and in ErlangAttribute.  It seemed a little odd to 'expose' a definition of Expressions from here
    //but maybe it would be better to avoid having it defined in two places.
    //
    //exprs -> expr
    //exprs -> expr ',' exprs
    m_expressions = m_expression >> -(qi::hold[m_lexer.comma >> m_expressions]);

    //clause_guard -> 'when' guard
    //clause_guard -> '$empty'
    ClauseGuard = -(qi::hold[m_lexer.keywordWhen >> m_guard]);

    //cr_clause -> expr clause_guard clause_body
    m_crClause = m_expression >> ClauseGuard >> ClauseBody;

    //cr_clauses -> cr_clause
    //cr_clauses -> cr_clause ';' cr_clauses
    m_crClauses = m_crClause >> -(qi::hold[m_lexer.semiColon >> m_crClauses]);

    //case_expr -> 'case' expr 'of' cr_clauses 'end'
    m_caseExpression = m_lexer.keywordCase >> m_expression >> m_lexer.keywordOf >> m_crClauses >> m_lexer.keywordEnd;

    //receive_expr -> 'receive' cr_clauses 'end'
    //receive_expr -> 'receive' 'after' expr clause_body 'end'
    //receive_expr -> 'receive' cr_clauses 'after' expr clause_body 'end'
    //
    //TODO:  Try and simplify the last two alternations into one with an optional m_crClauses
    m_receiveExpression = qi::hold[m_lexer.keywordReceive >> m_crClauses >> m_lexer.keywordEnd]                                          |
                          qi::hold[m_lexer.keywordReceive >> m_lexer.keywordAfter >> m_expression >> ClauseBody >> m_lexer.keywordEnd]   |
                          m_lexer.keywordReceive >> m_crClauses >> m_lexer.keywordAfter >> m_expression >> ClauseBody >> m_lexer.keywordEnd;

    //try_catch -> 'catch' try_clauses 'end'
    //try_catch -> 'catch' try_clauses 'after' exprs 'end'
    //try_catch -> 'after' exprs 'end'
    m_tryCatch = qi::hold[m_lexer.keywordCatch >> m_tryClauses >> -(qi::hold[m_lexer.keywordAfter >> m_expressions]) >> m_lexer.keywordEnd] |
                 m_lexer.keywordAfter >> m_expressions >> m_lexer.keywordEnd;

    //try_clause -> expr clause_guard clause_body
    //try_clause -> atom ':' expr clause_guard clause_body
    //try_clause -> var ':' expr clause_guard clause_body
    m_tryClause = -(qi::hold[m_terminals.AtomOrVariable >> m_lexer.colon]) >> m_expression >> ClauseGuard >> ClauseBody;

    //try_clauses -> try_clause
    //try_clauses -> try_clause ';' try_clauses
    m_tryClauses = m_tryClause >> -(qi::hold[m_lexer.semiColon >> m_tryClauses]);

    //try_expr -> 'try' exprs 'of' cr_clauses try_catch
    //try_expr -> 'try' exprs try_catch
    m_tryExpression = m_lexer.keywordTry >> m_expressions >> -(qi::hold[m_lexer.keywordOf >> m_crClauses]) >> m_tryCatch;

    //argument_list -> '(' ')'
    //argument_list -> '(' exprs ')'
    ArgumentList = m_lexer.leftParen >> -(qi::hold[m_expressions]) >> m_lexer.rightParen;

    //fun_clause -> argument_list clause_guard clause_body
    m_funClause = ArgumentList >> ClauseGuard >> ClauseBody;

    //fun_clauses -> fun_clause
    //fun_clauses -> fun_clause ';' fun_clauses
    m_funClauses = m_funClause >> -(qi::hold[m_lexer.semiColon >> m_funClauses]);

    //fun_expr -> 'fun' atom '/' integer
    //fun_expr -> 'fun' atom ':' atom '/' integer
    //fun_expr -> 'fun' fun_clauses 'end'
    m_funExpression = qi::hold[m_lexer.keywordFun >> m_lexer.atom >> -(qi::hold[m_lexer.colon >> m_lexer.atom]) >> m_lexer.forwardSlash >> m_terminals.Integer] |
                      m_lexer.keywordFun >> m_funClauses >> m_lexer.keywordEnd;

    //query_expr -> 'query' list_comprehension 'end'
    m_queryExpression = m_lexer.keywordQuery >> m_listComprehension >> m_lexer.keywordEnd;

    //expr_max -> var
    //expr_max -> atomic
    //expr_max -> list
    //expr_max -> binary
    //expr_max -> list_comprehension
    //expr_max -> binary_comprehension
    //expr_max -> tuple
    //%%expr_max -> struct
    //expr_max -> '(' expr ')'
    //expr_max -> 'begin' exprs 'end'
    //expr_max -> if_expr
    //expr_max -> case_expr
    //expr_max -> receive_expr
    //expr_max -> fun_expr
    //expr_max -> try_expr
    //expr_max -> query_expr
    m_expressionMax =   qi::hold[m_lexer.variable]                                            |
                        qi::hold[m_atomic]                                                    |
                        qi::hold[m_list]                                                      |
                        qi::hold[m_binary]                                                    |
                        qi::hold[m_listComprehension]                                         |
                        qi::hold[m_binaryComprehension]                                       |
                        qi::hold[m_tuple]                                                     |
                        qi::hold[m_lexer.leftParen >> m_expression >> m_lexer.rightParen]       |
                        qi::hold[m_lexer.keywordBegin >> m_expressions >> m_lexer.keywordEnd]   |
                        qi::hold[m_ifExpression]                                              |
                        qi::hold[m_caseExpression]                                            |
                        qi::hold[m_receiveExpression]                                         |
                        qi::hold[m_funExpression]                                             |
                        qi::hold[m_tryExpression]                                             |
                        m_queryExpression;

    //Helpers to be used in a number of places that use the pattern .<atom> or #<atom>
    m_hashAtom = m_lexer.hash >> m_lexer.atom;
    m_dotAtom = m_lexer.dot >> m_lexer.atom;

    //expr_900 -> '.' atom
    //expr_900 -> expr_900 '.' atom
    //expr_900 -> expr_max
    //NOTE:  The nested hold at the end is actually needed, not just me being crazy :)  The problem is that the optional pareser (-) will
    //always succeed, by definition, since not matching can be a success here.  If it encounters a string that is 
    //
    //  <terminator> <anything else besides an atom>
    //
    //it will add the terminator to the attribute, go on to fail the next item in the sequence but since - always succeeds then it will
    //take the modified attribute (consisting of <terminator>) and propagate it out to the larger expression, but the token hasn't been
    //consumed and can go on to match somewhere else later.
    m_nlrExpression900 = m_dotAtom >> -(qi::hold[m_nlrExpression900]);
    m_expression900 = qi::hold[(m_expressionMax | m_dotAtom)] >> -(qi::hold[m_nlrExpression900]);

    //expr_800 -> expr_900 ':' expr_max
    //expr_800 -> expr_900
    m_expression800 = m_expression900 >> -(qi::hold[m_lexer.colon >> m_expressionMax]);

    //%% N.B. This is called from expr_700.
    //function_call -> expr_800 argument_list
    m_functionCall = m_expression800 >> ArgumentList;

    //record_field -> var '=' expr
    //record_field -> atom '=' expr
    m_recordField = m_terminals.AtomOrVariable >> m_lexer.operatorMatch >> m_expression;

    //record_fields -> record_field
    //record_fields -> record_field ',' record_fields
    m_recordFields = m_recordField >> -(qi::hold[m_lexer.comma >> m_recordFields]);

    //record_tuple -> '{' '}'
    //record_tuple -> '{' record_fields '}'
    m_recordTuple = m_lexer.leftCurlyBracket >> -(qi::hold[m_recordFields]) >> m_lexer.rightCurlyBracket;

    //record_expr -> record_expr '#' atom '.' atom
    //record_expr -> record_expr '#' atom record_tuple
    m_nlrRecordExpression = m_hashAtom >> (m_dotAtom | m_recordTuple) >> -(qi::hold[m_nlrRecordExpression]);

    //record_expr -> '#' atom '.' atom
    //record_expr -> '#' atom record_tuple
    //record_expr -> expr_max '#' atom '.' atom
    //record_expr -> expr_max '#' atom record_tuple
    m_recordExpression = (qi::hold[(m_hashAtom >> qi::hold[(m_dotAtom | m_recordTuple)])] |
                         (m_expressionMax >> m_hashAtom >> (qi::hold[m_dotAtom | m_recordTuple]))) >>
                         -(qi::hold[m_nlrRecordExpression]);

    //expr_700 -> function_call
    //expr_700 -> record_expr
    //expr_700 -> expr_800
    m_expression700 = qi::hold[m_functionCall]     |
                      qi::hold[m_recordExpression] |
                      m_expression800;

    //expr_600 -> prefix_op expr_700
    //expr_600 -> expr_700
    m_expression600 = -(qi::hold[m_terminals.PrefixOperator]) >> m_expression700;

    //expr_500 -> expr_500 mult_op expr_600
    //expr_500 -> expr_600
    m_nlrExpression500 = m_terminals.MultOperator >> m_expression600 >> -(qi::hold[m_nlrExpression500]);
    m_expression500 = m_expression600 >> -(qi::hold[m_nlrExpression500]);

    //expr_400 -> expr_400 add_op expr_500
    //expr_400 -> expr_500
    m_nlrExpression400 = m_terminals.AddOperator >> m_expression500 >> -(qi::hold[m_nlrExpression400]);
    m_expression400 = m_expression500 >> -(qi::hold[m_nlrExpression400]); 

    //expr_300 -> expr_400 list_op expr_300
    //expr_300 -> expr_400
    m_expression300 = m_expression400 >> -(qi::hold[m_terminals.ListOperator >> m_expression300]);

    //expr_200 -> expr_300 comp_op expr_300
    //expr_200 -> expr_300
    m_expression200 = m_expression300 >> -(qi::hold[m_terminals.ComparisonOperator >> m_expression300]);

    //expr_160 -> expr_200 'andalso' expr_160
    //expr_160 -> expr_200
    m_expression160 = m_expression200 >> -(qi::hold[m_lexer.keywordAndAlso >> m_expression160]);

    //expr_150 -> expr_160 'orelse' expr_150
    //expr_150 -> expr_160
    m_expression150 = m_expression160 >> -(qi::hold[m_lexer.keywordOrElse >> m_expression150]);

    //expr_100 -> expr_150 '=' expr_100
    //expr_100 -> expr_150 '!' expr_100
    //expr_100 -> expr_150
    m_expression100 = m_expression150 >> -(qi::hold[(m_lexer.operatorMatch | m_lexer.operatorSend) >> m_expression100]);

    //expr -> 'catch' expr
    //expr -> expr_100
    m_expression = qi::hold[m_lexer.keywordCatch >> m_expression] |
                   m_expression100;

    #pragma region Debug Support

    BOOST_SPIRIT_DEBUG_NODES(
        (ArgumentList)
        (ClauseGuard)
        (ClauseBody)
        (ListComprehensionExpressions)
        (m_atomic)
        (m_tail)
        (m_list)
        (m_bitType)
        (m_bitTypeList)
        (m_bitExpression)
        (m_binaryElement)
        (m_binaryElements)
        (m_binary)
        (m_listComprehensionExpression)
        (m_listComprehension)
        (m_binaryComprehension)
        (m_tuple)
        (m_guard)
        (m_ifClause)
        (m_ifClauses)
        (m_ifExpression)
        (m_caseExpression)
        (m_crClause)
        (m_crClauses)
        (m_receiveExpression)
        (m_tryCatch)
        (m_tryClauses)
        (m_tryClause)
        (m_tryExpression)
        (m_funClause)
        (m_funClauses)
        (m_funExpression)
        (m_queryExpression)
        (m_functionCall)
        (m_recordTuple)
        (m_recordField)
        (m_recordFields)
        (m_nlrRecordExpression)
        (m_recordExpression)
        (m_expression100)
        (m_expression150)
        (m_expression160)
        (m_expression200)
        (m_expression300)
        (m_nlrExpression400)
        (m_expression400)
        (m_nlrExpression500)
        (m_expression500)
        (m_expression600)
        (m_expression700)
        (m_expression800)
        (m_nlrExpression900)
        (m_expression900)
        (m_expressionMax)
        (m_hashAtom)
        (m_dotAtom)
        (m_expression)
        (m_expressions));

    //debug(ArgumentList);
    //debug(ClauseGuard);
    //debug(ClauseBody);
    //debug(ListComprehensionExpressions);
    //debug(m_atomic);
    //debug(m_tail);
    //debug(m_list);
    //debug(m_bitType);
    //debug(m_bitTypeList);
    //debug(m_bitExpression);
    //debug(m_binaryElement);
    //debug(m_binaryElements);
    //debug(m_binary);
    //debug(m_listComprehensionExpression);
    //debug(m_listComprehension);
    //debug(m_binaryComprehension);
    //debug(m_tuple);
    //debug(m_guard);
    //debug(m_ifClause);
    //debug(m_ifClauses);
    //debug(m_ifExpression);
    //debug(m_caseExpression);
    //debug(m_crClause);
    //debug(m_crClauses);
    //debug(m_receiveExpression);
    //debug(m_tryCatch);
    //debug(m_tryClauses);
    //debug(m_tryClause);
    //debug(m_tryExpression);
    //debug(m_funClause);
    //debug(m_funClauses);
    //debug(m_funExpression);
    //debug(m_queryExpression);
    //debug(m_functionCall);
    //debug(m_recordTuple);
    //debug(m_recordField);
    //debug(m_recordFields);
    //debug(m_nlrRecordExpression);
    //debug(m_recordExpression);
    //debug(m_expression100);
    //debug(m_expression150);
    //debug(m_expression160);
    //debug(m_expression200);
    //debug(m_expression300);
    //debug(m_nlrExpression400);
    //debug(m_expression400);
    //debug(m_nlrExpression500);
    //debug(m_expression500);
    //debug(m_expression600);
    //debug(m_expression700);
    //debug(m_expression800);
    //debug(m_nlrExpression900);
    //debug(m_expression900);
    //debug(m_expressionMax);
    //debug(m_hashAtom);
    //debug(m_dotAtom);
    //debug(m_expression);
    //debug(m_expressions);

    #pragma endregion
}
