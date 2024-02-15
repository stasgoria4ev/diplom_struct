# 'Google_test' is the subproject name
#project(Google_tests)
cmake_minimum_required(VERSION 3.24)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SrcFiles
        ${MY_SRC_DIR}/inverted_index.cpp
        ${MY_SRC_DIR}/server.cpp
        ${MY_SRC_DIR}/converter.cpp
        )

set(TestsFiles
        index_tests.cpp
        server_tests.cpp
        )

add_executable(Google_Tests_run ${TestsFiles} ${SrcFiles})
target_link_libraries(Google_Tests_run nlohmann_json::nlohmann_json GTest::gtest_main)
include(GoogleTest)
target_include_directories(Google_Tests_run PUBLIC ${MY_INCLUDE_DIR})
gtest_discover_tests(Google_Tests_run)

set(gtest_disable_pthreads on)
# 'lib' is the folder with Google Test sources
add_subdirectory(lib)