#include "StudentDAO.cpp"
#include "TeacherDAO.cpp"
#include "ClassDAO.cpp"
#include "../include/Menu.hpp"

class Controller {
    protected:
    Menu menu;
    StudentDAO student;
    TeacherDAO teacher;
    ClassDAO classInfo;

    public:
    Controller() : student(), teacher(), classInfo() {}
    void displayMainMenu() {
        int choice;
        menu.showMenu();   
        cin >> choice; 
        menu.menuChoice(choice);
    }

    void inputData() {
        
    }

    void outputData() {
        menu.subMenuReport();
    }

    /* void addStudent(const StudentDTO& student) {
        this->student.add(student);
    }

    void addTeacher(const TeacherDTO& teacher) {
        this->teacher.add(teacher);
    }

    void addSubject(const ClassDAO& classInfo) {
        this->classInfo.add(classInfo);
    } */
};
