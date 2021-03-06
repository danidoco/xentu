cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

file(GLOB_RECURSE SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(sandbox ${SOURCE_FILES})

target_include_directories(sandbox PRIVATE 
   ${CMAKE_CURRENT_SOURCE_DIR}/include
   ${CMAKE_SOURCE_DIR}/include
   ${CMAKE_SOURCE_DIR}/vendor/glfw/include
   ${CMAKE_SOURCE_DIR}/vendor/glad/include
   ${CMAKE_SOURCE_DIR}/vendor/spdlog/include
   ${CMAKE_SOURCE_DIR}/vendor/glm
)

target_link_libraries(sandbox 
   ${CMAKE_SOURCE_DIR}/build/out/libxentu.a
   ${CMAKE_SOURCE_DIR}/vendor/glad/libglad.a
   ${CMAKE_SOURCE_DIR}/vendor/glfw/src/libglfw3.a
   ${CMAKE_SOURCE_DIR}/vendor/spdlog/libspdlog.a
)

if(${BUILD_MODE} STREQUAL RELEASE)
   set(CMAKE_CXX_FLAGS "-DXN_RELEASE")
elseif(${BUILD_MODE} STREQUAL DEBUG)
   set(CMAKE_CXX_FLAGS "-DXN_DEBUG")
endif()

set_target_properties(sandbox PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/sandbox
)
