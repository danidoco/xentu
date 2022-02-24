file(GLOB TEST_SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

remove(TEST_SOURCE_FILES tests.cpp)

create_test_sourcelist(TEST_SOURCELIST tests.cpp
   ${TEST_SOURCE_FILES}
)

add_executable(tests ${TEST_SOURCELIST})

remove(TEST_SOURCELIST tests.cpp)

foreach(TEST_SOURCE ${TEST_SOURCELIST})
   get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
   add_test(${TEST_NAME} tests ${TEST_NAME})
endforeach()