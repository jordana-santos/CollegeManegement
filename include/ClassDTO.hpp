#ifndef CLASS_HPP
#define CLASS_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Semester.hpp"
#include "Subject.hpp"

using namespace std;

class Class: public Semester, Subject{
    private:
        string code, name, syllabus, teacherId;
        int semesterNumber, year;
        vector<string> studentsRA;
        map<string, double> studentGrades;

    public:
        Class(string code, string name, string syllabus, int semesterNumber, int year):
        code(code), name(name), syllabus(syllabus), semesterNumber(semesterNumber), year(year){}

        //get
        string getCode() { return code; }

        string getName() { return name; }

        string getSyllabus(){ return syllabus; }

        int getSemesterNumber(){ return semesterNumber; }

        int getyear(){ return year; }

        vector<string> getStudentsRa(){ return studentsRA; }

        map<string, double> getStudentGrades(){ return studentGrades; }

        //set
        void setCode(string code){
            this->code = code;
        }

        void setName(string name){
            this->name = name;
        }
        
        void setSyllabus(string syllabus){
            this->syllabus = syllabus;
        }

        void setYear(int year){
            this->year = year;
        }

        void setSemesterNumber(int semesterNumber){
            this->semesterNumber = semesterNumber;
        }

        void setStudentsRA(vector<string> studentsRA) {
            this->studentsRA = studentsRA;
        }

        void setStudentGrades(map<string, double> studentGrades) {
            this->studentGrades = studentGrades;
        }

};

#endif
