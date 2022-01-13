cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(sandbox ${SOURCE_FILES})
target_include_directories(sandbox PRIVATE 
   ${CMAKE_CURRENT_SOURCE_DIR}/include
   ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(sandbox ${CMAKE_SOURCE_DIR}/build/out/libxentu.a)
set_target_properties(sandbox PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/sandbox
)
