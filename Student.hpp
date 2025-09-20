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
    Student();
    Student(int id, string name, double gpa);
    int getId() const;
    string getName() const;
    double getGpa() const;
    linkedList<Course>& getCourses();

    void setId(int id);
    void setName(string name);
    void setGpa(double gpa);

    void addCourse(const Course& new_course);

    void printStudent();
    int search(linkedList<Student>, int);

    friend std::ostream& operator<<(std::ostream& os, const Student& s);
};

#endif
