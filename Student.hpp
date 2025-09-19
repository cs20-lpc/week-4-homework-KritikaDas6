#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>
#include "linkedList.hpp"
#include "Course.hpp"

using std::string;

class Student {
private:
    int id;
    string name;
    double gpa;
    linkedList<Course> courses;

public:
    // constructors
    Student();
    Student(int id, string name, double gpa);

    // accessors
    int getId() const;
    string getName() const;
    double getGpa() const;
    linkedList<Course>& getCourses();

    // mutators
    void setId(int id);
    void setName(string name);
    void setGpa(double gpa);

    // course operations
    void addCourse(const Course& new_course);

    // utilities
    void printStudent();
    int search(linkedList<Student>, int);

    // pretty-print
    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};

#endif
