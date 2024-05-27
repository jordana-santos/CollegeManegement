#include "../include/AbstractDAO.hpp"
#include "../include/StudentDTO.hpp"

class StudentDAO : public AbstractDAO<StudentDTO> {
    protected:
    map<string, StudentDTO> studentsList;

    public:
    StudentDAO(){
        this->studentsList = map<string, StudentDTO>();
    }

    void add(const StudentDTO& student) override {
        studentsList[student.getRA()] = student;
        cout << "Adicionando "<<student.getName()<<" ao sistema..." <<endl;
    }

    map<string, StudentDTO> getAllStudentsList() const {
        return studentsList;
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
    const shared_ptr<StudentDTO> searchId(string id) override{
        auto searchIter = studentsList.find(id);
        if (searchIter != studentsList.end()){
            return make_shared<StudentDTO>(searchIter->second);
        }
        return nullptr;
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
};