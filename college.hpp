#ifndef COLLEGE_HPP
#define COLLEGE_HPP
#include <iostream>
#include <string>
#include <vector>
#include "studentDTO.hpp"
#include "teacherDTO.hpp"
#include "classDTO.hpp"


using namespace std;

class College {

    private:
        vector<shared_ptr<StudentDTO>> students;
        vector<shared_ptr<TeacherDTO>> teachers;
        vector<shared_ptr<ClassDTO>> classes;

    public:
        //get
        vector<shared_ptr<StudentDTO>>& getStudentList(); {
            return students;
        }

        vector<shared_ptr<TeacherDTO>>& getTeacherList(); {
            return teachers;
        }

        vector<shared_ptr<ClassDTO>>& getClassList(); {
            return classes;
        }

        //set
        

};

#endif
