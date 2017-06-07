cmake_minimum_required(VERSION 3.6)
project(Unit_Tests_in_C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/bin)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib/static)
set(SOURCE_FILES test/assertion.h test/assertion.c common/terminal.h)

if(CYGWIN)
    # windows cygwin
    message("building for Cygwin")
else()
    # unix
    message("building for Unix")
endif()

# libraries paths
set(COMPARERS_PATH ${CMAKE_SOURCE_DIR}/../comparers)
if(CYGWIN)
    # windows cygwin
    set(COMPARERS_LIB_PATH ${COMPARERS_PATH}/output/windows/lib/static/libcomparers.a)
elseif(APPLE)
    # apple

    # static:
    # set(COMPARERS_LIB_PATH ${COMPARERS_PATH}/output/unix/lib/static/libcomparers.a)

    # shared:
    set(COMPARERS_LIB_PATH ${COMPARERS_PATH}/output/unix/lib/libcomparers.dylib)

elseif(UNIX)
    # unix

endif()

add_library(Unit_Tests_Lib SHARED ${SOURCE_FILES})
set_target_properties(Unit_Tests_Lib PROPERTIES OUTPUT_NAME unit_tests)
target_link_libraries(Unit_Tests_Lib ${COMPARERS_LIB_PATH})

add_library(Unit_Tests_Lib_Static ${SOURCE_FILES})
set_target_properties(Unit_Tests_Lib_Static PROPERTIES OUTPUT_NAME unit_tests)
target_link_libraries(Unit_Tests_Lib_Static ${COMPARERS_LIB_PATH})

add_executable(Unit_Tests_in_C main.c)
set_target_properties(Unit_Tests_in_C PROPERTIES OUTPUT_NAME unit_tests)
target_link_libraries(Unit_Tests_in_C Unit_Tests_Lib_Static)

# install targets (executables, shared libraries, static libraries) in current project source directory
add_custom_target(Install_${PROJECT_NAME}
                  $(MAKE) install
                  DEPENDS ${PROJECT_NAME}
                  COMMENT "Installing ${PROJECT_NAME}")

if(CYGWIN)
    # windows cygwin
    set(RUNTIME_DEST_DIR ${CMAKE_SOURCE_DIR}/output/windows/bin)
    set(LIBRARY_DEST_DIR ${CMAKE_SOURCE_DIR}/output/windows/lib)
    set(ARCHIVE_DEST_DIR ${CMAKE_SOURCE_DIR}/output/windows/lib/static)
else()
    # unix
    set(RUNTIME_DEST_DIR ${CMAKE_SOURCE_DIR}/output/unix/bin)
    set(LIBRARY_DEST_DIR ${CMAKE_SOURCE_DIR}/output/unix/lib)
    set(ARCHIVE_DEST_DIR ${CMAKE_SOURCE_DIR}/output/unix/lib/static)
endif()

install(TARGETS Unit_Tests_in_C Unit_Tests_Lib Unit_Tests_Lib_Static
        RUNTIME DESTINATION ${RUNTIME_DEST_DIR}
        LIBRARY DESTINATION ${LIBRARY_DEST_DIR}
        ARCHIVE DESTINATION ${ARCHIVE_DEST_DIR})