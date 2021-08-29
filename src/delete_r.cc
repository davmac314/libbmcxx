#include <cstdlib>
#include <new>

// delete: regular

void operator delete(void *addr) noexcept
{
    if (addr != nullptr) {
        free(addr);
    }
}
