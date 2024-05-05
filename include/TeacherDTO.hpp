#ifndef TEACHERDTO_HPP
#define TEACHERDTO_HPP
#include <iostream>
#include <string>
#include "Person.hpp"

using namespace std;

class TeacherDTO: public Person{
    protected:
        string id;
        string name;

    public:
        TeacherDTO(string id):
        id(id), name(name){}

    //getters
    string getID() const{
        return id;
    }
    string getName() const{
        return name;
    }

    // setters
    void setID(string id){
        this->id = id;
    }
    void setName(string name){
        this->name = name;
    }
};

#endif
