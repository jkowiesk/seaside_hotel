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

std::ostream& operator<<(std::ostream& os,const Schedule& schedule) {
    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
    for (const auto& kv : schedule.scheduleMap) {
        std::cout << kv.first << ")";
        for (auto duty : kv.second) {
            std::cout << "\t" << duty;
        }
        std::cout << std::endl;
    }
    std::cout << "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;

    return os;
}

