#include <gtest/gtest.h>
#include "../src/hotel_worker.h"

TEST(HotelWorker, constructor) {
    HotelWorker marek;

    EXPECT_EQ(marek.getSalary(), -1);
}

TEST(HotelWorker, setFirstName) {
    HotelWorker marek;

    EXPECT_EQ(marek.getSalary(), -1);
}