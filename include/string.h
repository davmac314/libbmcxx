#ifndef _BMCXX_STRING_H_INCLUDED
#define _BMCXX_STRING_H_INCLUDED 1

// This implements various functions (memcpy etc) as inlines. To also generate non-inline
// instantiations a trick is used; the relevant source file (see eg memcpy.c) sets a macro for the
// relevant function (eg __BMCXX_MEMCPY_EMIT), which inhibits the declaration being marked as
// "extern" in this header. Since __attribute__((gnu_inline)) is applied, lack of "extern" causes
// a function body to be emitted.

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


// memcpy

#ifndef __BMCXX_MEMCPY_EMIT
#define __BMCXX_MEMCPY_EMIT extern
#endif

__BMCXX_NOTHROW_ATTR
__attribute__((gnu_inline)) __BMCXX_MEMCPY_EMIT
inline void *memcpy(void * __restrict dest, const void * __restrict src, size_t size) __BMCXX_NOEXCEPT
{
    char *destc = (char *)dest;
    char *srcc = (char *)src;
    for(size_t i = 0; i < size; i++) {
        destc[i] = srcc[i];
    }
    return dest;
}

#undef __BMCXX_MEMCPY_EMIT

// memmove

#ifndef __BMCXX_MEMMOVE_EMIT
#define __BMCXX_MEMMOVE_EMIT extern
#endif

__BMCXX_NOTHROW_ATTR
__attribute__((gnu_inline)) __BMCXX_MEMMOVE_EMIT
inline void *memmove(void * dest, const void * src, size_t size) __BMCXX_NOEXCEPT
{
    char *destc = (char *)dest;
    char *srcc = (char *)src;
    for(size_t i = 0; i < size; i++) {
        destc[i] = srcc[i];
    }
    return dest;
}

#undef __BMCXX_MEMMOVE_EMIT

// memset

#ifndef __BMCXX_MEMSET_EMIT
#define __BMCXX_MEMSET_EMIT extern
#endif

__BMCXX_NOTHROW_ATTR
__attribute__((gnu_inline)) __BMCXX_MEMSET_EMIT
inline void *memset(void *s, int c, size_t n)
{
    char *s_c = (char *)s;
    for(size_t i = 0; i < n; i++) {
        s_c[i] = c;
    }
    return s;
}

#undef __BMCXX_MEMSET_EMIT

// memcmp

#ifndef __BMCXX_MEMCMP_EMIT
#define __BMCXX_MEMCMP_EMIT extern
#endif

__BMCXX_NOTHROW_ATTR
__attribute__((gnu_inline)) __BMCXX_MEMCMP_EMIT
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

#undef __BMCXX_MEMCMP_EMIT

// stpcpy

#ifndef __BMCXX_STPCPY_EMIT
#define __BMCXX_STPCPY_EMIT extern
#endif

__BMCXX_NOTHROW_ATTR
__attribute__((gnu_inline)) __BMCXX_STPCPY_EMIT
inline char *stpcpy(char * __restrict dest, const char * __restrict src)
{
    while (*src != 0) {
        *dest = *src;
        ++src; ++dest;
    }
    *dest = *src;
    return dest;
}

#undef __BMCXX_STPCPY_EMIT

// strcpy

#ifndef __BMCXX_STRCPY_EMIT
#define __BMCXX_STRCPY_EMIT extern
#endif

__BMCXX_NOTHROW_ATTR
__attribute__((gnu_inline)) __BMCXX_STRCPY_EMIT
inline char *strcpy(char * __restrict dest, const char * __restrict src)
{
    stpcpy(dest, src);
    return dest;
}

#undef __BMCXX_STRCPY_EMIT

// strncpy

#ifndef __BMCXX_STRNCPY_EMIT
#define __BMCXX_STRNCPY_EMIT extern
#endif

__BMCXX_NOTHROW_ATTR
__attribute__((gnu_inline)) __BMCXX_STRNCPY_EMIT
inline char *strncpy(char * __restrict dest, const char * __restrict src, size_t size)
{
    size_t i = 0;
    while (i < size) {
        if (src[i] == 0) break;
        dest[i] = src[i];
        ++i;
    }

    while (i < size) {
        dest[i] = 0;
        ++i;
    }

    return dest;
}

#undef __BMCXX_STRCPY_EMIT

// strcmp

#ifndef __BMCXX_STRCMP_EMIT
#define __BMCXX_STRCMP_EMIT extern
#endif

__BMCXX_NOTHROW_ATTR
__attribute__((gnu_inline)) __BMCXX_STRCMP_EMIT
inline int strcmp(const char *s1, const char *s2)
{
    while (*s1 != 0) {
        if (*s1 != *s2) {
            return (int)(unsigned char)(*s1) - (int)(unsigned char)(*s2);
        }
        ++s1; ++s2;
    }

    // Return a positive value since s2 > s1
    return (int)(unsigned char)*s2;
}

#undef __BMCXX_STRCMP_EMIT

// strncmp

#ifndef __BMCXX_STRNCMP_EMIT
#define __BMCXX_STRNCMP_EMIT extern
#endif

__BMCXX_NOTHROW_ATTR
__attribute__((gnu_inline)) __BMCXX_STRNCMP_EMIT
inline int strncmp(const char *s1, const char *s2, size_t n)
{
    while (n > 0 && *s1 != 0) {
        if (*s1 != *s2) {
            return (int)(unsigned char)(*s1) - (int)(unsigned char)(*s2);
        }
        ++s1; ++s2; --n;
    }

    if (n == 0) return 0;

    // Return a positive value since s2 > s1
    return (int)(unsigned char)*s2;
}

#undef __BMCXX_STRCMP_EMIT

// strlen

#ifndef __BMCXX_STRLEN_EMIT
#define __BMCXX_STRLEN_EMIT extern
#endif

__BMCXX_NOTHROW_ATTR
__attribute__((gnu_inline)) __BMCXX_STRLEN_EMIT
inline size_t strlen(const char *str)
{
    size_t l = 0;
    while (str[l] != 0) {
        ++l;
    }
    return l;
}

#undef __BMCXX_STRLEN_EMIT

// strcat

#ifndef __BMCXX_STRCAT_EMIT
#define __BMCXX_STRCAT_EMIT extern
#endif

__BMCXX_NOTHROW_ATTR
__attribute__((gnu_inline)) __BMCXX_STRCAT_EMIT
inline char *strcat(char * __restrict dest, const char * __restrict src)
{
    size_t dstlen = strlen(dest);
    return strcpy(dest + dstlen, src);
}

#undef __BMCXX_STRLEN_EMIT

#ifdef __cplusplus
} // extern "C"
#endif

#undef __BMCXX_NOEXCEPT
#undef __BMCXX_NOTHROW_ATTR

#endif /* _BMCXX_STRING_H_INCLUDED */
