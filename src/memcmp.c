// Hook to cause memcmp (which is inline) to be emitted:
#define __BMCXX_MEMCMP_USED __attribute__((used))

#include <string.h>
