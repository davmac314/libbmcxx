#include <cstdlib>
#include <new>

// new: array

void *operator new[](size_t sz)
{
    void *r = malloc(sz);
#ifdef __cpp_exceptions
    if (r == nullptr) {
        throw std::bad_alloc();
    }
    // (see notes in new_r/new_n)
#endif
    return r;
}
