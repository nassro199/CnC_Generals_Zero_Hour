/*
 * Copyright (c) 1999 
 * Boris Fomitchev
 *
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 *
 * Permission to use or copy this software for any purpose is hereby granted 
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */

#ifdef _STLP_USE_PRAGMA_ONCE
#pragma once	// JKMCD should speed up compile times.
#endif

# if !defined (_STLP_OUTERMOST_HEADER_ID)
#  define _STLP_OUTERMOST_HEADER_ID 0x256
#  include <stl/_prolog.h>
# elif (_STLP_OUTERMOST_HEADER_ID == 0x256) && ! defined (_STLP_DONT_POP_0x256)
#  define _STLP_DONT_POP_0x256
# endif


# ifndef setjmp
#  include _STLP_NATIVE_C_HEADER(setjmp.h)
# endif

# if (_STLP_OUTERMOST_HEADER_ID == 0x256)
#  if ! defined (_STLP_DONT_POP_0x256)
#   include <stl/_epilog.h>
#   undef  _STLP_OUTERMOST_HEADER_ID
#   endif
#   undef  _STLP_DONT_POP_0x256
# endif

// Local Variables:
// mode:C++
// End:
