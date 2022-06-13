//
// Created by ASuS on 5/31/2022.
//

#include "course.h"
course::course() {
    this->name = " ";
    this->unit = 0;
    this->mark = new double;
    *this->mark = 0;
}
course::course(string name, int unit, double mark) {
    this->name = name;
    this->unit = unit;
    this->mark = new double;
    *this->mark = mark;
}

course::course(const course &c) {
    name = c.name;
    unit = c.unit;
    *mark = *c.mark;
}

course::~course() {
    delete mark;
}

void course::setName(string Name) {
    name = Name;
}

void course::setUnit(int Unit) {
    unit = Unit;
}

void course::setMark(double Mark) {
    this->mark = new double;
    *this->mark = Mark;
}

string course::getName() const {
    return name;
}

int course::getUnit() const {
    return unit;
}

double course::getMark() const {
    return *mark;
}

istream &operator>>(istream & ist, course & c) {
    cout<<"Enter course name: ";
    ist>>c.name;
    cout<<"Enter course unit: ";
    ist>>c.unit;
    cout<<"Enter course mark: ";
    ist>>*(c.mark);

    return ist;
}

ostream &operator<<(ostream & ost, course & c) {
    ost<<"Name: "<<c.name<<'\t'<<"Unit: "<<c.unit<<'\t'<<"Mark: "<<*c.mark<<endl;
    return ost;
}

course &course::operator=(const course &c) {
    if(this != &c){
        name = c.name;
        unit = c.unit;
        mark = new double ;
        mark = c.mark;
        return *this;
    }else{
        return *this;
    }
}



