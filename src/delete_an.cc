#include <cstdlib>
#include <new>

// delete: array non-throwing

void operator delete[](void *addr, const std::nothrow_t &) noexcept
{
    operator delete[](addr);
}
