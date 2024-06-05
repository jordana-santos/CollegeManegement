#include <iostream>
#include "../include/Menu.hpp"
#include "../include/SysInfo.hpp"
#include "StudentDAO.cpp"
#include "TeacherDAO.cpp"
#include "ClassDAO.cpp"

SystemInfo SysInfo;

StudentDAO stdntDAO;  // Representa o estudante a ser instanciado para então ser adicionado
TeacherDAO currentTeacher;
ClassDAO currentClass;

using namespace std;

void Menu::showMenu() {
    cout << "------ Main Menu ------" << endl;
    cout << "1. Students" << endl;
    cout << "2. Teachers" << endl;
    cout << "3. Subjects" << endl;
    cout << "4. Reports" << endl;
    cout << "5. Help" << endl;
    cout << "6. Leave Program" << endl;
    cout << "------------------" << endl;
    cout << "Pick an option: ";
}

void Menu::subMenuStudent() {
    cout << "----------- Student Menu -----------" << endl;
    cout << "1. Register new Student" << endl;
    cout << "2. See all students" << endl;
    cout << "3. Search by RA" << endl;
    cout << "4. Update registrations" << endl;
    cout << "5. Remove Student" << endl;
    cout << "6. Go back to main menu" << endl;
    cout << "----------------------" << endl;
    cout << "Pick an option: ";
    studentChoice();
}

void Menu::subMenuTeacher() {
    cout << "----------- Teacher Menu -----------" << endl;
    cout << "1. Register new Teacher" << endl;
    cout << "2. See all teachers" << endl;
    cout << "3. Update registrations" << endl;
    cout << "4. Remove Teacher" << endl;
    cout << "5. Go back to main menu" << endl;
    cout << "----------------------" << endl;
    cout << "Pick an option: ";
}

void Menu::subMenuSubject() {
    cout << "----------- Subject Menu -----------" << endl;
    cout << "1. Register new subject" << endl;
    cout << "2. See all subjects" << endl;
    cout << "3. Link a teacher to a subject" << endl;
    cout << "4. Link a Student to a subject" << endl;
    cout << "5. Update registrations" << endl;
    cout << "6. Remove Subject" << endl;
    cout << "7. Go back to main menu" << endl;
    cout << "----------------------" << endl;
    cout << "Pick an option: ";
}

void Menu::subMenuReport() {
    cout << "----------- Reports Menu -----------" << endl;
    cout << "1. See all students from a subject" << endl;
    cout << "2. Mean grade of a subject" << endl;
    cout << "3. Students with an especific grade in a subject" << endl;
    cout << "4. Student ranking in a subject" << endl;
    cout << "5. Go back to main menu" << endl;
    cout << "----------------------" << endl;
    cout << "Pick an option: "<<endl;
}

void Menu::menuChoice(int choice) {
    switch (choice) {
        case 1:
            subMenuStudent();
            break;
        case 2:
            subMenuTeacher();
            break;
        case 3:
            subMenuSubject();
            break;
        case 4:
            subMenuReport();
            break;
        case 5:
            cout << "Version: " << SysInfo.getVersion() << endl;
            SysInfo.showAuthors();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid option." << endl;
            break;
    }
}

void Menu::studentChoice() {
    //falta colocar os parametros nos metodos abaixo
    cin >> selected;
    switch (selected) {
        case 1:
            stdntDAO.addStudentInterface();
            stdntDAO.showAllStudents();
            stdntDAO.searchByRA();
            stdntDAO.deleteStudent();
            stdntDAO.showAllStudents();
            break;
        case 2:
            stdntDAO.showAllStudents();
            break;
        case 3:
            //StudentDAO::searchId();
            break;
        case 4:
            //StudentDAO::update();
            break;
        case 5:
            //StudentDAO::remove();
            break;
        case 6: 
            showMenu();
            break;
        default:
            cout << "Invalid Option." << endl;
            break;
    }
}

void Menu::teacherChoice() {
    //falta colocar os parametros nos metodos abaixo
    cin >> selected;
    switch (selected) {
        case 1:
            //TeacherDAO::add();
            break;
        case 2:
            //TeacherDAO::getAllTeachersList();
            break;
        case 3:
            //TeacherDAO::update();
            break;
        case 4:
            //TeacherDAO::remove();
            break;
        case 5:
            showMenu();
            break;
        default:
            cout << "Invalid Option." << endl;
            break;
    }
}

void Menu::subjectChoice() { //subject é o class
    //falta colocar os parametros nos metodos abaixo
    cin >> selected;
    switch (selected) {
        case 1:
            //ClassDAO::add();
            break;
        case 2:
            //ClassDAO::getAllclassesList();
            break;
        case 3:
            cout << "3. Link a teacher to a subject" << endl;
            ////falta fazer esse metodo la em ClassDAO
            break;
        case 4:
            cout << "4. Link a Student to a subject" << endl;
            ////falta fazer esse metodo la em ClassDAO
            break;
        case 5:
            //ClassDAO::update();
            break;
        case 6:
            //ClassDAO::remove();
            break;
        case 7:
            showMenu();
            break;
        default:
            cout << "Invalid Option." << endl;
            break;
    }
}

void Menu::reportChoice() {
    //nenhuma das classes tem metodo que faz as coisas abaixo
    cin >> selected;
    switch (selected) {
        case 1:
            cout << "1. See all students from a subject" << endl;
            break;
        case 2:
            cout << "2. Mean grade of a subject" << endl;
            break;
        case 3:
            cout << "3. Students with an especific grade in a subject" << endl;
            break;
        case 4:
            cout << "4. Student ranking in a subject" << endl;
            break;
        case 5:
            showMenu();
            break;
        default:
            cout << "Invalid Option." << endl;
            break;
    }
}
