# 'search_engine_tests' is the subproject name
cmake_minimum_required(VERSION 3.24)
project(search_engine_tests VERSION 1.0)

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

add_executable(search_engine_tests)
target_sources(search_engine_tests PRIVATE ${TestsFiles} ${SrcFiles})

target_link_libraries(search_engine_tests nlohmann_json::nlohmann_json GTest::gtest_main)
include(GoogleTest)
target_include_directories(search_engine_tests PUBLIC ${MY_INCLUDE_DIR})
gtest_discover_tests(search_engine_tests)

set(gtest_disable_pthreads on)
# 'lib' is the folder with Google Test sources
add_subdirectory(lib)