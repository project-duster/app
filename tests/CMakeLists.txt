cmake_minimum_required(VERSION 3.20)

project(appTests LANGUAGES CXX)

include(../cmake/folders.cmake)
include(../cmake/windows-set-path.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(app REQUIRED)
  enable_testing()
endif()

# ---- Tests ----
find_package(Catch2 3 REQUIRED
  PATHS "D:/Program Files/Catch2"
)

add_executable(app_test src/app_test.cpp)
target_link_libraries(app_test PRIVATE app_lib Catch2::Catch2WithMain)
target_compile_features(app_test PRIVATE cxx_std_17)

add_test(NAME app_test COMMAND app_test)
windows_set_path(app_test app::app)

# ---- End-of-file commands ----

add_folders(Test)
