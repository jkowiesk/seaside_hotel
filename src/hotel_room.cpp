#include <iostream>
#include "hotel_room.h"


int HotelRoom::getNumber()
{
    return number;
}
void HotelRoom::setNumber(int newNumber)
{
    number = newNumber;
}

int HotelRoom::getSlots()
{
    return slots;
}
void HotelRoom::setSlots(int newSlots)
{
    slots = newSlots;
}
int HotelRoom::emptySlots()
{
    int empty = slots - guestList.size();
    return empty;
}

int HotelRoom::getFloor()
{
    return floor;
}
void HotelRoom::setFloor(int newFloor)
{
    floor = newFloor;
}

int HotelRoom::getArea()
{
    return area;
}
void HotelRoom::setArea(int newSize)
{
    area = newSize;
}
std::vector<Equipment> HotelRoom::getEquipment()
{
    return equipmentList;
}
void HotelRoom::printEquipment()
{
    if (equipmentList.size() == 0)
    {
        std::cout << "There is no equipment in this room.";
    }
    else
    {
        std::cout << "Equipment in HotelRoom " << number << ":" << std::endl;
        for (int i=0; i < equipmentList.size(); i++)
        {
            std::cout << i + 1 << ". " << equipmentList[i] << std::endl;
        }
    }
}
void HotelRoom::addEquipment(Equipment newEq)
{
    equipmentList.push_back(newEq);
}
void HotelRoom::removeEquipment(int choice)
{
    while(std::cin.fail() | choice < 1 | choice > equipmentList.size())
    {
        std::cout << "Wrong input. Choose equipment from the list. ";
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cin >> choice;
    }
    equipmentList.erase (equipmentList.begin() + choice -1);
}

std::vector<Guest> HotelRoom::getGuests()
{
    return guestList;
}
void HotelRoom::printGuests()
{   if (guestList.size() == 0)
    {
        std::cout << "There are no guests in this room.";
    }
    else
    {
        std::cout << "Guests in HotelRoom " << number << ":" << std::endl;
        for (int i=0; i < guestList.size(); i++)
        {
            std::cout << i + 1 << ". " << equipmentList[i] << std::endl;
        }
    }
}
void HotelRoom::addGuest(Guest newGuest)
{
    if (guestList.size() < slots)
    {
        guestList.push_back(newGuest);
    }
    else
    {
        std::cout << "This room is full!" << std::endl;
    }
}
void HotelRoom::removeGuest(int choice)
{
    while(std::cin.fail() | choice < 1 | choice > guestList.size())
    {
        std::cout << "Wrong input. Choose a guest from the list. ";
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cin >> choice;
    }
    guestList.erase (guestList.begin() + choice);
}


std::ostream& operator<< (std::ostream &os, const HotelRoom room)
{
    os <<  "Rooom number: " << room.number << "   Slots: " << room.slots << "   Floor: " << room.floor << "   Area: " << room.area;
    return os;
}