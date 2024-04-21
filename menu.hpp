#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Menu {
public:
    int selected;
    void showMenu();
    void subMenuStudent();
    void subMenuTeacher();
    void subMenuSubject();
    void subMenuReport();
    void menuChoice(int choice);
    void studentChoice();
    void teacherChoice();
    void subjectChoice();
    void reportChoice();
};

#endif // MENU_HPP