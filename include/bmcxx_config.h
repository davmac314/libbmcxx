// This file contains configuration for libbmcxx. It can be edited in place, or supplanted by
// another version earlier on the include path (provided by the client application).

#ifndef BMCXX_CONFIG_H_INCLUDED
#define BMCXX_CONFIG_H_INCLUDED 1

// Whether to enable exceptions. If exceptions are disabled, no libbmcxx code will use "throw" or
// "try"/"catch". In general, where an exception would normally be thrown, "terminate" will be
// called instead.

// #define BMCXX_DISABLE_EXCEPTIONS 1


// Whether to disable support for floating point. If disabled, functions returning floating-point
// values or taking them as arguments will be unavailable.

// #define BMCXX_DISABLE_FLOAT 1

#endif
