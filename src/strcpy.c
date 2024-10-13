// Hook to cause strcpy (which is inline) to be emitted:
#define __BMCXX_STRCPY_EMIT

#include <string.h>
