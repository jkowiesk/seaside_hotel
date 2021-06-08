#ifndef HOTEL_WORKERS_H
#define HOTEL_WORKERS_H
#include "hotel_worker_api.h"

class Waiter : public HotelWorkerAPI {
public:
    Waiter() {
        HotelWorkerAPI("","", "Waiter", 1500, 1);
        addEveryDayDutyToSchedule(7, 30, "Clean tables");
        addDutyToSchedule("Sunday", 18, 00, "Get paycheck");
    }

};

class Cook : public HotelWorkerAPI {
public:
    Cook() {
        HotelWorkerAPI("","", "Cook", 3000, 2);
        addEveryDayDutyToSchedule(7, 30, "Check freshness of food");
        addEveryDayDutyToSchedule(8, 0, "Preheat oven");
        addDutyToSchedule("Sunday", 18, 00, "Get paycheck");
    }

};

class Receptionists : public HotelWorkerAPI {
public:
    Receptionists() {
        HotelWorkerAPI("","", "Receptionists", 2500, 3);
        addEveryDayDutyToSchedule(8, 0, "Start work on reception");
        addDutyToSchedule("Monday", 15, 00, "Check if all rooms have keys");
        addDutyToSchedule("Sunday", 18, 00, "Get paycheck");
    }

};

class Maid : public HotelWorkerAPI {
public:
    Maid() {
        HotelWorkerAPI("","", "Maid", 1000, 1);
        addEveryDayDutyToSchedule(6, 0, "Start cleaning");
        addDutyToSchedule("Saturday", 12, 00, "Order new detergents");
        addDutyToSchedule("Sunday", 18, 00, "Get paycheck");
    }

};


#endif //HOTEL_WORKERS_H