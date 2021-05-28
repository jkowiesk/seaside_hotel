#include "hotel_worker.h"
#include <iostream>
#include <string>

// set methods
void HotelWorker::setFirstName(const std::string& newFirstName) {
    firstName = newFirstName;
}

void HotelWorker::setLastName(const std::string& newLastName) {
    lastName = newLastName;
}

void HotelWorker::setPosition(const std::string& newPosition) {
    position = newPosition;
}

void HotelWorker::setPermissionLevel(const int& newPermissionLevel) {
    permissionLevel = newPermissionLevel;
}

void HotelWorker::setSalary(const long double& newSalary) {
    salary = newSalary;
}

void HotelWorker::setSchedule(const Schedule& newSchedule) {
    schedule = newSchedule;
}


// get methods
std::string HotelWorker::getFirstName() {
    return firstName;
}

std::string HotelWorker::getLastName() {
    return lastName;
}

std::string HotelWorker::getPosition() {
    return position;
}

int HotelWorker::getPermissionLevel() {
    return permissionLevel;
}

long double HotelWorker::getSalary() {
    return salary;
}

Schedule HotelWorker::getSchedule() {
    return schedule;
}

void HotelWorker::printSchedule() {
    std::cout << schedule;
}

void HotelWorker::addDutyToSchedule(std::string day, const unsigned int hour, const unsigned int minutes, std::string duty) {
    schedule.addDuty(day, DutyEntry(hour, minutes, duty));
}

void HotelWorker::addEveryDayDutyToSchedule(const unsigned int hour, const unsigned int minutes, std::string duty) {
    std::vector<std::string> weekDays {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    for (const auto& weekDay : weekDays) {
        schedule.addDuty(weekDay, DutyEntry(hour, minutes, duty));
    }

}

std::ostream& operator <<(std::ostream& os, const HotelWorker& worker) {
    if (!worker.firstName.empty())
        os << "First Name: " << worker.firstName << "\n";
    else
        os << "First Name: undefined\n";

    if (!worker.lastName.empty())
        os << "Last Name: " << worker.lastName << "\n";
    else
        os << "Last Name: undefined\n";

    if (!worker.position.empty())
        os << "Position: " << worker.position << "\n";
    else
        os << "Position: undefined\n";

    if (worker.salary != -1)
        os << "Salary: " << worker.salary << "\n";
    else
        os << "Salary: undefined\n";

    if (worker.permissionLevel != -1)
        os << "Permission level: " << worker.permissionLevel << "\n";
    else
        os << "Permission level: undefined\n";


    return os;
}





