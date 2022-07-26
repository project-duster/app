cmake_minimum_required(VERSION 3.21)

include(cmake/prelude.cmake)

project(
    app
    VERSION 0.1.0
    DESCRIPTION "Short description"
    HOMEPAGE_URL "https://example.com/"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    app_lib OBJECT
    src/lib.cpp
)

target_include_directories(
    app_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>"
)

find_package(SDK REQUIRED)
find_package(SDL2 REQUIRED)
find_package(FMT REQUIRED)
find_package(ENTT REQUIRED)
find_package(TOMLPLUSPLUS REQUIRED)

# message("SDK_DIR: ${SDK_DIR}")
# message("SDL2_DIR: ${SDL2_DIR}")
# message("FMT_DIR: ${FMT_DIR}")
target_link_libraries(app_lib PUBLIC sdk::sdk tomlplusplus::tomlplusplus)

# ---- Declare executable ----

add_executable(app_exe src/main.cpp)
add_executable(app::exe ALIAS app_exe)

set_target_properties(
    app_exe PROPERTIES
    OUTPUT_NAME app
    EXPORT_NAME exe
)

target_link_libraries(app_exe PRIVATE app_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT app_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of app"
  )
endif()

include(cmake/dev-mode.cmake)
