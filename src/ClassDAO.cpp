

/*
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
//};

#ifndef CLASSDAO_HPP
#define CLASSDAO_HPP

#include "include/AbstractDAO.hpp"
#include "include/ClassDTO.hpp"
#include "include/College.hpp"
#include <memory>
#include <algorithm> 

class ClassDAO : public AbstractDAO<Class> {
public:
    void add(const Class& classObject) override {
        College::getInstance().getClassList().push_back(std::make_shared<Class>(classObject));
    }

    void update(const Class& classObject) override {
        auto& classList = College::getInstance().getClassList();
        for (auto& classPtr : classList) {
            if (classPtr->getCode() == classObject.getCode()) {
                *classPtr = classObject;
                return;
            }
        }
    }

    void remove(const std::string& id) override { // Corrigindo para aceitar uma string como ID
        auto& classList = College::getInstance().getClassList();
        classList.erase(
            std::remove_if(classList.begin(), classList.end(),
                           [id](const std::shared_ptr<Class>& classPtr) {
                               return classPtr->getId() == id;
                           }),
            classList.end());
    }

    Class searchId(const std::string& id) override { // Corrigindo para aceitar uma string como ID
        for (const auto& classPtr : College::getInstance().getClassList()) {
            if (classPtr->getId() == id) {
                return *classPtr;
            }
        }
        throw std::runtime_error("Turma não encontrada.");
    }

    void addProfessorToClass(int classId, const std::string& professorId) {
        auto& classList = College::getInstance().getClassList();
        for (auto& classPtr : classList) {
            if (classPtr->getId() == classId) {
                classPtr->setTeacherId(professorId);
                return;
            }
        }
        throw std::runtime_error("Turma não encontrada.");
    }

    void addStudentToClass(int classId, const std::string& studentRA) {
        auto& classList = College::getInstance().getClassList();
        for (auto& classPtr : classList) {
            if (classPtr->getId() == classId) {
                classPtr->addStudentRA(studentRA);
                return;
            }
        }
        throw std::runtime_error("Turma não encontrada.");
    }
};

#endif
