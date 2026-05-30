#include <catch2/catch_test_macros.hpp>
#include "yaml/markup.hpp"

struct dto1 {
    double data{2.34353};
    int val{1};
    void fun() { }
};

TEST_CASE("serialize returns valid string")
{
    REQUIRE(std::string("data: 2.34353\nval: 1\n") == yaml::markup<dto1>::serialize(dto1()));
}

TEST_CASE("deserialize returns valid object")
{
    dto1 d = yaml::markup<dto1>::deserialize("data: 123.3223\nval: 14\n");
    REQUIRE(14 == d.val);
    REQUIRE(123.3223 == d.data);
}
