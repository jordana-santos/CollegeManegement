#include "../include/AbstractDAO.hpp"
#include "../include/StudentDTO.hpp"

class StudentDAO : public AbstractDAO<StudentDTO> {
    protected:
    vector<StudentDTO> studentsList;

    public:
    StudentDAO(){
        this->studentsList = {};
    }
    void add(const StudentDTO& student) override {
        studentsList.push_back(student);
        cout << "Adicionando "<<student.getName()<<" ao sistema..." <<endl;
    }
    vector<StudentDTO> getAllstudentsList() const {
        return studentsList;
    }
    shared_ptr<StudentDTO> searchStudentName(const string& name) {
        for (auto& student : studentsList) {
            if (student.getName() == name) {
                return make_shared<StudentDTO>(student);
            }
        }
        return nullptr; // Caso o aluno não seja encontrado, retorna um ponteiro vazio
    }
    const shared_ptr<StudentDTO> searchId(string id) override{
        for (const auto& student : studentsList) {
            if (student.getRA() == id) {
                return make_shared<StudentDTO>(student);;
            }
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
        }
    */
    void update(const StudentDTO& student) {
        for (auto& s : studentsList) {
            if (s.getRA() == student.getRA()) {
                s = student;
                return;
            }
        }
    }

    void remove(string id) override {
        studentsList.erase(
            remove_if(studentsList.begin(), studentsList.end(),
                [id](const StudentDTO& s) { return s.getRA() == id; }),
            studentsList.end());
    }
};