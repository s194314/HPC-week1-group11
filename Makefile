TARGET	= libmatmult.so
LIBSRCS	= matmult_funs.c
LIBOBJS	= $(LIBSRCS:.c=.o)
LDFLAGS = -L/usr/lib64/atlas -lsatlas # linker flags for ATLAS

OPT     = -g
PIC	= -fPIC

CC      = gcc
CFLAGS  = $(OPT) $(PIC) $(XOPTS)

SOFLAGS = -shared 
XLIBS	= 

$(TARGET): $(LIBOBJS)
	$(CC) -o $@ $(SOFLAGS) $(LIBOBJS) $(XLIBS) $(LDFLAGS)

clean:
	@/bin/rm -f core core.* $(LIBOBJS) 
