#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"

using namespace std;

int main() {
    // our linked list for students
    linkedList<Student> roster;  
    int option;

    do {
        cout << "\n==== Student Management Menu ====\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Lookup Student\n";
        cout << "4. Show All Students\n";
        cout << "5. Get Count\n";
        cout << "6. Assign Course\n";
        cout << "7. Quit\n";
        cout << "Choose an option: ";

        if (!(cin >> option)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (option == 1) {
            int sid;
            string sname;
            double sgpa;

            cout << "Enter ID: ";
            cin >> sid;
            cout << "Enter Name: ";
            cin >> sname;
            cout << "Enter GPA: ";
            cin >> sgpa;

            if (cin.fail() || sid <= 0 || sgpa <= 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid values. Try again.\n";
                continue;
            }

            Student st(sid, sname, sgpa);
            roster.append(st);
            cout << "Student added.\n";
        }
        else if (option == 2) {
            int sid;
            cout << "Enter ID to remove: ";
            cin >> sid;

            bool deleted = false;
            for (int i = 0; i < roster.getLength(); i++) {
                Student st = roster.getElement(i);
                if (st.getId() == sid) {
                    roster.remove(i);
                    cout << "Removed student " << sid << ".\n";
                    deleted = true;
                    break;
                }
            }
            if (!deleted) cout << "ID not found.\n";
        }
        else if (option == 3) {
            int sid;
            cout << "Enter ID to find: ";
            cin >> sid;

            bool located = false;
            for (int i = 0; i < roster.getLength(); i++) {
                Student st = roster.getElement(i);
                if (st.getId() == sid) {
                    cout << "Found → " << st.getName() 
                         << " (GPA: " << st.getGpa() << ")\n";
                    located = true;
                    break;
                }
            }
            if (!located) cout << "No student with that ID.\n";
        }
        else if (option == 4) {
            cout << "All students:\n";
            cout << roster;
        }
        else if (option == 5) {
            cout << "Number of students: " << roster.getLength() << endl;
        }
        else if (option == 6) {
            int sid;
            cout << "Enter ID to assign course: ";
            cin >> sid;

            bool updated = false;
            for (int i = 0; i < roster.getLength(); i++) {
                Student st = roster.getElement(i);
                if (st.getId() == sid) {
                    string cname, cloc;
                    cout << "Course name: ";
                    cin >> cname;
                    cout << "Location: ";
                    cin >> cloc;
                    Course crs(cname, cloc);
                    st.addCourse(crs);
                    roster.replace(i, st);
                    cout << "Course assigned.\n";
                    updated = true;
                    break;
                }
            }
            if (!updated) cout << "Student not found.\n";
        }
        else if (option == 7) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice. Please pick 1–7.\n";
        }
    } while (true);

    return 0;
}
