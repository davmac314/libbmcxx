// Hook to cause memmove (which is inline) to be emitted:
#define __BMCXX_MEMMOVE_EMIT

#include <string.h>
