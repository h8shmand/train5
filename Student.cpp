//
// Created by ASuS on 6/1/2022.
//

#include <regex>
#include "Student.h"

Student::Student(string lastName, string firstName, string id, double workHours,
                 course *courses, string FieldOfStudy, int numOfCourses)
        : person(lastName, firstName, id, workHours) {
    if (Student::validate(id)) {
        this->courses = new course[numOfCourses+3];
        for (int i = 0; i < numOfCourses; i++) {
            this->courses[i] = courses[i];
        }
        this->FieldOfStudy = FieldOfStudy;
        this->numOfCourses = numOfCourses;
        person(lastName, firstName, id, workHours);
    } else {
        cerr << "Error: Invalid ID!" << endl;
        exit(1);
    }

}

Student::Student(const person &p, const Student &s) : person(p) {
    courses = s.courses;
    FieldOfStudy = s.FieldOfStudy;
    numOfCourses = s.numOfCourses;
}

course *Student::getCourses() const {
    return courses;
}

void Student::setCourses(course *Course) {
    this->courses = new course[numOfCourses+3];
    for(int i = 0 ; i<numOfCourses ; i++){
        this->courses[i] = Course[i];
    }
}

string Student::getFieldOfStudy() const {
    return FieldOfStudy;
}

void Student::setFieldOfStudy(string fieldOfStudy) {
    FieldOfStudy = fieldOfStudy;
}

int Student::getNumOfCourses() const {
    return numOfCourses;
}

void Student::setNumOfCourses(int numOfCourse) {
    Student::numOfCourses = numOfCourse;
}

Student::~Student() {
    delete[]courses;
}

bool Student::validate(string Id) {
    if (Id.size() < 8 || Id.size() > 10) {
        return false;
    } else {

        regex r("(8[4-9]|9[0-9]|00)\\*([^0-9]){1,2}([0-3]|[7-9]){5}");
        return regex_match(Id, r);
    }
}

double Student::gpa() {
    double sumOfMarks = 0.0;
    int sumOfUnits = 0;
    for (int i = 0; i < numOfCourses; i++) {
        sumOfMarks += ((courses[i].getMark()) * (courses[i].getUnit()));
        sumOfUnits += courses[i].getUnit();
    }
    return sumOfMarks / sumOfUnits;
}

istream &operator>>(istream &ist, Student &s) {
    string str;
    double d;
    cout << "Enter firstname: ";
    cin >> str;
    s.setFirstName(str);
    cout << "Enter lastname: ";
    cin >> str;
    s.setLastName(str);
    cout << "Enter ID: ";
    cin >> str;
    if (s.validate(str)) { s.setId(str); }
    else {
        cerr << "Error: Invalid ID!";
        exit(1);
    }
    cout << "Enter work hours: ";
    ist >> d;
    s.setWorkHours(d);

    return ist;
}

ostream &operator<<(ostream &ost, Student &s) {
    ost << "FirstName: " << s.getFirstName() << endl;
    ost << "LastName: " << s.getLastName() << endl;
    ost << "ID: " << s.getId() << endl;
    ost << "WorkHours: " << s.getWorkHours() << endl;
    ost << "Field of study: " << s.FieldOfStudy << endl;
    ost << "Number of courses: " << s.numOfCourses << endl;
    ost << "Courses: " << endl;
    for (int i = 0; i < s.numOfCourses; i++) {
        ost << (s.courses[i]);
    }
    return ost;
}

double Student::calculateSalary() {
    double salaryPerHour = 20000;
    double salary = (salaryPerHour * getWorkHours());
    if (gpa() > 17) {
        return salary + (salary * 0.10);
    } else {
        return salary;
    }
}

Student &Student::operator=(const Student &s) {
    if(this == &s){
        return *this;
    }else {
        this->setFirstName(s.getFirstName());
        this->setLastName(s.getLastName());
        this->setId(s.getId());
        this->setWorkHours(s.getWorkHours());
        this->setFieldOfStudy(s.getFieldOfStudy());
        this->setNumOfCourses(s.numOfCourses);
        this->setCourses(s.courses);
        return *this;
    }
}