#ifndef DUTY_ENTRY_H
#define DUTY_ENTRY_H
#include <string>
#include <iostream>

class DutyEntry {
    unsigned int hour;
    unsigned int minutes;
    std::string duty;

public:
    DutyEntry(const unsigned int, const unsigned int, const std::string);
    unsigned int getHour();
    unsigned int getMinutes();
    std::string getDuty();

    bool operator<(const DutyEntry&);
    friend std::ostream& operator<<(std::ostream&, const DutyEntry&);

    inline bool operator==(const DutyEntry& other) const {
        return (hour == other.hour && minutes == other.minutes && duty == other.duty);
    }

};


#endif //DUTY_ENTRY_H
