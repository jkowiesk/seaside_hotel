#ifndef HOTEL_WORKER_API_H
#define HOTEL_WORKER_API_H
#include "hotel_worker.h"

class HotelWorkerAPI {
    HotelWorker worker;
public:
    HotelWorkerAPI(std::string newFirstName="", std::string newLastName="",
                   std::string newPosition="", long double newSalary=-1, int newPermissionLevel=-1):
    worker(newFirstName, newLastName, newPosition, newSalary, newPermissionLevel) {}

    virtual void addEveryDayDutyToSchedule(const unsigned int hour, const unsigned int minutes, std::string duty) {
    std::vector<std::string> weekDays {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    for (const auto& weekDay : weekDays) {
        worker.addDutyToSchedule(weekDay, hour, minutes, duty);
    }
}

virtual void addDutyToSchedule(std::string day, const unsigned int hour, const unsigned int minutes, std::string duty) {
    worker.addDutyToSchedule(day, hour, minutes, duty);
}

virtual void printSchedule() {
    std::cout << worker.getSchedule();
}

};

#endif // HOTEL_WORKER_API_H