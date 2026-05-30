#include <catch2/catch_test_macros.hpp>
#include "yaml/markup.hpp"

struct dto1 {
    int val{1};
};

TEST_CASE("serialize returns valid string")
{
    REQUIRE(std::string("val: 1\n") == yaml::markup<dto1>::serialize(dto1()));
}

TEST_CASE("deserialize returns valid object")
{
    REQUIRE(2 == yaml::markup<dto1>::deserialize("val: 2\n").val);
}
