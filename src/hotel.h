#ifndef HOTEL_H
#define HOTEL_H
#include "hotel_room.h"
#include "hotel_guest.h"
#include "hotel_worker.h"
#include "hotel_workers.h"
#include <vector>
#include <string>
#include <utility>


class Hotel
{
    int indexGuests = 0;
public:
    int income = 0;
    int cost = 0;
    int getGuestsIndex() {return indexGuests;}
    std::map<int, HotelWorker> hotelWorkers;
    std::map<int, Guest> guests;
    std::vector<HotelRoom> availableRooms;
    Hotel() {}
    void createRooms(std::vector<int> rooms);
    void hireWorkers(std::vector<std::pair<std::string, std::string>> names);
    void addGuest(Guest guest, int visitLength);
    void checkVisitTimes();
    int getNumberOfGuests();
    void charge(int value) {income+=value;}
    void pay(int value) {cost+=value;}
    double calculateVisitCost(HotelRoom room, Guest guest);
    int cleanRooms();
    void guestOrdersEq(int roomId, Equipment eq);
    void guestCallsTaxi(int guestId);
    std::vector<std::pair<HotelWorker, DutyEntry>> getOnDuty(unsigned int hour, std::string day);
};
#endif