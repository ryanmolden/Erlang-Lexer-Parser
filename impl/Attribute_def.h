#pragma once
#include "Attribute.h"

template <typename Iterator, typename Lexer, typename SkipperType>
ErlangAttribute<Iterator, Lexer, SkipperType>::ErlangAttribute(const Lexer& lexer, 
                                                               const ErlangTerminals<Iterator, Lexer, SkipperType>& terminals,
                                                               const ErlangExpression<Iterator, Lexer, SkipperType>& expression) : ErlangAttribute::base_type(m_attribute),
                                                                                                                                   m_lexer(lexer),
                                                                                                                                   m_terminals(terminals),
                                                                                                                                   m_expression(expression)
{
    //TODO:  This is duplicated here and in ErlangExpression.  It seemed a little odd to 'expose' a definition of Expressions from Expression
    //but maybe it would be better to avoid having it defined in two places.
    //
    //exprs -> expr
    //exprs -> expr ',' exprs
    m_expressions = m_expression >> -(qi::hold[m_lexer.comma >> m_expressions]);

    //attr_val -> expr
    //attr_val -> expr ',' exprs
    //attr_val -> '(' expr ',' exprs ')'
    m_attributeValue = qi::hold[m_expression] |
                       -m_lexer.leftParen >> m_expression >> m_lexer.comma >> m_expressions >> -m_lexer.rightParen;

    //field_type -> atom '::' top_type          
    m_fieldType = m_lexer.atom >> m_lexer.typeSeparator >> m_topType;

    //field_types -> field_type                 
    //field_types -> field_type ',' field_types 
    m_fieldTypes = m_fieldType >> -(qi::hold[m_lexer.comma >> m_fieldTypes]);

    //bin_base_type -> var ':' type
    m_binaryBaseType = m_lexer.variable >> m_lexer.colon >> m_type;

    //bin_unit_type -> var ':' var '*' type
    m_binaryUnitType = m_lexer.variable >> m_lexer.colon >> m_lexer.variable >> m_lexer.operatorMultiply >> m_type;

    //binary_type -> '<<' '>>'
    //binary_type -> '<<' bin_base_type '>>'
    //binary_type -> '<<' bin_unit_type '>>'
    //binary_type -> '<<' bin_base_type ',' bin_unit_type '>>'
    m_binaryType = qi::hold[m_lexer.bitstringHead >> -(qi::hold[m_binaryBaseType | m_binaryUnitType]) >> m_lexer.bitstringTail] |
                   m_lexer.bitstringHead >> m_binaryBaseType >> m_lexer.comma >> m_binaryUnitType;

    //fun_type -> '(' ')' '->' top_type
    //fun_type -> '(' top_types ')' '->' top_type
    m_funType = m_lexer.leftParen >> -(qi::hold[m_topTypes]) >> m_lexer.rightParen >> m_lexer.arrow >> m_topType;

    //fun_type_100 -> '(' '...' ')' '->' top_type
    //fun_type_100 -> fun_type
    m_funType100 = qi::hold[m_lexer.leftParen >> m_lexer.unspecifiedType >> m_lexer.rightParen >> m_lexer.arrow >> m_topType] |
                   m_funType;

    m_hashAtom = m_lexer.hash >> m_lexer.atom;

    //type -> '(' top_type ')'
    //type -> var
    //type -> atom
    //type -> atom '(' ')'
    //type -> atom '(' top_types ')'
    //type -> atom ':' atom '(' ')'
    //type -> atom ':' atom '(' top_types ')'
    //type -> '[' ']'
    //type -> '[' top_type ']'
    //type -> '[' top_type ',' '...' ']'
    //type -> '{' '}'
    //type -> '{' top_types '}'
    //type -> '#' atom '{' '}'
    //type -> '#' atom '{' field_types '}'
    //type -> binary_type
    //type -> integer
    //type -> 'fun' '(' ')'
    //type -> 'fun' '(' fun_type_100 ')'
    m_type = qi::hold[m_lexer.leftParen >> m_topType >> m_lexer.rightParen]                                                                |
             qi::hold[m_lexer.variable]                                                                                                    |
             qi::hold[m_lexer.atom]                                                                                                        |
             qi::hold[m_lexer.atom >> m_lexer.leftParen >> -(qi::hold[m_topTypes]) >> m_lexer.rightParen]                                  |
             qi::hold[m_lexer.atom >> m_lexer.colon >> m_lexer.atom >> m_lexer.leftParen >> -(qi::hold[m_topTypes]) >> m_lexer.rightParen] |
             qi::hold[m_lexer.leftBracket >> -(qi::hold[m_topType]) >> m_lexer.rightBracket]                                               |
             qi::hold[m_lexer.leftBracket >> m_topType >> m_lexer.comma >> m_lexer.unspecifiedType >> m_lexer.rightBracket]                |
             qi::hold[m_lexer.leftCurlyBracket >> -(qi::hold[m_topTypes]) >> m_lexer.rightCurlyBracket]                                    |
             qi::hold[m_hashAtom >> m_lexer.leftCurlyBracket >> -(qi::hold[m_fieldTypes]) >> m_lexer.rightCurlyBracket]                    |
             qi::hold[m_binaryType]                                                                                                        |
             qi::hold[m_terminals.Integer]                                                                                                 |
             m_lexer.keywordFun >> m_lexer.leftParen >> -(qi::hold[m_funType100]) >> m_lexer.rightParen;

    //type_500 -> prefix_op type
    //type_500 -> type
    m_type500 = -(qi::hold[m_terminals.PrefixOperator]) >> m_type;

    //type_400 -> type_400 mult_op type_500     
    //type_400 -> type_500                      
    m_nlrType400 = m_terminals.MultOperator >> m_type500 >> -(qi::hold[m_nlrType400]);
    m_type400 = m_type500 >> -(qi::hold[m_nlrType400]);

    //type_300 -> type_300 add_op type_400
    //type_300 -> type_400
    m_nlrType300 = m_terminals.AddOperator >> m_type400 >> -(qi::hold[m_nlrType300]);
    m_type300 = m_type400 >> -(qi::hold[m_nlrType300]);

    //type_200 -> type_300 '..' type_300        
    //type_200 -> type_300                      
    m_type200 = m_type300 >> -(qi::hold[m_lexer.typeValueRange >> m_type300]);

    //top_type_100 -> type_200
    //top_type_100 -> type_200 '|' top_type_100 
    m_type100 = m_type200 >> -(qi::hold[m_lexer.bar >> m_type100]);

    //top_type -> var '::' top_type_100         
    //top_type -> top_type_100                  
    m_topType = -(qi::hold[m_lexer.variable >> m_lexer.typeSeparator]) >> m_type100;

    //top_types -> top_type                     
    //top_types -> top_type ',' top_types       
    m_topTypes = m_topType >> -(qi::hold[m_lexer.comma >> m_topTypes]);

    //typed_expr -> expr '::' top_type          
    m_typedExpression = m_expression >> m_lexer.typeSeparator >> m_topType;

    //typed_exprs -> typed_expr
    //typed_exprs -> typed_expr ',' typed_exprs 
    //typed_exprs -> expr ',' typed_exprs
    //typed_exprs -> typed_expr ',' exprs
    m_typedExpressions = qi::hold[m_typedExpression >> -(qi::hold[m_lexer.comma >> (m_typedExpressions | m_expressions)])] |
                         m_expression >> m_lexer.comma >> m_typedExpressions;

    //typed_record_fields -> '{' typed_exprs '}'
    m_typedRecordFields = m_lexer.leftCurlyBracket >> m_typedExpressions >> m_lexer.rightCurlyBracket;

    //typed_attr_val -> expr ',' typed_record_fields
    //typed_attr_val -> expr '::' top_type
    m_typedAttributeValue = m_expression >> (qi::hold[m_lexer.comma >> m_typedRecordFields] | 
                                             m_lexer.typeSeparator >> m_topType);

    //type_guard -> atom '(' top_types ')'      
    //type_guard -> var '::' top_type           
    m_typeGuard = qi::hold[m_lexer.atom >> m_lexer.leftParen >> m_topTypes >> m_lexer.rightParen] |
                  m_lexer.variable >> m_lexer.typeSeparator >> m_topTypes;

    //type_guards -> type_guard                 
    //type_guards -> type_guard ',' type_guards 
    m_typeGuards = m_typeGuard >> -(qi::hold[m_lexer.comma >> m_typeGuards]);

    //type_sig -> fun_type
    //type_sig -> fun_type 'when' type_guards   
    m_typeSig = m_funType >> -(qi::hold[m_lexer.keywordWhen >> m_typeGuards]);

    //type_sigs -> type_sig                     
    //type_sigs -> type_sig ';' type_sigs       
    m_typeSigs = m_typeSig >> -(qi::hold[m_lexer.semiColon >> m_typeSigs]);

    //spec_fun -> atom
    //spec_fun -> atom ':' atom
    m_specFun = m_lexer.atom >> -(qi::hold[m_lexer.colon >> m_lexer.atom]);

    //type_spec -> spec_fun type_sigs
    //type_spec -> '(' spec_fun type_sigs ')'
    m_typeSpec = -m_lexer.leftParen >> m_specFun >> m_typeSigs >> -m_lexer.rightParen;
                   
    //attribute -> '-' atom attr_val
    //attribute -> '-' atom typed_attr_val
    //attribute -> '-' atom '(' typed_attr_val ')'
    //attribute -> '-' 'spec' type_spec
    m_attribute = qi::hold[m_lexer.specAttributeHead >> m_typeSpec]          |
                  qi::hold[m_lexer.genericAttributeHead >> m_attributeValue] |
                  m_lexer.genericAttributeHead >> -m_lexer.leftParen >> m_typedAttributeValue >> -m_lexer.rightParen;
}