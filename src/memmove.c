// Hook to cause memmove (which is inline) to be emitted:
#define __BMCXX_MEMMOVE_USED __attribute__((used))

#include <string.h>
