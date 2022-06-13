//
// Created by ASuS on 5/31/2022.
//

#ifndef T5_2_COURSE_H
#define T5_2_COURSE_H

#include <iostream>
using namespace std;
class course {
private:
    string name;
    int unit;
    double *mark;
public:
    course();
    course(string , int , double );
    course(const course&);
    ~course();
    //set methods
    void setName(string);
    void setUnit(int);
    void setMark(double);
    //get methods
    string getName() const;
    int getUnit() const;
    double getMark() const;
    course& operator =(const course& c);
    friend istream& operator>>(istream& , course&);
    friend ostream& operator<<(ostream& , course&);
};


#endif //T5_2_COURSE_H