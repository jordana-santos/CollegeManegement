#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <string>
#include <vector>
#include <memory>
#include "../dto/College.hpp"

using namespace std;

class Controller final {
    private:
	void actionStudents();
	void actionTeachers();
	void actionClasses();
	void actionReports();
	void launchActions(string title, vector<string> menuItens, vector<void (Controller::*)()> functions);
	void actionSysInfo();
	void actionToDo(void);

	//Students:
    void actionShowAllStudents();
	void actionAddStudent();
	void actionSearchStudentByRA();
	void actionUpdateStudents();
	void actionRemoveStudents();

	//Teachers:
    void actionShowAllTeachers();
	void actionAddTeacher();
	void actionSearchTeacherByID();
	void actionUpdateTeachers();
	void actionRemoveTeachers();

	//Classes:
    void actionShowAllClasses();
	void actionAddClass();
	void actionSearchClassByCode();
	void actionLinkTeacherToClass();
	void actionLinkStudentToClass();
	void actionUpdateClasses();
	void actionRemoveClasses();

	//Reports:
	void allStudentClasses();
	void allClassStudentsGrades();
	void allTeacherClasses();
	void classAverage();
	void studentAverage();

    public:
	Controller();
	virtual ~Controller();
	void start();

};

#endif /* CONTROLLER_H_ */