#ifndef HOTEL_WORKERS_H
#define HOTEL_WORKERS_H
#include "hotel_worker.h"

class Waiter : virtual public HotelWorker {
public:
    Waiter() {
        HotelWorker("","", "", -1, 1);
        addEveryDayDutyToSchedule(7, 30, "Clean tables");
        addDutyToSchedule("Friday", 18, 20, "Get paycheck");
    }

};

#endif //HOTEL_WORKERS_H