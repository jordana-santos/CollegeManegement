#ifndef CLASSDTO_HPP
#define CLASSDTO_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "./Semester.hpp"
#include "./Subject.hpp"

using namespace std;

class ClassDTO: public Semester, Subject{
    protected:
        string code, name, syllabus, teacherId;
        int semesterNumber, year;
        map<string, double> studentGrades;

    public:
        ClassDTO(){};
        ClassDTO(string code, string name, string syllabus, int semesterNumber, int year, string teacherId, map<string, double> studentGrades):
        code(code), name(name), syllabus(syllabus), semesterNumber(semesterNumber), year(year), teacherId(teacherId), studentGrades(studentGrades){};

        //getters
        string getCode() const { return code; }
        string getName() const { return name; }
        string getSyllabus() const { return syllabus; }
        string getTeacherID() const { return teacherId; }
        int getSemesterNumber() const { return semesterNumber; }
        int getyear() const { return year; }
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
        void setTeacherID(string teacherId) {
            this->teacherId = teacherId;
        }
        void setSemesterNumber(int semesterNumber){
            this->semesterNumber = semesterNumber;
        }
        void setStudentGrades(map<string, double> studentGrades) {
            this->studentGrades = studentGrades;
        }
        void addStudentGrades(string studentRA, double studentGrade){
            this->studentGrades[studentRA] = studentGrade;
        }

        //sobrecarga do <<
        friend ostream& operator<<(ostream& os, const ClassDTO& targetClass) {
            os << endl<<"-----------------"<<endl<<" Nome:         "<<targetClass.name<<endl<<" Semestre/Ano: "<<targetClass.semesterNumber <<"s/"<<targetClass.year<<endl<<" Descrição:    "<<targetClass.syllabus <<endl<<"-----------------"<<endl;
            return os;
        }
};

#endif