#pragma once

#include <fstream>
#include <iostream>
#include "EmployeeRecord.h"

class EmployeeDatabase {
private:
	EmployeeRecord* m_pRoot;
	ifstream inFile;
	void printEmployeeRecords(EmployeeRecord* rt);
	void destroyTree(EmployeeRecord* rt);
	bool getNextLine(char* line, int lineLen);


public:
	EmployeeDatabase();
	~EmployeeDatabase();
	bool addEmployee(EmployeeRecord* e);
	EmployeeRecord* getEmployee(int ID);
	EmployeeRecord* removeEmployee(int ID);
	void printEmployeeRecords();
	bool buildDatabase(char* dataFile);
};