CXXOBJS=terminate.o new_r.o new_n.o new_a.o new_an.o delete_r.o delete_rs.o delete_n.o delete_a.o \
	delete_as.o delete_an.o exception.o bad_alloc.o
COBJS=memcpy.o memset.o

# default, should be overridden:
OUTDIR ::= .

LIBBMCXX_CPPFLAGS ::= -I../include

all: $(CXXOBJS) $(COBJS) $(SOBJS)
	ar r $(OUTDIR)/libbmcxx.a $(CXXOBJS) $(COBJS) $(SOBJS)

$(CXXOBJS): %.o: %.cc
	g++ $(CXXPPFLAGS) $(LIBBMCXX_CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(COBJS): %.o: %.c
	gcc $(CPPFLAGS) $(LIBBMCXX_CPPFLAGS) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(COBJS) $(CXXOBJS)
