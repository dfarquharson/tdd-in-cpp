#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -- only do this in one cpp file

#include "catch.hpp"

unsigned int Factorial(unsigned int number) {
    return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorial works", "[factorial]") {
    REQUIRE(Factorial(0) == 0);
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(5) == 120);
    REQUIRE(Factorial(6) == 720);
    REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("Addition works", "[addition]") {
    REQUIRE(1 + 1 == 2);
}

TEST_CASE("Subtraction works", "[subtraction]") {
    REQUIRE(1 - 1 == 0);
}

TEST_CASE("Division works", "[division]") {
    REQUIRE(2 / 2 == 1);
    REQUIRE(3 / 2 == 1);
    REQUIRE(3 % 2 == 1);
    REQUIRE(5 / 2 == 2);
    REQUIRE(5 % 2 == 1);
}

// Playing with templates

template<typename T>
T add(T a, T b) {
    return a + b;
}

TEST_CASE("Generic Add Ints") {
    REQUIRE(1 + 2 == 3);
    REQUIRE(add(1, 2) == 3);
}

TEST_CASE("Generic Add Doubles") {
    REQUIRE(1.5 + 1.5 == 3.0);
    REQUIRE(add(1.5, 1.5) == 3.0);
}

TEST_CASE("Generic Add Strings") {
    REQUIRE(std::string("ab") + std::string("xy") == "abxy");
    REQUIRE(add(std::string("ab"), std::string("xy")) == "abxy");
}

// Playing with testing structures

TEST_CASE("More Elaborate Example") {
    SECTION("Section A") {
        REQUIRE(1 + 1 == 2);
    } SECTION("Section B") {
        REQUIRE(std::string("a") + std::string("b") == "ab");
    }
}

TEST_CASE("BDD-style?") {
    GIVEN("A vector with some items") {
        std::vector<int> v(5);

        REQUIRE(v.size() == 5);
        REQUIRE(v.capacity() == 5);

        WHEN("The size is increased") {
            v.resize(10);

            THEN("The capacity gets bigger") {
                REQUIRE(v.size() == 10);
                REQUIRE(v.capacity() >= 10);
            }
        }

        WHEN("The size is reduced") {
            v.resize(0);

            THEN("The size changes, but not the capacity") {
                REQUIRE(v.empty()); // same as v.size() == 0
                REQUIRE(v.capacity() >= 5);
            }
        }

        WHEN("More capacity is reserved") {
            v.reserve(10);

            THEN("The size changes but not capacity") {
                REQUIRE(v.size() == 5);
                REQUIRE(v.capacity() >= 5);
            }
        }

        WHEN("Less capacity is reserved") {
            v.reserve(0);

            THEN("Neither size nor capacity are changed") {
                REQUIRE(v.size() == 5);
                REQUIRE(v.capacity() >= 5);
            }
        }
    }
}