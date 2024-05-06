#ifndef CLASSDAO_HPP
#define CLASSDAO_HPP

#include "../include/AbstractDAO.hpp"
#include "../include/ClassDTO.hpp"
#include <memory>
#include <algorithm> 

class ClassDAO : public AbstractDAO<ClassDTO> {
    protected:
    vector<ClassDTO> classesList;

    public:
    ClassDAO(){
        this->classesList = {};
    }
    void add(const ClassDTO& classInfo) override {
        classesList.push_back(classInfo);
        cout << "Adicionando turma "<<classInfo.getName()<<" ao sistema..." <<endl;
    }
    vector<ClassDTO> getAllclassesList() const {
        return classesList;
    }
    shared_ptr<ClassDTO> searchClassName(const string& name) {
        for (auto& classInfo : classesList) {
            if (classInfo.getName() == name) {
                return make_shared<ClassDTO>(classInfo);
            }
        }
        return nullptr;
    }
    const shared_ptr<ClassDTO> searchId(string id) override {
        for (const auto& classInfo : classesList) {
            if (classInfo.getCode() == id) {
                return make_shared<ClassDTO>(classInfo);
            }
        }
        return nullptr;
    }
    void update(const ClassDTO& classInfo) override {
        for (auto& c : classesList) {
            if (c.getCode() == classInfo.getCode()) {
                c = classInfo;
                return;
            }
        }
    }

    void remove(string id) override {
        classesList.erase(
            remove_if(classesList.begin(), classesList.end(),
                [id](const ClassDTO& c) { return c.getCode() == id; }),
            classesList.end());
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