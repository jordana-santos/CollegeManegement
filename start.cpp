#include <iostream>
#include "menu.hpp"

using namespace std;

int main() {
    //variaveis
    Menu menu;
    int choice;

    //chamada do menu
    menu.showMenu();
    cin >> choice;
    menu.option(choice);
    
}