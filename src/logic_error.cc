#include <stdexcept>
#include <string_view>
#include <memory>

namespace std {

logic_error::logic_error(const char *what_arg)
{
    what_ptr = make_shared<char[]>(string_view(what_arg).length() + 1);
}

} // namespace std
