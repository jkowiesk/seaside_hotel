#include "hotel.h"
#include "hotel_room.h"
#include "hotel_guest.h"
#include <cmath>

void Hotel::createRooms(int roomArray[]) {
    // roomArr[2, 3, 4, 1, 2, 5, 2, 5, 2]
    for (int i=0; i < ; i++)
    {

    }
}
int Hotel::addGuests(int guestsNumber) {
    if(guestsNumber==1){
        SingleRoom room1(rand()%100, rand()%10, rand()%30+10);
        room1.addGuest(Guest("Andrzej", "Zalew"));
        return room1.getNumber();

    }
    else if(guestsNumber==2){
        DoubleRoom room2(rand()%100, rand()%10, rand()%30+10);
        Guest guest1, guest2;
        room2.addGuest(guest1);
        room2.addGuest(guest2);
        return room2.getNumber();
    }
    else{
        HotelRoom room(rand()%100, guestsNumber, rand()%10, rand()%30+10);
        // implement abstract factory
        return room.getNumber();
    }
}
double Hotel::calculateDailyCost(HotelRoom room)
{
    int dayCost = 0;
    for (int i = 0; i < room.getSlots(); i++)
    {
        dayCost += 50 * pow(0.8 , i);
    }
    dayCost += 0.5 * room.getArea() + 0.3 * room.getFloor();
    return dayCost;
}
double Hotel::calculateVisitCost(HotelRoom room, Guest guest)
{
    double dayCost = calculateDailyCost(room);
    return guest.get_visitLength() * dayCost;
}