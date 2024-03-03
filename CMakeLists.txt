cmake_minimum_required(VERSION 3.5)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project( image_analysis )

find_package( OpenCV REQUIRED )

include_directories(
    ${CMAKE_SOURCE_DIR}/include 
    ${OpenCV_INCLUDE_DIRS}
)

add_executable( image_analysis src/main.cpp src/ImageIO.cpp src/Analysis.cpp)

target_link_libraries( image_analysis ${OpenCV_LIBS} )
