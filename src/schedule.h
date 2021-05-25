#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <map>
#include "duty_entry.h"
#include <vector>

class Schedule {
    std::map<std::string, std::vector<DutyEntry>> scheduleMap;

public:
    Schedule();
    void addDuty(std::string, DutyEntry);
    std::vector<DutyEntry> getDuties(std::string);
    friend std::ostream& operator<<(std::ostream&, const Schedule&);
};


#endif //SCHEDULE_H
