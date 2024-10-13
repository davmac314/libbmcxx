// Hook to cause stpcpy (which is inline) to be emitted:
#define __BMCXX_STPCPY_EMIT

#include <string.h>
