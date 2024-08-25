CC = gcc
CFLAGS = -fPIC
LDLIBS = -ldl
LIBDIR = libs
SRC = sum.c dif.c mult.c divM.c max.c min.c calc.c
OBJS = $(SRC:.c=.o)

all: $(LIBDIR) $(LIBDIR)/libsum.so $(LIBDIR)/libdif.so $(LIBDIR)/libmult.so $(LIBDIR)/libdivM.so $(LIBDIR)/libmax.so $(LIBDIR)/libmin.so calc

$(LIBDIR):
	mkdir -p $(LIBDIR)

$(LIBDIR)/lib%.so: %.c
	$(CC) -shared -o $@ $< $(CFLAGS)

calc: $(OBJS)
	$(CC) -o $@ $^ $(LDLIBS)

clean:
	rm -f $(OBJS) calc $(LIBDIR)/*.so

cleanlibs:
	rm -f $(LIBDIR)/*.so