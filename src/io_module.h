#ifndef IO_MODULE_PY_H
#define IO_MODULE_PY_H
#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <limits>

namespace io {

    void clearInputStream(std::string str) {

        std::cin.clear();
        std::cin.ignore(str.max_size(), '\n');
    }

    int getInt() {
        std::string input;
        int value;
        std::cin >> value;
        while (!std::cin || value < 0) {
            std::cout << "Wrong value.\n";
            clearInputStream(input);
            std::cin >> value;
        }
        clearInputStream(input);

        return value;

    }

    std::vector<std::pair<std::string, std::string>> getNames(std::string fileName, int numberOfNames = INT_MAX) {
        std::ifstream cif;
        std::string name;
        std::string firstName;
        std::string lastName;
        int index;
        std::vector<std::pair<std::string, std::string>> names;
        cif.open(fileName);
        for (int i = 0; i < numberOfNames; i++) {
            if (cif >> name) {
                index = name.find(';');
                firstName = name.substr(0, index);
                lastName = name.substr(index + 1, name.size());
                names.push_back(std::make_pair(firstName, lastName));
            }
            else
                break;
        }

        return names;
    }

}





#endif //IO_MODULE_PY_H
