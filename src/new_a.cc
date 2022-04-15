#include <cstdlib>
#include <new>

#include <bmcxx_config.h>

// new: array

void *operator new[](size_t sz)
{
    void *r = malloc(sz);
#if !BMCXX_DISABLE_EXCEPTIONS
    if (r == nullptr) {
        throw std::bad_alloc();
    }
    // (see notes in new_r/new_n)
#endif
    return r;
}
