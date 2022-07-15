#include "lib.hpp"
#include <iostream>
#include <sdk/sdk.hpp>

auto main(int argv, char **args) -> int {
    std::cout << sdk::greeting() << '\n';
    return 0;
}