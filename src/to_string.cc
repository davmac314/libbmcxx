#include <string>
#include <limits>

namespace std {

string to_string(unsigned long val)
{
    string r;
    if (val == 0) {
        r += '0';
    }
    else {
        unsigned long dpos = 1;
        while (dpos < val) {
            if (dpos > numeric_limits<unsigned long>::max() / 10) break;
            dpos *= 10;
        }

        if (dpos > val) dpos /= 10;

        while (dpos > 0) {
            int digit_val = val / dpos;
            val -= (dpos * digit_val);
            dpos /= 10;

            r += (char)(digit_val + '0');
        }
    }
    return r;
}

}
