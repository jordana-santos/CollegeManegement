#include "../include/AbstractDAO.hpp"
#include "../include/TeacherDTO.hpp"

class TeacherDAO : public AbstractDAO<TeacherDTO> {
    protected:
    vector<TeacherDTO> teachers;

    public:
    
    void add(const TeacherDTO& teacher) override {
        teachers.push_back(teacher);
        cout << "Adicionando "<<teacher.getName()<<" ao sistema..." <<endl;
    }
    vector<TeacherDTO> getAllTeachers() const {
        return teachers;
    }
    TeacherDTO* searchStudentName(const string& name) {
        for (auto& teacher : teachers) {
            if (teacher.getName() == name) {
                return &teacher;
            }
        }
        return nullptr; // Caso o aluno não seja encontrado, retorna um ponteiro vazio
    }
    const TeacherDTO* searchId(string id) override {
        for (const auto& teacher : teachers) {
            if (teacher.getID() == id) {
                return &teacher;
            }
        }
        return nullptr;
    }
    void update(const TeacherDTO& teacher) override {
        for (auto& t : teachers) {
            if (t.getID() == teacher.getID()) {
                t = teacher;
                return;
            }
        }
    }

    void remove(string id) override {
        teachers.erase(
            remove_if(teachers.begin(), teachers.end(),
                [id](const TeacherDTO& t) { return t.getID() == id; }),
            teachers.end());
    }
};