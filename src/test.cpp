#include "test.h"
#include <iostream>
#include <unistd.h>
#include "io_module.h"

void Test::initOptions() {
    options = {
            {0, "set first name"},
            {1, "set last name "},
            {2, "set worker position"},
            {3, "set salary"},
            {4, "set permission level"},
            {10, "get first name"},
            {11, "get last name "},
            {12, "get worker position"},
            {13, "get salary"},
            {14, "get permission level"},
            {15, "get schedule object"},
            {20, "add new duty to the schedule"},
            {21, "print schedule"}
    };
}

bool Test::isInOptions() {
    if (options.count(option))
        return true;
    else
        return false;
}

void Test::getOption() {
    std::string input;
    std::cin >> option;
    while (!std::cin || !isInOptions()) {
        if (!std::cin) {
            std::cin.clear();
            std::cin >> input;

            if (input == "q") {
                quitKeyPressed = true;
                break;
            }

            std::cout << "Wrong value.\n";
            std::cin.ignore(input.max_size(), '\n');

        } else {
            std::cout << "Wrong input. There is not option with number '" << option << "'\n";
            io::clearInputStream(input);

        }
        std::cin >> option;
    }
    io::clearInputStream(input);

}

inline void Test::printPrompt() {
    std::cout << "Which Option to test: ";
}

inline void Test::printOptions() {
    for (const auto& kv : options) {
        std::cout << kv.first << ") " << kv.second << std::endl;
    }

    std::cout << "q) Quit\n";
}

void Test::testOption() {
    if (option < 10) {
        std::string str;
        long double real;
        int integer;
        switch (option) {
            case 0:
                str = io::getString();
                worker.setFirstName(str);
                break;
            case 1:
                str = io::getString();
                worker.setLastName(str);
                break;
            case 2:
                str = io::getString();
                worker.setPosition(str);
                break;
            case 3:
                real = io::getLongDouble();
                worker.setSalary(real);
                break;
            case 4:
                integer = io::getInt();
                worker.setPermissionLevel(integer);
                break;
        }
        std::cout << worker << std::endl;

    } else if (option < 20) {
        std::cout << "The value is: ";
        std::string str;
        long double real;
        int integer;
        switch (option) {
            case 10:
                str = worker.getFirstName();
                std::cout << str << std::endl;
                break;
            case 11:
                str = worker.getLastName();
                std::cout << str << std::endl;
                break;
            case 12:
                str = worker.getPosition();
                std::cout << str << std::endl;
                break;
            case 13:
                real = worker.getSalary();
                std::cout << real << std::endl;
                break;
            case 14:
                integer = worker.getPermissionLevel();
                std::cout << integer << std::endl;
                break;
        }
        std::cout << worker << std::endl;

    } else if (option < 30) {
        if (option == 20) {
            std::string day, duty;
            int hour, minutes;
            std::cout << "\nType day: ";
            day = io::getString();
            std::cout << "Type hours: ";
            hour = io::getInt();
            std::cout << "Type minutes: ";
            minutes = io::getInt();
            std::cout << "Type type of duty: ";
            duty = io::getString();

            worker.addDutyToSchedule(day, hour, minutes, duty);
        } else if (option == 21) {
            worker.printSchedule();
        }
    }

}

void Test::run() {
    while (true) {
        printOptions();

        printPrompt();
        getOption();

        if (quitKeyPressed)
            exit(0);

        testOption();
        sleep(5);
    }

}

void Test::greetUser() {
    std::cout << "||| Welcome to debug mode !!! |||\n";
}

void Test::main() {
    initOptions();
    greetUser();
    run();
}