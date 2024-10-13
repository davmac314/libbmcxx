// Hook to cause strncpy (which is inline) to be emitted:
#define __BMCXX_STRNCPY_EMIT

#include <string.h>
