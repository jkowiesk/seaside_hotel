#include <iostream>
#include <vector>
#include <algorithm>
#include "hotel_guest.h"

//setters and getters for Document class
void Document::set_name(std::string new_name) {
    name = new_name;
   }
std::string Document::get_name() {
    return name;
}
void Document::set_id_number(std::string new_id) {
    id_number = new_id;
}
std::string Document::get_id_number() {
    return id_number;
}
//constructor
Document::Document(std::string x, std::string y) {
    name = x;
    id_number = y;
}
//operators overload
bool Document::operator==(Document &doc) {
    if(doc.name == name && doc.id_number == id_number) {
        return true;
    } else {
        return false;
    }
}
bool Document::operator!=(Document &a) {
    if(a.name != name && a.id_number != id_number) {
        return true;
    } else {
        return false;
    }
}

//setters and getters for Preferences class
void Preferences::set_bed_amount(int new_amount) {
    bed_amount = new_amount;
}
int Preferences::get_bed_amount(){
    return bed_amount;
}
void Preferences::set_balcony(bool choice){
    balcony = choice;
}
bool Preferences::get_balcony() {
    return balcony;
}
void Preferences::set_kitchenette(bool choice) {
    kitchenette = choice;
}
bool Preferences::get_kitchenette() {
    return kitchenette;
}
void Preferences::set_window_view(std::string view){
    window_view = view;
}
std::string Preferences::get_window_view() {
    return window_view;
}
//constructor
Preferences::Preferences() {
    bed_amount = 1;
    balcony = false;
    kitchenette = false;
    window_view = "";
}


//Booked_rooms
void Booked_rooms::add_room(int room) {
    booked_rooms.push_back(room);
}
void Booked_rooms::delete_room(int room) {
    booked_rooms.erase(std::remove(booked_rooms.begin(), booked_rooms.end(), room), booked_rooms.end());
}

//setters and getters for Guest class
void Guest::set_surname(std::string new_surname){
    surname = new_surname;
}
void Guest::set_name(std::string new_name){
    name = new_name;
}
std::string Guest::get_name() {
    return name;
}
std::string Guest::get_surname() {
    return surname;
}
void Guest::set_document(Document new_document){
    document = new_document;
}
Document Guest::get_document() {
    return document;
}
void Guest::set_check_in(int hour) {
    if(hour > 0 && hour <= 24) {
        check_in = hour;
    }
}
int Guest::get_check_in() {
    return check_in;
}
void Guest::set_check_out(int hour) {
    if (hour > 0 && hour <= 24) {
        check_out = hour;
    }
}
int Guest::get_check_out() {
    return check_out;
}
void Guest::set_booked_rooms(Booked_rooms rooms){
    booked_rooms = rooms;
}
Booked_rooms Guest::get_booked_rooms() {
    return booked_rooms;
}
void Guest::set_visitLength(int period) {
    visitLength = period;
}
// //constructor
// Guest::Guest(std::string a, std::string b, int c, int d, Document e) {
//     name = a;
//     surname = b;
//     check_in = c;
//     check_out = d;
//     document = e;
// }


//Bartosz Kosinski