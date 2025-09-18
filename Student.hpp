// TO DO:  Student class definition  here.
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>
#include "Course.hpp"
#include "linkedList.hpp"
using namespace std;

class Student{
    private:
        int id;
        string name;
        double gpa;
        linkedList<Course> course;
    public:
        Student();
        Student(int id, const string& name, double gpa);

        int getId() const;
        const string& getName() const;
        double getGpa() const;

        void addCourse(const Course& coursera);
};

ostream& operator<<(ostream& os, const Student& s);

#endif