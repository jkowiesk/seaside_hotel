#ifndef IO_MODULE_PY_H
#define IO_MODULE_PY_H
#include <iostream>
#include <string>

namespace io {
    bool isNumber(std::string str) {
        for (auto ch : str) {
            if (isdigit(ch))
                return true;
        }
        return false;
    }

    void clearInputStream(std::string str) {

        std::cin.clear();
        std::cin.ignore(str.max_size(), '\n');
    }

    int getInt() {
        std::string input;
        int value;
        std::cin >> value;
        while (!std::cin) {
            std::cout << "Wrong value.\n";
            clearInputStream(input);
            std::cin >> value;
        }
        clearInputStream(input);

        return value;

    }

    long double getLongDouble() {
        std::string input;
        long double value;
        std::cin >> value;
        while (!std::cin) {
            std::cout << "Wrong value.\n";
            clearInputStream(input);
            std::cin >> value;
        }
        clearInputStream(input);

        return value;

    }

    std::string getString() {
        std::string input;
        std::cin >> input;
        while (!std::cin || isNumber(input)) {
            std::cout << "Wrong value.\n";
            clearInputStream(input);
            std::cin >> input;
        }
        clearInputStream(input);

        return input;

    }
}





#endif //IO_MODULE_PY_H
