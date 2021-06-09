#include <stdio.h>
#include <vector>
#include "hotel_room.h"
#ifndef HOTEL_GUEST_
#define HOTEL_GUEST_

class Document {
    private:
        std::string name;
        std::string id_number;
    public:
        void set_name(std::string new_name);
        std::string get_name();
        void set_id_number(std::string new_id);
        std::string get_id_number();
        Document() {};
        Document(std::string x, std::string y);
        bool operator==(Document &doc);
        bool operator!=(Document &a);
        friend std::ostream& operator<<(std::ostream& stream, const Document& document) {
            stream << "Document name:" << document.name << '\t';
            stream << "Document id:" << document.id_number << '\t';
            return stream;
        }
};

class Preferences {
    public:
        int bed_amount;
        bool balcony;
        bool kitchenette;
        std::string window_view;
        void set_bed_amount(int new_amount);
        int get_bed_amount();
        void set_balcony(bool choice);
        bool get_balcony();
        void set_kitchenette(bool choice);
        bool get_kitchenette();
        void set_window_view(std::string view);
        std::string get_window_view();
        Preferences();
};

class Booked_rooms {
    public:
        std::vector<int> booked_rooms;
        void add_room(int room);
        void delete_room(int room);
        Booked_rooms() {};
        friend std::ostream& operator<<(std::ostream& stream, const Booked_rooms& bookedrooms) {
            int size = bookedrooms.booked_rooms.size();
            for(int i=0; i < size; i ++) {
                stream << bookedrooms.booked_rooms[i] << ", ";
            }
            return stream;
        }
};

class Guest {
        std::string name;
        std::string surname;
        int check_in;
        int check_out;
        int visitLength;
        int visitTime=0;
        double concession=1;
        Document document;
        Booked_rooms booked_rooms;
    public:
        HotelRoom* bookedRoom;
        void set_name(std::string new_name);
        void set_surname(std::string new_surname);
        std::string get_name();
        std::string get_surname();
        void set_document(Document new_document);
        Document get_document();
        void set_check_in(int hour);
        int get_check_in();
        void set_check_out(int hour);
        int get_check_out();
        void set_booked_rooms(Booked_rooms rooms);
        Booked_rooms get_booked_rooms();
        int get_visitLength() {return visitLength;}
        void dayPassed() {visitTime++;}
        bool visitEnded() {visitLength-visitTime==0 ? true : false;}
        void set_visitLength(int period);
        friend std::ostream& operator<<(std::ostream& stream, Guest& guest) {
            stream << "Guest name: " << guest.get_name() << std::endl;
            stream << "Guest surname: " << guest.get_surname() << std::endl;
            // stream << "Guest document: " << guest.get_document() << std::endl;
            // stream << "Guest check in hour: " << guest.get_check_in() << std::endl;
            // stream << "Guest check out hour: " << guest.get_check_out() << std::endl;
            // stream << "Guest booked rooms numbers: " << guest.get_booked_rooms() << std::endl;
            return stream;
        }
        Guest() {};
        Guest(std::string nname, std::string nsurname) : name(nname), surname(nsurname) {}
        Guest(const Guest& other)
        : name(other.name), surname(other.surname){}
};

class Student : public Guest {
    public:
        double concession=0.5;
};

class Military : public Guest {
    public:
        double concession=0.7;
};

#endif


//Bartosz Kosinski