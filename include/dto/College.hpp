#ifndef COLLEGE_HPP
#define COLLEGE_HPP
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <algorithm> 
#include "./StudentDTO.hpp"
#include "./TeacherDTO.hpp"
#include "./ClassDTO.hpp"

using namespace std;

class College {
    protected:
        static map<string, StudentDTO> students;
        static map<string, TeacherDTO> teachers;
        static map<string, ClassDTO> classes;

    public:
        //getters
        static map<string, StudentDTO>& getStudentList();
        static map<string, TeacherDTO>& getTeacherList();
        static map<string, ClassDTO>& getClassList();

        //funcionalidades
        static void showAllStudents();
        static void showAllTeachers();
        static void showAllClasses();

        static void addToStudentList(map<string, StudentDTO> &stdntDTO);
        static void addToTeacherList(map<string, TeacherDTO> &tchrDTO);
        static void addToClassList(map<string, ClassDTO> &clssDTO);

        static void removeFromStudentList(string id);
        static void removeFromTeacherList(string id);
        static void removeFromClassList(string id);

};

#endif
