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

#ifndef _STLP_FSTREAM_H
# define _STLP_FSTREAM_H

# ifndef _STLP_OUTERMOST_HEADER_ID
#  define _STLP_OUTERMOST_HEADER_ID 0x2026
#  include <stl/_prolog.h>
# endif

# if defined (_STLP_OWN_IOSTREAMS)
#ifdef __BORLANDC__
#  include <fstream.>
#else
#  include <fstream>
#endif
// get desired pollution
#  include <iostream.h>

# ifndef __LOCALE_INITIALIZED
#  define __LOCALE_INITIALIZED
// Global initializer object, to ensure initialization of locale subsystem.
static ios_base::_Loc_init _LocInit;
# endif

#  ifndef _STLP_HAS_NO_NAMESPACES
#   include <using/fstream>
#  endif

# elif ! defined (_STLP_USE_NO_IOSTREAMS)
# include <wrap_std/h/fstream.h>
# endif

# if (_STLP_OUTERMOST_HEADER_ID == 0x2026)
#  include <stl/_epilog.h>
#  undef _STLP_OUTERMOST_HEADER_ID
# endif

#endif /* _STLP_FSTREAM_H */

// Local Variables:
// mode:C++
// End:

