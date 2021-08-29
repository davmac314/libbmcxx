#ifndef _BMCXX_STDLIB_H_INCLUDED
#define _BMCXX_STDLIB_H_INCLUDED

// Use undocumented GCC magic for size_t
#define __need_size_t 1
#include "stddef.h"
#undef __need_size_t

#ifdef __cplusplus
extern "C" {
#endif

__attribute__((noreturn,nothrow))
void abort(void);

__attribute__((nothrow,malloc))
void *malloc(size_t size);

void free(void *ptr);

#ifdef __cplusplus
}
#endif

#endif
