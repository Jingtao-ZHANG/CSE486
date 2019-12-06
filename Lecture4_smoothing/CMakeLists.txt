cmake_minimum_required(VERSION 3.15)
project(Lecture4_smoothing)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lecture4_smoothing main.cpp)

# find opencv package
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Lecture4_smoothing ${OpenCV_LIBS})