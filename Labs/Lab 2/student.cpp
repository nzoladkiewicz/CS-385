/*******************************************************************************
* Filename: student.cpp
* Author : Natalie Zoladkiewicz
* Version : 1.0
* Date : 09/15/2023
* Description: Student class.
* Pledge : I pledge my honor that I have abided by the Stevens Honor System.
****************************************************************************/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Student {

private:
    string first_;
    string last_;
    float gpa_;
    int id_;

public:
    Student(const string first, const string last, float gpa, int id): first_(first), last_(last), gpa_(gpa), id_(id) { }

    string full_name() const {
        return first_ + " " + last_;
    }

    int id() const {
        return id_;
    }

    float gpa() const {
        return gpa_;
    }

    void print_info() const {
        cout << full_name() << ", " << "GPA: " << fixed << setprecision(2) << gpa() << ", " << "ID: " << id() << endl;
    }
};

vector<Student> find_failing_students(const vector<Student> &students) {
    vector<Student> failing_students;

    for(const auto &student : students) {
        if(student.gpa() < 1.00) {
            failing_students.push_back(student);
        }
    }

    return failing_students;
}

void print_students(const vector<Student> &students) {
    for (auto iterator = students.begin(); iterator != students.end(); ++iterator) {
    (*iterator).print_info();
}
}

int main() {
    string first_name, last_name;
    float gpa;
    int id;
    char repeat;
    vector<Student> students;

    do {
        cout << "Enter student's first name: ";
        cin >> first_name;
        cout << "Enter student's last name: ";
        cin >> last_name;
        gpa = -1;
        while (gpa < 0 || gpa > 4) {
            cout << "Enter student's GPA (0.0-4.0): ";
            cin >> gpa;
        }
        cout << "Enter student's ID: ";
        cin >> id;
        students.push_back(Student(first_name, last_name, gpa, id));
        cout << "Add another student to database (Y/N)? ";
        cin >> repeat;
    } while (repeat == 'Y' || repeat == 'y');

    cout << endl << "All students:" << endl;
    print_students(students);
    cout << endl << "Failing students:";
    
    // Finds failing students and prints None if no students are failing
    if (find_failing_students(students).size() == 0)
        cout << " " << "None" << endl;
    else {
        cout << endl;
        print_students(find_failing_students(students));
    }

    return 0;
}