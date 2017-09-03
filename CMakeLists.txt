cmake_minimum_required(VERSION 3.6)
project(Unit_Tests_in_C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
set(SOURCE_FILES include/test/assertion.h src/test/assertion.c include/common/terminal.h)
# set(TEST_SOURCE_FILES ...)

file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs)
if(CYGWIN)
    # windows cygwin
    message("building for Cygwin")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/cygwin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/cygwin)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/bin/cygwin)
elseif(APPLE)
    # apple
    message("building for Apple")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/apple)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/apple)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/bin/apple)
else()
    # unix
    message("building for Unix")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/unix)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/lib/unix)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/outputs/bin/unix)
endif()

# libraries paths
set(COMPARERS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../comparers)
if(CYGWIN)
    # windows cygwin
    set(COMPARERS_LIB_PATH ${COMPARERS_SRC_DIR}/outputs/lib/cygwin/libcomparers.so)
    set(COMPARERS_STATIC_LIB_PATH ${COMPARERS_SRC_DIR}/outputs/lib/cygwin/libcomparers.a)
elseif(APPLE)
    # apple
    set(COMPARERS_LIB_PATH ${COMPARERS_SRC_DIR}/outputs/lib/apple/libcomparers.dylib)
    set(COMPARERS_STATIC_LIB_PATH ${COMPARERS_SRC_DIR}/outputs/lib/apple/libcomparers.a)
else()
    # unix
    set(COMPARERS_LIB_PATH ${COMPARERS_SRC_DIR}/outputs/lib/unix/libcomparers.so)
    set(COMPARERS_STATIC_LIB_PATH ${COMPARERS_SRC_DIR}/outputs/lib/unix/libcomparers.a)
endif()

### MAKING LIBRARIES ###
# include current project headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# libraries import
# SHARED
add_library(Comparers_Lib SHARED IMPORTED)
set_target_properties(Comparers_Lib PROPERTIES IMPORTED_LOCATION ${COMPARERS_LIB_PATH})
# STATIC
add_library(Comparers_Lib_Static STATIC IMPORTED)
set_target_properties(Comparers_Lib_Static PROPERTIES IMPORTED_LOCATION ${COMPARERS_STATIC_LIB_PATH})

# include libraries headers
include_directories( ${COMPARERS_SRC_DIR}/include )

# current project shared and static libraries creation
# SHARED
add_library(Unit_Tests_Lib SHARED ${SOURCE_FILES})
set_target_properties(Unit_Tests_Lib PROPERTIES OUTPUT_NAME unit_tests)
target_link_libraries(Unit_Tests_Lib Comparers_Lib)

# STATIC
add_library(Unit_Tests_Lib_Static ${SOURCE_FILES})
set_target_properties(Unit_Tests_Lib_Static PROPERTIES OUTPUT_NAME unit_tests)
target_link_libraries(Unit_Tests_Lib_Static Comparers_Lib_Static)

### MAKING EXECUTABLE ###
# current project executable creation
add_executable(Unit_Tests_in_C src/main.c)
set_target_properties(Unit_Tests_in_C PROPERTIES OUTPUT_NAME unit_tests)
target_link_libraries(Unit_Tests_in_C Unit_Tests_Lib)