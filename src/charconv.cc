#include <charconv>
#include <limits>
#include <system_error>

namespace std {

from_chars_result from_chars(const char *first, const char *last, unsigned &value, int base)
{
    unsigned pval = 0;
    const char *dig = first;

    // penultimate digit limit, i.e. what is the value beyond which there can be no more digits
    unsigned pen_limit = numeric_limits<unsigned>::max() / base;

    bool out_of_range = false;

    while (dig != last) {
        unsigned digit_val;
        if (base <= 10 || *dig <= '9') {
            if (*dig >= '0' && *dig < ('0' + base)) {
                digit_val = *dig - '0';
            }
            else break;
        }
        else {
            if (*dig >= 'a' && *dig < ('a' + base - 10)) {
                digit_val = 10 + (*dig - 'a');
            }
            else if (*dig >= 'A' && *dig < ('A' + base - 10)) {
                digit_val = 10 + (*dig - 'A');
            }
            else break;
        }

        if (pval > pen_limit) {
            out_of_range = true;
        }

        if (!out_of_range) {
            pval *= base;
            if (pval > (numeric_limits<unsigned>::max() - digit_val)) {
                out_of_range = true;
            }
            else {
                pval += digit_val;
            }
        }

        dig++;
    }

    if (out_of_range) {
        return { dig, errc::result_out_of_range };
    }

    if (dig == first) {
        return { dig, errc::invalid_argument };
    }

    value = pval;
    return { dig, errc{} };
}

} // std
