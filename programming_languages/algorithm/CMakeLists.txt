cmake_minimum_required(VERSION 3.5.0)
project(leetcode VERSION 0.1.0 LANGUAGES C CXX)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_executable(leetcode solution.cc)

target_compile_options(leetcode PRIVATE -g)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
