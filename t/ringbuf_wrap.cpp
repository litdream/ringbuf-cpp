#include <Python.h>
#include <pybind11/pybind11.h>   // $HOME/github/ringbuf-cpp/venv/include/site/python3.7/pybind11
#include "ringbuf.h"    // ..

// TODO:
//    Still not compiling:
//    g++ -I.. -I/Library/Frameworks/Python.framework/Versions/3.7/include/python3.7m  -I../venv/include/site/python3.7 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` ringbuf_wrap.cpp -o ringbuf_wrap`python3-config --extension-suffix`


// TEST Compile:
//  g++ -I.. -I$HOME/local/include/python3.8 -L$HOME/local/lib/ -lpython3.8 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes`  ringbuf_wrap.cpp ../ringbuf.o -o ringbuf_wrap`python3-config --extension-suffix`

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
	m.doc() = "pybind11 test for pytest.";
	py::class_<RingBuf>(m, "RingBuf")
		.def(py::init<const int>())
		.def("put", &RingBuf::put)
		.def("get", &RingBuf::get)
		.def("peek", &RingBuf::peek)
		.def("isEmpty", &RingBuf::isEmpty)
		.def("isFull", &RingBuf::isFull)
		.def("capacity", &RingBuf::capacity)
		.def("size", &RingBuf::size)
		.def("Print", &RingBuf::Print);
}
