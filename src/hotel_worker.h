#ifndef HOTEL_WORKER_H
#define HOTEL_WORKER_H
#include <string>
#include "schedule.h"

class HotelWorker {
    std::string firstName;
    std::string lastName;
    std::string position;
    long double salary;
    int permissionLevel;
    Schedule schedule;

public:
    HotelWorker();
    void setFirstName(const std::string&);
    void setLastName(const std::string&);
    void setPosition(const std::string&);
    void setSalary(const long double&);
    void setPermissionLevel(const int&);
    void setSchedule(const Schedule&);

    std::string getFirstName();
    std::string getLastName();
    std::string getPosition();
    long double getSalary();
    int getPermissionLevel();
    Schedule getSchedule();

    void printSchedule();
    void addDutyToSchedule(std::string day, const unsigned int hour, const unsigned int minutes, std::string duty);



    friend std::ostream& operator<<(std::ostream&, const HotelWorker&);


};


#endif //HOTEL_WORKER_H
