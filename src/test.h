#ifndef TEST_H
#define TEST_H
#include "hotel_worker.h"
#include <map>
#include <string>

class Test {
    int option;
    HotelWorker worker;
    bool quitKeyPressed = false;
    std::map<int, std::string> options;

    bool isInOptions();

    void printOptions();
    void printPrompt();
    void getOption();
    void testOption();


    void initOptions();
    void run();
    void greetUser();

public:
    void main();
};


#endif //TEST_H
