#include <iostream>
#include "roster.h"

using namespace std;

int main() {
    cout << "Course: C867 - Scripting and Programming: Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 011407107" << endl;
    cout << "Name: Ali Ilyas" << endl;

    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Ali,Ilyas,AliIlyas@gmail.com,19,18,18,18,SOFTWARE"
    };

    Roster classRoster;

    for (int i = 0; i < 5; i++) {
        size_t rhs = 0;
        size_t lhs = 0;
        lhs = studentData[i].find(",", rhs);
        string studentID = studentData[i].substr(rhs, lhs - rhs);

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        string firstName = studentData[i].substr(rhs, lhs - rhs);

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        string lastName = studentData[i].substr(rhs, lhs - rhs);

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        string emailAddress = studentData[i].substr(rhs, lhs - rhs);

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        int age = stoi(studentData[i].substr(rhs, lhs - rhs));

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        int daysInCourse1 = stoi(studentData[i].substr(rhs, lhs - rhs));

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        int daysInCourse2 = stoi(studentData[i].substr(rhs, lhs - rhs));

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        int daysInCourse3 = stoi(studentData[i].substr(rhs, lhs - rhs));

        rhs = lhs + 1;
        lhs = studentData[i].find(",", rhs);
        string degreeString = studentData[i].substr(rhs, lhs - rhs);
        DegreeProgram degreeProgram = SOFTWARE; // Default initialization

        if (degreeString == "SECURITY") {
            degreeProgram = SECURITY;
        }
        else if (degreeString == "NETWORK") {
            degreeProgram = NETWORK;
        }
        else if (degreeString == "SOFTWARE") {
            degreeProgram = SOFTWARE;
        }

        classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }

    cout << "\nPrinting all students:" << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Printing invalid emails:" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Average days in course for student " << classRoster.getStudentIDByIndex(i) << ": ";
        classRoster.printAverageDaysInCourse(classRoster.getStudentIDByIndex(i));
    }
    cout << endl;

    cout << "Printing students by degree program: SOFTWARE" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "Removing student A3" << endl;
    classRoster.remove("A3");

    cout << "Printing all students after removal of A3:" << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Trying to remove student A3 again" << endl;
    classRoster.remove("A3");

    return 0;
}
