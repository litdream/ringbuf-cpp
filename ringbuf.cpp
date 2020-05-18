#include "ringbuf.h"

RingBuf::RingBuf(int sz, int len) : sz_elm(sz), ring_len(len), iadv(0), ifol(0)
{
	buf.reserve(len);
	for (int i=0; i<len; ++i) 
		buf.push_back(new char[sz]);
}

RingBuf::~RingBuf()
{
	for (int i=0; i<ring_len; ++i)
		delete buf[i];
}
