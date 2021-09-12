# libbmcxx - bare metal C++ lib

Work-in-progress.

Provides various C++ (and C) standard library components that are suitable for bare metal
applications. Requires G++/Clang++, and uses the C headers provided by the compiler
(in `-ffreestanding` mode).

Note: no floating-point support or thread support (yet; both may be added as options later).

The intention is to provide a useful subset of the C++ standard library, eventually with
options for excluding exception-throwing code etc.

You may use and redistribute this code, in any form, without restriction.

Currently provides (at least partial implementations of):
- C "string" functions: `memcpy`, `memset`
- various C++ header wrappers (`cstddef`, `cstdint`, etc)
- `string_view` and variants
- `unique_ptr` and `shared_ptr`
- `terminate()` (calls `abort`)
- various standard new/delete overloads (which ultimately call `malloc`/`free`)
- some of `type_traits`, `limits`
- some standard exception types via `exception`, `stdexcept`
- very little of `algorithm`

Client application must provide:
- `abort()`
- `malloc()`/`free()`
- C++ ABI runtime support (see eg bmcxxabi, bmunwind)

TODO:
- optional thread support
- optional floating-point support
- optional heap allocator implementation (i.e. implementation of malloc/free etc)
- custom allocator support for collections/strings
- make "assert" useful
- option for non-replaceable versions of new/delete variants which act sensibly.
  (see for example nothrow new, which to be standard-conformant has to be implemented
  by calling the throwing new, and catching the exception, ugh).
