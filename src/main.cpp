#include "lib.hpp"
#include <iostream>
#include <sdk/sdk.hpp>
#undef main

auto main(int argv, char **args) -> int {
    std::string g = sdk::greeting();
    std::cout << g << '\n';
    return 0;
}