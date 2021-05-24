#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <iostream>


class Equipment
{
protected:
    std::string name;
    int quantity;
public:
    Equipment() {}
    Equipment(std::string n, int q) : name(n), quantity(q) {}

    friend
    std::ostream& operator<< (std::ostream &os, const Equipment eq)
    {
      os << eq.name << "    Quantity: " << eq.quantity;
      return os;
    };
};

class Bed: public Equipment
{
public:
    Bed() {}
    Bed(int q) : Equipment("Bed", q) {}

    friend
    std::ostream& operator<< (std::ostream &os, const Bed bd)
    {
        os << "Bed for one person.  Quantity: " << bd.quantity;
        return os;
    }
};

class DoubleBed: public Equipment
{
public:
    DoubleBed() {}
    DoubleBed(int q) : Equipment("Double bed", q) {}

    friend
    std::ostream& operator<< (std::ostream &os, const DoubleBed bd)
    {
        os << "Bed for two people.  Quantity: " << bd.quantity;
        return os;
    }
};


#endif