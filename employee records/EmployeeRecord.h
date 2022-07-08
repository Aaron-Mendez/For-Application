
#pragma once

#include <string.h>
#include "CustomerList.h"

using namespace std;

class EmployeeRecord
{
private:
    int m_iEmployeeID;
    char m_sLastName[32];
    char m_sFirstName[32];
    int m_iDeptID;
    double m_dSalary;
    CustomerList *m_pCustomerList;

public:
    EmployeeRecord();
    EmployeeRecord(int ID, char *fName, char *lName, int dept, double sal);
    ~EmployeeRecord();
    void setID(int ID);
    int getID();
    void setName(char* fName, char* lName);
    void getName(char* fName, char* lName);
    void setDept(int d);
    int getDept();
    void setSalary(double sal);
    double getSalary();
    void printRecord();
    CustomerList *getCustomerList();
    EmployeeRecord *m_pLeft, *m_pRight;
    void removeCustomerList();
    void destroyCustomerList();
};