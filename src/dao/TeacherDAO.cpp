#include "../../include/dao/AbstractDAO.hpp"
#include "../../include/dto/College.hpp"
#include "../../include/menu/Menu.hpp"

class TeacherDAO : public AbstractDAO<TeacherDTO> {
    protected:
    map<string, TeacherDTO> teachersList;
    TeacherDTO currentTeacher;

    public:
    TeacherDAO(){
        this->teachersList = map<string, TeacherDTO>();
    }
    
    void addTeacherInterface(){
        string name, id, phone;
        int age;
        char choice = 'S';
        while(choice == 'S' || choice =='s'){
            cout<<"-----------------"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Para o cin ignorar o enter e não dar erro de pular linha
            do {
                cout<<"Digite o nome do professor: ";
                getline(cin, name);
            }while(!Menu::validateData(name, "name"));
            do{
                cout<<"Digite a idade do professor: ";
                cin>>age;
            } while(!Menu::validateData(age, "age"));
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            do{
                cout<<"Digite o telefone (com ddd) do professor: ";
                getline(cin, phone);
            } while(!Menu::validateData(phone, "phone"));
            do {
                cout<<"Digite o ID do professor: ";
                getline(cin, id);
                if(searchId(id)!=nullptr) cout<<" - ID já existente! Tente outro. "<<endl;
            } while (searchId(id)!=nullptr);
            cout<<"Confirme os dados:"<<endl<<"-----------------"<<endl<<"Nome:     "<<name<<endl;
            cout<<"Idade:    "<<age<<endl<<"Telefone: "<<phone<<endl<<"ID:       "<<id<<endl<<"-----------------"<<endl;
            cout<<"Deseja alterar algum dado? (S/N) ";
            cin>>choice;
        }
        currentTeacher.setName(name);
        currentTeacher.setPhone(phone);
        currentTeacher.setPhone(phone);
        currentTeacher.setID(id);
        add(currentTeacher);
    }
    
    void add(const TeacherDTO& teacher) override {
        teachersList[teacher.getID()] = teacher;
        College::addToTeacherList(teachersList);
        cout << "Adicionando "<<teacher.getName()<<" ao sistema..." <<endl;
    }

    const shared_ptr<TeacherDTO> searchId(string id) const override {
        auto searchIter = College::getTeacherList().find(id);
        if (searchIter != College::getTeacherList().end()){
            return make_shared<TeacherDTO>(searchIter->second);
        }
        return nullptr;
    }
    void searchByID() const{
        string searchedID;
        cout << " - Digite o ID do professor a ser procurado:"<<endl;
        cin >> searchedID;
        auto targetTeacher = searchId(searchedID);
        if(targetTeacher != nullptr){
            cout<<" - Registro do ID "<<targetTeacher->getID()<<" encontrado: ";
            cout<<*targetTeacher;
        } else {
            cout<<" - Nenhum registro com esse ID foi encontrado."<<endl;
        }
    }
    
    void update(const TeacherDTO& teacher) override {
        auto searchIter = College::getTeacherList().find(teacher.getID());
        if (searchIter != College::getTeacherList().end()){
            searchIter->second = teacher;
        }
    }

    void updateTeacher() {
        char option;
        string selectedRA;
        cout << " - Digite o ID do professor a ser alterado:"<<endl;
        cin >> selectedRA;
        auto targetTeacher = searchId(selectedRA);
        if(targetTeacher != nullptr){
            cout<<" - Registro do ID "<<targetTeacher->getID()<<" encontrado - Nome:  "<<targetTeacher->getName() <<endl;

            string name, phone;
            int age;
            char choice = 'S';
            while(choice == 'S' || choice =='s'){
                cout<<"-----------------"<<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Para o cin ignorar o enter e não dar erro de pular linha
                do{
                    cout<<"Digite o nome do professor: ";
                    getline(cin, name);
                } while(!Menu::validateData(name, "name"));
                do{
                    cout<<"Digite a idade do professor: ";
                    cin>>age;
                } while(!Menu::validateData(age, "age"));
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                do{
                    cout<<"Digite o telefone (com ddd) do professor: ";
                    getline(cin, phone);
                }while(!Menu::validateData(phone, "phone"));
                cout<<"Confirme os dados:"<<endl<<"-----------------"<<endl<<"Nome:     "<<name<<endl;
                cout<<"Idade:    "<<age<<" anos"<<endl<<"Telefone: "<<phone<<endl<<"-----------------"<<endl;
                cout<<"Deseja alterar algum dado? (S/N) ";
                cin>>choice;
            }
            targetTeacher->setName(name);
            targetTeacher->setAge(age);
            targetTeacher->setPhone(phone);

            update(*targetTeacher);
        } else cout<<" - Professor não encontrado!"<<endl;
    }

    void remove(string id) override {
        College::removeFromTeacherList(id);
    }

    void deleteTeacher() {
        char option;
        string selectedRA;
        cout << " - Digite o ID do professor a ser deletado:"<<endl;
        cin >> selectedRA;
        auto targetTeacher = searchId(selectedRA);
        if(targetTeacher != nullptr){
            cout<<"Deseja realmente excluir "<<targetTeacher->getName()<<"? Essa ação é irreversível. (Digite S/N) ";
            cin>>option;
            if(option == 's' || option == 'S'){
                cout<<" - Removendo "<<targetTeacher->getName()<<" do sistema..."<<endl;
                remove(targetTeacher->getID());
            } else cout<<" - Exclusão cancelada."<<endl;
        } else cout<<" - Professor não encontrado!"<<endl;
    }
};