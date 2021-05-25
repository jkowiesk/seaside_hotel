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