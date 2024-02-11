cmake_minimum_required(VERSION 3.0.0)
#add_executable(search_engine main.cpp converter.cpp inverted_index.cpp server.cpp)
add_executable(search_engine main.cpp)

target_include_directories(search_engine PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)
