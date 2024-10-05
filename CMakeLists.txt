cmake_minimum_required(VERSION 3.10)

project(TapeSort VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
cmake_policy(SET CMP0167 NEW)


# Find Boost
find_package(Boost 1.85 REQUIRED COMPONENTS system)

# Add TapeClass library
add_library(TapeClass STATIC 
            ${CMAKE_CURRENT_SOURCE_DIR}/Tape/Tape.h 
            ${CMAKE_CURRENT_SOURCE_DIR}/Tape/Tape.cpp)

add_subdirectory(test)

include_directories(${Boost_INCLUDE_DIRS})


add_executable(TapeSort main.cpp)

# Link libraries
target_link_libraries(TapeSort PUBLIC ${Boost_LIBRARIES} TapeClass)

# Include directories
target_include_directories(TapeClass PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Tape)

# Enable testing
enable_testing()
add_test(NAME RunTests COMMAND tests) 

# Custom command to run tests after build
add_custom_command(TARGET TapeSort POST_BUILD
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
)