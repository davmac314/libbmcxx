#ifndef LIBBMCXX_CHAR_TRAITS_INCLUDED
#define LIBBMCXX_CHAR_TRAITS_INCLUDED 1

#include <cstring>

namespace std {

using size_t = decltype(sizeof(0));

template <class CharT>
struct __bmcxx_char_traits_ops
{
    using char_type = CharT;

    static constexpr void assign(char_type &r, const char_type &a) noexcept { r = a; }
    static constexpr void assign(char_type *p, size_t count, const char_type &a) noexcept
    {
        for (size_t i = 0; i < count; i++) {
            p[i] = a;
        }
    }

    static constexpr bool eq(char_type a, char_type b) noexcept { return a == b; }
    static constexpr bool lt(char_type a, char_type b) noexcept { return a < b; }

    static char_type *copy(char_type *dest, const char_type *src, size_t count) noexcept
    {
        memcpy(dest, src, count * sizeof(char_type));
    }

    static constexpr size_t length(const char_type *s)
    {
        size_t i = 0;
        for ( ; s[i] != 0; i++) ;
        return i;
    }

    static constexpr int compare(const char_type *s1, const char_type *s2, size_t count)
    {
        for (size_t i = 0; i < count; i++) {
            if (lt(s1[i], s2[i])) return -1;
            if (lt(s2[i], s1[i])) return 1;
        }
        return 0;
    }
};

template <class CharT>
class char_traits : public __bmcxx_char_traits_ops<CharT> { };

template <>
class char_traits<char> : public __bmcxx_char_traits_ops<char>
{
public:
    using int_type = int;
    using pos_type = size_t;

    static constexpr bool eq(char_type a, char_type b) noexcept { return (unsigned char)a == (unsigned char)b; }
    static constexpr bool lt(char_type a, char_type b) noexcept { return (unsigned char)a < (unsigned char)b; }
};

}

#endif
