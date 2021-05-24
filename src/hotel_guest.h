#include <stdio.h>
#include <vector>
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
        bool operator==(Document &a);
        bool operator!=(Document &a);
        friend std::ostream& operator<<(std::ostream& stream, const Document& document) {
            stream << "Document name:" << document.name << '\n';
            stream << "Document id:" << document.id_number << '\n';
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

class Room {
    public:
        int number;
        Room(int a);
        Room() {};
        bool operator==(Room &a);
        bool operator!=(Room &a);
};


class Booked_rooms {
    public:
        std::vector<int> booked_rooms;
        void add_room(int room);
        void delete_room(int room);
        Booked_rooms() {};
        friend std::ostream& operator<<(std::ostream& stream, const Booked_rooms& booked_rooms) {
            int size = booked_rooms.booked_rooms.size();
            stream << "Booked rooms numbers: ";
            for(int i=0; i < size; i ++) {
                stream << booked_rooms.booked_rooms[i] << ", ";
            }
            return stream;
        }
};

class Guest {
    public:
        std::string name;
        std::string surname;
        int check_in;
        int check_out;
        Document document;
        Booked_rooms booked_rooms;
        void set_name(std::string new_name);
        void set_surname(std::string new_surname);
        std::string get_name();
        std::string get_surname();
        void set_document(Document new_document);
        Document get_document();
        void set_check_in(float hour);
        float get_check_in();
        void set_check_out(float hour);
        float get_check_out();
        void set_booked_rooms();
        Booked_rooms get_booked_rooms();
        Guest() {};
        Guest(std::string a, std::string b, float c, float d, Document e, Booked_rooms f);
        Guest(const Guest& other)
        : name(other.name), surname(other.surname){}
};

#endif


//Bartosz Kosiński