#ifndef COLLEGE_HPP
#define COLLEGE_HPP
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm> 
#include "../src/StudentDAO.cpp"
#include "../src/TeacherDAO.cpp"
#include "../src/ClassDAO.cpp"

using namespace std;

class College {
    protected:
        vector<shared_ptr<StudentDTO>> students;
        vector<shared_ptr<TeacherDTO>> teachers;
        vector<shared_ptr<ClassDTO>> classes;

    public:
        //getters
        vector<shared_ptr<StudentDTO>>& getStudentList() {
            return students;
        }
        vector<shared_ptr<TeacherDTO>>& getTeacherList() {
            return teachers;
        }
        vector<shared_ptr<ClassDTO>>& getClassList() {
            return classes;
        }

        //setters
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
