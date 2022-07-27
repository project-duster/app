#include "lib.hpp"
#include <SDL2/SDL.h>
#include <entt/entt.hpp>
#include <filesystem>
#include <fmt/format.h>
#include <fmt/std.h>
#include <iostream>
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
            auto path          = e.path() / "manifest.toml";
            auto mainfest_file = std::ifstream{path.string()};
            if(auto manifest = sdk::read_manifest(mainfest_file)) {
                auto dll_path = e.path() / fmt::format("lib{}d.dll", manifest->name);
                plugin_service.load_plugin(dll_path.string().c_str());
            }
        }
    }

    SDL_Delay(2500);

    return 0;
}