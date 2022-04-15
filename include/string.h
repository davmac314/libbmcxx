#ifndef _BMCXX_STRING_H_INCLUDED
#define _BMCXX_STRING_H_INCLUDED 1

// This implements various functions as inlines. To also generate non-inline instantiations a
// trick is used; the relevant source file (see eg memcpy.c) sets a macro for the relevant
// function (eg __BMCXX_MEMCPY_USED) to an attribute which will force generation
// ("__attribute__((used))").

// Use undocumented GCC magic for size_t
#define __need_size_t 1
#include "stddef.h"
#undef __need_size_t

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
#define __BMCXX_NOEXCEPT noexcept
#define __BMCXX_NOTHROW_ATTR
#else
#define __BMCXX_NOEXCEPT
#define __BMCXX_NOTHROW_ATTR __attribute__((nothrow))
#endif

// Attributes to prevent compiler from generating calls to the same function
// we are trying to define:
#if defined(__clang__)
#define __BMCXX_MEMOP_ATTRIBUTE __attribute__((no_builtin))
#elif defined(__GNUC__)
#define __BMCXX_MEMOP_ATTRIBUTE __attribute__((optimize("3,no-tree-loop-distribute-patterns")))
#endif

#ifndef __BMCXX_MEMCPY_USED
#define __BMCXX_MEMCPY_USED
#endif

__BMCXX_MEMOP_ATTRIBUTE __BMCXX_MEMCPY_USED __BMCXX_NOTHROW_ATTR
inline void *memcpy(void * __restrict dest, const void * __restrict src, size_t size) __BMCXX_NOEXCEPT
{
    char *destc = (char *)dest;
    char *srcc = (char *)src;
    for(size_t i = 0; i < size; i++) {
        destc[i] = srcc[i];
    }
    return dest;
}

#undef __BMCXX_MEMCPY_USED

#ifndef __BMCXX_MEMMOVE_USED
#define __BMCXX_MEMMOVE_USED
#endif

__BMCXX_MEMOP_ATTRIBUTE __BMCXX_MEMMOVE_USED __BMCXX_NOTHROW_ATTR
inline void *memmove(void * __restrict dest, const void * __restrict src, size_t size) __BMCXX_NOEXCEPT
{
    char *destc = (char *)dest;
    char *srcc = (char *)src;
    for(size_t i = 0; i < size; i++) {
        destc[i] = srcc[i];
    }
    return dest;
}

#undef __BMCXX_MEMMOVE_USED

#ifndef __BMCXX_MEMSET_USED
#define __BMCXX_MEMSET_USED
#endif

__BMCXX_MEMOP_ATTRIBUTE __BMCXX_MEMSET_USED
inline void *memset(void *s, int c, size_t n)
{
    char *s_c = (char *)s;
    for(size_t i = 0; i < n; i++) {
        s_c[i] = c;
    }
    return s;
}

#ifndef __BMCXX_MEMCMP_USED
#define __BMCXX_MEMCMP_USED
#endif

__BMCXX_MEMOP_ATTRIBUTE __BMCXX_MEMCMP_USED __BMCXX_NOTHROW_ATTR
inline int memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *s1c = (const unsigned char *)s1;
    const unsigned char *s2c = (const unsigned char *)s2;
    for (size_t i = 0; i < n; i++) {
        int diff = s1c[i] - s2c[i];
        if (diff != 0) {
            return diff;
        }
    }
    return 0;
}

#undef __BMCXX_MEMCMP_USED

#ifdef __cplusplus
} // extern "C"
#endif

#undef __BMCXX_MEMSET_USED

#undef __BMCXX_NOEXCEPT
#undef __BMCXX_NOTHROW_ATTR

#endif /* _BMCXX_STRING_H_INCLUDED */
