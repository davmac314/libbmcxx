#include <cstdlib>
#include <new>

// new: array

void *operator new[](size_t sz)
{
    void *r = malloc(sz);
    if (r == nullptr) {
        throw std::bad_alloc();
    }
    return r;
}
