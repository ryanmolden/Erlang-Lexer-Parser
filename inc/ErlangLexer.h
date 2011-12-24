#pragma once
#include <boost/spirit/include/lex_lexertl.hpp>
#include "ErlangTokens.h"
#include <string>

#pragma region Erlang.yrl

//This is the YRL grammar I am basing the lexer (and eventually the qi parser) on.
//
//%% -*- erlang -*-
//%%
//%% %CopyrightBegin%
//%%
//%% Copyright Ericsson AB 1996-2011. All Rights Reserved.
//%%
//%% The contents of this file are subject to the Erlang Public License,
//%% Version 1.1, (the "License"); you may not use this file except in
//%% compliance with the License. You should have received a copy of the
//%% Erlang Public License along with this software. If not, it can be
//%% retrieved online at http://www.erlang.org/.
//%%
//%% Software distributed under the License is distributed on an "AS IS"
//%% basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
//%% the License for the specific language governing rights and limitations
//%% under the License.
//%%
//%% %CopyrightEnd%
//%%
//
//%% Definition of the Erlang grammar.
//
//Nonterminals
//form
//attribute attr_val
//function function_clauses function_clause
//clause_args clause_guard clause_body
//expr expr_100 expr_150 expr_160 expr_200 expr_300 expr_400 expr_500
//expr_600 expr_700 expr_800 expr_900
//expr_max
//list tail
//list_comprehension lc_expr lc_exprs
//binary_comprehension
//tuple
//%struct
//record_expr record_tuple record_field record_fields
//if_expr if_clause if_clauses case_expr cr_clause cr_clauses receive_expr
//fun_expr fun_clause fun_clauses
//try_expr try_catch try_clause try_clauses query_expr
//function_call argument_list
//exprs guard
//atomic strings
//prefix_op mult_op add_op list_op comp_op
//rule rule_clauses rule_clause rule_body
//binary bin_elements bin_element bit_expr
//opt_bit_size_expr bit_size_expr opt_bit_type_list bit_type_list bit_type
//top_type top_type_100 top_types type typed_expr typed_attr_val
//type_sig type_sigs type_guard type_guards fun_type fun_type_100 binary_type
//type_spec spec_fun typed_exprs typed_record_fields field_types field_type
//bin_base_type bin_unit_type type_200 type_300 type_400 type_500.
//
//Terminals
//char integer float atom string var
//
//'(' ')' ',' '->' ':-' '{' '}' '[' ']' '|' '||' '<-' ';' ':' '#' '.'
//'after' 'begin' 'case' 'try' 'catch' 'end' 'fun' 'if' 'of' 'receive' 'when'
//'andalso' 'orelse' 'query'
//'bnot' 'not'
//'*' '/' 'div' 'rem' 'band' 'and'
//'+' '-' 'bor' 'bxor' 'bsl' 'bsr' 'or' 'xor'
//'++' '--'
//'==' '/=' '=<' '<' '>=' '>' '=:=' '=/=' '<='
//'<<' '>>'
//'!' '=' '::' '..' '...'
//'spec' % helper
//dot.
//
//Expect 2.
//
//Rootsymbol form.
//
//form -> attribute dot
//form -> function dot
//form -> rule dot
//
//attribute -> '-' atom attr_val
//attribute -> '-' atom typed_attr_val
//attribute -> '-' atom '(' typed_attr_val ')'
//attribute -> '-' 'spec' type_spec
//
//type_spec -> spec_fun type_sigs
//type_spec -> '(' spec_fun type_sigs ')'
//
//spec_fun -> atom
//spec_fun -> atom ':' atom
//
//%% The following two are retained only for backwards compatibility;
//%% they are not part of the EEP syntax and should be removed.
//spec_fun -> atom '/' integer '::'
//spec_fun -> atom ':' atom '/' integer '::'
//
//typed_attr_val -> expr ',' typed_record_fields
//typed_attr_val -> expr '::' top_type          
//
//typed_record_fields -> '{' typed_exprs '}'
//
//typed_exprs -> typed_expr                 
//typed_exprs -> typed_expr ',' typed_exprs 
//typed_exprs -> expr ',' typed_exprs       
//typed_exprs -> typed_expr ',' exprs       
//
//typed_expr -> expr '::' top_type          
//
//type_sigs -> type_sig                     
//type_sigs -> type_sig ';' type_sigs       
//
//type_sig -> fun_type                      
//type_sig -> fun_type 'when' type_guards   
//                                          
//
//type_guards -> type_guard                 
//type_guards -> type_guard ',' type_guards 
//
//type_guard -> atom '(' top_types ')'      
//type_guard -> var '::' top_type           
//
//top_types -> top_type                     
//top_types -> top_type ',' top_types       
//
//top_type -> var '::' top_type_100         
//top_type -> top_type_100                  
//
//top_type_100 -> type_200                  
//top_type_100 -> type_200 '|' top_type_100 
//
//type_200 -> type_300 '..' type_300        
//type_200 -> type_300                      
//
//type_300 -> type_300 add_op type_400      
//type_300 -> type_400                      
//
//type_400 -> type_400 mult_op type_500     
//type_400 -> type_500                      
//
//type_500 -> prefix_op type                
//type_500 -> type                          
//
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
//
//fun_type_100 -> '(' '...' ')' '->' top_type                                          
//fun_type_100 -> fun_type                  
//
//fun_type -> '(' ')' '->' top_type
//fun_type -> '(' top_types ')' '->' top_type
//                                   
//field_types -> field_type                 
//field_types -> field_type ',' field_types 
//
//field_type -> atom '::' top_type          
//                                          
//binary_type -> '<<' '>>'                  					    					     
//binary_type -> '<<' bin_base_type '>>'    
//binary_type -> '<<' bin_unit_type '>>'
//binary_type -> '<<' bin_base_type ',' bin_unit_type '>>'
//
//bin_base_type -> var ':' type
//
//bin_unit_type -> var ':' var '*' type
//
//attr_val -> expr
//attr_val -> expr ',' exprs
//attr_val -> '(' expr ',' exprs ')'
//
//function -> function_clauses
//
//function_clauses -> function_clause
//function_clauses -> function_clause ';' function_clauses
//
//function_clause -> atom clause_args clause_guard clause_body
//
//clause_args -> argument_list
//
//clause_guard -> 'when' guard
//clause_guard -> '$empty'
//
//clause_body -> '->' exprs
//
//expr -> 'catch' expr
//expr -> expr_100
//
//expr_100 -> expr_150 '=' expr_100
//expr_100 -> expr_150 '!' expr_100
//expr_100 -> expr_150
//
//expr_150 -> expr_160 'orelse' expr_150
//expr_150 -> expr_160
//
//expr_160 -> expr_200 'andalso' expr_160
//expr_160 -> expr_200
//
//expr_200 -> expr_300 comp_op expr_300
//expr_200 -> expr_300
//
//expr_300 -> expr_400 list_op expr_300
//expr_300 -> expr_400
//
//expr_400 -> expr_400 add_op expr_500
//expr_400 -> expr_500
//
//expr_500 -> expr_500 mult_op expr_600
//expr_500 -> expr_600
//
//expr_600 -> prefix_op expr_700
//expr_600 -> expr_700
//
//expr_700 -> function_call
//expr_700 -> record_expr
//expr_700 -> expr_800
//
//expr_800 -> expr_900 ':' expr_max
//expr_800 -> expr_900
//
//expr_900 -> '.' atom
//expr_900 -> expr_900 '.' atom
//expr_900 -> expr_max
//
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
//
//list -> '[' ']'
//list -> '[' expr tail
//
//tail -> ']'
//tail -> '|' expr ']'
//tail -> ',' expr tail
//
//binary -> '<<' '>>'
//binary -> '<<' bin_elements '>>'
//
//bin_elements -> bin_element
//bin_elements -> bin_element ',' bin_elements
//
//bin_element -> bit_expr opt_bit_size_expr opt_bit_type_list
//
//bit_expr -> prefix_op expr_max
//bit_expr -> expr_max
//
//opt_bit_size_expr -> ':' bit_size_expr
//opt_bit_size_expr -> '$empty'
//
//opt_bit_type_list -> '/' bit_type_list
//opt_bit_type_list -> '$empty'
//
//bit_type_list -> bit_type '-' bit_type_list
//bit_type_list -> bit_type
//
//bit_type -> atom
//bit_type -> atom ':' integer
//
//bit_size_expr -> expr_max
//
//list_comprehension -> '[' expr '||' lc_exprs ']'
//binary_comprehension -> '<<' binary '||' lc_exprs '>>'
//
//lc_exprs -> lc_expr
//lc_exprs -> lc_expr ',' lc_exprs
//
//lc_expr -> expr
//lc_expr -> expr '<-' expr
//lc_expr -> binary '<=' expr
//
//tuple -> '{' '}'
//tuple -> '{' exprs '}'
//
//%%struct -> atom tuple
//
//%% N.B. This is called from expr_700.
//%% N.B. Field names are returned as the complete object, even if they are
//%% always atoms for the moment, this might change in the future.
//record_expr -> '#' atom '.' atom
//record_expr -> '#' atom record_tuple
//record_expr -> expr_max '#' atom '.' atom
//record_expr -> expr_max '#' atom record_tuple
//record_expr -> record_expr '#' atom '.' atom
//record_expr -> record_expr '#' atom record_tuple
//
//record_tuple -> '{' '}'
//record_tuple -> '{' record_fields '}'
//
//record_fields -> record_field
//record_fields -> record_field ',' record_fields
//
//record_field -> var '=' expr
//record_field -> atom '=' expr
//
//%% N.B. This is called from expr_700.
//function_call -> expr_800 argument_list
//
//if_expr -> 'if' if_clauses 'end'
//
//if_clauses -> if_clause
//if_clauses -> if_clause ';' if_clauses
//
//if_clause -> guard clause_body
//
//case_expr -> 'case' expr 'of' cr_clauses 'end'
//
//cr_clauses -> cr_clause
//cr_clauses -> cr_clause ';' cr_clauses
//
//cr_clause -> expr clause_guard clause_body
//
//receive_expr -> 'receive' cr_clauses 'end'
//receive_expr -> 'receive' 'after' expr clause_body 'end'
//receive_expr -> 'receive' cr_clauses 'after' expr clause_body 'end'
//
//fun_expr -> 'fun' atom '/' integer
//fun_expr -> 'fun' atom ':' atom '/' integer
//fun_expr -> 'fun' fun_clauses 'end'
//
//fun_clauses -> fun_clause
//fun_clauses -> fun_clause ';' fun_clauses
//
//fun_clause -> argument_list clause_guard clause_body
//
//try_expr -> 'try' exprs 'of' cr_clauses try_catch
//try_expr -> 'try' exprs try_catch
//
//try_catch -> 'catch' try_clauses 'end'
//try_catch -> 'catch' try_clauses 'after' exprs 'end'
//try_catch -> 'after' exprs 'end'
//
//try_clauses -> try_clause
//try_clauses -> try_clause ';' try_clauses
//
//try_clause -> expr clause_guard clause_body
//try_clause -> atom ':' expr clause_guard clause_body
//try_clause -> var ':' expr clause_guard clause_body
//
//query_expr -> 'query' list_comprehension 'end'
//
//argument_list -> '(' ')'
//argument_list -> '(' exprs ')'
//
//exprs -> expr
//exprs -> expr ',' exprs
//
//guard -> exprs
//guard -> exprs ';' guard
//
//atomic -> char
//atomic -> integer
//atomic -> float
//atomic -> atom
//atomic -> strings
//
//strings -> string
//strings -> string strings
//
//prefix_op -> '+'
//prefix_op -> '-'
//prefix_op -> 'bnot'
//prefix_op -> 'not'
//
//mult_op -> '/'
//mult_op -> '*'
//mult_op -> 'div'
//mult_op -> 'rem'
//mult_op -> 'band'
//mult_op -> 'and'
//
//add_op -> '+'
//add_op -> '-'
//add_op -> 'bor' 
//add_op -> 'bxor'
//add_op -> 'bsl' 
//add_op -> 'bsr' 
//add_op -> 'or'
//add_op -> 'xor'
//
//list_op -> '++'
//list_op -> '--'
//
//comp_op -> '=='
//comp_op -> '/='
//comp_op -> '=<'
//comp_op -> '<' 
//comp_op -> '>='
//comp_op -> '>' 
//comp_op -> '=:='
//comp_op -> '=/='
//
//rule -> rule_clauses
//
//rule_clauses -> rule_clause
//rule_clauses -> rule_clause ';' rule_clauses
//
//rule_clause -> atom clause_args clause_guard rule_body
//
//rule_body -> ':-' lc_exprs
#pragma endregion

namespace lex = boost::spirit::lex;

enum LexerBehavior
{
    LB_Standard = 0,
    LB_AllowUnterminatedStringLiterals = 1
};

template <typename Lexer>
struct ErlangLexer : lex::lexer<Lexer>
{
    //TODO:  Make the underlying char type a template param, problem is MSVC wants L'' for wide chars and '' for non-wide,
    //so it can be a little tricky to have the right literals here if the user can swtich the underlying stream type.
    //Likely need a char_traits type approach that would expose a prefix (possibly the empty string) to be added to my
    //literals.
    typedef lex::token_def<std::wstring, wchar_t> Token;

    ErlangLexer(LexerBehavior lexerBehavior = LB_Standard)
    {
        // define tokens (the regular expression to match and the corresponding token id) and add them to the lexer 

        /*Seperators*/
        leftParen            = Token(L'(', ERLANGTOKEN_LEFTPAREN);
        rightParen           = Token(L')', ERLANGTOKEN_RIGHTPAREN);
        comma                = Token(L',', ERLANGTOKEN_COMMA);
        arrow                = Token(L"->", ERLANGTOKEN_ARROW);
        ruleSeparator        = Token(L":-", ERLANGTOKEN_RULESEPARATOR);
        leftCurlyBracket     = Token(L'{', ERLANGTOKEN_LEFTCURLYBRACKET);
        rightCurlyBracket    = Token(L'}', ERLANGTOKEN_RIGHTCURLYBRACKET);
        leftBracket          = Token(L'[', ERLANGTOKEN_LEFTBRACKET);
        rightBracket         = Token(L']', ERLANGTOKEN_RIGHTBRACKET);
        bitstringHead        = Token(L"<<", ERLANGTOKEN_BITSTRINGHEAD);
        bitstringTail        = Token(L">>", ERLANGTOKEN_BITSTRINGTAIL);
        bar                  = Token(L'|', ERLANGTOKEN_BAR);
        doubleBar            = Token(L"\\|\\|", ERLANGTOKEN_DOUBLEBAR);
        semiColon            = Token(L';', ERLANGTOKEN_SEMICOLON);
        colon                = Token(L':', ERLANGTOKEN_COLON);
        forwardSlash         = Token(L'/', ERLANGTOKEN_FORWARDSLASH);
        hash                 = Token(L'#', ERLANGTOKEN_HASH);
        typeSeparator        = Token(L"::", ERLANGTOKEN_TYPESEPARATOR);
        typeValueRange       = Token(L"\\.\\.", ERLANGTOKEN_TYPEVALUERANGE);
        unspecifiedType      = Token(L"\\.\\.\\.", ERLANGTOKEN_UNSPECIFIEDTYPE);

        //The dot is somewhat of a special case in Erlang as there is ambiguity between a dot that ends a term (.[whitespace]) and
        //a dot that is part of expr_900 (.<atom>).  Since the lexer normally eats whitespace we need to detect the two conditions 
        //here and produce the proper token or our parser would have no way of parsing certain, otherwise valid, constructs.
        //
        //NOTE:  The lack of \\n in the character class is not an oversight.  lexertl seems to always treat \\n as a line\input terminator and
        //thus it never matches \\.\\n and always, instead, matches \\.$ (i.e. it treats the newline as a 'special' character that doesn't
        //participate in the match).
        dotTerminator = Token(L"\\.[ \\t\\r]", ERLANGTOKEN_DOTTERMINATOR);
        dotTerminatorAtEOI = Token(L"\\.$", ERLANGTOKEN_DOTTERMINATOR);
        dot = Token(L'.', ERLANGTOKEN_DOT);

        /*Keywords*/
        keywordAfter      = Token(L"after", ERLANGTOKEN_AFTER);
        keywordBegin      = Token(L"begin", ERLANGTOKEN_BEGIN);
        keywordCase       = Token(L"case", ERLANGTOKEN_CASE);
        keywordTry        = Token(L"try", ERLANGTOKEN_TRY);
        keywordCatch      = Token(L"catch", ERLANGTOKEN_CATCH);
        keywordEnd        = Token(L"end", ERLANGTOKEN_END);
        keywordFun        = Token(L"fun", ERLANGTOKEN_FUN);
        keywordIf         = Token(L"if", ERLANGTOKEN_IF); 
        keywordOf         = Token(L"of", ERLANGTOKEN_OF);
        keywordReceive    = Token(L"receive", ERLANGTOKEN_RECEIVE); 
        keywordWhen       = Token(L"when", ERLANGTOKEN_WHEN);
        keywordAndAlso    = Token(L"andalso", ERLANGTOKEN_ANDALSO);
        keywordOrElse     = Token(L"orelse", ERLANGTOKEN_ORELSE);
        keywordQuery      = Token(L"query", ERLANGTOKEN_QUERY);

        /*Operators*/
        //
        //NOTE - There is no floating point division operator (/) as it is ambiguous with the function name and arity seperator, since it is the
        //same symbol.  I chose to just call it ID_FORWARDSLASH and the parser can disambiguate whether it is an FP division or a name/arity 
        //separator as it will have more context.
        operatorBNOT             = Token(L"bnot", ERLANGTOKEN_OPBNOT);
        operatorNOT              = Token(L"not", ERLANGTOKEN_OPNOT);
        operatorMultiply         = Token(L'*', ERLANGTOKEN_OPMULT);
        operatorIntDivide        = Token(L"div", ERLANGTOKEN_OPINTDIV);
        operatorRemainder        = Token(L"rem", ERLANGTOKEN_OPREM);
        operatorBAND             = Token(L"band", ERLANGTOKEN_OPBAND);
        operatorAND              = Token(L"and", ERLANGTOKEN_OPAND);
        operatorListConcat       = Token(L"\\+\\+", ERLANGTOKEN_OPLISTCONCAT);
        operatorListSubtract     = Token(L"--", ERLANGTOKEN_OPLISTSUBTRACT);
        operatorPlus             = Token(L'+', ERLANGTOKEN_OPPLUS);
        operatorMinus            = Token(L'-', ERLANGTOKEN_OPMINUS);
        operatorBOR              = Token(L"bor", ERLANGTOKEN_OPBOR);
        operatorBXOR             = Token(L"bxor", ERLANGTOKEN_OPBXOR);
        operatorBSL              = Token(L"bsl", ERLANGTOKEN_OPBSL);
        operatorBSR              = Token(L"bsr", ERLANGTOKEN_OPBSR);
        operatorOR               = Token(L"or", ERLANGTOKEN_OPOR);
        operatorXOR              = Token(L"xor", ERLANGTOKEN_OPXOR);
        operatorEqualTo          = Token(L"==", ERLANGTOKEN_OPEQUALTO);
        operatorNotEqualTo       = Token(L"\\/=", ERLANGTOKEN_OPNOTEQUALTO);
        operatorLessThanEqual    = Token(L"=<", ERLANGTOKEN_OPLESSTHANEQUAL);
        operatorLessThan         = Token(L'<', ERLANGTOKEN_OPLESSTHAN);
        operatorGreaterThanEqual = Token(L">=", ERLANGTOKEN_OPGREATERTHANEQUAL);
        operatorGreaterThan      = Token(L'>', ERLANGTOKEN_OPGREATERTHAN);
        operatorIdenticalTo      = Token(L"=:=", ERLANGTOKEN_OPIDENTICALTO);
        operatorNotIdenticalTo   = Token(L"=\\/=", ERLANGTOKEN_OPNOTIDENTICALTO);
        operatorGenerate         = Token(L"<-", ERLANGTOKEN_OPGENERATE);
        operatorBitGenerate      = Token(L"<=", ERLANGTOKEN_OPBITGENERATE);
        operatorSend             = Token(L'!', ERLANGTOKEN_OPSEND);
        operatorMatch            = Token(L'=', ERLANGTOKEN_OPMATCH);

        std::wstring validEscapeSequence(L"\\\\^[\\x40-\\x5f]|\\\\[0-7][0-7]?[0-7]?|\\\\[btnvdefrs'\"\\\\]");

        /*Misc*/
        universalPattern     = Token('_', ERLANGTOKEN_UNIVERSALPATTERN);
        atom          = Token(std::wstring(L"([a-z][\\w@]*)|'([^\\'\\x00-\\x1F]") + L"|" + validEscapeSequence + L")+'", ERLANGTOKEN_ATOM);
        comment       = Token(L"%[\t\\x20-\\x7E]*(\\n|\\r|\\r\\n|\\n\\r)?", ERLANGTOKEN_COMMENT);
        variable      = Token(L"[A-Z][\\w@]*|(_[\\w@]+)", ERLANGTOKEN_VARIABLE);

        /*Literals*/
        characterLiteral     = Token(std::wstring(L"$([\\x20-\\x7E]") + L"|" + validEscapeSequence + L")", ERLANGTOKEN_CHARACTERLITERAL);
        explicitRadixLiteral = Token(L"2#[01]+|16#[\\da-fA-F]+|3#[0-2]+|4#[0-3]+|5#[0-4]+|6#[0-5]+|7#[0-6]+|8#[0-7]+|9#[0-8]+|10#[\\d]+|11#[\\daA]+|12#[\\daAbB]+|13#[\\da-cA-C]+|14#[\\da-dA-D]+|15#[\\da-eA-E]+", ERLANGTOKEN_EXPLICITRADIXLITERAL);
        floatLiteral         = Token(L"[\\d]+\\.[\\d]+([eE][+-][\\d]+)?", ERLANGTOKEN_FLOATLITERAL);
        decimalLiteral       = Token(L"[\\d]+", ERLANGTOKEN_DECIMALLITERAL);

        //We have a flag that allows us to recognize an unterminated string literal as a string literal, this is useful for users who
        //want to use the lexer to classify text in an IDE. This allows something like "Foo to be recognized as a string literal while
        //the user is typing it, as opposed to waiting until after they have closed it via the final "
        std::wstring stringLiteralRegEx(L"\\\"([^\\\\\"\\x00-\\x1F]");
        stringLiteralRegEx += L"|" + validEscapeSequence + L")*\\\"";

        if((lexerBehavior & LB_AllowUnterminatedStringLiterals) == LB_AllowUnterminatedStringLiterals)
        {
            //If the user wants to allow unterminated string literals we just make the closing " optional in our regex.
            stringLiteralRegEx += L"?";
        }

        stringLiteral = Token(stringLiteralRegEx, ERLANGTOKEN_STRINGLITERAL);

        /*Attributes*/
        specAttributeHead     = Token(L"-spec", ERLANGTOKEN_SPECATTRIBUTEHEAD);
        callbackAttributeHead = Token(L"-callback", ERLANGTOKEN_CALLBACKATTRIBUTEHEAD);
        genericAttributeHead  = Token(std::wstring(L"-(([a-z][\\w@]*)|'([^\\'\\x00-\\x1F]") + L"|" + validEscapeSequence + L")*')", ERLANGTOKEN_GENERICATTRIBUTEHEAD);

        //Add our tokens
        this->self = specAttributeHead | callbackAttributeHead | genericAttributeHead |

                     characterLiteral | explicitRadixLiteral | floatLiteral | decimalLiteral | stringLiteral | 
                     
                     leftParen | rightParen | comma | arrow | ruleSeparator | leftCurlyBracket | rightCurlyBracket | leftBracket | rightBracket | 
                     bitstringHead | bitstringTail | bar | doubleBar | semiColon | colon | forwardSlash | hash | typeSeparator | typeValueRange | unspecifiedType |
                     dotTerminator | dotTerminatorAtEOI | dot | 

                     keywordAfter | keywordBegin  | keywordCase | keywordTry | keywordCatch | keywordEnd | keywordFun | keywordIf | keywordOf | 
                     keywordReceive | keywordWhen | keywordAndAlso | keywordOrElse | keywordQuery |

                     operatorBNOT | operatorNOT | operatorMultiply | operatorIntDivide | operatorRemainder | operatorBAND | operatorAND | 
                     operatorListConcat | operatorListSubtract | operatorPlus | operatorMinus | operatorBOR | operatorBXOR | operatorBSL | 
                     operatorBSR | operatorOR | operatorXOR | operatorEqualTo | operatorNotEqualTo | operatorLessThanEqual |operatorLessThan | 
                     operatorGreaterThanEqual | operatorGreaterThan | operatorIdenticalTo | operatorNotIdenticalTo | operatorGenerate | operatorBitGenerate |
                     operatorSend | operatorMatch | 
                     
                     universalPattern | atom  | comment | variable;

        //ignore whitespace
        this->self += Token(L"[ \\t\\r\\n]+") [lex::_pass = lex::pass_flags::pass_ignore];
    }

    //TODO: Move to lex::char_ and lex::string since I am not exposing attributes, trying to do that gives me complaints about not being able to use
    //boost::spirit::string (though lex should be an alias for boost::spirit::lex so it seems lex::string should be equivalent to boost::spirit::lex::string,
    //but even the fully qualified name isn't working).

    Token leftParen;
    Token rightParen;
    Token leftBracket;
    Token rightBracket;
    Token leftCurlyBracket;
    Token rightCurlyBracket;
    Token forwardSlash;
    Token typeSeparator;
    Token colon;
    Token semiColon;
    Token comma;
    Token questionMark;
    Token arrow;
    Token ruleSeparator;
    Token doubleBar;
    Token bar;
    Token hash;    
    Token universalPattern;
    Token typeValueRange;
    Token unspecifiedType;
    Token dot;
    Token dotTerminator;
    Token dotTerminatorAtEOI;
    Token bitstringHead;
    Token bitstringTail;

    Token keywordAfter;
    Token keywordBegin;
    Token keywordCase;
    Token keywordTry;
    Token keywordCatch;
    Token keywordEnd;
    Token keywordFun;
    Token keywordIf;
    Token keywordOf;
    Token keywordReceive;
    Token keywordWhen;
    Token keywordAndAlso;
    Token keywordOrElse;
    Token keywordQuery;

    Token operatorListConcat;
    Token operatorListSubtract;
    Token operatorPlus;
    Token operatorMinus;
    Token operatorMultiply;
    Token operatorIntDivide;
    Token operatorRemainder;
    Token operatorOR;
    Token operatorXOR;
    Token operatorBOR;
    Token operatorBXOR;
    Token operatorBSL;
    Token operatorBSR;
    Token operatorAND;
    Token operatorBAND;
    Token operatorEqualTo;
    Token operatorNotEqualTo;
    Token operatorIdenticalTo;
    Token operatorNotIdenticalTo;
    Token operatorLessThan;
    Token operatorLessThanEqual;
    Token operatorGreaterThan;
    Token operatorGreaterThanEqual;
    Token operatorNOT;
    Token operatorBNOT;
    Token operatorMatch;
    Token operatorSend;
    Token operatorGenerate;
    Token operatorBitGenerate;

    Token characterLiteral;
    Token floatLiteral;
    Token decimalLiteral;
    Token explicitRadixLiteral;
    Token stringLiteral;
    Token atom;
    Token comment;
    Token variable;

    Token specAttributeHead;
    Token callbackAttributeHead;
    Token genericAttributeHead;
};
