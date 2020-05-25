#ifndef __RAY_RINGBUF_H
#define __RAY_RINGBUF_H

// I start supporting memory block std::string.
// Templatizing will be later the code stablizes
//
// NOTE:
//   put/get isn't robust.  Use empty/full check before
//   using put/get.
//
#include <string>
#include <memory>

class RingBuf
{
 public:
	RingBuf(int ring_len);
	~RingBuf();

	void put(std::string item);
	std::string get();
	std::string peek();
	
	bool isEmpty() const;
	bool isFull() const;
	size_t capacity() const;
	size_t size() const;

	// For debug Only;
	void Print();
	
 protected:
	std::unique_ptr<std::string[]> buf;
	std::size_t iadv;
	std::size_t ifol;
	const std::size_t ring_len;
};

#endif  /* __RAY_RINGBUF_H */
