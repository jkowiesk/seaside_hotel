#ifndef HOTEL_WORKERS_H
#define HOTEL_WORKERS_H
#include "hotel_worker.h"

class Waiter : public HotelWorker {
public:
    Waiter(std::string firstName, std::string lastName) : HotelWorker(firstName, lastName, "Waiter", 1500, 1) {
        addEveryDayDutyToSchedule(7, 30, "Clean tables");
    }

};

class Cook : public HotelWorker {
public:
    Cook(std::string firstName, std::string lastName) : HotelWorker(firstName, lastName, "Cook", 3000, 2) {
        addEveryDayDutyToSchedule(7, 30, "Check freshness of food");
    }

};

class Receptionists : public HotelWorker {
public:
    Receptionists(std::string firstName, std::string lastName) : HotelWorker(firstName, lastName, "Receptionists", 2500, 3) {
        addDutyToSchedule("Sunday", 18, 00, "Get paycheck");
    }

};

class Maid : public HotelWorker {
public:
    Maid(std::string firstName, std::string lastName) : HotelWorker(firstName, lastName, "Maid", 1000, 1) {
        addDutyToSchedule("Sunday", 6, 00, "Clean all rooms");
    }

};


#endif //HOTEL_WORKERS_H
