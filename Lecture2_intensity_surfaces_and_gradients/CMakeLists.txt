cmake_minimum_required(VERSION 3.15)
project(Lecture2_intensity_surfaces_and_gradients)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lecture2_intensity_surfaces_and_gradients main.cpp)

# find opencv package
find_package(OpenCV)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Lecture2_intensity_surfaces_and_gradients ${OpenCV_LIBS})

# find python package
find_package(PythonLibs 3 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})
target_link_libraries(Lecture2_intensity_surfaces_and_gradients ${PYTHON_LIBRARIES})


