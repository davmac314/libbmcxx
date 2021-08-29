#include <cstdlib>
#include <new>

// new: array no-throw

void *operator new[](size_t sz, const std::nothrow_t &) noexcept
{
    return malloc(sz);
}
