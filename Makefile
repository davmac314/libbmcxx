# Variables, which can be set on command line or here:
#
# OUTDIR
#   Where the resulting library, libbmcxx.a, should be placed
#
# CPPFLAGS
#   Preprocessor options for C. Generally should *not* include -nostdinc, as the compiler-provided
#   headers should be available (unless suitable replacements are provided).
#
# CXXPPFLAGS
#   Preprocessor options for C++; should generally include "-nostdinc++".
#
# CFLAGS
#   C compilation options. Should include necessary architectural options. For x86-64, probably
#   should include "-march=x86-64 -mno-sse -mno-red-zone". Should disable any features which may
#   require additional runtime support.
#
# CXXFLAGS
#   C++ compilation options. As for CFLAGS.
#
# CC
#   The c compiler, eg gcc/clang.
#
# CXX
#   The c++ compiler, eg g++/clang++.
#
# AR
#   The "ar" (archive) utility, eg ar.
#
# Eg values:
# CXXPPFLAGS=-nostdinc++
# CXXFLAGS=-g -march=x86-64 -mno-sse -mno-red-zone -ffreestanding -fno-stack-protector

export OUTDIR CPPFLAGS CXXPPFLAGS CFLAGS CXXFLAGS CC CXX AR

all:
	$(MAKE) -C src all

clean:
	$(MAKE) -C src clean
