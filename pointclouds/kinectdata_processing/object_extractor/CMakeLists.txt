cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(3dobjext)

include_directories(inc/)

find_package(PCL 1.2 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(3dobjext	src/Markup.cpp
						src/diranalyzer.cpp 
						src/file.cpp
						src/xmlobject.cpp
						src/ymlobject.cpp
						src/scene.cpp
						src/main.cpp)

target_link_libraries(3dobjext yaml-cpp ${PCL_LIBRARIES})
