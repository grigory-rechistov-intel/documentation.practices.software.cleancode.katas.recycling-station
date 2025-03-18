cmake_minimum_required(VERSION 3.18)
project(recyclingstation)

enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(external/googletest)

add_executable(my_test my_test.cpp recyclingstation.cpp crusher.cpp smelter.cpp better_recycling.cpp)
add_test(my_test my_test)
target_link_libraries(my_test gtest gmock gmock_main)

