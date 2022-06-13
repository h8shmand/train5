//
// Created by ASuS on 5/31/2022.
//

#include <regex>
#include "person.h"
#include <string>

person::person(string lastName, string firstName, string id, double workHours ) {
    if (validate(id)) {
        this->id = id;
        this->lastName = lastName;
        this->firstName = firstName;
        this->workHours = new double;
        *this->workHours = workHours;
    } else {
        cerr << "Error: Invalid ID!";
        exit(1);
    }

}

person::person(const person &p) {
    lastName = p.lastName;
    firstName = p.firstName;
    id = p.id;
    workHours = p.workHours;
}

person::~person() {
    //delete workHours;
}

void person::setFirstName(string FirstName) {
    firstName = FirstName;
}

void person::setLastName(string LastName) {
    lastName = LastName;
}

void person::setId(string Id) {
    if (validate(Id)) {
        id = Id;
    } else{
        cerr<<"Error: Invalid ID!";
        exit(1);
    }
}

void person::setWorkHours(double WorkHours) {
    *workHours = WorkHours;
}

string person::getFirstName() {
    return firstName;
}

string person::getLastName() {
    return lastName;
}

string person::getId() {
    return id;
}

double person::getWorkHours() {
    return *workHours;
}

istream &operator>>(istream &ist, person &p) {
    cout<<"Enter firstname: ";
    ist>>p.firstName;
    cout<<"Enter lastname: ";
    ist>>p.lastName;
    cout<<"Enter ID: ";
    string Id;
    ist>>Id;
    if (p.validate(Id)) {
        p.id = Id;
    } else{
        cerr<<"Error: Invalid ID!";
        exit(1);
    }
    cout<<"Enter work hours: ";
    ist>>*p.workHours;

    return ist;
}

ostream &operator<<(ostream &ost, person &p) {
    ost << "FirstName: " << p.firstName << endl;
    ost << "LastName: " << p.lastName << endl;
    ost << "Id: " << p.id << endl;
    ost << "WorkHour: " << *p.workHours << endl;

    return ost;
}

bool person::validate(string Id) {
    if (Id.size() < 8 || Id.size() > 10) {
        return false;
    } else {

        regex r("(8[4-9]|9[0-9]|00)([^0-9]){1,3}([0-3]|[7-9]){5}");
        return regex_match(Id, r);
    }
}

double person::calculateSalary() {
    double salaryPerHour = 10000;
    return (*workHours) * salaryPerHour;
}

person& person::operator=(const person &p) {
    if(this != &p){
        lastName = p.lastName;
        firstName = p.firstName;
        id = p.id;
        workHours = p.workHours;
    }
    return *this;
}


