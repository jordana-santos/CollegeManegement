#ifndef ALUNO_HPP
#define ALUNO_HPP
#include <iostream>
#include <string>
#include "Person.hpp"

using namespace std;

class StudentDTO: public Person{
    protected:
        int ra;
        string course;

    public:
        StudentDTO(int ra, string course): Person(name, age, phone),
        ra(ra), course(course){}

    //getters
    int getRA() const{
        return ra;
    }
    string getCourse() const{
        return course;
    }

    //setters
    void setRA(int ra){
        this->ra = ra;
    }
    void setCourse(string course){
        this->course = course;
    }

};
#endif
