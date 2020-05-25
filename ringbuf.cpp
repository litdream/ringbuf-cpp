#include "ringbuf.h"
#include <iostream>

RingBuf::RingBuf(int len) : ring_len(len+1), iadv(0), ifol(0),
			    buf(std::unique_ptr<std::string[]>(new std::string[len+1]))
{
}

RingBuf::~RingBuf()
{
}

void RingBuf::put(std::string item)
{
	buf[iadv] = item;
	iadv = (iadv + 1) % ring_len;
}

std::string RingBuf::get()
{
	std::string rtn = buf[ifol];
	ifol = (ifol + 1) % ring_len;
	return rtn;
}

std::string RingBuf::peek()
{
	return buf[ifol];
}

bool RingBuf::isEmpty() const
{
	return iadv == ifol;
}

bool RingBuf::isFull() const
{
	return (iadv + 1) % ring_len == ifol;
}

size_t RingBuf::capacity() const
{
	return ring_len;
}

size_t RingBuf::size() const
{
	if (iadv > ifol)
		return iadv - ifol;
	else
		return iadv + ring_len - ifol;
}


// DEBUG only
void RingBuf::Print()
{
	int itr = ifol;
	while (itr != iadv) {
		std::cout << "[" << buf[itr] << "] ";
		itr = (itr+1) % ring_len;
	}
	std::cout << std::endl;
}
