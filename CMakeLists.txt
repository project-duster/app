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

target_compile_features(app_lib PUBLIC cxx_std_17)

find_package(SDK REQUIRED)
find_package(SDL2 REQUIRED)
find_package(fmt REQUIRED)

target_link_libraries(app_lib PUBLIC sdk::sdk)

# ---- Declare executable ----

add_executable(app_exe src/main.cpp)
add_executable(app::exe ALIAS app_exe)

set_target_properties(
    app_exe PROPERTIES
    OUTPUT_NAME app
    EXPORT_NAME exe
)

target_compile_features(app_exe PRIVATE cxx_std_17)

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
