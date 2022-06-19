##########################
##### CMakeLists.txt #####
##########################

cmake_minimum_required(VERSION 3.20)
project(CPPAssignments1)

file(GLOB SOURCE_FILES ${CMAKE_SOURCE_DIR}/Sources/*.c ${CMAKE_SOURCE_DIR}/Sources/*.cpp)

file(GLOB ASSIGNMENT6_SOLUTION1_FILES ${CMAKE_SOURCE_DIR}/Sources/Assignment6/Solution1/*.c ${CMAKE_SOURCE_DIR}/Sources/Assignment6/Solution1/*.cpp)
file(GLOB ASSIGNMENT6_SOLUTION2_FILES ${CMAKE_SOURCE_DIR}/Sources/Assignment6/Solution2/*.c ${CMAKE_SOURCE_DIR}/Sources/Assignment6/Solution2/*.cpp)
file(GLOB ASSIGNMENT7_SOLUTION1_FILES ${CMAKE_SOURCE_DIR}/Sources/Assignment7/Solution1/*.c ${CMAKE_SOURCE_DIR}/Sources/Assignment7/Solution1/*.cpp)
file(GLOB ASSIGNMENT7_SOLUTION2_FILES ${CMAKE_SOURCE_DIR}/Sources/Assignment7/Solution2/*.c ${CMAKE_SOURCE_DIR}/Sources/Assignment7/Solution2/*.cpp)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
