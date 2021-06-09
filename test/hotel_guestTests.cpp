#include <gtest/gtest.h>
#include "../src/hotel_guest.h"
#include <sstream>

TEST(Geust, set_name) {
    Guest Jarek;
    Jarek.set_name("Jarek");
    EXPECT_EQ(Jarek.get_name(), "Jarek");
}

TEST(Guest, set_surname) {
    Guest guest;
    guest.set_surname("Nowak");
    EXPECT_EQ(guest.get_surname(), "Nowak");
}

TEST(Guest, document){
    Document doc("legitka", "123455");
    Guest guest;
    guest.set_document(doc);
    EXPECT_EQ(guest.get_document()==doc, true);
}

TEST(Guest, check_in){
   Guest guest;
   guest.set_check_in(14);
   EXPECT_EQ(guest.get_check_in(), 14);
}

TEST(Guest, check_out){
    Guest guest;
    guest.set_check_out(10);
    EXPECT_EQ(guest.get_check_out(), 10);
}
