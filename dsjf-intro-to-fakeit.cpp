#include <string>
#include "catch.hpp"
//#include "fakeit.hpp"

struct SomeInterface {
    virtual int foo(int) = 0;

    virtual int bar(std::string) = 0;
};

//fakeit::Mock <SomeInterface> mock;
//
//When(Method(mock, foo)).Return(1);
//
//TEST_CASE("Mocking works", "[mock]") {
//    REQUIRE(mock::foo == 1);
//}
