cmake_minimum_required(VERSION 3.10)
project(calculator_tests)

set(CMAKE_C_STANDARD 11)

find_package(cmocka REQUIRED)

add_executable(test_calculator test.c)
target_link_libraries(test_calculator cmocka)

enable_testing()
add_test(NAME test_calculator COMMAND test_calculator)