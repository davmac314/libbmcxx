#ifndef _BMCXX_CTYPE_H_INCLUDED
#define _BMCXX_CTYPE_H_INCLUDED 1

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __BMCXX_EMIT_CTYPE
#define __BMCXX_EMIT_CTYPE extern
#endif

__attribute__((gnu_inline))
__BMCXX_EMIT_CTYPE inline int toupper(int c)
{
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

__attribute__((gnu_inline))
__BMCXX_EMIT_CTYPE inline int tolower(int c)
{
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c;
}

__attribute__((gnu_inline))
__BMCXX_EMIT_CTYPE inline int isprint(int c)
{
    return c >= 32 && c < 127;
}

__attribute__((gnu_inline))
__BMCXX_EMIT_CTYPE inline int isxdigit(int c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

__attribute__((gnu_inline))
__BMCXX_EMIT_CTYPE inline int isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

__attribute__((gnu_inline))
__BMCXX_EMIT_CTYPE inline int isspace(int c)
{
    return c == ' ' || c == '\f' || c == '\r' || c == '\n' || c == '\t' || c == '\v';
}

#ifdef __cplusplus
}
#endif

#endif
