#ifndef _BMCXX_ASSERT_H_INCLUDED
#define _BMCXX_ASSERT_H_INCLUDED

#ifdef NDEBUG
#define assert(N) ((void)0)
#else
#define assert(N) { if(!(N)) __builtin_abort(); }
#endif

#endif // _BMCXX_ASSERT_H_INCLUDED
