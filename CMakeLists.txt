cmake_minimum_required(VERSION 3.5)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project( ImageAnalysis )

find_package( OpenCV REQUIRED )

include_directories(
    ${CMAKE_SOURCE_DIR}/include 
    ${OpenCV_INCLUDE_DIRS}
)

message(${OpenCV_INCLUDE_DIRS})
 
add_executable( ImageAnalysis src/main.cpp src/Interact.cpp)

target_link_libraries( ImageAnalysis ${OpenCV_LIBS} )
