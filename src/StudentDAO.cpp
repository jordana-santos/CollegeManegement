#include "../include/AbstractDAO.hpp"
#include "../include/StudentDTO.hpp"

class StudentDAO : public AbstractDAO<StudentDTO> {
    protected:
    vector<StudentDTO> students;

    public:
    void add(const StudentDTO& student) override {
        students.push_back(student);
        cout << "Adicionando "<<student.getName()<<" ao sistema..." <<endl;
    }
    vector<StudentDTO> getAllStudents() const {
        return students;
    }
    StudentDTO* searchStudentName(const string& name) {
        for (auto& student : students) {
            if (student.getName() == name) {
                return &student;
            }
        }
        return nullptr; // Caso o aluno não seja encontrado, retorna um ponteiro vazio
    }
    const StudentDTO* searchId(string RA) override {
        for (const auto& student : students) {
            if (student.getRA() == RA) {
                return &student;
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
    void update(const StudentDTO& student) override {
        for (auto& s : students) {
            if (s.getRA() == student.getRA()) {
                s = student;
                return;
            }
        }
    }

    void remove(string id) override {
        students.erase(
            remove_if(students.begin(), students.end(),
                [id](const StudentDTO& s) { return s.getRA() == id; }),
            students.end());
    }
};