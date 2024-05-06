#include "../include/AbstractDAO.hpp"
#include "../include/TeacherDTO.hpp"

class TeacherDAO : public AbstractDAO<TeacherDTO> {
    protected:
    vector<TeacherDTO> teachersList;

    public:
    TeacherDAO(){
        this->teachersList = {};
    }
    
    void add(const TeacherDTO& teacher) override {
        teachersList.push_back(teacher);
        cout << "Adicionando "<<teacher.getName()<<" ao sistema..." <<endl;
    }
    vector<TeacherDTO> getAllteachersList() const {
        return teachersList;
    }
    shared_ptr<TeacherDTO> searchStudentName(const string& name) {
        for (auto& teacher : teachersList) {
            if (teacher.getName() == name) {
                return make_shared<TeacherDTO>(teacher);
            }
        }
        return nullptr; // Caso o aluno não seja encontrado, retorna um ponteiro vazio
    }
    const shared_ptr<TeacherDTO> searchId(string id) override {
        for (const auto& teacher : teachersList) {
            if (teacher.getID() == id) {
                return make_shared<TeacherDTO>(teacher);
            }
        }
        return nullptr;
    }
    void update(const TeacherDTO& teacher) override {
        for (auto& t : teachersList) {
            if (t.getID() == teacher.getID()) {
                t = teacher;
                return;
            }
        }
    }

    void remove(string id) override {
        teachersList.erase(
            remove_if(teachersList.begin(), teachersList.end(),
                [id](const TeacherDTO& t) { return t.getID() == id; }),
            teachersList.end());
    }
};