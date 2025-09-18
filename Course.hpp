// TODO:  Course class definitins go here.

#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>
using namespace std;

class Course {
private:
    string courseName;
    string location;

public:
    Course();
    Course(const string& name, const string& location);

    void setCourseName(const string& name);
    void setLocation(const string& location);

    const string& getCourseName() const;
    const string& getLocation() const;
};

ostream& operator<<(ostream& os, const Course& c);

#endif