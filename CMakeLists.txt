cmake_minimum_required(VERSION 3.5)
project(Unit_Tests_in_C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(SOURCE_FILES test/assertion.h test/assertion.c common/terminal.h)

# libraries paths
set(COMPARERS_PATH /Users/michzio/Developer/MyProjects/BachelorDegree/c/comparers)

add_library(Unit_Tests_Lib SHARED ${SOURCE_FILES})
set_target_properties(Unit_Tests_Lib PROPERTIES OUTPUT_NAME libunit_tests_shared)
target_link_libraries(Unit_Tests_Lib ${COMPARERS_PATH}/libcomparers.a)

add_library(Unit_Tests_Lib_Static ${SOURCE_FILES})
set_target_properties(Unit_Tests_Lib_Static PROPERTIES OUTPUT_NAME libunit_tests)
target_link_libraries(Unit_Tests_Lib_Static ${COMPARERS_PATH}/libcomparers.a)

add_executable(Unit_Tests_in_C main.c)
target_link_libraries(Unit_Tests_in_C Unit_Tests_Lib_Static)