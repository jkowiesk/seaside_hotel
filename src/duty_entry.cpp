#include "duty_entry.h"
#include <iostream>

DutyEntry::DutyEntry(const unsigned newHour, const unsigned int newMintues, const std::string newDuty) {
    hour = newHour;
    minutes = newMintues;
    duty = newDuty;
}

inline unsigned int DutyEntry::getHour() {
    return hour;
}

inline unsigned int DutyEntry::getMinutes() {
    return minutes;
}

inline std::string DutyEntry::getDuty() {
    return duty;
}

bool DutyEntry::operator <(const DutyEntry& dutyEntry) {
    bool isEarlierSameHour = (hour == dutyEntry.hour && minutes < dutyEntry.minutes) ? true : false;

    if (hour < dutyEntry.hour || isEarlierSameHour) {
        return true;
    } else {
        return false;
    }
}

std::ostream& operator <<(std::ostream& os, const DutyEntry& dutyEntry) {
    os << dutyEntry.hour << ":" << dutyEntry.minutes << " " << dutyEntry.duty;
    return os;
}