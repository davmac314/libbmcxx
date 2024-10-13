CXXOBJS=terminate.o new_r.o new_n.o new_a.o new_an.o delete_r.o delete_rs.o delete_n.o delete_a.o \
	delete_as.o delete_an.o exception.o bad_alloc.o logic_error.o to_string.o to_wstring.o \
	charconv.o
# compile with -fno-builtin, prevent self-calling implementations:
NB_COBJS=memcpy.o memset.o memmove.o memcmp.o stpcpy.o strcmp.o strncmp.o strlen.o strcat.o strncpy.o ctype.o

CXX ?= g++
CC ?= gcc

# default, should be overridden:
OUTDIR ::= .

LIBBMCXX_CPPFLAGS ::= -I../include

all: $(CXXOBJS) $(NB_COBJS)
	ar r $(OUTDIR)/libbmcxx.a $(CXXOBJS) $(NB_COBJS)

$(CXXOBJS): %.o: %.cc
	$(CXX) $(CXXPPFLAGS) $(LIBBMCXX_CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Note we compile string operations with -O3 as we generally want them fast even when otherwise
# compiling with a preference for size or debuggability etc. TODO: make configurable.
$(NB_COBJS): %.o: %.c
	$(CC) $(CPPFLAGS) $(LIBBMCXX_CPPFLAGS) $(CFLAGS) -O3 -fno-builtin -c $< -o $@

clean:
	rm -f $(COBJS) $(CXXOBJS) $(STRCPYOBJ)
