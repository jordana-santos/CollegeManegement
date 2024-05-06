#include "StudentDAO.cpp"
#include "TeacherDAO.cpp"
#include "../include/Subject.hpp"
#include "Menu.cpp"

class Controller {
protected:

    Menu menu;
    StudentDAO student;
    TeacherDAO teacher;
    Subject subject;

public:

    void displayMainMenu(int choice) {
        menu.showMenu();   
        cin >> choice; 
        menu.menuChoice(choice);
    }

    void inputData() {
        
    }

    void outputData() {
        menu.subMenuReport();
    }

    void addStudent(const StudentDTO& student) {
        this->student.add(student);
    }

    void addTeacher(const TeacherDTO& teacher) {
        this->teacher.add(teacher);
    }

    void addSubject(const Subject& subject) {
        this->subject.add(subject);
    }
};
