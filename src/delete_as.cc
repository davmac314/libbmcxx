#include <cstdlib>
#include <new>

// delete: array sized

void operator delete[](void *addr, size_t size) noexcept
{
    operator delete(addr);
}
