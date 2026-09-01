cmake_minimum_required(VERSION 3.10.0)
project(ascii_vision)

set(CMAKE_CXX_STANDARD 17)

# Find opencv package installed on system
find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(ascii_vision src)
target_link_libraries(ascii_vision ${OpenCV_LIBS})
