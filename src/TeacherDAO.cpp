#include "AbstractDAO.hpp"
#include "TeacherDTO.hpp"

class TeacherDAO : public AbstractDAO<TeacherDTO> {
    protected:
    vector<TeacherDTO> teachers;

    public:
    //getters
    string getID(){
        return id;
    }
    string getName(){
        return name;
    }

    //setters
    void setID(string id){
        this->id = id;
    }
    void setName(string name){
        this->name = name;
    }
    
    void add(const TeacherDTO& teacher) override {
        teachers.push_back(teacher);
        cout << "Adicionando "<<teacher.getNome()<<" ao sistema..." <<endl;
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
    TeacherDTO* searchId(int id) override {
        for (const auto& teacher : teachers) {
            if (teacher.id == id) {
                return &teacher;
            }
        }
        return nullptr
    }
    void update(const TeacherDTO& teacher) override {
        for (auto& t : teachers) {
            if (t.id == teacher.id) {
                t = teacher;
                return;
            }
        }
    }

    void remove(int id) override {
        teachers.erase(
            std::remove_if(teachers.begin(), teachers.end(),
                [id](const TeacherDTO& t) { return t.id == id; }),
            teachers.end());
    }
};