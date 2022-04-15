// This file contains configuration for libbmcxx. It can be edited in place, or supplanted by
// another version earlier on the include path (provided by the client application).

// Whether to enable exceptions. If exceptions are disabled, no libbmcxx code will use "throw" or
// "try"/"catch". In general, where an exception would normally be thrown, "terminate" will be
// called instead.
#define BMCXX_ENABLE_EXCEPTIONS 1
