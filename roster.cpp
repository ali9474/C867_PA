#include "roster.h"
#include <iostream>

using namespace std;

Roster::Roster() {
    lastIndex = -1;
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i] = nullptr;
    }
}

Roster::~Roster() {
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            delete classRosterArray[i];
            classRosterArray[i] = classRosterArray[lastIndex];
            classRosterArray[lastIndex] = nullptr;
            lastIndex--;
            break;
        }
    }
    if (!found) {
        cout << "ERROR: Student ID " << studentID << " not found!" << endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i <= lastIndex; ++i) {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int* days = classRosterArray[i]->getDaysInCourse();
            cout << (days[0] + days[1] + days[2]) / 3 << endl;
            return;
        }
    }
    cout << "Student ID " << studentID << " not found!" << endl;
}

void Roster::printInvalidEmails() {
    for (int i = 0; i <= lastIndex; ++i) {
        string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            cout << email << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= lastIndex; ++i) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

string Roster::getStudentIDByIndex(int index) {
    if (index <= lastIndex) {
        return classRosterArray[index]->getStudentID();
    }
    return "";
}
