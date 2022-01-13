cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

project(
   xentu
   LANGUAGES CXX
)

################### Default build configurations ###################

# Build options
if(NOT DEFINED BUILD_MODE)
   set(BUILD_MODE RELEASE)
endif()

if(NOT DEFINED BIN_TYPE)
   set(BIN_TYPE STATIC)
endif()

# Directory configurations
set(SOURCE_DIR    ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADER_DIR    ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BUILD_DIR     ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(VENDOR_DIR    ${CMAKE_CURRENT_SOURCE_DIR}/vendor)
set(TEST_DIR      ${CMAKE_CURRENT_SOURCE_DIR}/test)

# External static libraries
set(EXTERNAL_STATIC_LIBS
   ${VENDOR_DIR}/glad/libglad.a
   ${VENDOR_DIR}/glfw/src/libglfw3.a
   ${VENDOR_DIR}/spdlog/libspdlog.a
)

# External include directories
set(EXTERNAL_INCLUDE_DIRS
   ${VENDOR_DIR}/glad/include
   ${VENDOR_DIR}/glfw/include
   ${VENDOR_DIR}/glm
   ${VENDOR_DIR}/spdlog/include
)

####################################################################

# Validate build mode
if(NOT ((${BUILD_MODE} STREQUAL RELEASE) OR (${BUILD_MODE} STREQUAL DEBUG)))
   message(WARNING "Given build mode '${BUILD_MODE}' is not valid. Continue with default value: RELEASE")
   set(BUILD_MODE RELEASE)
endif()

# Print build mode
message(STATUS "Build mode: ${BUILD_MODE}")

# Validate binary type
if(NOT ((${BIN_TYPE} STREQUAL STATIC) OR (${BIN_TYPE} STREQUAL SHARED)))
   message(WARNING "Given binary type '${BIN_TYPE}' is not valid. Continue with default value: STATIC")
   set(BIN_TYPE STATIC)
endif()

# Print binary type
message(STATUS "Binary type: ${BIN_TYPE}")

# Fetch source file paths
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}/*.cpp)

# Add main target
add_library(xentu ${BIN_TYPE} ${SOURCE_FILES})

# Set library output directory
set_target_properties(xentu PROPERTIES
   ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR}/out
   LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIR}/out
   RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR}/out
)

# Set C++ standard
set_target_properties(xentu PROPERTIES CXX_STANDARD 17)

# Set C++ compiler flags
if(${BUILD_MODE} STREQUAL RELEASE)
   set(CMAKE_CXX_FLAGS "-w -O2 -DXN_RELEASE_BUILD")
elseif(${BUILD_MODE} STREQUAL DEBUG)
   set(CMAKE_CXX_FLAGS "-O0 -DXN_DEBUG_BUILD")
endif()

# Set include paths
target_include_directories(xentu PRIVATE
   ${HEADER_DIR}
   ${EXTERNAL_INCLUDE_DIRS}
)

# Check existance of external libraries
foreach(LIB ${EXTERNAL_STATIC_LIBS})
   if(NOT EXISTS ${LIB})
      message(FATAL_ERROR "External library '${LIB}' is not built.")
   elseif(EXISTS ${LIB})
      message(STATUS "External library '${LIB}' found")
   endif()
endforeach()

# Link external static libraries
target_link_libraries(xentu ${EXTERNAL_STATIC_LIBS})

# Build sandbox app
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sandbox)
