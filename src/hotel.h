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
    int income;
    int cost;
    int indexGuests;
public:
    int getGuestsIndex() {return indexGuests;}
    std::map<int, HotelWorker> hotelWorkers;
    std::map<int, Guest> guests;
    std::vector<HotelRoom> availableRooms;
    Hotel() {}
    void createRooms(std::vector<int> rooms);
    void hireWorkers(std::vector<std::pair<std::string, std::string>> names);
    int addGuest(Guest guest);
    void checkVisitTimes();
    int getNumberOfGuests();
    void charge(int value) {income+=value;}
    void pay(int value) {cost+=value;}
    double calculateVisitCost(HotelRoom room, Guest guest);
    int cleanRooms();
    void guestOrdersEq(int guestId, Equipment eq);
    std::string guestCallsTaxi(int guestId);
    std::vector<DutyEntry> getOnDuty(unsigned int hour, std::string day);
};
#endif
    // for (const auto& kv : options) {
    //     std::cout << kv.first << ") " << kv.second << std::endl;
    // }
    // map.insert({ 2, 30 });