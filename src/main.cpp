#include "lib.hpp"
#include <SDL2/SDL.h>
#include <entt/entt.hpp>
#include <filesystem>
#include <fmt/format.h>
#include <fmt/std.h>
#include <sdk/sdk.hpp>
#undef main

namespace sdk = pd::sdk;

auto main() -> int {
    // Application initialization
    auto reg            = entt::registry{};
    auto plugin_service = sdk::plugin_service{};

    // Plugin loading from cwd
    for(const auto &e: std::filesystem::directory_iterator(".\\plugins")) {
        if(e.is_directory()) {
            fmt::print("{}\n", e.path());
            plugin_service.load_plugin((e.path() / std::filesystem::path{"librendererd.dll"}).string().c_str());
        }
    }

    SDL_Delay(2500);

    return 0;
}