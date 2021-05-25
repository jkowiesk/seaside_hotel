#include "schedule.h"
#include <iostream>
#include <vector>
#include "duty_entry.h"

Schedule::Schedule() {
    std::vector<DutyEntry> emptyVector;
    scheduleMap = {
            {"Monday", emptyVector},
            {"Tuesday", emptyVector},
            {"Wednesday", emptyVector},
            {"Thursday", emptyVector},
            {"Friday", emptyVector},
            {"Saturday", emptyVector},
            {"Sunday", emptyVector}
    };
}

void Schedule::addDuty(const std::string day, DutyEntry dutyEntry) {
    if (!scheduleMap[day].empty()) {
        std::vector<DutyEntry>::iterator it = scheduleMap[day].begin();

        while (*it < dutyEntry)
            it++;

        scheduleMap[day].insert(it, dutyEntry);

    } else {
        scheduleMap[day].push_back(dutyEntry);

    }
}

std::vector<DutyEntry> Schedule::getDuties(std::string day) {
    return scheduleMap.at(day);
}

std::ostream& operator<<(std::ostream& os,const Schedule& schedule) {
    std::vector<std::string> weekDays {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    os << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;

    for (const auto& weekDay : weekDays) {
        os << weekDay << ")";
            for (const auto& duty : schedule.scheduleMap.at(weekDay)) {
                os << "\t" << duty;
            }
            os << std::endl;
    }
    os << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;

    return os;
}

