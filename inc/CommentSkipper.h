#ifndef COMMENTSKIPPER_21DD23C1
#define COMMENTSKIPPER_21DD23C1

#include <boost/spirit/include/qi.hpp>

template <typename Iterator, typename CommentTokenType>
struct CommentSkipper : qi::grammar<Iterator>
{
    CommentSkipper(const CommentTokenType& commentToken) : CommentSkipper::base_type(m_root)
    {
        m_root = commentToken;
    }

private:
    qi::rule<Iterator> m_root;
};

#endif