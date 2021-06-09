#ifndef HOTEL_WORKERS_H
#define HOTEL_WORKERS_H
#include "hotel_worker.h"

class Waiter : public HotelWorker {
public:
    Waiter(std::string firstName, std::string lastName) {
        HotelWorker(firstName, lastName, "Waiter", 1500, 1);
        addEveryDayDutyToSchedule(7, 30, "Clean tables");
        addDutyToSchedule("Sunday", 18, 00, "Get paycheck");
    }

};

class Cook : public HotelWorker {
public:
    Cook(std::string firstName, std::string lastName) {
        HotelWorker(firstName, lastName, "Cook", 3000, 2);
        addEveryDayDutyToSchedule(7, 30, "Check freshness of food");
        addEveryDayDutyToSchedule(8, 0, "Preheat oven");
        addDutyToSchedule("Sunday", 18, 00, "Get paycheck");
    }

};

class Receptionists : public HotelWorker {
public:
    Receptionists(std::string firstName, std::string lastName) {
        HotelWorker(firstName, lastName, "Receptionists", 2500, 3);
        addEveryDayDutyToSchedule(8, 0, "Start work on reception");
        addDutyToSchedule("Monday", 15, 00, "Check if all rooms have keys");
        addDutyToSchedule("Sunday", 18, 00, "Get paycheck");
    }

};

class Maid : public HotelWorker {
public:
    Maid(std::string firstName, std::string lastName) {
        HotelWorker(firstName, lastName, "Maid", 1000, 1);
        addEveryDayDutyToSchedule(6, 0, "Start cleaning");
        addDutyToSchedule("Sunday", 18, 00, "Order new detergents");
    }

};


#endif //HOTEL_WORKERS_H
