#include <iostream>
#include "menu.hpp"

using namespace std;

void Menu::showMenu() {
    cout << "----- Menu -----" << endl;
    cout << "1. Students" << endl;
    cout << "2. Teachers" << endl;
    cout << "3. Subjects" << endl;
    cout << "4. Reports" << endl;
    cout << "5. Help" << endl;
    cout << "6. Leave Program" << endl;
    cout << "----------------" << endl;
}

void Menu::option(int choice) {
    switch (choice) {
    case 1:
        cout << "You chose the option: Students." << endl;
        break;
    case 2:
        cout << "You chose the option: Teachers." << endl;
        break;
    case 3:
        cout << "You chose the option: Subjects." << endl;
        break;
    case 4:
        cout << "You chose the option: Reports." << endl;
        break;
    case 5:
        cout << "You chose the option: Help." << endl;
        break;
    case 6:
        //exit(0);
        break;
    default:
        cout << "This option doesn't exist." << endl;
        break;
    }
    
}