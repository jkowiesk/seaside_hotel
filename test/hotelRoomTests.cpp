#include <gtest/gtest.h>
#include "../src/hotel_room.h"
#include "../src/hotel_guest.h"
#include "../src/equipment.h"
#include <sstream>


TEST(HotelRoom, constructor) {
    HotelRoom room(515, 2, 10, 40);
    EXPECT_EQ(room.getNumber(), 515);
    EXPECT_EQ(room.getSlots(), 2);
    EXPECT_EQ(room.getFloor(), 10);
    EXPECT_EQ(room.getArea(), 40);
}

TEST(HotelRoom, setNumber) {
    HotelRoom myRoom(515, 2, 10, 40);
    EXPECT_EQ(myRoom.getNumber(), 515);
    myRoom.setNumber(420);
    EXPECT_EQ(myRoom.getNumber(), 420);
}

TEST(HotelRoom, setSlots) {
    HotelRoom myRoom(515, 2, 10, 40);
    EXPECT_EQ(myRoom.getSlots(), 2);
    myRoom.setSlots(4);
    EXPECT_EQ(myRoom.getSlots(), 4);
}

TEST(HotelRoom, setFloor) {
    HotelRoom myRoom(515, 2, 10, 40);
    EXPECT_EQ(myRoom.getFloor(), 10);
    myRoom.setFloor(20);
    EXPECT_EQ(myRoom.getFloor(), 20);
}

TEST(HotelRoom, setArea) {
    HotelRoom myRoom(515, 2, 10, 40);
    EXPECT_EQ(myRoom.getArea(), 40);
    myRoom.setArea(70);
    EXPECT_EQ(myRoom.getArea(), 70);
}

TEST(HotelRoom, addGuest) {
    HotelRoom myRoom(515, 2, 10, 40);
    Guest myGuest;
    myRoom.addGuest(myGuest);
    EXPECT_EQ(myRoom.getGuests().size(), 1);
}

TEST(HotelRoom, getGuests) {
    HotelRoom myRoom(515, 3, 10, 40);
    Guest myGuest1, myGuest2, myGuest3;
    myRoom.addGuest(myGuest1);
    myRoom.addGuest(myGuest2);
    myRoom.addGuest(myGuest3);
    EXPECT_EQ(myRoom.getGuests().size(), 3);
}

TEST(HotelRoom, removeGuest) {
    HotelRoom myRoom(515, 2, 10, 40);
    Guest myGuest;
    myRoom.addGuest(myGuest);
    EXPECT_EQ(myRoom.getGuests().size(), 1);
    myRoom.removeGuest(1);
    EXPECT_EQ(myRoom.getGuests().size(), 0);
}

TEST(HotelRoom, addEquipment) {
    HotelRoom myRoom(515, 2, 10, 40);
    Equipment myEq;
    myRoom.addEquipment(myEq);
    EXPECT_EQ(myRoom.getEquipment().size(), 1);
}

TEST(HotelRoom, getEquipment) {
    HotelRoom myRoom(515, 3, 10, 40);
    Equipment myEq1, myEq2, myEq3;
    myRoom.addEquipment(myEq1);
    myRoom.addEquipment(myEq2);
    myRoom.addEquipment(myEq3);
    EXPECT_EQ(myRoom.getEquipment().size(), 3);
}

TEST(HotelRoom, removeEqipment) {
    HotelRoom myRoom(515, 2, 10, 40);
    Equipment myEq;
    myRoom.addEquipment(myEq);
    EXPECT_EQ(myRoom.getEquipment().size(), 1);
    myRoom.removeEquipment(1);
    EXPECT_EQ(myRoom.getEquipment().size(), 0);
}