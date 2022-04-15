#include <cstdlib>
#include <new>

#include <bmcxx_config.h>

// new: array no-throw

void *operator new[](size_t sz, const std::nothrow_t &) noexcept
{
    // Yes, this is stupid. C++ requires that nothrow new is implemented in terms of regular new,
    // though, and presumably the same is true for array-new.
#if !BMCXX_DISABLE_EXCEPTIONS
    try {
        return operator new[](sz);
    }
    catch (std::bad_alloc &e) {
        return nullptr;
    }
#else
    return operator new[](sz);
#endif
}
