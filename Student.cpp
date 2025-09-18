// TODO:  Student class methods implementation here.

#include "Student.hpp"
#include <iostream>
#include <string>
using namespace std;

Student::Student() : id(0), name(" "), gpa(0.0) {}

Student::Student(int id, const string& name, double gpa) 
: id(id), name(name), gpa(gpa){}

int Student::getId()const {
    return id;
}

const string& Student::getName() const {
    return name;
}

double Student::getGpa() const {
    return gpa;
}

void Student::addCourse(const Course &c) {
    course.append(c);
}

ostream& operator<<(ostream& os, const Student& s) {
    os << s.getId() << " " << s.getName() << " " << s.getGpa();
    return os;
}