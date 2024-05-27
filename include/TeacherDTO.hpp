#ifndef TEACHERDTO_HPP
#define TEACHERDTO_HPP
#include <iostream>
#include <string>
#include <map>
#include "Person.hpp"

using namespace std;

class TeacherDTO: public Person{
    protected:
        string id;

    public:
        TeacherDTO(): Person(), id("0"){};
        TeacherDTO(string id) : Person(name, age, phone), id(id){};

    //getters
    string getID() const{ return id; }

    // setters
    void setID(string id){ this->id = id; }
};

#endif
