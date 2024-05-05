#ifndef COLLEGE_HPP
#define COLLEGE_HPP
#include <iostream>
#include <string>
#include <vector>
#include "StudentDTO.hpp"
#include "ClassDTO.hpp"

using namespace std;

const class College {

    private:
        vector<shared_ptr<studentDTO>> students;
        vector<shared_ptr<teacherDTO>> teachers;
        vector<shared_ptr<classDTO>> classes;

    public:
        //get
        vector<shared_ptr<studentDTO>>& getStudentList() {
            return students;
        }

        vector<shared_ptr<teacherDTO>>& getTeacherList() {
            return teachers;
        }

        vector<shared_ptr<classDTO>>& getClassList() {
            return classes;
        }

        //set
        void setStudentList() {
            this->students = students;
        }

        void setTeacherList() {
            this->teachers = teachers;
        }

        void setClassList() {
            this->classes = classes;
        }

};

#endif
