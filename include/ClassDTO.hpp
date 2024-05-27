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
        map<string, string> studentsRA;
        map<string, double> studentGrades;

    public:
        ClassDTO(){};
        ClassDTO(string code, string name, string syllabus, int semesterNumber, int year):
        code(code), name(name), syllabus(syllabus), semesterNumber(semesterNumber), year(year){};

        //getters
        string getCode() const { return code; }
        string getName() const { return name; }
        string getSyllabus() const { return syllabus; }
        int getSemesterNumber() const { return semesterNumber; }
        int getyear() const { return year; }
        map<string, string> getStudentsRa() const { return studentsRA; }
        map<string, double> getStudentGrades() const { return studentGrades; }

        //setters
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
        void setStudentsRA(map<string, string> studentsRA) {
            this->studentsRA = studentsRA;
        }
        void setStudentGrades(map<string, double> studentGrades) {
            this->studentGrades = studentGrades;
        }
};

#endif