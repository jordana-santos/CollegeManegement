#include "../../include/dto/College.hpp"

map<string, StudentDTO> College::students;
map<string, TeacherDTO> College::teachers;
map<string, ClassDTO> College::classes;

//getters
map<string, StudentDTO>& College::getStudentList() {
    return students;
}
map<string, TeacherDTO>& College::getTeacherList() {
    return teachers;
}
map<string, ClassDTO>& College::getClassList() {
    return classes;
}

//funcionalidades
void College::showAllStudents() {
    if(students.empty()){
        cout<<"     Não há alunos registrados!"<<endl;
        return;
    }
    cout<<"--------------------------"<<endl<<" Alunos cadastrados no sistema"<<endl<<"--------------------------"<<endl<<"   RA    -   Nome"<<endl;
    for (auto it = students.begin(); it != students.end(); ++it) {
        cout << " " << it->first << "  -   " << it->second.getName() << endl;
    }
}
void College::showAllTeachers(){
    if(teachers.empty()){
        cout<<"     Não há professores registrados!"<<endl;
        return;
    }
    cout<<"--------------------------"<<endl<<" Profs. cadastrados no sistema"<<endl<<"--------------------------"<<endl<<"   ID    -   Nome"<<endl;
    for (auto it = teachers.begin(); it != teachers.end(); ++it) {
        cout << " " << it->first << "  -   " << it->second.getName() << endl;
    }
};
void College::showAllClasses(){
    if(classes.empty()){
        cout<<"     Não há turmas registradas!"<<endl;
        return;
    }
    cout<<"--------------------------"<<endl<<" Turmas cadastradas no sistema"<<endl<<"--------------------------"<<endl<<"   Cód    -   Nome"<<endl;
    for (auto it = classes.begin(); it != classes.end(); ++it) {
        cout << " " << it->first << "  -   " << it->second.getName() << endl;
    }
};

void College::addToStudentList(map<string, StudentDTO> &stdntDTO) {
    for (const auto& par : stdntDTO) {
        students.insert(par);
    }
}
void College::addToTeacherList(map<string, TeacherDTO> &tchrDTO) {
    for (const auto& par : tchrDTO) {
        teachers.insert(par);
    }
}
void College::addToClassList(map<string, ClassDTO> &clssDTO) {
    for (const auto& par : clssDTO) {
        classes.insert(par);
    }
}

void College::removeFromStudentList(string id){
    students.erase(id);
}
void College::removeFromTeacherList(string id){
    teachers.erase(id);
}
void College::removeFromClassList(string id){
    classes.erase(id);
}