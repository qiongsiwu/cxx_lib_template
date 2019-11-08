cmake_minimum_required(VERSION 3.10)

project(testapp VERSION 1.0.1 DESCRIPTION "test project using testlib")

# Include the external library
set(TESTLIB_INSTALL_PATH "" CACHE PATH "Root of testlib")
list(APPEND CMAKE_PREFIX_PATH "${TESTLIB_INSTALL_PATH}/lib/")

find_package(testlib REQUIRED CONFIG)
add_definitions(${testlib_DEFINITIONS})
message("definitions ${testlib_DEFINITIONS}")
include_directories("${TESTLIB_INSTALL_PATH}")

add_executable(app src/main.cpp)
target_link_libraries(app testlib)
