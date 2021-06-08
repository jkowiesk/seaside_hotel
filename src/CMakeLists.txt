cmake_minimum_required(VERSION 3.19)

set(CORE_SOURCES hotel_worker.cpp duty_entry.cpp schedule.cpp test.cpp simulation.cpp hotel.cpp hotel_room.cpp)

add_library(core ${CORE_SOURCES})