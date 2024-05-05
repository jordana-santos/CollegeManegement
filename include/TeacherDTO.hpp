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

    //get
    string getID();
    string getName();

    //set
    void setID(string id);
    void setName(string name);

    void add(const TeacherDTO& teacher) override;
    vector<TeacherDTO> getAllTeachers() const;
    TeacherDTO* searchStudentName(const string& name);
    TeacherDTO* searchId(int id) override;
    void update(const TeacherDTO& teacher) override;
    void remove(int id) override;
};

#endif
