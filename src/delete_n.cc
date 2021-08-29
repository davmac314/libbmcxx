#include <cstdlib>
#include <new>

// delete: non-throwing

void operator delete(void *addr, const std::nothrow_t &) noexcept
{
    operator delete(addr);
}
