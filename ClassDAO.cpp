#include <iostream>
#include <vector>
#include "classDTO.hpp"
#include "studentDTO.hpp"
#include "teacherDTO.hpp"

using namespace std;

class ClassDAO {
private:
    vector<Class> classes;

public:
    void add(const Class& newClass) {
        classes.push_back(newClass);
        cout << "New class added successfully!" << endl;
    }

    void addProfessorToClass(const string& name, const Teacher& professor) {
        for (auto& c : classes) {
            if (c.getName() == name) {
                c.addProfessor(professor);
                cout << "Professor added to class successfully!" << endl;
                return;
            }
        }
        cout << "Error: Class not found!" << endl;
    }

    void addStudentToClass(const string& name, const Aluno& student) {
        for (auto& c : classes) {
            if (c.getName() == name) {
                c.addAluno(student);
                cout << "Student added to class successfully!" << endl;
                return;
            }
        }
        cout << "Error: Class not found!" << endl;
    }

    void read(const string& name) {
        for (const auto& c : classes) {
            if (c.getName() == name) {
                cout << "Class information: " << endl;
                cout << "Name: " << c.getName() << endl;
                cout << "Professors: ";
                for (const auto& professor : c.getProfessors()) {
                    cout << "ID: " << professor.getID() << endl;
                }
                cout << endl;
                cout << "Students: ";
                for (const auto& student : c.getAlunos()) {
                    cout << "RA: " << student.getRA() << ", Course: " << student.getCourse() << endl;
                }
                cout << endl;
                return;
            }
        }
        cout << "Error: Class not found!" << endl;
    }

    // Other methods of the ClassDAO class...
};
