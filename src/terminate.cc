#include <exception>
#include <stdlib.h>

namespace std {

[[noreturn]]
void terminate() noexcept
{
    abort();
}

}
