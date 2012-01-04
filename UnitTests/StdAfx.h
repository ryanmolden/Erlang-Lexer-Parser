#ifndef STDAFX_21DD23C1
#define STDAFX_21DD23C1

#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "ErlangTokens.h"
#include "ErlangLexer.h"
#include "ErlangParser.h"
#include "TestUtil.h"
#include <boost/spirit/include/lex_lexertl.hpp>
#include "CommentSkipper.h"

//Some handy stuff not generally defined on linux
#if !defined(UNALIGNED)
#if defined(_MSC_VER) && (defined(_M_IA64) || defined(_M_AMD64))
#define UNALIGNED __unaligned
#else
#define UNALIGNED
#endif
#endif

/* _countof helper */
#if !defined(_countof)
#if !defined(__cplusplus)
#define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))
#else
extern "C++"
{
    template <typename _CountofType, size_t _SizeOfArray>
    char (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];

    #define _countof(_Array) (sizeof(*__countof_helper(_Array)) + 0)
}
#endif
#endif

#endif