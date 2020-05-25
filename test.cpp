#include <iostream>
#include "ringbuf.h"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
	// TODO:
	//   Learn Some c++ unittest, such as google-test.
	//
	RingBuf buf(3);

	cout << "Empty should be true: " << buf.isEmpty() << endl;
	cout << "Full should be false: " << buf.isFull() << endl;

	buf.put(string("Hello"));
	buf.put(string("world"));
	cout << "Empty should be false: " << buf.isEmpty() << endl;
	cout << "Full should be false: " << buf.isFull() << endl;
	buf.Print();
	
	buf.put(string("Home"));
	cout << "Full should be true: " << buf.isFull() << endl;
	buf.Print();

	cout << buf.peek() << endl;
	buf.Print();

	cout << buf.get() << endl;
	buf.Print();

	cout << buf.get() << endl;
	buf.Print();
	cout << "Empty should be false: " << buf.isEmpty() << endl;
	cout << "Full should be false: " << buf.isFull() << endl;

	cout << buf.get() << endl;
	buf.Print();
	cout << "Empty should be true: " << buf.isEmpty() <<endl;
	cout << "Full still false: " << buf.isFull() << endl;

	cout << "-------------------------" << endl;
	buf.put("Hello");     // This is (const char *)!
	buf.Print();
	
	return 0;
}
