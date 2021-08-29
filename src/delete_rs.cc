#include <cstdlib>
#include <new>

// delete: regular sized

void operator delete(void *addr, size_t sz) noexcept
{
    operator delete(addr);
}
