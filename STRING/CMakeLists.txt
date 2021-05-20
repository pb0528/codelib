cmake_minimum_required(VERSION 3.0.0)
project(STRINGS VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)

add_executable(STRINGS stringEXP.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
