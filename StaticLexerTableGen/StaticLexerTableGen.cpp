//NOTE:  The static lexer generation that this program does requires patches to 
//boost\spirit\home\lex\lexer\lexertl\generate_static.hpp that do not exist in the
//actual boost release (I have reported the bug (https://svn.boost.org/trac/boost/ticket/6253) 
//the patches work around, but I don't beleive my patches are really boost quality, so 
//someone involved in the boost/spirit area should probably fix it 'the boost way'.  Contact 
//me if you need to build this file and thus need the hack patches I made for my own use.

#include "ErlangLexer.h"
#include <fstream>
#include <iostream>
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/lex_lexertl.hpp>
#include <boost/spirit/include/lex_generate_static_lexertl.hpp>
#include <boost/spirit/include/lex_static_lexertl.hpp>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout << "Usage:  StaticLexerTableGen <output file path>" << endl;
        return -1;
    }

    typedef lex::lexertl::token<const wchar_t*> token_type;
    typedef lex::lexertl::actor_lexer<token_type> lexer_type;

    // create the lexer object instance needed to invoke the generator
    ErlangLexer<lexer_type> lexer;

    // open the output file, where the generated tokenizer function will be 
    // written to
    string targetFilename(argv[1]);
    ofstream outputStream(targetFilename);

    // invoke the generator, passing the token definition, the output stream 
    // and the name suffix of the tables and functions to be generated
    //
    // The suffix "erlang" used below results in a type lexertl::static_::lexer_erlang
    // to be generated, which needs to be passed as a template parameter to the 
    // lexertl::static_lexer template.
    return (lex::lexertl::generate_static_dfa(lexer, outputStream, "erlang") ? 0 : 1);
}