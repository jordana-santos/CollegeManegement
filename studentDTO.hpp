#ifndef ALUNO_HPP
#define ALUNO_HPP
#include <iostream>
#include <string>
#include "person.hpp"

using namespace std;

class Aluno: public Person{


    private:
        string ra;
        string course;

    public:
        Aluno(string ra, string course):
        ra(ra), course(course){}

    //get
    string getRA(){
        return ra;
    }

    string getCourse(){
        return course;
    }

    //set
    void setRA(string ra){
        this->ra = ra;
    }

    void setCourse(string course){
    this->course = course;
    }

};

#endif
