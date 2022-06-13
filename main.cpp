#include <iostream>
#include "cmake-build-debug/course.h"
#include "person.h"
#include "Student.h"

int main() {
    course c;
    c.setName("dif");
    c.setMark(17.1);
    c.setUnit(2);
Student s("Hooshmand" , "Mohammadreza" , "00*sd11111" , 30 , &c , "CE" , 1);
cout<<s.calculateSalary();
}
