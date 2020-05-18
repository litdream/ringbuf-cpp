#ifndef __RAY_RINGBUF_H
#define __RAY_RINGBUF_H

#include <vector>

// I start supporting memory block (uchar *) only.
// Templatizing will be later the code stablizes
//

class RingBuf
{
 protected:
	int ring_len;
	int sz_elm;
	std::vector <char *> buf;
	int iadv, ifol;  // advande/follow index
	
 public:
	RingBuf(int sz_elm, int ring_len);
	~RingBuf();
};

#endif  /* __RAY_RINGBUF_H */
