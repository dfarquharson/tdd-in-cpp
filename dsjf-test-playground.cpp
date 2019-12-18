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
