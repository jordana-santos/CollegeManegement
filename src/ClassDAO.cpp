#ifndef CLASSDAO_HPP
#define CLASSDAO_HPP

#include "../include/AbstractDAO.hpp"
#include "../include/ClassDTO.hpp"
#include <memory>
#include <algorithm> 

class ClassDAO : public AbstractDAO<ClassDTO> {
    protected:
    vector<ClassDTO> classes;

    public:
    void add(const ClassDTO& classInfo) override {
        classes.push_back(classInfo);
        cout << "Adicionando turma "<<classInfo.getName()<<" ao sistema..." <<endl;
    }
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
    const ClassDTO* searchId(string id) override {
        for (const auto& classInfo : classes) {
            if (classInfo.getCode() == id) {
                return &classInfo;
            }
        }
        return nullptr;
    }
    void update(const ClassDTO& classInfo) override {
        for (auto& c : classes) {
            if (c.getCode() == classInfo.getCode()) {
                c = classInfo;
                return;
            }
        }
    }

    void remove(string id) override {
        classes.erase(
            remove_if(classes.begin(), classes.end(),
                [id](const ClassDTO& c) { return c.getCode() == id; }),
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
#endif