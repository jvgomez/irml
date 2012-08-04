cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(xmlparser)

#find_package(PCL 1.2 REQUIRED)
#find_package(ImageMagick COMPONENTS Magick++)

#include_directories(${PCL_INCLUDE_DIRS})
#include_directories(${ImageMagick_INCLUDE_DIRS})

#link_directories(${PCL_LIBRARY_DIRS})

#add_definitions(${PCL_DEFINITIONS})

add_executable(xmlparser main.cpp Markup.cpp)

#target_link_libraries(yamlparser ${ImageMagick_LIBRARIES} ${PCL_LIBRARIES})
#target_link_libraries(yamlparser yaml-cpp)
