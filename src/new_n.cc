#include <cstdlib>
#include <new>

// new: no-throw

void *operator new(size_t sz, const std::nothrow_t &) noexcept
{
    // Yes, this is stupid. C++ requires that nothrow new is implemented in terms of regular new,
    // though. :(

    try {
        return operator new(sz);
    }
    catch (std::bad_alloc &e) {
        return nullptr;
    }
}
