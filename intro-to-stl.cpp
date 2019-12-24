#include "catch.hpp"

#include <optional>


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

TEST_CASE("Optional") {
    auto i = std::optional<int>{1};
    REQUIRE(i.has_value() == true);
    REQUIRE(std::optional<std::string>{"Wow"}.has_value() == true);
    REQUIRE(std::optional<bool>{}.has_value() == false);
    REQUIRE(i.has_value());
    REQUIRE(!std::optional<char>{}.has_value());
}

TEST_CASE("HoFs") {
    SECTION("std::transform") {
        auto xs = std::vector<int>{1, 2, 3, 4, 5};
        std::vector<int> ys = std::vector{1, 2, 3, 4, 5};
        std::vector<int> result;
        std::transform(xs.begin(), xs.end(),
                       std::back_inserter(result),
                       [](int i) { return i + 1; });
        REQUIRE(result == std::vector<int>{2, 3, 4, 5, 6});
    }
}
