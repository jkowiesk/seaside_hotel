#ifndef TEST_H
#define TEST_H
#include "hotel_room.h"
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
    void doTask();
    void printDuty();
    void printTask(unsigned int hour, unsigned int minutes, std::string msg);

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
    std::vector<int> ranges;
    std::vector<std::pair<std::string, std::string>> guestNames;
    std::vector<DutyEntry> duties;
    int guestIndex;
    int numberOfDays;
    int numberOfRooms;
    int busyness;
    int rand;
    const int numberOfActions = 5;
    Hotel hotel;
public:
    void main();
};


#endif //TEST_H
