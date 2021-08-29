// Hook to cause mempcy (which is inline) to be emitted:
#define __BMCXX_MEMSET_USED __attribute__((used))

#include <string.h>
