#include "../include/AbstractDAO.hpp"
#include "../include/TeacherDTO.hpp"

class TeacherDAO : public AbstractDAO<TeacherDTO> {
    protected:
    map<string, TeacherDTO> teachersList;

    public:
    TeacherDAO(){
        this->teachersList = map<string, TeacherDTO>();
    }
    
    void add(const TeacherDTO& teacher) override {
        teachersList[teacher.getID()] = teacher;
        cout << "Adicionando "<<teacher.getName()<<" ao sistema..." <<endl;
    }

    map<string, TeacherDTO> getAllTeachersList() const {
        return teachersList;
    }
    /*shared_ptr<TeacherDTO> searchStudentName(const string& name) {
        for (auto& teacher : teachersList) {
            if (teacher.getName() == name) {
                return make_shared<TeacherDTO>(teacher);
            }
        }
        return nullptr; // Caso o aluno não seja encontrado, retorna um ponteiro vazio
    }*/
    const shared_ptr<TeacherDTO> searchId(string id) const override {
        auto searchIter = teachersList.find(id);
        if (searchIter != teachersList.end()){
            return make_shared<TeacherDTO>(searchIter->second);
        }
        return nullptr;
    }
    
    void update(const TeacherDTO& teacher) override {
        auto searchIter = teachersList.find(teacher.getID());
        if (searchIter != teachersList.end()) {
            searchIter->second = teacher;
        }
    }

    void remove(string id) override {
        teachersList.erase(id);
    }
};