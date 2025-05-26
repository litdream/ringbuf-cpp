#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../ringbuf.hpp"
#include <string>

TEST_CASE( "Ringbuf empty case", "[ringbuf]") {
	RingBuf buf(3);

	REQUIRE( buf.capacity() == 3 );
	REQUIRE( buf.isEmpty() == true );

	SECTION("add new items and list") {
		buf.put(std::string("Hello"));
		buf.put(std::string("world"));

		REQUIRE( buf.isEmpty() == false );
		REQUIRE( buf.isFull() == false );
		REQUIRE( buf.capacity() == 3 );
		REQUIRE( buf.size() == 2 );
		REQUIRE( buf.toString() == "[Hello] [world]");
	}

	SECTION("full item") {
		buf.put(std::string("Hello"));
		buf.put(std::string("world"));
		buf.put(std::string("Home"));

		REQUIRE( buf.isEmpty() == false );
		REQUIRE( buf.isFull() == true );
		REQUIRE( buf.capacity() == 3 );
		REQUIRE( buf.size() == 3 );
		REQUIRE( ! buf.put(std::string("SHOULDN'T BE HERE")) );
		REQUIRE( buf.toString() == "[Hello] [world] [Home]");
	}

	SECTION("pop item") {
		buf.put(std::string("Hello"));
		buf.put(std::string("world"));
		buf.put(std::string("Home"));

		REQUIRE( buf.peek() == "Hello" );
		REQUIRE( buf.size() == 3 );
		REQUIRE( buf.get() == "Hello");
		REQUIRE( buf.get() == "world");
		REQUIRE( buf.get() == "Home");

		REQUIRE( buf.isEmpty() == true );
		REQUIRE( buf.isFull() == false );
		REQUIRE( buf.capacity() == 3 );
		REQUIRE( buf.size() == 0 );

		buf.put("Hello");
		REQUIRE( buf.isEmpty() == false );
		REQUIRE( buf.isFull() == false );
		REQUIRE( buf.capacity() == 3 );
		REQUIRE( buf.size() == 1 );
		REQUIRE( buf.toString() == "[Hello]");
	}

}
