#include "StdAfx.h"
#include "Expression_def.h"

namespace lex = boost::spirit::lex;

typedef lex::lexertl::token<const wchar_t*> TokenType;
typedef ErlangLexer<lex::lexertl::actor_lexer<TokenType>> LexerType;
typedef LexerType::iterator_type LexerIteratorType;
typedef CommentSkipper<LexerIteratorType, typename LexerType::Token> CommentSkipperType;

//Force an instantiation of the ErlangTerminals class so the ctor is processed.
template struct ErlangExpression<LexerIteratorType, LexerType, CommentSkipperType>;