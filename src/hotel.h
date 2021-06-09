#ifndef HOTEL_H
#define HOTEL_H
#include "hotel_room.h"
#include "hotel_guest.h"
#include "hotel_worker.h"
#include <vector>


class Hotel
{
    int income;
    int cost;
public:
    std::vector<HotelRoom> availableRooms;
    //std::vector<HotelWorker> workers;
    Hotel() {}
    Hotel(int n) { createRooms(n);}
    void createRooms(int hotelSize);
    int addGuests(int guestsNumber);
    bool guestCheckOut() {return true;}
    void charge(int value) {income+=value;}
    void pay(int value) {cost+=value;}
    double calculateDailyCost(HotelRoom room);
    double calculateVisitCost(HotelRoom room, Guest guest);

};
#endif