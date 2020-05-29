CXX = g++ -std=c++11

all: test.o
	$(CXX) test.o ../ringbuf.o
	./a.out
test.o:

clean:
	rm -f test.o
