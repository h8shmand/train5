//
// Created by ASuS on 6/2/2022.
//

#include <regex>
#include "Professor.h"

Professor::Professor(string title, string lastName, string firstName,
                     string id, double workHours)
        : person(lastName, firstName, id, workHours) {
    if (Professor::validate(id)) {
        this->title = title;
    } else {
        cerr << "Error: Invalid ID!";
        exit(1);
    }


}

ostream &operator<<(ostream &ost, Professor &p) {
    ost << "Title: " << p.title << endl;
    ost << "FirstName: " << p.getFirstName() << endl;
    ost << "LastName: " << p.getLastName() << endl;
    ost << "ID: " << p.getId() << endl;
    ost << "WorkHours: " << p.getWorkHours() << endl;
    return ost;
}

istream &operator>>(istream &ist, Professor &p) {
    string str;
    double d;
    cout << "Enter firstname: ";
    ist >> str;
    p.setFirstName(str);
    cout << "Enter lastname: ";
    ist >> str;
    p.setLastName(str);
    cout << "Enter title: ";
    ist >> p.title;
    cout << "Enter ID: ";
    ist >> str;
    if (p.validate(str)) { p.setId(str); }
    else {
        cerr << "Error: Invalid ID!";
        exit(1);
    }
    cout << "Enter work hours: ";
    ist >> d;
    p.setWorkHours(d);

    return ist;
}

bool Professor::validate(string Id) {
    if (Id.size() != 8) {
        return false;
    } else {

        regex r("(8[4-9]|9[0-9]|00)\\#([0-3]|[7-9]){5}");
        return regex_match(Id, r);
    }
}

double Professor::calculateSalary() {
    double salaryPerHour = 50000;
    int DATE_THIS_YEAR = 100;
    char dateOfEmployeement[3];
    string tempID = getId();
    for (int i = 0; i < 2; i++) {
        dateOfEmployeement[i] = tempID[i];
    }
    int dateOfEmployeementToInt = stoi(dateOfEmployeement);
    if(dateOfEmployeementToInt!=0) { salaryPerHour += (DATE_THIS_YEAR - dateOfEmployeementToInt) * 2000; }
    for (int i = 0; i < 4; i++) {
        if (Titles[i] == title) {
            salaryPerHour += (i + 1) * 10000;
            break;
        }
    }
    return salaryPerHour * (getWorkHours());
}