// Hook to cause mempcy (which is inline) to be emitted:
#define __BMCXX_MEMCPY_USED __attribute__((used))

#include <string.h>
