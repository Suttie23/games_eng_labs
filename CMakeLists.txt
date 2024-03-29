cmake_minimum_required(VERSION 3.11)
# Require modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Games_Engineering)

#### Setup Directories ####
#Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
# Ouput all DLLs from all libs into main build folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

#### Add External Dependencies ####
add_subdirectory("lib/sfml")
set(SFML_INCS "lib/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

## ECM Lib
file(GLOB_RECURSE SOURCE_FILES lib_ecm/*.cpp lib_ecm/*.h)
add_library(lib_ecm STATIC ${SOURCE_FILES})
target_include_directories(lib_ecm INTERFACE "${CMAKE_SOURCE_DIR}/lib_ecm/" )
target_link_libraries(lib_ecm lib_maths)

## Tile loader lib
file(GLOB_RECURSE SOURCE_FILES lib_tile_level_loader/*.cpp lib_tile_level_loader/*.h)
add_library(lib_tile_level_loader STATIC ${SOURCE_FILES})
target_include_directories(lib_tile_level_loader INTERFACE "${CMAKE_SOURCE_DIR}/lib_tile_level_loader/")
target_link_libraries(lib_tile_level_loader lib_maths sfml-graphics)

## Maths lib
add_library(lib_maths INTERFACE)
target_sources(lib_maths INTERFACE "${CMAKE_SOURCE_DIR}/lib_maths/maths.h")
target_include_directories(lib_maths INTERFACE "${CMAKE_SOURCE_DIR}/lib_maths" SYSTEM INTERFACE ${SFML_INCS})

# B2D - Box2D phyics library
add_subdirectory("lib/b2d/Box2D")
#include_directories("lib/b2d/Box2D/")
set(B2D_INCS "lib/b2d/Box2D/")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml/lib")

#### Custom Targets ####
add_custom_target(copy_resources ALL COMMAND ${CMAKE_COMMAND} 
  -E copy_directory
    "${PROJECT_SOURCE_DIR}/res"
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>/res
)

add_custom_target(copy_dll ALL COMMAND ${CMAKE_COMMAND} 
  -E copy_directory
    "${PROJECT_SOURCE_DIR}/dlls"
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIGURATION>
)

#### Practical 1 - Pong ####
file(GLOB_RECURSE SOURCES practical_1/*.cpp practical_1/*.h)
add_executable(PRACTICAL_1 ${SOURCES})
target_include_directories(PRACTICAL_1 PRIVATE ${SFML_INCS})
target_link_libraries(PRACTICAL_1 sfml-graphics)
target_link_libraries(PRACTICAL_1 sfml-audio)
set_target_properties(PRACTICAL_1 
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
)
add_dependencies(PRACTICAL_1 copy_dll)
add_dependencies(PRACTICAL_1 copy_resources)

#### Practical 2 - Space Invaders ####
file(GLOB_RECURSE SOURCES practical_2/*.cpp practical_2/*.h)
add_executable(PRACTICAL_2 ${SOURCES} )
target_include_directories(PRACTICAL_2 SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(PRACTICAL_2 sfml-graphics)
set_target_properties(PRACTICAL_2 
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
)
add_dependencies(PRACTICAL_2 copy_resources)

#### Practical 3 - Tile Engine ####
file(GLOB_RECURSE SOURCES practical_3/*.cpp practical_3/*.h)
add_executable(PRACTICAL_3 ${SOURCES} )
target_include_directories(PRACTICAL_3 SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(PRACTICAL_3 lib_tile_level_loader lib_maths sfml-graphics)
set_target_properties(PRACTICAL_3 
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
)
add_dependencies(PRACTICAL_3 copy_resources)

#### Practical 4 - Pacman ####
file(GLOB_RECURSE SOURCES practical_4/*.cpp practical_4/*.h)
add_executable(PRACTICAL_4 ${SOURCES})
target_include_directories(PRACTICAL_3 SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(PRACTICAL_4 sfml-graphics lib_ecm) 
set_target_properties(PRACTICAL_4 
	 PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY
	 ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$(Configuration)
)

#### Practical 5 - Physics ####
file(GLOB_RECURSE SOURCES practical_5/*.cpp practical_5/*.h)
add_executable(PRACTICAL_5 ${SOURCES})
target_include_directories(PRACTICAL_5 SYSTEM PRIVATE ${SFML_INCS} ${B2D_INCS})
target_link_libraries(PRACTICAL_5 Box2D sfml-graphics)
set(EXECUTABLES ${EXECUTABLES} PRACTICAL_5)