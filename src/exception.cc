#include <exception>

namespace std {

exception::~exception() { }

const char *exception::what() const noexcept
{
    return "unspecified exception";
}

} // namespace std
