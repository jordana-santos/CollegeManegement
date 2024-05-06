#include <iostream>
#include "../include/Menu.hpp"

using namespace std;

void Menu::showMenu() {
    cout << "------ menu ------" << endl;
    cout << "1. Students" << endl;
    cout << "2. Teachers" << endl;
    cout << "3. Subjects" << endl;
    cout << "4. Reports" << endl;
    cout << "5. Help" << endl;
    cout << "6. Leave Program" << endl;
    cout << "------------------" << endl;
    cout << "Chose an option: ";
}

void Menu::subMenuStudent() {
    cout << "----------------------" << endl;
    cout << "1. Register new Student" << endl;
    cout << "2. See all students" << endl;
    cout << "3. Search by RA" << endl;
    cout << "4. Update registrations" << endl;
    cout << "5. Go back to main menu" << endl;
    cout << "----------------------" << endl;
    cout << "Chose an option: ";
}

void Menu::subMenuTeacher() {
    cout << "----------------------" << endl;
    cout << "1. Register new Teacher" << endl;
    cout << "2. See all teachers" << endl;
    cout << "3. Update registrations" << endl;
    cout << "4. Go back to main menu" << endl;
    cout << "----------------------" << endl;
    cout << "Chose an option: ";
}

void Menu::subMenuSubject() {
    cout << "----------------------" << endl;
    cout << "1. Register new subject" << endl;
    cout << "2. See all subjects" << endl;
    cout << "3. Link subject with teacher and students" << endl;
    cout << "4. Update registrations" << endl;
    cout << "5. Go back to main menu" << endl;
    cout << "----------------------" << endl;
    cout << "Chose an option: ";
}

void Menu::subMenuReport() {
    cout << "----------------------" << endl;
    cout << "1. See all students from a subject" << endl;
    cout << "2. Mean grade of a subject" << endl;
    cout << "3. Students with an especific grade in a subject" << endl;
    cout << "4. Student ranking in a subject" << endl;
    cout << "5. Go back to main menu" << endl;
    cout << "----------------------" << endl;
    cout << "Chose an option: "<<endl;
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
            cout << "You chose 'Help'." << endl;
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
    cin >> selected;
    switch (selected) {
        case 1:
            cout << "1. Register new Student" << endl;
            break;
        case 2:
            cout << "2. See all students" << endl;
            break;
        case 3:
            cout << "3. Search by RA" << endl;
            break;
        case 4:
            cout << "4. Update registrations" << endl;
            break;
        case 5:
            showMenu();
            break;
        default:
            cout << "Invalid Option." << endl;
            break;
    }
}

void Menu::teacherChoice() {
    cin >> selected;
    switch (selected) {
        case 1:
            cout << "1. Register new Teacher" << endl;
            break;
        case 2:
            cout << "2. See all teachers" << endl;
            break;
        case 3:
            cout << "3. Update registrations" << endl;
            break;
        case 4:
            showMenu();
            break;
        default:
            cout << "Invalid Option." << endl;
            break;
    }
}

void Menu::subjectChoice() {
    cin >> selected;
    switch (selected) {
        case 1:
            cout << "1. Register new subject" << endl;
            break;
        case 2:
            cout << "2. See all subjects" << endl;
            break;
        case 3:
            cout << "3. Link subject with teacher and students" << endl;
            break;
        case 4:
            cout << "4. Update registrations" << endl;
            break;
        case 5:
            showMenu();
            break;
        default:
            cout << "Invalid Option." << endl;
            break;
    }
}

void Menu::reportChoice() {
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

