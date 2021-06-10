#include "simulation.h"
#include <iostream>
#include "io_module.h"
#include <random>
#include <functional>
#include <vector>
#include <utility>
#include <sstream>
#include <algorithm>
#include <thread>
#include <chrono>

void Simulation::init() {
    intToDay = {
            {0, "Monday"},
            {1, "Tuesday"},
            {2, "Wednesday"},
            {3, "Thursday"},
            {4, "Friday"},
            {5, "Saturday"},
            {6, "Sunday"}
    };


    guestIndex = 0;

    guestNames = io::getNames("guestList.txt");
    std::vector<int> rooms;
    for (int j = 0; j < numberOfRooms;j++) {
        rooms.push_back(randomizeInstant(1, 5));
    }
    hotel.createRooms(rooms);
    hotel.hireWorkers(io::getNames("workerList.txt"));
}

int Simulation::randomizeInstant(int minInt, int maxInt) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(minInt, maxInt);
    int num = dist(mt);
    return num;
}

std::vector<int> Simulation::generateHours() {
    std::vector<int> hours;
    for (int i = 0; i < busyness; i++) {
        hours.push_back(randomizeInstant(1, 23));
    }
    std::sort(hours.begin(), hours.end());
    return hours;
}

void Simulation::cleanSstream() {
    ss.str(std::string());
}

void Simulation::addGuest() {
    hotel.addGuest(Guest(guestNames[hotel.getGuestsIndex() % 200].first, guestNames[hotel.getGuestsIndex() % 200].second), randomizeInstant(1, numberOfDays));
    ss << "0:00: " << guestNames[hotel.getGuestsIndex() % 200].first << " " << guestNames[hotel.getGuestsIndex() % 200].second << " registered\n";

    std::cout << ss.str();
    file_out_string.append(ss.str());
    cleanSstream();
}

void Simulation::getParams() {
    promptMsg("Type number of days to simulate:");
    numberOfDays = io::getInt();

    promptMsg("Type number of rooms in hotel:");
    numberOfRooms = io::getInt();

    promptMsg("Type how many interactions each day:");
    busyness = io::getInt();

}

void Simulation::promptMsg(std::string msg) {
    std::cout << msg << std::endl;
}

void Simulation::printDay(int day, std::string msg) {
    cleanSstream();
    std::cout << msg << " " << day << ":" << std::endl;
    ss << msg << " " << day << ":" << std::endl;

    file_out_string.append(ss.str());
    cleanSstream();
}

void Simulation::printTask(unsigned int hour, std::string msg) {
    std::cout << hour << ":00 "<< msg << std::endl;
    ss << hour << ":00 " << msg << "\n";

    file_out_string.append(ss.str());
    cleanSstream();
}

void Simulation::printDuty(HotelWorker worker, DutyEntry duty) {
    cleanSstream();
    std::cout << duty << " by " << worker.getFirstName() << " " << worker.getLastName() << std::endl;
    ss << duty << " by " << worker.getFirstName() << " " << worker.getLastName() << "\n";

    file_out_string.append(ss.str());
    cleanSstream();
}

std::string Simulation::doTask() {
    int guestId;
    switch (randomizeInstant(1,3)) {
        case 1:
            hotel.addGuest(Guest(guestNames[hotel.getGuestsIndex() % 200].first, guestNames[hotel.getGuestsIndex() % 200].second), randomizeInstant(1, numberOfDays));
            ss << guestNames[hotel.getGuestsIndex() % 200].first << " " << guestNames[hotel.getGuestsIndex() % 200].second << " registered";
            break;
        case 2:
            guestId = randomizeInstant(0,hotel.guests.size()-1);
            hotel.guestCallsTaxi(guestId);
            ss << "Guest " << hotel.guests[guestId].get_surname() << " called a taxi";
            break;
        case 3:
            guestId = randomizeInstant(0,hotel.availableRooms.size()-1);
            hotel.guestOrdersEq(guestId, Equipment("Furniture"));
            ss <<   "Guest from room nr " << guestId << " ordered new furniture." ;
            break;
        default:
            break;
    }

    return ss.str();
}

void Simulation::run() {
        int i;
        for (int day = 1; day <= numberOfDays; day++) {
            printDay(day, "Day");
            addGuest();
            hours = generateHours();
            i = 0;
            for (int hour = 1; hour < 24; hour++) {
                while (hour == hours[i]) {
                    i++;
                    msg = doTask();
                    cleanSstream();
                    printTask(hour, msg);
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
                std::vector<std::pair<HotelWorker, DutyEntry>> pairs = hotel.getOnDuty(hour,intToDay.at((day - 1) % 7));
                for (auto &pair : pairs) {
                    printDuty(pair.first, pair.second);
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }


}

void Simulation::greetUser() {
    std::cout << "||| Welcome to Seaside Hotel !!! |||\n";
}

void Simulation::main() {
    greetUser();
    getParams();
    init();
    run();
    io::wirteStringToFile("output.txt", file_out_string);
}
