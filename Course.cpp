// TODO:  Course class methods implementation here.
#include "Course.hpp"
#include <iostream>
#include <string>
using namespace std;


Course::Course() : courseName(""), location("") {}


Course::Course(const std::string& name, const std::string& loc)
    : courseName(name), location(loc) {}


void Course::setCourseName(const std::string& name) {
    courseName = name;
}

void Course::setLocation(const std::string& loc) {
    location = loc;
}

const std::string& Course::getCourseName() const {
    return courseName;
}

const std::string& Course::getLocation() const {
    return location;
}

ostream& operator<<(ostream& os, const Course& name) {
    os << name.getCourseName() << " " << name.getLocation();
    return os;
}           