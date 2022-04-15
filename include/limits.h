// Dummy "limits.h" file.
//
// The gcc "include-fixed" limits.h file tries to include the system limits.h file, after setting
// up a few definitions itself. We want the values it does define, but we don't want to include
// the system limits.h file.
//
// Here, we define _LIBC_LIMITS_H_, to prevent pulling in the system libc limits.h

#ifndef LIBBMCXX_LIMITS_H_INCLUDED
#define LIBBMCXX_LIMITS_H_INCLUDED 1

#define _LIBC_LIMITS_H_ 1

#include_next "limits.h"

/* empty, at least for now */

#endif
