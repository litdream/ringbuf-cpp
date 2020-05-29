#include "ringbuf.h"
#include <iostream>
#include <sstream>

RingBuf::RingBuf(int len) : ring_len(len+1), iadv(0), ifol(0),
			    buf(std::unique_ptr<std::string[]>(new std::string[len+1]))
{
}

RingBuf::~RingBuf()
{
}

static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

bool RingBuf::put(std::string item)
{
	if ( ! this->isFull()) {
		buf[iadv] = item;
		iadv = (iadv + 1) % ring_len;
		return true;
	}
	else {
		return false;
	}
}

std::string RingBuf::get()
{
	if ( ! this->isEmpty()) {
		std::string rtn = buf[ifol];
		ifol = (ifol + 1) % ring_len;
		return rtn;
	}
	else {
		return "";
	}
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
	return ring_len-1;
}

size_t RingBuf::size() const
{
	if (iadv >= ifol)
		return iadv - ifol;
	else
		return iadv + ring_len - ifol;
}


// DEBUG only
void RingBuf::Print()
{
	std::cout << this->toString() << std::endl;
}

std::string RingBuf::toString()
{
	std::ostringstream sstr;
	int itr = ifol;
	while (itr != iadv) {
		sstr << "[" << buf[itr] << "] ";
		itr = (itr+1) % ring_len;
	}
	std::string rtn = sstr.str();
	rtrim(rtn);
	return rtn;
}
