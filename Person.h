//
// Created by ASuS on 5/31/2022.
//

#ifndef T5_2_PERSON_H
#define T5_2_PERSON_H

#include <iostream>
using namespace std;

class person {
private:
    string firstName;
    string lastName;
    string id;
    double *workHours;
public:
    person(string = "" , string = "" , string = "00abc11111" , double = 0);
    person(const person&);
    ~person();
    //set methods
    void setFirstName(string FirstName);
    void setLastName(string LastName);
    void setId(string Id);
    void setWorkHours(double WorkHours);
    //get methods
    string getFirstName();
    string getLastName();
    string getId();
    double getWorkHours();
    person& operator=(const person& p);
    friend istream& operator>>(istream& , person&);
    friend ostream& operator<<(ostream& , person&);

    virtual bool validate(string Id);

    virtual double calculateSalary();
};


#endif //T5_2_PERSON_H
