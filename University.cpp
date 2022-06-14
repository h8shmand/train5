//
// Created by ASuS on 6/2/2022.
//


#include "University.h"

University::University(long int budget, int numOfProfessors, int numOfStudents, Professor *professor,
                       Student *student) {
    this->budget = budget;
    this->numOfProfessors = numOfProfessors;
    this->numOfStudents = numOfStudents;
    this->professor = new Professor[numOfProfessors];
    for (int i = 0; i < numOfProfessors; ++i) {
        this->professor[i] = professor[i];
    }
    this->student = new Student[numOfStudents];
    for (int i = 0; i < numOfStudents; ++i) {
        this->student[i] = student[i];
    }

}

University::University(const University &u) {
    budget = u.budget;
    numOfProfessors = u.numOfProfessors;
    numOfStudents = u.numOfStudents;
    professor = u.professor;
    student = u.student;
}

University::~University() {
    delete []professor;
    delete []student;
}

ostream &operator<<(ostream &ost, University &u) {
    cout << "-------------------" << endl;
    cout << "List of professors:" << endl;
  //  auto *studentTemp = new Student[u.numOfStudents+3];

//    for (int i = 0; i < u.numOfStudents; ++i) {
//        studentTemp[i].setFirstName(u.student[i].getFirstName());
//
//    }
//    cout<<"g";
//
//    auto *professorTemp = new Professor[u.numOfProfessors+3];
//    for (int i = 0; i < u.numOfProfessors; ++i) {
//        professorTemp[i] = u.professor[i];
//    }

    Professor tmp;
    Student tmp2;
    string firstEntryYearToString;
    string secondEntryYearToString;
    for (int i = 0; i < u.numOfProfessors - 1; i++) {
        for (int j = i + 1; j < u.numOfProfessors; j++) {
            for (int k = 0; k < 2; k++) firstEntryYearToString[k] = u.professor[i].getId()[k];
            int firstEntryYear = stoi(firstEntryYearToString);
            if (firstEntryYear == 0) firstEntryYear = 100;
            for (int k = 0; k < 2; k++) secondEntryYearToString[k] = u.professor[j].getId()[k];
            int secondEntryYear = stoi(secondEntryYearToString);
            if (secondEntryYear == 0) secondEntryYear = 100;
            if (firstEntryYear > secondEntryYear) {
                tmp = u.professor[i];
                u.professor[i] = u.professor[j];
                u.professor[j] = tmp;
            }if (firstEntryYear == secondEntryYear) {

            }
        }
    }
    for (int i = 0; i < u.numOfProfessors; ++i) {
        ost << i + 1 << "-" << u.professor[i].getFirstName() << " " << u.professor[i].getLastName() << endl;
    }

    cout << "-------------------" << endl;
    cout << "List of students:" << endl;
    for (int i = 0; i < u.numOfStudents - 1; i++) {
        for (int j = i + 1; j < u.numOfStudents; j++) {
            for (int k = 0; k < 2; k++) firstEntryYearToString[k] = u.student[i].getId()[k];
            int firstEntryYear = stoi(firstEntryYearToString);
            if (firstEntryYear == 0) firstEntryYear = 100;
            for (int k = 0; k < 2; k++) secondEntryYearToString[k] = u.student[j].getId()[k];
            int secondEntryYear = stoi(secondEntryYearToString);
            if (secondEntryYear == 0) secondEntryYear = 100;
            if (firstEntryYear > secondEntryYear) {
                tmp2 = u.student[i];
                u.student[i] = u.student[j];
                u.student[j] = tmp2;
            } else if (firstEntryYear == secondEntryYear) {


            }
        }
    }
    for (int i = 0; i < u.numOfStudents; ++i) {
        ost << i + 1 << "-" << u.student[i].getFirstName() << " " << u.student[i].getLastName() << endl;
    }

    return ost;
}

istream &operator>>(istream &ist, University &u) {
    cout << "Enter budget: ";
    ist >> u.budget;
    cout << "Enter number of professors: ";
    ist >> u.numOfProfessors;
    cout << "Enter number of students: ";
    ist >> u.numOfStudents;

    return ist;
}

double University::averageGpa() {
    double sumOfGpas = 0.0;

    for (int i = 0; i < numOfStudents; i++) {
        sumOfGpas += student[i].gpa();
    }
    return sumOfGpas / numOfStudents;
}

double University::averageGpaOfField(string field) {
    double sumOfGpas = 0.0;
    int counter = 0;
    bool fieldFound = false;
    for (int i = 0; i < numOfStudents; i++) {
        if (student[i].getFieldOfStudy() == field) {
            fieldFound = true;
            sumOfGpas += student[i].gpa();
            counter++;
        }
    }
    if (!fieldFound) {
        cout << "Field not found or no student has the field!" << endl;
        return 0;
    } else {

        return sumOfGpas / counter;
    }
}

double University::averageMarkOfCourse(string courseName) {
    double sumOfMarks = 0.0;
    int counter = 0;
    for (int i = 0; i < numOfStudents; i++) {
        for (int j = 0; j < student[i].getNumOfCourses(); j++) {
            if (student[i].getCourses()[j].getName() == courseName) {
                sumOfMarks += student[i].getCourses()[j].getMark();
                counter++;
            }
        }
    }
    return sumOfMarks / counter;
}

bool University::isEnoughBudget() {
    double sumOfStudentsBudget = 0;
    double sumOfProfessorsBudget = 0;
    for (int i = 0; i < numOfStudents; i++) {
        sumOfStudentsBudget += student[i].calculateSalary();
    }
    for (int i = 0; i < numOfProfessors; i++) {
        sumOfProfessorsBudget += professor[i].calculateSalary();
    }
    if (budget >= (sumOfProfessorsBudget + sumOfStudentsBudget)) {
        return true;
    } else {
        return false;
    }
}

void University::saveToFile() const {
    string fields[numOfStudents];
    fstream File("TopStudents.txt", ios::out);
    for (int i = 0; i < numOfStudents; i++) {
        fields[i] = student[i].getFieldOfStudy();
    }
    for (int i = 0; i < numOfStudents; ++i) {
        for (int j = i + 1; j < numOfStudents - 1; ++j) {
            if (fields[i] == fields[j]) {
                fields[j] = "";
            }
        }
    }
    double topGpa = 0;
    string studentName;
    string studentID;
    File << "TOP STUDENTS:\n" << endl;
    for (int i = 0; i < numOfStudents; i++) {
        for (int j = 0; j < numOfStudents; j++) {
            if ((student[j].getFieldOfStudy() == fields[i]) && (student[j].gpa() > topGpa)) {
                topGpa = student[j].gpa();
                studentName = student[j].getFirstName() + " " + student[j].getLastName();
                studentID = student[j].getId();
            }
        }
        if (!fields[i].empty()) {
            File << "Field: " << fields[i] << "\nStudent: " << studentName << "\nID: " << studentID << "\nGPA: "
                 << topGpa << endl;
            File << "---------" << endl;
        }
        topGpa = 0;
    }

}

void University::printCourse() {
    int numOfCourses = 0;
    int k = 0;
    for (int i = 0; i < numOfStudents; i++) {
        for (int j = 0; j < student[i].getNumOfCourses(); j++) {
            numOfCourses++;
        }
    }
    auto *courses = new course[numOfCourses+3];
    for (int i = 0; i < numOfStudents; i++) {
        for (int j = 0; j < student[i].getNumOfCourses(); j++) {
            courses[k] = student[i].getCourses()[j];
            k++;
        }
    }
    course temp;
    for (int i = 0; i < numOfCourses - 1; i++) {
        for (int j = i + 1; j < numOfCourses; j++) {
            if (averageMarkOfCourse(courses[i].getName()) > averageMarkOfCourse(courses[j].getName())) {
                temp = courses[i];
                courses[i] = courses[j];
                courses[j] = temp;
            }
        }
    }
    cout<<"--------------------------"<<endl;
    cout<<"\nCourses of University"<<endl;
    cout << "*AMC = Average Mark of Course\n" << endl;
    cout << "List of courses sorted by AMC:" << endl;
    int count = 1;
    for (int i = 0; i < numOfCourses; i++) {
        if (courses[i].getName() == courses[i + 1].getName()) continue;
        cout << count << "-" << courses[i].getName() << "\tUnit: " << courses[i].getUnit() << "\tAMC: "
             << averageMarkOfCourse(courses[i].getName()) << endl;
        count++;
    }
    cout<<"--------------------------"<<endl;
    delete[]courses;
}