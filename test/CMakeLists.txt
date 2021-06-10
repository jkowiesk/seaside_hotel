cmake_minimum_required(VERSION 3.19)
project(tests)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(src)

set(SOURCES hotelWorkerTests.cpp scheduleTests.cpp hotelRoomTests.cpp hotel_guestTests.cpp dutyEntryTests.cpp)
add_executable(Google_Tests_run ${SOURCES})

target_link_libraries(Google_Tests_run gtest gtest_main)
target_link_libraries(Google_Tests_run core)