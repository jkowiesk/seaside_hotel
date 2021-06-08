#ifndef HOTEL_ROOM_H
#define HOTEL_ROOM_H
#include "equipment.h"
#include <iostream>
#include <vector>
#include <string>
#include "hotel_guest.h"

//class Guest
//{
//    std::string name;
//public:
//    friend
//    std::ostream& operator<< (std::ostream &os, const Guest g)
//    {
//        os << "Guest name: " << g.name;
//        return os;
//    }
//};


class HotelRoom
{
    int number;
    int slots;
    int floor;
    int area;
    std::vector<Equipment> equipmentList;
    std::vector<Guest> guestList;
public:
    HotelRoom() {}
    HotelRoom(int n) : number(n) {}
    HotelRoom(int number, int slots, int floor, int area) : number(number), slots(slots), floor(floor), area(area) {}
    int getNumber();
    void setNumber(int newNumber);
    int getSlots();
    void setSlots(int newSlots);
    void emptySlots();
    int getFloor();
    void setFloor(int newFloor);
    int getArea();
    void setArea(int newSize);
    std::vector<Equipment> getEquipment();
    void printEquipment();
    void addEquipment(Equipment newEq);
    void removeEquipment(int choice);
    std::vector<Guest> getGuests();
    void printGuests();
    void addGuest(Guest newGuest);
    void removeGuest(int choice);

    friend
    std::ostream& operator<< (std::ostream &os, const HotelRoom room);
    bool operator== (const HotelRoom room)
    {
        if (number == room.number)
        { return true; }
        else
        { return false; }
    };
    bool operator!= (const HotelRoom room)
    {
        if (number != room.number)
        { return true; }
        else
        { return false; }
    };
};

class SingleRoom: public HotelRoom
{
public:
    SingleRoom() {}
    SingleRoom(int number, int floor, int area) : HotelRoom(number, 1, floor, area) {
        Bed bed01(1);
        this->addEquipment(bed01);
    }
};

class TwinRoom: public HotelRoom
{
public:
    TwinRoom() {}
    TwinRoom(int number, int floor, int area) : HotelRoom(number, 2, floor, area) {
        Bed bed01(2);
        this->addEquipment(bed01);
    }
};

class DoubleRoom: public HotelRoom
{
public:
    DoubleRoom() {}
    DoubleRoom(int number, int floor, int area) : HotelRoom(number, 2, floor, area) {
        DoubleBed bed01(1);
        this->addEquipment(bed01);
    }
};

class TripleRoom: public HotelRoom
{
public:
    TripleRoom() {}
    TripleRoom(int number, int floor, int area) : HotelRoom(number, 3, floor, area) {
        Bed bed01(1);
        DoubleBed bed02(1);
        this->addEquipment(bed01);
        this->addEquipment(bed02);
    }
};

class SquadRoom: public HotelRoom
{
public:
    SquadRoom() {}
    SquadRoom(int number, int floor, int area) : HotelRoom(number, 4, floor, area) {
        Bed bed01(2);
        DoubleBed bed02(1);
        this->addEquipment(bed01);
        this->addEquipment(bed02);
    }
};

class Dormitory: public HotelRoom
{
public:
    Dormitory() {}
    Dormitory(int number, int slots, int floor, int area) : HotelRoom(number, slots, floor, area) {
        Bed bed01(slots);
        this->addEquipment(bed01);
    }

};

#endif