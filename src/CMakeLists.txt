cmake_minimum_required(VERSION 3.19)

set(CORE_SOURCES hotel_worker.cpp duty_entry.cpp schedule.cpp hotel_room.cpp hotel.cpp simulation.cpp hotel_guest.cpp)

add_library(core ${CORE_SOURCES})
