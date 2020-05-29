## TODO:
##   Learn CMake
##

CPPFLAGS = -g
LDFLAGS = -g
LDLIBS =
CXX = g++ -std=c++11
all: ringbuf.o test.o
	$(CXX) test.o ringbuf.o

ringbuf.o: 
test.o:  ringbuf.o

.PHONY: clean test
test: ringbuf.o
	cd t && $(MAKE)

clean:
	rm -f *.o a.out
	rm -f t/*.o t/a.out
