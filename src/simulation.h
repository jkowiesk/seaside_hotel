#ifndef TEST_H
#define TEST_H
#include "hotel_room.h"
#include "hotel_worker.h"
#include "duty_entry.h"
#include <map>
#include <string>
#include "hotel.h"
#include <vector>
#include <sstream>

class Simulation {

    void getParams();
    void promptMsg(std::string);
    int randomizeInstant(int, int);
    std::vector<int> generateHours();
    std::string doTask();
    void printDuty(HotelWorker, DutyEntry);
    void printDay(int, std::string);
    void printTask(unsigned int, std::string);
    void printTask(unsigned int, unsigned int , std::string);

    void randomize(int);
    void run();
    void greetUser();
    void init();
    void cleanSstream();
    void addGuest();

    std::string file_out_string;
    std::stringstream ss;
    std::string msg;
    std::map<int, std::string> intToDay;
    std::vector<std::pair<std::string, std::string>> guestNames;
    std::vector<DutyEntry> duties;
    int numberOfDays;
    int numberOfRooms;
    int busyness;
    std::vector<int> hours;
    const int numberOfActions = 5;
    Hotel hotel;
public:
    void main();
};


#endif //TEST_H
