#include<iostream>
#include "menu.hpp"

using namespace std;

int start() {
    //variaveis
    Menu menu;
    int choice;
    
    menu.showMenu();
    cin >> choice;
    menu.menuChoice(choice); 

    return 0;
}