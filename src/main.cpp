#include "lib.hpp"
#include <SDL2/SDL.h>
#include <entt/entt.hpp>
#include <fmt/format.h>
#include <sdk/sdk.hpp>
#undef main

namespace sdk = pd::sdk;

auto main() -> int {
    fmt::print("starting\n");
    auto reg = entt::registry{};

    sdk::plugin_service plugin_service{};
    auto path   = R"--(D:\Dev\project-duster\renderer\build\dev\librendererd.dll)--";
    auto plugin = plugin_service.load_plugin(path);

    fmt::print("loaded\n");

    return 0;
}