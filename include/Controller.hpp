#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <string>
#include <vector>
#include <memory>
#include "../include/SysInfo.hpp"
#include "../src/StudentDAO.cpp"
#include "../src/TeacherDAO.cpp"
#include "../src/ClassDAO.cpp"
#include "../src/Report.cpp"

using namespace std;

class Controller final
{
private:
	void actionStudents();
	void actionTeachers();
	void actionSubjects();
	void actionReports();
	void actionSysInfo(void);
	void launchActions(string title, vector<string> menuItens, vector<void (Controller::*)()> functions);
	void launchStudents(string title, vector<string> menuItens, vector<void (StudentDAO::*)()> functions);
	void launchTeachers(string title, vector<string> menuItens, vector<void (TeacherDAO::*)()> functions);
	void launchSubjects(string title, vector<string> menuItens, vector<void (ClassDAO::*)()> functions);
	void launchReports(string title, vector<string> menuItens, vector<void (Report::*)()> functions);


    
public:
	Controller();
	virtual ~Controller();
	void start();

};

#endif /* CONTROLLER_H_ */