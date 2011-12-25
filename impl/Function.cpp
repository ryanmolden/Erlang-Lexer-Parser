#include "StdAfx.h"
#include <boost/spirit/include/lex_lexertl.hpp>
#include "Function_def.h"
#include "ErlangLexer.h"
#include "CommentSkipper.h"

namespace lex = boost::spirit::lex;

typedef lex::lexertl::token<const wchar_t*> TokenType;
typedef ErlangLexer<lex::lexertl::actor_lexer<TokenType>> LexerType;
typedef LexerType::iterator_type LexerIteratorType;
typedef CommentSkipper<LexerIteratorType, typename LexerType::Token> CommentSkipperType;

//Force an instantiation of the ErlangFunction class so the ctor is generated.
template struct ErlangFunction<LexerIteratorType, LexerType, CommentSkipperType>;
