#ifndef ALUNO_HPP
#define ALUNO_HPP
#include <iostream>
#include <string>
#include <map>
#include "./Person.hpp"

using namespace std;

class StudentDTO: public Person{
    protected:
        string ra;
        string course;

    public:
    StudentDTO(): Person(), ra("0"), course(""){};
    StudentDTO(string ra, string course): Person(name, age, phone), ra(ra), course(course){};

    //getters
    string getRA() const{ return ra; }
    string getCourse() const{ return course; }

    //setters
    void setRA(string ra){ this->ra = ra; }
    void setCourse(string course){ this->course = course; }

    //sobrecarga do <<
    friend ostream& operator<<(ostream& os, const StudentDTO& student) {
        os<<endl<<"-----------------"<<endl<<" Nome:     "<<student.name <<endl<<" Idade:    "<<student.age <<" anos"<<endl<<" Telefone: "<<student.phone <<endl<<" Curso:    "<<student.course<<endl<<"-----------------"<<endl;
        return os;
    }
};

#endif
