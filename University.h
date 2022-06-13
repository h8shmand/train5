//
// Created by ASuS on 6/2/2022.
//

#ifndef T5_2_UNIVERSITY_H
#define T5_2_UNIVERSITY_H

#include <fstream>
#include "Professor.h"
#include "Student.h"

class University {
private:
    int budget;
    int numOfProfessors;
    int numOfStudents;
    Professor *professor;
    Student *student;
public:
    University( long int budget = 0, int numOfProfessors = 0, int numOfStudents = 0, Professor *professor = 0, Student *student = 0);

    University(const University &u);

    ~University();

    friend ostream &operator<<(ostream &ost, University &u);

    friend istream &operator>>(istream &ist, University &u);

    double averageGpa();
    double averageGpaOfField(string field);
    double averageMarkOfCourse(string courseName);
    bool isEnoughBudget();
    void saveToFile() const;
    void printCourse();
};


#endif //T5_2_UNIVERSITY_H
