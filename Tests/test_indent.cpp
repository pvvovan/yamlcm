#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include "indent.hpp"

TEST_CASE("stream operator")
{
    yaml::indent ind(1);
    std::stringstream ss{};
    ss << ind;
    REQUIRE(std::string("  ") == ss.str());
}