#include <gtest/gtest.h>
#include "../src/hotel_worker.h"
#include <sstream>

TEST(HotelWorker, constructor) {
    HotelWorker marek;

    EXPECT_EQ(marek.getSalary(), -1);
}

TEST(HotelWorker, setFirstName) {
    HotelWorker marek;

    marek.setFirstName("Marek");
    EXPECT_EQ(marek.getFirstName(), "Marek");
}

TEST(HotelWorker, setPosition) {
    HotelWorker marek;

    marek.setPosition("Maid");
    EXPECT_EQ(marek.getPosition(), "Maid");
}

TEST(HotelWorker, setPermissionLevel) {
    HotelWorker marek;

    marek.setPermissionLevel(1);
    EXPECT_EQ(marek.getPermissionLevel(), 1);
}

TEST(HotelWorker, setSalary) {
    HotelWorker marek;

    marek.setSalary(1000);
    EXPECT_EQ(marek.getSalary(), 1000);
}