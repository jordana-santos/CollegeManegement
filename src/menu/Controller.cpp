#include <exception>
#include <iostream>
#include "../../include/menu/Controller.hpp"
#include "../../include/system/SysInfo.hpp"
#include "../../include/menu/Menu.hpp"
#include "../dao/StudentDAO.cpp"
#include "../dao/TeacherDAO.cpp"
#include "../dao/ClassDAO.cpp"

StudentDAO student_DAO;
TeacherDAO teacher_DAO;
ClassDAO class_DAO;

Controller::Controller() {} 
Controller::~Controller() {} 

void Controller::launchActions(string title, vector<string> menuItens, vector<void (Controller::*)()> functions) {
    try {
        Menu menu(menuItens, title, "Sua opção: ");
        menu.setSymbol("-");

        while (int choice = menu.getChoice()) {
            (this->*functions.at(choice - 1))();
        }
    } catch (const exception &myException) {
        cout<<" - Houve um problema inesperado. "<<string(myException.what());
    }
}

void Controller::actionToDo(void) {
    cout<<"Place holder function. Code was not written yet!\n";
}


void Controller::start() {
    vector<string> menuPrincipal {"Estudantes", "Professores", "Turmas", "Relatórios",
        "Informação sobre o sistema", "Encerrar programa"};
    vector<void (Controller::*)()> functions {&Controller::actionStudents, &Controller::actionTeachers, 
        &Controller::actionClasses, &Controller::actionReports, &Controller::actionSysInfo};
    launchActions("Menu Principal", menuPrincipal, functions);
}

void Controller::actionStudents() {
    vector<string> menuStudents {"Adicionar estudante", "Ver todos os estudantes", "Pesquisar por RA", 
        "Atualizar registros", "Remover estudante", "Voltar ao menu"};
    vector<void (Controller::*)()> functions {&Controller::actionAddStudent, &Controller::actionShowAllStudents,
        &Controller::actionSearchStudentByRA, &Controller::actionUpdateStudents, &Controller::actionRemoveStudents};
    launchActions("Menu de Estudantes", menuStudents, functions);
}

void Controller::actionTeachers(){
    vector<string> menuTeachers {"Adicionar professor", "Ver todos os professores", "Pesquisar por ID", "Atualizar professores", 
        "Remover professor", "Voltar ao menu principal"};
    vector<void (Controller::*)()> functions {&Controller::actionAddTeacher, &Controller::actionShowAllTeachers,
        &Controller::actionSearchTeacherByID, &Controller::actionUpdateTeachers, &Controller::actionRemoveTeachers};
    launchActions("Menu de professores", menuTeachers, functions);
}

void Controller::actionClasses(){ 
    vector<string> menuClass {"Registrar nova turma", "Ver todas as turmas", "Pesquisar por código de disciplina", "Relacionar professor a uma turma", 
        "Relacionar estudantes a uma turma", "Atualizar registros", "Remover turma", "Voltar ao menu"};
    vector<void (Controller::*)()> functions {&Controller::actionAddClass, &Controller::actionShowAllClasses, 
        &Controller::actionSearchClassByCode, &Controller::actionLinkTeacherToClass, &Controller::actionLinkStudentToClass, &Controller::actionUpdateClasses, &Controller::actionRemoveClasses};
    launchActions("Menu de turmas", menuClass, functions);
}

void Controller::actionReports(){
    vector<string> menuReports {"Disciplinas matriculadas por um estudante", "Estudantes matriculados em uma disciplina",
        "Disciplinas ministradas por um professor", "Média de uma disciplina", "Média de um estudante", "Voltar ao menu"};
    vector<void (Controller::*)()> functions { &Controller::allStudentClasses, &Controller::allClassStudentsGrades, &Controller::allTeacherClasses, &Controller::classAverage, &Controller::studentAverage};
    launchActions("Menu de Relatórios", menuReports, functions);
}

void Controller::actionSysInfo(){
    SystemInfo::showInfo();
}

// Student Actions
void Controller::actionAddStudent(){
    student_DAO.addStudentInterface();
}
void Controller::actionShowAllStudents(){
    College::showAllStudents();
}
void Controller::actionSearchStudentByRA(){
    student_DAO.searchByRA();
}
void Controller::actionUpdateStudents(){
    student_DAO.updateStudent();
};
void Controller::actionRemoveStudents(){
    student_DAO.deleteStudent();
};

// Teacher Actions
void Controller::actionAddTeacher(){
    teacher_DAO.addTeacherInterface();
}
void Controller::actionShowAllTeachers(){
    College::showAllTeachers();
}
void Controller::actionSearchTeacherByID(){
    teacher_DAO.searchByID();
}
void Controller::actionUpdateTeachers(){
    teacher_DAO.updateTeacher();
};
void Controller::actionRemoveTeachers(){
    teacher_DAO.deleteTeacher();
};

// Class Actions
void Controller::actionAddClass(){
    class_DAO.addClassInterface();
}
void Controller::actionShowAllClasses(){
    College::showAllClasses();
}
void Controller::actionSearchClassByCode(){
    class_DAO.searchByCode();
}
void Controller::actionLinkTeacherToClass(){
    class_DAO.addTeacherToClass();
}
void Controller::actionLinkStudentToClass(){
    class_DAO.addStudentToClass();
}
void Controller::actionUpdateClasses(){
    class_DAO.updateClass();
};
void Controller::actionRemoveClasses(){
    class_DAO.deleteClass();
};

// Relatórios (reports)
void Controller::allStudentClasses(){
    College::showAllStudents();
    if(College::getStudentList().empty()) return;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string targetRA;
    cout<<"Digite o RA do aluno a ter as disciplinas exibidas: ";
    getline(cin, targetRA);
    auto targetStudent = student_DAO.searchId(targetRA);
    if(targetStudent != nullptr){
        map<string, string> studentClasses;
        for (const auto& classEntry : College::getClassList()) {
            const ClassDTO& classInfo = classEntry.second;
            auto it = classInfo.getStudentGrades().find(targetStudent->getRA());
            if (it != classInfo.getStudentGrades().end()) {
                studentClasses[classEntry.first] = classInfo.getName();
            }
        }
        cout<<" O aluno de RA "<<targetRA<<" - \""<<targetStudent->getName()<<"\" está matriculado nas turmas:"<<endl;
        for (const auto& classInfo : studentClasses) {
            cout<<"Cód "<<classInfo.first<<" - \"" <<classInfo.second<<"\""<<endl;
        }
    } else {
        cout<<" - Aluno não encontrado!"<<endl;
    }
}
void Controller::allClassStudentsGrades(){
    College::showAllClasses();
    if(College::getClassList().empty()) return;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string targetCode;
    cout<<"Digite o código da turma a ter a média calculada: ";
    getline(cin, targetCode);
    auto targetClass = class_DAO.searchId(targetCode);
    if(targetClass != nullptr){
        auto studentList = targetClass->getStudentGrades();
        cout<<"Notas da turma \""<<targetClass->getName()<<"\": "<<endl;
        for (const auto& student : studentList) {
            cout<<" "<<student.first<<" - \""<<student_DAO.searchId(student.first)->getName()<<"\" - Nota: "<<student.second<<endl;
        }
    } else cout<<" - Turma não encontrada!"<<endl;
};
void Controller::allTeacherClasses(){
    College::showAllTeachers();
    if(College::getTeacherList().empty()) return;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Para o cin ignorar o enter e não dar erro de pular linha
    string targetID;
    cout<<"Digite o ID do professor desejado: ";
    getline(cin, targetID);
    auto targetTeacher = teacher_DAO.searchId(targetID);
    if(targetTeacher != nullptr){
        vector<string> classesLinked;
        for (const auto& classEntry : College::getClassList()) {
            const ClassDTO& classInfo = classEntry.second;
            if (classInfo.getTeacherID() == targetTeacher->getID()) {
                classesLinked.push_back(classEntry.first);
            }
        }
        if(!classesLinked.empty()){
            cout<<" - O professor \""<<targetTeacher->getName()<<"\" apresenta as seguintes matérias: "<<endl<<"------------------"<<endl;
            for(const string classCode : classesLinked){
                cout<<" "<<classCode<<" - "<<class_DAO.searchId(classCode)->getName()<<endl;
            }
        } else cout<<" - O professor \""<<targetTeacher->getName()<<"\" não apresenta nenhuma matéria! "<<endl;
    } else {
        cout<<" - Professor não encontrado!"<<endl;
    }   
};
void Controller::classAverage(){
    College::showAllClasses();
    if(College::getClassList().empty()) return;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Para o cin ignorar o enter e não dar erro de pular linha
    string targetCode;
    cout<<"Digite o código da turma a ter a média calculada: ";
    getline(cin, targetCode);
    auto targetClass = class_DAO.searchId(targetCode);
    if(targetClass != nullptr){
        auto studentGrades = targetClass->getStudentGrades();
        vector<double> grades;
        for (const auto& grade : studentGrades) {
            grades.push_back(grade.second);
        }
        double sum = 0;
        for (double grade : grades) {
            sum += grade;
        }
        sum /= grades.size();
        cout<<" - A média da disciplina \""<<targetClass->getName()<<"\" é de "<<sum<<" ."<<endl;
    } else {
        cout<<" - Turma não encontrada!"<<endl;
    }   
};
void Controller::studentAverage(){
    College::showAllStudents();
    if(College::getStudentList().empty()) return;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Para o cin ignorar o enter e não dar erro de pular linha
    string targetRA;
    cout<<"Digite o RA do aluno a ter a média calculada: ";
    getline(cin, targetRA);
    auto targetStudent = student_DAO.searchId(targetRA);
    if(targetStudent != nullptr){
        vector<double> grades;
        for (const auto& classEntry : College::getClassList()) {
            const ClassDTO& classInfo = classEntry.second;  // Ve se o aluno ta na classe atual
            auto it = classInfo.getStudentGrades().find(targetStudent->getRA());
            if (it != classInfo.getStudentGrades().end()) {
                grades.push_back(it->second);
            }
        }
        double sum = 0;
        for (double grade : grades) {
            sum += grade;
        }
        sum /= grades.size();
        cout<<" - A média do aluno \""<<targetStudent->getName()<<"\" é de "<<sum<<" ."<<endl;
    } else {
        cout<<" - Aluno não encontrado!"<<endl;
    }
};