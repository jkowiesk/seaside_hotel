#include <iostream>
#include <time.h>
#include "hotel.h"
#include "windows.h"

void cleanRooms(Hotel hotel)
{
    // add cleaning to workers schedules
    std::cout << hotel.availableRooms.size() << " pokojów zostało wyczyszczonych." << std::endl;
}
void guestArrival(Hotel hotel, int guests=1, int period=1)
{
    int number = hotel.addGuests(guests);
    std::cout << guests << " gości zostało zakwaterowanych w pokoju numer " << number
              << "na " << period << "dni." << std::endl;
}
void guestOrdersEquipment(Hotel hotel)
{
    std::cout << "Gość z pokoju " << " zamawia dodatkowe wyposarzenie do pokoju. " << std::endl;
}
void guestOrdersTaxi(Hotel hotel)
{
    std::cout << "Gość z pokoju " << " zamawia taksówkę. " << std::endl;
}
void payWorkers(Hotel hotel)
{
    // calculate and add workers' salaries
    //std::cout << hotel.workers.size() << " otrzymało wypłatę na łączną kwotę " << std::endl;
    std::cout  << " otrzymało wypłatę na łączną kwotę " << std::endl;
}
void loop(int days, int hotelSize=30, int busyness=1)
{
    Hotel seasideHotel(hotelSize);
    std::cout << "Witamy w naszym hotelu!" << std::endl;
    for(int day = 1; day <= days; day++)
    {
        std::cout << "Dzień " << day << std::endl;
        // random actions
        for(int i=0;i<busyness;i++)
        {
            switch(rand()%5+1)
            {
                case 1:
                    guestArrival(seasideHotel, rand()%3+1, rand()%7+1);
                    break;
                case 2:
                    guestOrdersTaxi(seasideHotel);
                    break;
                case 3:
                    guestOrdersEquipment(seasideHotel);
                    break;
            }
        }
        // guaranteed actions
        cleanRooms(seasideHotel);
        if(day%7==0) {payWorkers(seasideHotel);}
        if(seasideHotel.guestCheckOut()) {}
        // write all actions of each loop iteration to output file
        Sleep(1000);
    }
}
int main()
{
    srand (time(NULL)); // use <random> library
    loop(5, 20, 3);
    return 0;
}
