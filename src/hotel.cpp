#include "hotel.h"
#include "hotel_room.h"
#include "hotel_guest.h"
#include "duty_entry.h"
#include <cmath>

void Hotel::createRooms(std::vector<int> rooms) {
    // roomArr[2, 3, 4, 1, 2, 5, 2, 5, 2]
    for (int i=0; i < rooms.size() ; i++) {
        switch (rooms[i])
        {
        case 1:
            availableRooms.push_back(SingleRoom(i+1, i+1%i/3, 12));
            break;
        case 2:
            availableRooms.push_back(DoubleRoom(i+1, i+1%i/3, 24));
            break;
        case 3:
            availableRooms.push_back(TripleRoom(i+1, i+1%i/3, 30));
            break;
        case 4:
            availableRooms.push_back(SquadRoom(i+1, i+1%i/3, 36));
            break;
        default:
            availableRooms.push_back(Dormitory(i+1, rooms[i], i+1%i/3, 40));
            break;
        }
    }
}
void Hotel::hireWorkers(std::vector<std::pair<std::string, std::string>> names) {
    for (int i=0;i<availableRooms.size()/10;i++) {
        hotelWorkers.insert({i, Maid(names[i].first, names[i].second)});
    }
};
int Hotel::addGuest(Guest guest)
{
    guests.insert({indexGuests++, guest});
    for (int i=0; i < availableRooms.size() ; i++) {
        if ( availableRooms[i].emptySlots() > 0){
            availableRooms[i].addGuest(guest);
            guest.bookedRoom = &availableRooms[i];
        }
    }
}
double Hotel::calculateVisitCost(HotelRoom room, Guest guest)
{
    int cost = 0;
    for (int i = 0; i < guest.get_visitLength(); i++)
    {
        cost += 50 * pow(0.8 , i) + 0.5 * room.getArea() + 0.3 * room.getFloor();
    }
    return cost;
}
void Hotel::checkVisitTimes() {
    for (int i=0; i < availableRooms.size() ; i++) {
        for (int j=0; j < availableRooms[i].getGuests().size();j++) {
            availableRooms[i].getGuests()[j].dayPassed();
            if (availableRooms[i].getGuests()[j].visitEnded()) {
                // need to communicate that somehow
                int payment = calculateVisitCost(availableRooms[i], availableRooms[i].getGuests()[j]);
                charge(payment);
                availableRooms[i].removeGuest(j);
                std::cout << "Guest from room number" << i+1 << "checked out and paid" << payment << "." << std::endl;
            }
        }
    }
}
int Hotel::cleanRooms() {
    int noCleaned;
    for (int i=0; i < availableRooms.size() ; i++) {
        if (availableRooms[i].emptySlots() > 0) {
            noCleaned ++;
        }
    }
    return noCleaned;
    // std::cout << noCleaned << " were cleaned." << std::endl;
}

std::vector<DutyEntry> Hotel::getOnDuty(unsigned int hour, std::string day) {
    std::vector<HotelWorker> tempHotelWorkers;
    std::vector<DutyEntry> duties;
    for (auto& kv : hotelWorkers) {
        for(auto& duty : kv.second.getSchedule().getDuties(day)) {
            if (duty.getHour() == hour)
                duties.push_back(duty);
                break;
        }
    }
    return du;
}
void Hotel::guestOrdersEq(int guestId, Equipment eq) {
    guests[guestId].bookedRoom->addEqupment(eq);
}
std::string Hotel::guestCallsTaxi(int guestId) {
    return guests[guestId].get_surname();
}
