#include "Student.hpp"
#include <iostream>
using namespace std;

// default constructor
Student::Student() : id(0), name(""), gpa(0.0) {}

// parameterized constructor
Student::Student(int id, string name, double gpa)
    : id(id), name(name), gpa(gpa) {}

// accessors
int Student::getId() const { return this->id; }
string Student::getName() const { return this->name; }
double Student::getGpa() const { return this->gpa; }
linkedList<Course>& Student::getCourses() { return this->courses; }

// mutators
void Student::setId(int id) { this->id = id; }
void Student::setName(string name) { this->name = name; }
void Student::setGpa(double gpa) { this->gpa = gpa; }

// course operations
void Student::addCourse(const Course& new_course) {
    courses.append(new_course);
}

// print info
void Student::printStudent() {
    cout << id << " " << name << " (GPA: " << gpa << ")";
    if (!courses.isEmpty()) {
        cout << "\n  Courses:";
        for (int i = 0; i < courses.getLength(); i++) {
            Course c = courses.getElement(i);
            cout << "\n    " << c.getCourseName() << " " << c.getLocation();
        }
    }
    cout << endl;
}

// search student by ID in a list
int Student::search(linkedList<Student> students_list, int id) {
    int length = students_list.getLength();
    for (int i = 0; i < length; i++) {
        if (students_list.getElement(i).getId() == id) {
            return i;
        }
    }
    return -1;
}

// pretty-print operator
std::ostream& operator<<(std::ostream& os, const Student& s) {
    os << s.id << " " << s.name << " " << s.gpa;
    if (!s.courses.isEmpty()) {
        os << "\n  Courses:";
        for (int i = 0; i < s.courses.getLength(); i++) {
            Course c = s.courses.getElement(i);
            os << "\n    " << c.getCourseName() << " " << c.getLocation();
        }
    }
    return os;
}
