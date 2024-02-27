cmake_minimum_required(VERSION 3.24)
project(search_engine VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(SrcFiles
        ${MY_SRC_DIR}/inverted_index.cpp
        ${MY_SRC_DIR}/server.cpp
        ${MY_SRC_DIR}/converter.cpp
        ${MY_SRC_DIR}/main.cpp
        )

add_executable(search_engine)

target_sources(search_engine PRIVATE ${SrcFiles})

target_link_libraries(search_engine PUBLIC nlohmann_json::nlohmann_json)
target_include_directories(search_engine PUBLIC ${MY_INCLUDE_DIR})