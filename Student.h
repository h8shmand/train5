//
// Created by ASuS on 6/1/2022.
//

#ifndef T5_2_STUDENT_H
#define T5_2_STUDENT_H


#include "person.h"
#include "cmake-build-debug/course.h"

class Student : public person{
private:
    course *courses;
    string FieldOfStudy;
    int numOfCourses;
public:
    Student(string lastName = "",string firstName = "", string id = "00*aa11111", double workHours = 0,
            course *courses = nullptr , string FieldOfStudy = "" , int numOfCourses = 0);
    Student(const person &unnamed, const Student &s);
    ~Student();
    bool validate(string Id);
    double gpa();
    friend ostream& operator<<(ostream& ost , Student& s);
    friend istream& operator>>(istream& ist , Student& s);
    double calculateSalary();

    course *getCourses() const;

    void setCourses(course *course);

    string getFieldOfStudy() const;

    void setFieldOfStudy(const string &fieldOfStudy);

    int getNumOfCourses() const;

    void setNumOfCourses(int numOfCourse);


};


#endif //T5_2_STUDENT_H
