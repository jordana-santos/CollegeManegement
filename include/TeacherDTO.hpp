#ifndef TEACHER_HPP
#define TEACHER_HPP
#include <iostream>
#include <string>
#include "Person.hpp"

using namespace std;

class Teacher: public Person{

    private:
        string id;

    public:
        Teacher(string id):
        id(id){}

    //get
    string getID(){
        return id;
    }


    //set
    void setID(string id){
        this->id = id;
    }
};

#endif
