CXXOBJS=terminate.o new_r.o new_n.o new_a.o new_an.o delete_r.o delete_rs.o delete_n.o delete_a.o \
	delete_as.o delete_an.o exception.o bad_alloc.o logic_error.o to_string.o to_wstring.o \
	charconv.o
COBJS=memcpy.o memset.o memmove.o memcmp.o

CXX ?= g++
CC ?= gcc

# default, should be overridden:
OUTDIR ::= .

LIBBMCXX_CPPFLAGS ::= -I../include

all: $(CXXOBJS) $(COBJS) $(SOBJS)
	ar r $(OUTDIR)/libbmcxx.a $(CXXOBJS) $(COBJS) $(SOBJS)

$(CXXOBJS): %.o: %.cc
	$(CXX) $(CXXPPFLAGS) $(LIBBMCXX_CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(COBJS): %.o: %.c
	$(CC) $(CPPFLAGS) $(LIBBMCXX_CPPFLAGS) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(COBJS) $(CXXOBJS)
