#ifndef ERLANGPARSER_21DD23C1
#define ERLANGPARSER_21DD23C1

#include <boost/spirit/include/qi.hpp>
#include "ErlangLexer.h"
#include <string>
#include "Terminals.h"
#include "Expression.h"
#include "Attribute.h"
#include "Rule.h"
#include "Function.h"
#include "CommentSkipper.h"

//Add helpers to the traits namespace that will dump our tokens to wcout properly for the debug stuff. Can't change the DEBUG_OUT stream in 
//spirit to be wcout as the simple trace stuff doesn't output wide strings.
namespace boost { namespace spirit { namespace traits
{
    typedef boost::spirit::lex::lexertl::token<wchar_t const *,boost::mpl::vector0<boost::mpl::na>,boost::mpl::bool_<1>,unsigned int> MyTokenType;

    template <typename Out>
    inline void print_token(Out& out, MyTokenType const& val)
    {
        std::wcout << std::wstring(val.value().begin(), val.value().end());
    }

    typedef boost::fusion::cons<std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > &,boost::fusion::nil> MyAttributeType;
    template <typename Out>
    inline void print_attribute(Out& out, const MyAttributeType& val)
    {
        std::wcout << std::wstring(val.car);
    }
}}}

namespace qi = boost::spirit::qi;

template <typename Iterator, typename Lexer>
struct ErlangParser : qi::grammar<Iterator, std::vector<std::wstring>(), CommentSkipper<Iterator, typename Lexer::Token>>
{
    typedef CommentSkipper<Iterator, typename Lexer::Token> CommentSkipperType;

    ErlangParser(Lexer const& lexer) : ErlangParser::base_type(m_root),
                                       m_terminals(lexer),
                                       m_expression(lexer, m_terminals),
                                       m_attribute(lexer, m_terminals, m_expression),
                                       m_rule(lexer, m_terminals, m_expression),
                                       m_function(lexer, m_terminals, m_expression),
                                       m_lexer(lexer) 
    {
        //form -> attribute dot
        //form -> function dot
        //form -> rule dot
        m_form = qi::hold[m_attribute >> (m_lexer.dotTerminator | m_lexer.dotTerminatorAtEOI)] |
                 qi::hold[m_function >> (m_lexer.dotTerminator | m_lexer.dotTerminatorAtEOI)]  |
                 m_rule >> (m_lexer.dotTerminator | m_lexer.dotTerminatorAtEOI);

        m_root = +m_form;

        #pragma region Debug Support

        BOOST_SPIRIT_DEBUG_NODES(
            (m_root)
            (m_form)
        );

        //debug(m_root);
        //debug(m_form);

        #pragma endregion
    }

private:
    const Lexer& m_lexer;
    ErlangTerminals<Iterator, Lexer, CommentSkipperType> m_terminals;
    ErlangExpression<Iterator, Lexer, CommentSkipperType> m_expression;
    ErlangAttribute<Iterator, Lexer, CommentSkipperType> m_attribute;
    ErlangRule<Iterator, Lexer, CommentSkipperType> m_rule;
    ErlangFunction<Iterator, Lexer, CommentSkipperType> m_function;

    qi::rule<Iterator, std::wstring(), CommentSkipperType> m_form;
    qi::rule<Iterator, std::vector<std::wstring>(), CommentSkipperType> m_root;
};

#endif