#include <cstdlib>
#include <new>

// delete: array

void operator delete[](void *addr) noexcept
{
    operator delete(addr);
}
