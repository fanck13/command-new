#define CATCH_CONFIG_MAIN

#include "catch2/catch.hpp"
#include "../src/Utils.h"

TEST_CASE("the test for getfileext", "[single file]"){
    auto ext = Utils::get_file_ext("example.txt");
    REQUIRE(ext == ".txt");

    auto no_ext = Utils::get_file_ext("example");
    REQUIRE(no_ext == "");

}
