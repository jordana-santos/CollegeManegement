#include "AbstractDAO.hpp"
#include "ClassDTO.hpp"

class ClassDAO : public AbstractDAO<ClassDTO> {
    protected:
    vector<ClassDTO> classes;

    public:
    void add(const ClassDTO& classInfo) override {
        classes.push_back(classInfo);
        cout << "Adicionando turma "<<classInfo.getNome()<<" ao sistema..." <<endl;
    }

    public:
    vector<ClassDTO> getAllClasses() const {
        return classes;
    }
    ClassDTO* searchClassName(const string& name) {
        for (auto& classInfo : classes) {
            if (classInfo.getName() == name) {
                return &classInfo;
            }
        }
        return nullptr;
    }
    ClassDTO* searchId(int id) override {
        for (const auto& classInfo : classes) {
            if (classInfo.id == id) {
                return &classInfo;
            }
        }
        return nullptr
    }
    void update(const ClassDTO& classInfo) override {
        for (auto& c : classes) {
            if (c.id == classInfo.id) {
                c = classInfo;
                return;
            }
        }
    }

    void remove(int id) override {
        classes.erase(
            std::remove_if(classes.begin(), classes.end(),
                [id](const ClassDTO& c) { return c.id == id; }),
            classes.end());
    }

    /*  A SER DESENVOLVIDO NA ENTREGA COMPLETA
    // Método para adicionar um professor a uma classe
    void addTeacherToClass(const ClassDTO& classInfo, const ClassDTO& classInfo) {
    }

    // Método para adicionar um estudante a uma determinada classe
    void addStudentToClass(const StudentDTO& student, const ClassDTO& classInfo) {
    }*/
};