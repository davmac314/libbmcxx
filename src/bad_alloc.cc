#include <new>

namespace std {

const char *bad_alloc::what() const noexcept
{
    return "out of memory";
}

} // namespace std
