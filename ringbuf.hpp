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
#include <optional>

class RingBuf
{
public:
	RingBuf(int ring_len);
	~RingBuf();

	bool put(const std::string& item);
	std::optional<std::string> get();
	std::optional<std::string> peek() const;
	
	bool isEmpty() const;
	bool isFull() const;
	size_t capacity() const;
	size_t size() const;

	// For debug Only;
	void Print();
	std::string toString();
	
protected:
	const std::size_t ring_len;
	std::size_t iadv;
	std::size_t ifol;
	std::unique_ptr<std::string[]> buf;
};

#endif  /* __RAY_RINGBUF_H */
