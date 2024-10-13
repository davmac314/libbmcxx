// Hook to cause strcpy (which is inline) to be emitted:
#define __BMCXX_STRLEN_EMIT

#include <string.h>
