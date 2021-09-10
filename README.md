# libbmcxx - bare metal C++ lib

Work-in-progress.

Provides various C++ (and C) standard library components that are suitable for bare metal
applications. Requires G++/Clang++.

Note: no floating-point support (yet; may be added as a configurable option later). No
thread support.

The intention is to provide a useful subset of the C++ standard library, eventually with
options for excluding exception-throwing code etc.

You may use and redistribute this code, in any form, without restriction.

Currently provides:
- C "string" functions: `memcpy`, `memset`
- various C++ header wrappers (`cstddef`, `cstdint`, etc)
- a usable (though not 100% complete) implementation of `unique_ptr` (via `memory`)
- `std::terminate` (calls `abort`)
- various standard new/delete overloads (which ultimately call `malloc`/`free`)
- at least some of `type_traits`, `limits`

Client application must provide:
- `abort()`
- `malloc()`/`free()`
- C++ ABI runtime support (see eg bmcxxabi, bmunwind)

TODO:
- optional thread support
- optional floating-point support
- optional heap allocator implementation
- make "assert" useful
- optional for non-replaceable versions of new/delete variants which act sensibly.
  (see for example nothrow new, which to be standard-conformant has to be implemented
  by calling the throwing new, and catching the exception, ugh).
