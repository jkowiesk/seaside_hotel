cmake_minimum_required(VERSION 3.19)
project(SeasideHotel)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES main.cpp)

add_executable(SeasideHotel ${SOURCES})

add_subdirectory(src)
add_subdirectory(test)

target_link_libraries(${PROJECT_NAME} core)