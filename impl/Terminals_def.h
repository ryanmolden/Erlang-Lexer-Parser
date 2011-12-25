#pragma once
#include "Terminals.h"

template <typename Iterator, typename Lexer, typename SkipperType>
ErlangTerminals<Iterator, Lexer, SkipperType>::ErlangTerminals(Lexer const& lexer) : m_lexer(lexer) 
{
    //prefix_op -> '+'
    //prefix_op -> '-'
    //prefix_op -> 'bnot'
    //prefix_op -> 'not'
    PrefixOperator = m_lexer.operatorPlus  |
                     m_lexer.operatorMinus |
                     m_lexer.operatorBNOT  |
                     m_lexer.operatorNOT;

    //comp_op -> '=='
    //comp_op -> '/='
    //comp_op -> '=<'
    //comp_op -> '<' 
    //comp_op -> '>='
    //comp_op -> '>' 
    //comp_op -> '=:='
    //comp_op -> '=/='
    ComparisonOperator = m_lexer.operatorEqualTo          |
                         m_lexer.operatorNotEqualTo       |
                         m_lexer.operatorLessThanEqual    |
                         m_lexer.operatorLessThan         |
                         m_lexer.operatorGreaterThanEqual |
                         m_lexer.operatorGreaterThan      |
                         m_lexer.operatorIdenticalTo      |
                         m_lexer.operatorNotIdenticalTo;

    //list_op -> '++'
    //list_op -> '--'
    ListOperator = m_lexer.operatorListConcat |
                   m_lexer.operatorListSubtract;

    //add_op -> '+'
    //add_op -> '-'
    //add_op -> 'bor' 
    //add_op -> 'bxor'
    //add_op -> 'bsl' 
    //add_op -> 'bsr' 
    //add_op -> 'or'
    //add_op -> 'xor'
    AddOperator = m_lexer.operatorPlus  |
                  m_lexer.operatorMinus |
                  m_lexer.operatorBOR   |
                  m_lexer.operatorBXOR  |
                  m_lexer.operatorBSL   |
                  m_lexer.operatorBSR   |
                  m_lexer.operatorOR    |
                  m_lexer.operatorXOR;


    //mult_op -> '/'
    //mult_op -> '*'
    //mult_op -> 'div'
    //mult_op -> 'rem'
    //mult_op -> 'band'
    //mult_op -> 'and'
    MultOperator = m_lexer.forwardSlash      |
                   m_lexer.operatorMultiply  |
                   m_lexer.operatorIntDivide |
                   m_lexer.operatorRemainder |
                   m_lexer.operatorBAND      |
                   m_lexer.operatorAND;

    AtomOrVariable = qi::hold[m_lexer.atom | m_lexer.variable];

    Integer = qi::hold[m_lexer.explicitRadixLiteral | m_lexer.decimalLiteral];

    IntegerOrVariable = qi::hold[Integer | m_lexer.variable];

    #pragma region Debug Support
    BOOST_SPIRIT_DEBUG_NODES(
        (PrefixOperator)
        (ComparisonOperator)
        (ListOperator)
        (AddOperator)
        (MultOperator)
        (AtomOrVariable)
        (Integer)
        (IntegerOrVariable));

    //debug(PrefixOperator);
    //debug(ComparisonOperator);
    //debug(ListOperator);
    //debug(AddOperator);
    //debug(MultOperator);
    //debug(AtomOrVariable);
    //debug(Integer);
    //debug(IntegerOrVariable);

    #pragma endregion
}