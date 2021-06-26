cmake_minimum_required(VERSION 3.0.0)
project(HelloWorld VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)

add_executable(HelloWorld main.cpp)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
add_subdirectory(STRING)
add_subdirectory(Test_leetcode)
add_subdirectory(CONTAINER)
