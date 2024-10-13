// Hook to cause strcmp (which is inline) to be emitted:
#define __BMCXX_STRNCMP_EMIT

#include <string.h>
