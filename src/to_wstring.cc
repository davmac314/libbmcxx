#include <string>
#include <limits>

namespace std {

wstring to_wstring(unsigned long val)
{
    wstring r;
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

            r += (wchar_t)(digit_val + L'0');
        }
    }
    return r;
}

}
