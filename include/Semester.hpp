#ifndef SEMESTER_HPP
#define SEMESTER_HPP
#include <iostream>
#include <string>

using namespace std;

class Semester {
    protected:
        string id;
        int year;
        int semesterNumber;

    public:
        Semester(){};
        Semester(string id, int year, int semesterNumber):
        id(id), year(year), semesterNumber(semesterNumber){}

        // getters
        string getId(){ return id; }
        int getYear(){ return year; }
        int getSemesterNumber(){ return semesterNumber; }

        //setters
        void setId(string id){ this->id = id; }
        void setYear(int year){ this->year = year; }
        void setSemesterNumber(int semesterNumber){
            this->semesterNumber = semesterNumber;
        }
};

#endif