## TODO:
##   Learn CMake
##

CPPFLAGS = -g
LDFLAGS = -g
LDLIBS =

all: ringbuf.o test.o
	g++ test.o ringbuf.o

ringbuf.o: 
test.o:  ringbuf.o

.PHONY: clean
clean:
	rm -f *.o a.out
