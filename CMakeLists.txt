cmake_minimum_required(VERSION 3.10)

project(TapeSort VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(tests)

add_executable(TapeSort main.cpp)

# Enable testing
enable_testing()
add_test(NAME RunTests COMMAND tests) 

# Custom command to run tests after build
add_custom_command(TARGET TapeSort POST_BUILD
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
)