cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(save_vfh)

find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (save_vfh save_vfh.cpp diranalyzer.cpp file.cpp)
target_link_libraries (save_vfh ${PCL_LIBRARIES})
