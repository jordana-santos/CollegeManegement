#include "../../include/dao/AbstractDAO.hpp"
#include "../../include/dto/College.hpp"
#include "../../include/menu/Menu.hpp"

class StudentDAO : public AbstractDAO<StudentDTO> {
    protected:
    map<string, StudentDTO> studentsList;
    StudentDTO currentStudent;

    public:
    StudentDAO(){
        this->studentsList = map<string, StudentDTO>();
    }

    void addStudentInterface(){
        string name, RA, phone, course;
        int age;
        char choice = 'S';
        while(choice == 'S' || choice =='s'){
            cout<<"-----------------"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Para o cin ignorar o enter e não dar erro de pular linha
            do{
                cout<<"Digite o nome do estudante: ";
                getline(cin, name);
            }while(!Menu::validateData(name, "name"));
            do{
                cout<<"Digite a idade do estudante: ";
                cin>>age;
            } while(!Menu::validateData(age, "age"));
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            do{
                cout<<"Digite o telefone (no formato '(xx) xxxxx-xxxx' ) do estudante: ";
                getline(cin, phone);
            } while(!Menu::validateData(phone, "phone"));
            do {
                do{
                    cout<<"Digite o RA do estudante: ";
                    getline(cin, RA);
                } while(!Menu::validateData(RA, "RA"));
                if(searchId(RA)!=nullptr) cout<<" - RA já existente! Tente outro. "<<endl;
            } while (searchId(RA)!=nullptr);
            cout<<"Digite o curso do estudante: ";
            getline(cin, course);
            cout<<"Confirme os dados:"<<endl<<"-----------------"<<endl<<"Nome:     "<<name<<endl;
            cout<<"Idade:    "<<age<<" anos"<<endl<<"Telefone: "<<phone<<endl<<"RA:       "<<RA<<endl<<"Curso:    "<<course<<endl<<"-----------------"<<endl;
            cout<<"Deseja alterar algum dado? (S/N) ";
            cin>>choice;
        }
        currentStudent.setName(name);
        currentStudent.setAge(age);
        currentStudent.setCourse(course);
        currentStudent.setPhone(phone);
        currentStudent.setRA(RA);
        add(currentStudent);
    }

    void add(const StudentDTO& student) override {
        studentsList[student.getRA()] = student;
        College::addToStudentList(studentsList);
        cout << " - Adicionando "<<student.getName()<<" ao sistema..." <<endl<<endl;
    }

    const shared_ptr<StudentDTO> searchId(string id) const override{
        auto searchIter = College::getStudentList().find(id);
        if (searchIter != College::getStudentList().end()){
            return make_shared<StudentDTO>(searchIter->second);
        }
        return nullptr;
    }
    void searchByRA() const{
        string searchedRA;
        cout << " - Digite o RA a ser procurado:"<<endl;
        cin >> searchedRA;
        auto targetStudent = searchId(searchedRA);
        if(targetStudent != nullptr){
            cout<<" - Registro do RA "<<targetStudent->getRA()<<" encontrado: ";
            cout<<*targetStudent;
        } else {
            cout<<" - Nenhum registro com esse RA foi encontrado."<<endl<<endl;
        }
    }
    
    void update(const StudentDTO& student) {
        auto searchIter = College::getStudentList().find(student.getRA());
        if (searchIter != College::getStudentList().end()) {
            searchIter->second = student;
        }
    }
    void updateStudent() {
        char option;
        string selectedRA;
        cout << " - Digite o RA do aluno a ser alterado:"<<endl;
        cin >> selectedRA;
        auto targetStudent = searchId(selectedRA);
        if(targetStudent != nullptr){
            cout<<" - Registro do RA "<<targetStudent->getRA()<<" encontrado - Nome:  "<<targetStudent->getName() <<endl;

            string name, phone, course;
            int age;
            char choice = 'S';
            while(choice == 'S' || choice =='s'){
                cout<<"-----------------"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Para o cin ignorar o enter e não dar erro de pular linha
                do{
                    cout<<"Digite o nome do estudante: ";
                    getline(cin, name);
                } while(!Menu::validateData(name, "name"));
                do{
                    cout<<"Digite a idade do estudante: ";
                    cin>>age;
                } while(!Menu::validateData(age, "age"));
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                do{
                    cout<<"Digite o telefone (com ddd) do estudante: ";
                    getline(cin, phone);
                } while(!Menu::validateData(phone, "phone"));
                cout<<"Digite o curso do estudante: ";
                getline(cin, course);
                cout<<"Confirme os dados:"<<endl<<"-----------------"<<endl<<"Nome:     "<<name<<endl;
                cout<<"Idade:    "<<age<<" anos"<<endl<<"Telefone: "<<phone<<endl<<"Curso:    "<<course<<endl<<"-----------------"<<endl;
                cout<<"Deseja alterar algum dado? (S/N) ";
                cin>>choice;
            }
            targetStudent->setName(name);
            targetStudent->setAge(age);
            targetStudent->setCourse(course);
            targetStudent->setPhone(phone);

            update(*targetStudent);
        } else cout<<" - Aluno não encontrado!"<<endl;
    }

    void remove(string id) override {
        College::removeFromStudentList(id);
    }

    void deleteStudent() {
        char option;
        string selectedRA;
        cout << " - Digite o RA do aluno a ser deletado:"<<endl;
        cin >> selectedRA;
        auto targetStudent = searchId(selectedRA);
        if(targetStudent != nullptr){
            cout<<"Deseja realmente excluir "<<targetStudent->getRA()<<" - "<<targetStudent->getName()<<"? Essa ação é irreversível. (Digite S/N) ";
            cin>>option;
            if(option == 's' || option == 'S'){
                cout<<" - Removendo "<<targetStudent->getName()<<" do sistema..."<<endl;
                remove(targetStudent->getRA());
            } else cout<<" - Exclusão cancelada."<<endl;
        } else cout<<" - Aluno não encontrado!"<<endl;
    }
};