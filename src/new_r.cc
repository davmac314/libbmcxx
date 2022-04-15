#include <cstdlib>
#include <new>

#include <bmcxx_config.h>

// new: regular

void *operator new(size_t sz)
{
    void *r = malloc(sz);
#if !BMCXX_DISABLE_EXCEPTIONS
    if (r == nullptr) {
        throw std::bad_alloc();
    }
    // if exceptions are disabled it seems like we should abort() on failure, but that would
    // actually break new(nothrow) since that must call this. Instead we offer the semantics
    // that new() returns nullptr on failure, just as new(nothrow) does.
#endif
    return r;
}
