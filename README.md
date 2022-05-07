# libbmcxx - bare metal C++ lib

Work-in-progress.

*You may use and redistribute this code, in any form, without restriction.* There is no warranty
expressed or implied.

*Testing has been minimal. Use at your own risk*.

Provides various C++ (and C) standard library components that are suitable for bare metal
applications. Requires G++/Clang++ or something very compatible, and uses the C headers provided
by the compiler (in `-ffreestanding` mode). Aims roughly for C++14 (but with a bit of later
standards thrown in for good measure too).

Note: no floating-point support or thread support (yet; both may be added as options later).

The intention is to provide a useful subset of the C++ standard library, with various options
useful for bare metal including exception-less mode and float-less mode.


Currently provides (at least partial implementations of):
- C "string" functions: `memcpy`, `memset`, `memmove`, `memcmp`
- various C++ wrapper headers (`cstddef`, `cstdint`, etc)
- `string_view` and variants, `string` and variants (rudimentary)
- `vector` (rudimentary)
- `unique_ptr` and `shared_ptr`
- `pair` (but not yet `tuple`)
- `terminate()` (calls `abort`)
- a little bit of `atomic`
- various standard new/delete overloads (which ultimately call `malloc`/`free`)
- some of `type_traits`, `limits`
- some standard exception types via `exception`, `stdexcept`
- very little of `algorithm`

Client application must provide:
- `abort()`
- `malloc()`/`free()`
- C++ ABI runtime support (see eg bmcxxabi, bmunwind)


## Configuration

The "bmcxx_config.h" file contains configuration options for the library and can be edited or
supplanted by an alternative version earlier on the include path. Currently the supported options
are:

 * `BMCXX_DISABLE_EXCEPTIONS` - if defined true, will prevent exceptions from being thrown by the
   library.
   
   This is not implemented in all headers/functions. However with this set it should be possible
   to compile with `-fno-exceptions`, and in that case use of headers which throw exceptions
   should generate a compilation error.
   
   In general, where an exception would have been thrown, `std::terminate()` will be called
   instead. One exception is that calls to `new()` will return `nullptr` on failure (as if
   `new(nothrow)` had been used) rather than terminating. 

 * `BMCXX_DISABLE_FLOAT` - if defined true, floating-point functions (returning floating-point
   values or taking them as arguments) will be unavailable.
   
   This is currently a no-op since at present there are no such functions implemented anyway...


## TODO

- optional thread support
- optional floating-point support
- optional heap allocator implementation (i.e. implementation of malloc/free etc)
- custom allocator support for collections/strings
- make "assert" useful
- option for non-replaceable versions of new/delete variants which act sensibly.
  (see for example nothrow new, which to be standard-conformant has to be implemented
  by calling the throwing new, and catching the exception, ugh).
- audit use of new(), make sure to check result for nullptr if exceptions are disabled
