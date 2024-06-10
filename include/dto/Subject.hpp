#ifndef SUBJECT_HPP
#define SUBJECT_HPP
#include <iostream>
#include <string>

using namespace std;

class Subject {    
    protected:
        string code;
        string name;
        string syllabus;

    public:
        Subject(){};
        Subject(string code, string name, string syllabus):
        code(code), name(name), syllabus(syllabus){}

        //getters
        string getCode(){ return code; }
        string getName(){ return name; }
        string getSyllabus(){ return syllabus; }

        //setters
        void setCode(string code){ this->code = code; }
        void setName(string name){ this->name = name; }
        void setSyllabus(string syllabus){ this->syllabus = syllabus; }

};

#endif