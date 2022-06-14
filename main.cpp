#include <iostream>
#include "course.h"
#include "Student.h"
#include "Professor.h"
#include "University.h"

int main() {
    //Professors
    Professor professor1("associate professor", "Mansouri", "Azadeh", "00#12899", 24);
    Professor professor2("instructor", "Jalalian", "Zahra", "00#11298", 20);
    Professor professor3("professor", "Asghari", "Amir", "84#28911", 26);
    Professor professor4("assistant professor", "Najafi", "Sayyad", "85#78123", 8);
    Professor professor5("assistant professor", "Soheili", "Mohammadreza", "92#18998", 18);
    Professor professor6("associate professor", "Samaneh", "Akbari", "98#01239", 24);
    //Add professors to array
    auto *p = new Professor[6];
    p[0] = professor1;
    p[1] = professor2;
    p[2] = professor3;
    p[3] = professor4;
    p[4] = professor5;
    p[5] = professor6;
    //Courses
    auto *c = new course[15];
    c[0]("Advanced programming", 3, 0);
    c[1]("Math2", 2, 0);
    c[2]("English", 1, 0);
    c[3]("Engineering Mathematics", 2, 0);
    c[4]("Data base", 3, 0);
    c[5]("Math1", 2, 0);
    c[6]("programming principles", 3, 0);
    c[7]("Physics laboratory", 2, 0);
    c[8]("Physics" , 2 , 0);
    c[9]("Principles of sociology" , 3 , 0);
    c[10]("Psychology of religion" , 3 , 0);
    c[11]("Farsi" , 1 , 0);
    c[12]("Static" , 3 , 0);
    c[13]("Building materials" , 3 ,0);
    auto *cs1 = new course[3];
    cs1[0] = c[0];  cs1[0].setMark(18);
    cs1[1] = c[1];  cs1[1].setMark(15);
    cs1[2] = c[4];  cs1[2].setMark(17);
    Student student1("Hooshmand", "Mohammadreza", "00*MH18988", 10, cs1, "computer engineering", 3);
    auto *cs2 = new course[3];
    cs2[0] = c[5];  cs2[0].setMark(16.25);
    cs2[1] = c[2];  cs2[1].setMark(17);
    cs2[2] = c[7];  cs2[2].setMark(15);
    Student student2("Farahani", "Mahdi", "99*MF98989", 8, cs2, "industrial engineering", 3);
    auto *cs3 = new course[3];
    cs3[0] = c[0];  cs3[0].setMark(20);
    cs3[1] = c[1];  cs3[1].setMark(17);
    cs3[2] = c[4];  cs3[2].setMark(18.5);
    Student student3("Hemmati", "Soroosh", "00*SH78912", 5, cs3, "computer engineering", 3);
    auto *cs4 = new course[3];
    cs4[0] = c[0];  cs4[0].setMark(18.75);
    cs4[1] = c[1];  cs4[1].setMark(19);
    cs4[2] = c[2];  cs4[2].setMark(20);
    Student student4("Pourshaban" , "Tabassom" , "98*SH78812" , 5 , cs4 , "computer science" , 3);
    auto *cs5 = new course[3];
    cs5[0] = c[7];  cs5[0].setMark(17);
    cs5[1] = c[8];  cs5[1].setMark(14.5);
    cs5[2] = c[2];  cs5[2].setMark(16);
    Student student5("Davoodi" , "Reza" , "99*RD98210" , 15 , cs5 , "geology" , 3);
    auto *cs6 = new course[3];
    cs6[0] = c[0];  cs6[0].setMark(16);
    cs6[1] = c[1];  cs6[1].setMark(12);
    cs6[2] = c[2];  cs6[2].setMark(15.5);
    Student student6("Mirzaei" , "Kaveh" , "98*RD98210" , 16 , cs6 , "computer science" , 3);
    auto *cs7 = new course[3];
    cs7[0] = c[0];  cs7[0].setMark(14);
    cs7[1] = c[8];  cs7[1].setMark(17);
    cs7[2] = c[1];  cs7[2].setMark(14);
    Student student7("Mostafavi", "Sohrab", "00*SM72018", 10, cs7, "computer engineering", 3);
    auto *cs8 = new course[3];
    cs8[0] = c[9];  cs8[0].setMark(18);
    cs8[1] = c[10];  cs8[1].setMark(16);
    cs8[2] = c[11];  cs8[2].setMark(12);
    Student student8("Mohebi", "Mahtab", "98*MM72009", 12, cs8, "psychology", 3);
    auto *cs9 = new course[3];
    cs9[0] = c[9];  cs9[0].setMark(14);
    cs9[1] = c[10];  cs9[1].setMark(18);
    cs9[2] = c[11];  cs9[2].setMark(15.75);
    Student student9("Sajedi", "Sajad", "98*SS08899", 9, cs9, "psychology", 3);
    auto *cs10 = new course[3];
    cs10[0] = c[4];  cs10[0].setMark(16.75);
    cs10[1] = c[3];  cs10[1].setMark(18);
    cs10[2] = c[8];  cs10[2].setMark(19);
    Student student10("Hamedi", "Ebrahim", "98*MH18901", 14, cs10, "computer engineering", 3);
    auto *cs11 = new course[3];
    cs11[0] = c[4];  cs11[0].setMark(18);
    cs11[1] = c[12];  cs11[1].setMark(17.5);
    cs11[2] = c[13];  cs11[2].setMark(19);
    Student student11("Arefkia", "Aref", "99*AA17098", 13, cs11, "civil engineering", 3);
    auto *cs12 = new course[3];
    cs12[0] = c[1];  cs12[0].setMark(18.75);
    cs12[1] = c[11];  cs12[1].setMark(16.25);
    cs12[2] = c[7];  cs12[2].setMark(18);
    Student student12("Hosseini", "Hashem", "00*HH27009", 17, cs12, "Metallurgy", 3);

    auto *s = new Student[12];
    s[0] = student1;
    s[1] = student2;
    s[2] = student3;
    s[3] = student4;
    s[4] = student5;
    s[5] = student6;
    s[6] = student7;
    s[7] = student8;
    s[8] = student9;
    s[9] = student10;
    s[10] = student11;
    s[11] = student12;

    University u(25000000, 6, 12, p, s);
    u.printCourse();
    cout << u;
    cout<<"--------------------------"<<endl;
    cout<<"IS BUDGET ENOUGH?"<<endl;
    if(u.isEnoughBudget()){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    cout<<"--------------------------"<<endl;
    cout<<"Average GPA of university: "<<u.averageGpa()<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"Enter a field to show average GPA(enter lower case): "<<endl;
    string str;
    getline(cin , str);
    cout<<"Average GPA of field: "<<u.averageGpaOfField(str)<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"TOP STUDENTS SAVED IN \"TopStudents.txt\""<<endl;
    u.saveToFile();
    cout<<"--------------------------"<<endl;
    return 0;
}
