#ifndef CLASSDAO_CPP
#define CLASSDAO_CPP

#include "../../include/dao/AbstractDAO.hpp"
#include "../../include/dto/College.hpp"
#include "../../include/menu/Menu.hpp"
#include <unordered_map>

class ClassDAO : public AbstractDAO<ClassDTO> {
    protected:
    map<string, ClassDTO> classesList;
    ClassDTO currentClass;

    public:
    ClassDAO(){
        this->classesList = map<string, ClassDTO>();
    }

    void add(const ClassDTO& classInfo) override {
        classesList[classInfo.getCode()] = classInfo;
        College::addToClassList(classesList);
        cout << " - Adicionando "<<classInfo.getName()<<" ao sistema..." <<endl;
    }

    void addClassInterface(){
        string code, name, syllabus;
        int semester, year;
        char choice = 'S';
        while(choice == 'S' || choice =='s'){
            cout<<"-----------------"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Para o cin ignorar o enter e não dar erro de pular linha
            do {
                cout<<"Digite o código da disciplina: ";
                cin>>code;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if(searchId(code)!=nullptr) cout<<" - Código de disciplina já existente! Tente outro. "<<endl;
            } while (searchId(code)!=nullptr);
            cout<<"Digite o nome da disciplina: ";
            getline(cin, name);
            cout<<"Dê uma breve descrição sobre a disciplina: ";
            getline(cin, syllabus);
            do {
                cout<<"Digite o semestre em que a disciplina é aplicada (1/2): ";
                cin>> semester;
            } while(!Menu::validateData(semester, "semester"));
            do {
                cout<<"Digite o ano em que a disciplina está sendo aplicada: ";
                cin>>year;
            } while(!Menu::validateData(year, "year"));
            cout<<"Confirme os dados:"<<endl<<"-----------------"<<endl<<"Disciplina:   "<<name<<endl;
            cout<<"Código:       "<<code<<endl<<"Semestre/Ano: "<<semester<<"/"<<year<<endl<<"Descrição:    "<<syllabus<<endl;
            cout<<"Deseja alterar algum dado? (S/N) ";
            cin>>choice;
        }
        currentClass.setName(name);
        currentClass.setCode(code);
        currentClass.setSyllabus(syllabus);
        currentClass.setYear(year);
        currentClass.setSemesterNumber(semester);
        currentClass.setTeacherID("0");
        currentClass.setStudentGrades({});
        add(currentClass);
    }

    const shared_ptr<ClassDTO> searchId(string id) const override{
        auto searchIter = classesList.find(id);
        if (searchIter != classesList.end()){
            return make_shared<ClassDTO>(searchIter->second);
        }
        return nullptr;
    }
    void searchByCode() const{  // Procurar a turma por seu código
        string searchedCode;
        cout << " - Digite o código da turma a ser procurada:"<<endl;
        cin >> searchedCode;
        auto targetClass = searchId(searchedCode);
        if(targetClass != nullptr){
            string profName = "Sem professor vinculado";    // Para mostrar o nome do professor da turma
            if(searchTeacherByID(targetClass->getTeacherID()) != nullptr)
                profName = searchTeacherByID(targetClass->getTeacherID())->getName();
            cout<<" - Registro do código "<<targetClass->getCode()<<" - \'"<<targetClass->getName()<<"\' encontrado:";
            cout<<*targetClass;
        } else {
            cout<<" - Nenhum registro com esse código foi encontrado."<<endl;
        }
    }

    shared_ptr<TeacherDTO> searchTeacherByID(string id) const {   // Para encontrar o professor ao qual a turma é vinculada
        auto searchIter = College::getTeacherList().find(id);
        if (searchIter != College::getTeacherList().end()){
            return make_shared<TeacherDTO>(searchIter->second);
        }
        return nullptr;
    }
    shared_ptr<StudentDTO> searchStudentByID(string id) const {   // Para encontrar o aluno vinculado à turma
        auto searchIter = College::getStudentList().find(id);
        if (searchIter != College::getStudentList().end()){
            return make_shared<StudentDTO>(searchIter->second);
        }
        return nullptr;
    }
    
    void addTeacherToClass(){
        College::showAllClasses();
        if(!classesList.empty()){
            string classCode;
            cout<<" Digite o código da disciplina a ter um professor implementado: ";
            cin>>classCode;
            auto targetClass = searchId(classCode);
            if(targetClass != nullptr){
                College::showAllTeachers();
                if(College::getTeacherList().empty()) return;
                string teacherCode;
                cout<<" Digite o código do professor a ser registrado na turma \""<<targetClass->getName()<<"\": ";
                cin>>teacherCode;
                auto targetTeacher = searchTeacherByID(teacherCode);
                if(targetTeacher != nullptr){
                    char option;
                    cout<<" - Deseja atrelar \'"<<targetTeacher->getName()<<"\' - "<<targetTeacher->getID()<<" à turma \""<<targetClass->getName()<<"\" ? (S/N) ";
                    cin>>option;
                    if(option == 's' || option == 'S'){
                        cout<<" - Adicionando "<<targetTeacher->getName()<<" à turma..."<<endl;
                        string teacherIDGet = targetTeacher->getID();
                        targetClass->setTeacherID(teacherIDGet);
                        update(*targetClass);
                    } else cout<<" - Adição cancelada."<<endl;
                } else cout<<" - Professor não encontrado!"<<endl;
            } else {
                cout<<" - Turma não encontrada!"<<endl;
            }            
        }
    }

    void addStudentToClass(){
        College::showAllClasses();
        if(!classesList.empty()){
            string classCode;
            cout<<" Digite o código da disciplina para inserir alunos: ";
            cin>>classCode;
            auto targetClass = searchId(classCode);
            if(targetClass != nullptr){
                College::showAllStudents();
                if(College::getStudentList().empty()) return;
                string studentCode;
                while(studentCode != "0"){
                    cout<<" Digite o código do aluno a ser registrado na turma \""<<targetClass->getName()<<"\": (digite 0 para cancelar) ";
                    cin>>studentCode;
                    auto targetStudent = searchStudentByID(studentCode);
                    double studentGrade;
                    if(targetStudent != nullptr){
                        do{
                            cout<<" Digite a média de "<<targetStudent->getName()<<" nesta matéria: ";
                            cin>>studentGrade;
                        } while(!Menu::validateData(studentGrade));
                        char option;
                        cout<<" - Deseja atrelar \'"<<targetStudent->getName()<<" - "<<targetStudent->getRA()<<"\' com nota "<<studentGrade<<" à turma \""<<targetClass->getName()<<"\" ? (S/N) ";
                        cin>>option;
                        if(option == 's' || option == 'S'){
                            cout<<" - Adicionando "<<targetStudent->getName()<<" à turma..."<<endl;
                            targetClass->addStudentGrades(targetStudent->getRA(), studentGrade);
                            targetClass->setStudentGrades(targetClass->getStudentGrades());
                            update(*targetClass);
                        } else cout<<" - Adição cancelada."<<endl;
                    } else cout<<" - Aluno não encontrado!"<<endl;
                }                
            } else {
                cout<<" - Turma não encontrada!"<<endl;
            }            
        }
    }
    
    void update(const ClassDTO& classInfo) override {
        auto searchIter = College::getClassList().find(classInfo.getCode());
        if (searchIter != College::getClassList().end()) {
            searchIter->second = classInfo;
             searchIter->second.setStudentGrades(classInfo.getStudentGrades());
        }
    }

    void updateClass() {
        char option;
        string selectedCode;
        cout << " - Digite o código da turma a ser alterada:"<<endl;
        cin >> selectedCode;
        auto targetClass = searchId(selectedCode);
        if(targetClass != nullptr){
            string name, syllabus, teacherId;
            int semesterNumber, year;
            char choice = 'S';
            while(choice == 'S' || choice =='s'){
                cout<<"-----------------"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Digite o nome da turma: ";
                getline(cin, name);
                cout<<"Digite a ementa da matéria: ";
                getline(cin,syllabus);
                cout<<"Digite o ID do professor atrelado à matéria (0 se não houver): ";
                getline(cin, teacherId);
                do {
                    cout<<"Digite o semestre que a matéria é aplicada (1/2): ";
                    cin>>semesterNumber;
                } while(!Menu::validateData(semesterNumber, "semester"));
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                do {
                    cout<<"Digite o ano em que a matéria é aplicada: ";
                    cin>>year;
                } while(!Menu::validateData(year, "year"));
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Confirme os dados:"<<endl<<"-----------------"<<endl<<"Nome:     "<<name<<endl;
                cout<<"Ementa:    "<<syllabus<<endl<<"Sem./Ano: "<<semesterNumber<<"s/"<<year<<endl<<"ID do Prof.:    "<<teacherId<<endl<<"-----------------"<<endl;
                cout<<"Deseja alterar algum dado? (S/N) ";
                cin>>choice;
            }
            cout<<" - Atualizando turma \""<<targetClass->getName()<<"\"..."<<endl;
            targetClass->setName(name);
            targetClass->setTeacherID(teacherId);
            targetClass->setSyllabus(syllabus);
            targetClass->setYear(year);
            targetClass->setSemesterNumber(semesterNumber);
            update(*targetClass);
        } else cout<<" - Turma não encontrada!"<<endl;
    }

    void remove(string id) override{
        College::removeFromClassList(id);
    }
    
    void deleteClass() {
        char option;
        string selectedCode;
        cout << " - Digite o código da turma a ser deletado:"<<endl;
        cin >> selectedCode;
        auto targetClass = searchId(selectedCode);
        if(targetClass != nullptr){
            cout<<"Deseja realmente excluir "<<targetClass->getCode()<<" - \'"<<targetClass->getName()<<"\'? Essa ação é irreversível. (Digite S/N) ";
            cin>>option;
            if(option == 's' || option == 'S'){
                cout<<" - Removendo "<<targetClass->getName()<<" do sistema..."<<endl;
                remove(targetClass->getCode());
            } else cout<<" - Exclusão cancelada."<<endl;
        } else cout<<" - Turma não encontrada!"<<endl;
    }
};
#endif