#include "catch.hpp"

TEST_CASE("stl::Strings") {
    // https://en.cppreference.com/w/cpp/string
    std::string s = "hello";
    REQUIRE(s.length() == 5);
    REQUIRE(s.size() == 5);
    REQUIRE(s == "hello");

    SECTION("Uppercasing a String") {
        std::string t;
        std::transform(s.begin(), s.end(), std::back_inserter(t), ::toupper);
        REQUIRE(t == "HELLO");
    }
}
