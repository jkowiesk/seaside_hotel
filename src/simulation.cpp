#include "simulation.h"
#include <iostream>
#include "io_module.h"
#include <random>
#include <functional>
#include <vector>
#include <sstream>

void Simulation::init() {
    int temp = 24 / busyness;
    ranges.push_back(0);
    for (int i = temp; i <= 24; i += temp) {
        ranges.push_back(i);
    }

    intToDay = {
            {0, "Monday"},
            {1, "Tuesday"},
            {2, "Wednesday"},
            {3, "Thursday"},
            {4, "Friday"},
            {5, "Saturday"},
            {6, "Sunday "}
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
void Simulation::randomize(int maxInt) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, maxInt);
    rand = distribution(generator);
}

int Simulation::randomizeInstant(int minInt, int maxInt) {
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(minInt, maxInt);
    int num = distribution(generator);
    return num;
}

std::vector<int> Simulation::generateHours() {
    std::vector<int> hours;
    for (int i = 0; i < ranges.size()-1; i++) {
        hours.push_back(randomizeInstant(ranges[i], ranges[i+1]));
    }
    return hours;
}

void Simulation::cleanSstream() {
    ss.str(std::string());
}

void Simulation::addGuest() {
    hotel.addGuest(Guest(guestNames[hotel.getGuestsIndex()].first, guestNames[hotel.getGuestsIndex()].second));
    ss << guestNames[hotel.getGuestsIndex()].first << " " << guestNames[hotel.getGuestsIndex()].second << " registered";

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
    std::cout << msg << " " << day << ":" << std::endl;
    ss << msg << " " << day << ":" << std::endl;

    file_out_string.append(ss.str());
    cleanSstream();
}

void Simulation::printTask(unsigned int hour, std::string msg) {
    std::cout << hour << ":00 "<< msg << std::endl;
    ss << hour << ":00 " << msg < "\n";

    file_out_string.append(ss.str());
    cleanSstream();
}

void Simulation::printDuty(DutyEntry duty) {
    std::cout << duty << std::endl;
    ss << duty << "\n";

    file_out_string.append(ss.str());
    cleanSstream();
}

void Simulation::doTask() {
    switch (rand) {
        case 1:
            hotel.addGuest(Guest(guestNames[hotel.getGuestsIndex()].first, guestNames[hotel.getGuestsIndex()].second));
            ss << guestNames[hotel.getGuestsIndex()].first << " " << guestNames[hotel.getGuestsIndex()].second << " registered";
            break;
        case 2:
            int guestId = randomizeInstant(0,hotel.guests.size());
            hotel.guestCallsTaxi(guestId);
            ss << "Guest " << hotel.guests[guestId].get_surname() << " called a taxi\n";
            break;
        case 3:
            int guestId = randomizeInstant(0,hotel.guests.size());
            hotel.guestOrdersEq(guestId, Equipment("Furniture"));
            ss <<   "Guest " <<  hotel.guests[guestId].get_surname() << " ordered furniture to room number " <<
                    hotel.guests[guestId].bookedRoom->getNumber() << "\n";
            break;
        //case 4:
            // na wycieczke jedzie czy ki chuj
            //break;
        default:
            break;
    }

    return ss.str(); // czemu to jest w ogole zwracane?
}

void Simulation::run() {
    int i;
    for (int day = 1; day < numberOfDays; day++) {
        printMsg(day, "Day");
        addGuest();
        // file_out_string = "";
        hours = generateHours();
        i = 0;
        for (int hour = 1; hour < 24; hour++) {
            if (hour == hours[i]) {
                i++;
                msg = doTask(hour);
                cleanSstream();
                printTask(hour, msg);
            }
            duties = hotel.getOnDuty(hour, intToDay.at(day % 7));
            for(auto& duty : duties) {
                printDuty(duty);
            }
        }
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
}
