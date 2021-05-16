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
    bool operator<(const DutyEntry&);
    friend std::ostream& operator<<(std::ostream&, const DutyEntry&);


};


#endif //DUTY_ENTRY_H
