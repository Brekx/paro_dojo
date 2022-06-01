#include <catch.hpp>

#include "Memory.hpp"

TEST_CASE( "initially memory cells are set to 0", "[memory]" ) {
    Memory memory;
    REQUIRE( memory.get() == Memory::MemoryCell{0} );
}

TEST_CASE( "getting after setting gives the same value", "[memory]" ) {
    Memory memory;
    constexpr auto value = 42;
    memory.set(value);
    REQUIRE( memory.get() == value );
}

TEST_CASE( "increment", "[memory]" ) {
    Memory memory;
    int beg = memory.get();
    memory.increment();
    memory.increment();
    memory.increment();
	REQUIRE( memory.get() == beg + 3);
}


TEST_CASE( "decrement", "[memory]" ) {
    Memory memory;
		memory.set(10);
    int beg = memory.get();
    memory.decrement();
    memory.decrement();
    memory.decrement();
	REQUIRE( memory.get() == 7);
}

TEST_CASE( "memory position can be moved around", "[memory]" ) {
    Memory memory;

    memory.set(1);
    memory.moveRight();
    memory.set(2);
    memory.moveRight();
    memory.set(3);

    REQUIRE(memory.get() == 3);
    memory.moveLeft();
    REQUIRE(memory.get() == 2);
    memory.moveLeft();
    REQUIRE(memory.get() == 1);
    
}


SCENARIO( "getting after setting gives the same value", "[memory-scen]" ) {

    GIVEN( "memory and a value" ) {
        Memory memory;
        constexpr auto value = 42;

        WHEN ("we set the value") {
            memory.set(value);

            THEN ( "getting value yields same value" ) {
                REQUIRE( memory.get() == value );
            }
        }
    }
}
