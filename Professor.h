//
// Created by ASuS on 6/2/2022.
//

#ifndef T5_2_PROFESSOR_H
#define T5_2_PROFESSOR_H


#include "person.h"

class Professor : public person {
private:
    string title;
    string Titles[4]={"instructor" , "assistant professor" , "associate professor" , "professor" };
public:
    Professor(string title = "" , string lastName = "", string firstName = "", string id = "00#00000", double workHours = 0);
    bool validate(string Id);
    double calculateSalary();
    friend ostream& operator<<(ostream& ost , Professor& p);
    friend istream& operator>>(istream& ist , Professor& p);
};


#endif //T5_2_PROFESSOR_H
