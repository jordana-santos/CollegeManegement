#ifndef CLASSDTO_HPP
#define CLASSDTO_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Semester.hpp"
#include "Subject.hpp"

using namespace std;

class ClassDTO: public Semester, Subject{
    protected:
        string code, name, syllabus, teacherId;
        int semesterNumber, year;
        vector<string> studentsRA;
        map<string, double> studentGrades;

    public:
        ClassDTO(string code, string name, string syllabus, int semesterNumber, int year):
        code(code), name(name), syllabus(syllabus), semesterNumber(semesterNumber), year(year){}

        //get
        string getCode();
        string getName();
        string getSyllabus();
        int getSemesterNumber();
        int getyear();
        vector<string> getStudentsRa();
        map<string, double> getStudentGrades();

        //set
        void setCode(string code);
        void setName(string name);        
        void setSyllabus(string syllabus);
        void setYear(int year);
        void setSemesterNumber(int semesterNumber);
        void setStudentsRA(vector<string> studentsRA);
        void setStudentGrades(map<string, double> studentGrades);
};

#endif
