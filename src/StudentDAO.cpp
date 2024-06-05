#include "../include/AbstractDAO.hpp"
#include "../include/StudentDTO.hpp"

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
        int idade;
        char escolha = 'S';
        while(escolha == 'S' || escolha =='s'){
            cout<<"-----------------"<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Para o cin ignorar o enter e não dar erro de pular linha
            cout<<"Digite o nome do estudante: ";
            getline(cin, name);
            cout<<"Digite a idade do estudante: ";
            cin>>idade;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Digite o telefone (com ddd) do estudante: ";
            getline(cin, phone);
            cout<<"Digite o RA do estudante: ";
            getline(cin, RA);
            cout<<"Digite o curso do estudante: ";
            getline(cin, course);
            cout<<"Confirme os dados:"<<endl<<"-----------------"<<endl<<"Nome:     "<<name<<endl;
            cout<<"Idade:    "<<idade<<" anos"<<endl<<"Telefone: "<<phone<<endl<<"RA:       "<<RA<<endl<<"Curso:    "<<course<<endl<<"-----------------"<<endl;
            cout<<"Deseja alterar algum dado? (S/N) ";
            cin>>escolha;
        }
        currentStudent.setName(name);
        currentStudent.setAge(idade);
        currentStudent.setCourse(course);
        currentStudent.setPhone(phone);
        currentStudent.setRA(RA);
        add(currentStudent);
    }

    void add(const StudentDTO& student) override {
        studentsList[student.getRA()] = student;
        cout << " - Adicionando "<<student.getName()<<" ao sistema..." <<endl;
    }

    map<string, StudentDTO> getAllStudentsList() const {
        return studentsList;
    }

    void showAllStudents() const {
        if(studentsList.empty()){
            cout<<"     Não há alunos registrados!"<<endl;
            return;
        }
        cout<<"--------------------------"<<endl<<" Alunos cadastrados no sistema"<<endl<<"--------------------------"<<endl<<"   RA    -   Nome"<<endl;
        for (auto it = studentsList.begin(); it != studentsList.end(); ++it) {
            cout << " " << it->first << "  -   " << it->second.getName() << endl;
        }
    }
    /*
    shared_ptr<StudentDTO> searchStudentName(const string& name) {
        for (auto& student : studentsList) {
            if (student.getName() == name) {
                return make_shared<StudentDTO>(student);
            }
        }
        return nullptr; // Caso o aluno não seja encontrado, retorna um ponteiro vazio
    }*/
    const shared_ptr<StudentDTO> searchId(string id) const override{
        auto searchIter = studentsList.find(id);
        if (searchIter != studentsList.end()){
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
            cout<<" - Registro do RA "<<targetStudent->getRA()<<" encontrado: "<<endl<<"-----------------"<<endl<<" Nome:     "<<targetStudent->getName() <<endl;
            cout<<" Idade:    "<<targetStudent->getAge() <<" anos"<<endl<<" Telefone: "<<targetStudent->getPhone() <<endl<<" Curso:    "<<targetStudent->getCourse()<<endl<<"-----------------"<<endl;
        } else {
            cout<<" - Nenhum registro com esse RA foi encontrado."<<endl;
        }
    }
    /* Na hora da busca ficaria:
        StudentDTO* searchStudent = studentDAO.searchStudentName('ronaldo');
        if (searchStudent != nullptr) {
            cout << "\nAluno encontrado:\n";
            cout << "Nome: " << searchStudent->getName() << ", Idade: " << searchStudent->getAge() << endl;
        } else {
            cout << "\nAluno com nome '" << searchName << "' não encontrado." << endl;
        }*/
    
    void update(const StudentDTO& student) {
        auto searchIter = studentsList.find(student.getRA());
        if (searchIter != studentsList.end()) {
            searchIter->second = student;
        }
    }

    void remove(string id) override {
        studentsList.erase(id);
    }

    void deleteStudent() {
        char opcao;
        string selectedRA;
        cout << " - Digite o RA do aluno a ser deletado:"<<endl;
        cin >> selectedRA;
        auto targetStudent = searchId(selectedRA);
        if(targetStudent != nullptr){
            cout<<"Deseja realmente excluir "<<targetStudent->getName()<<"? Essa ação é irreversível. (Digite S/N) ";
            cin>>opcao;
            if(opcao == 's' || opcao == 'S'){
                cout<<" - Removendo "<<targetStudent->getName()<<" do sistema..."<<endl;
                remove(targetStudent->getRA());
            } else cout<<" - Exclusão cancelada."<<endl;
        } else cout<<" - Aluno não encontrado!"<<endl;
    }
};