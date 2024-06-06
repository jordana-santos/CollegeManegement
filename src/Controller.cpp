#include <exception>
#include <iostream>
#include "../include/Controller.hpp"
#include "../include/SysInfo.hpp"
#include "StudentDAO.cpp"
#include "TeacherDAO.cpp"
#include "ClassDAO.cpp"
#include "Report.cpp"

Controller::Controller() {} 
Controller::~Controller() {} 

void Controller::start() {
    vector<string> menuPrincipal {"Students", "Teachers", "Subjects", "Reports",
        "System Information", "Leave Program"};
    vector<void (Controller::*)()> functions {&Controller::actionSubjects, &Controller::actionTeachers, 
        &Controller::actionSubjects, &Controller::actionReports, &Controller::actionSysInfo};
    launchActions("Main Menu", menuPrincipal, functions);
}

void Controller::actionStudents() {
    vector<string> menuStudents {"Register new Student", "See all students", "Search by RA", 
        "Update registrations", "Remove Student", "Go back to main menu"};
    vector<void (StudentDAO::*)()> functions {&StudentDAO::addStudentInterface, &StudentDAO::showAllStudents,
        &StudentDAO::searchByRA, &StudentDAO::update, &StudentDAO::deleteStudent};
    launchStudents("Students Menu", menuStudents, functions);
}

void Controller::actionTeachers(){
    vector<string> menuTeachers {"Register new Teacher", "See all teachers", "Update registrations", 
        "Remove Teacher", "Go back to main menu"};
    vector<void (TeacherDAO::*)()> functions {&TeacherDAO::add, &TeacherDAO::getAllTeachersList, 
        &TeacherDAO::update, &TeacherDAO::remove};
    launchTeachers("Teachers Menu", menuTeachers, functions);
}

void Controller::actionSubjects(){ 
    vector<string> menuSubject {"Register new subject", "See all subjects", "Link a teacher to a subject", 
        "Link a Student to a subject", "Update registrations", "Remove Subject", "Go back to main menu"};
    vector<void (ClassDAO::*)()> functions {&ClassDAO::add, &ClassDAO::getAllclassesList, 
        &ClassDAO::update, &ClassDAO::remove};
    //falta os metodos de adicionar prof e alunos numa materia 
    launchSubjects("Subjects Menu", menuSubject, functions);
}

void Controller::actionReports(){
    vector<string> menuReports {"See all students from a subject", "Mean grade of a subject",
        "Students with an especific grade in a subject", "Student ranking in a subject", "Go back to main menu"};
    //falta os metodos de reports
    vector<void (Report::*)()> functions { };
    launchReports("Reports Menu", menuReports, functions);
}

void Controller::actionSysInfo(){
    SystemInfo::showInfo();
}
