#include <catch2/catch.hpp>

TEST_CASE("place0") {}
TEST_CASE("place1") {
    SECTION("place2") {}
    SECTION("place3") {
        REQUIRE(1+1 == 2);
    }
    REQUIRE(1+1 == 2);
}