#include "EmployeeDatabase.h"
using namespace std;

EmployeeDatabase::EmployeeDatabase()
{
    m_pRoot = NULL;
}

EmployeeDatabase::~EmployeeDatabase() 
{
    destroyTree(m_pRoot);
    m_pRoot = NULL;
}

bool EmployeeDatabase::addEmployee(EmployeeRecord* e) 
{
  
    EmployeeRecord* temp = m_pRoot;
    EmployeeRecord* back = NULL;

    while (temp != NULL)
    {
        back = temp;
        if (e->getID() < temp->getID())
            temp = temp->m_pLeft;
        else
            temp = temp->m_pRight;
    }

    if (back == NULL)
        m_pRoot = e;
    else
    {
        if (e->getID() < back->getID())
            back->m_pLeft = e;
        else
            back->m_pRight = e;
    }
    return true;
    
}


EmployeeRecord* EmployeeDatabase::getEmployee(int ID) 
{
   
    EmployeeRecord* temp = m_pRoot;

    while ((temp != NULL) && (temp->getID() != ID))
    {
        if (ID < temp->getID())
            temp = temp->m_pLeft;
        else
            temp = temp->m_pRight;
    }

    if (temp == NULL)
    {
        return NULL;
        cout << "Store doesn't exsist" << temp;
    }
    else
        return temp;
}


EmployeeRecord* EmployeeDatabase::removeEmployee(int ID)
{
    EmployeeRecord* back = NULL;
    EmployeeRecord* temp = m_pRoot;
    EmployeeRecord* delParent = NULL;
    EmployeeRecord* delNode = NULL;
        while ((temp != NULL) && (ID != temp->getID()))
    {
        back = temp;
        if (ID < temp->getID())
            temp = temp->m_pLeft;
        else
            temp = temp->m_pRight;
    }

    if (temp == NULL)
    {
        cout << "ID not found" << endl;
        return NULL;
    }
    else
    {
        delNode = temp;
        delParent = back;
    }
   
    if (delNode->m_pRight == NULL)
    {
        if (delParent == NULL)
        {
            m_pRoot = delNode->m_pLeft;
            delNode->m_pLeft = NULL;
            return delNode;
        }
        else
        {
            if (delParent->m_pLeft == delNode)
                delParent->m_pLeft = delNode->m_pLeft;
            else
                delParent->m_pRight = delNode->m_pLeft;
            delNode->m_pLeft = NULL;
            return delNode;
        }
        cout << "Store removed " << temp << endl;
    }
    else 
    {
       

        if (delNode->m_pLeft == NULL)
            

        {
            if (delParent == NULL)
            {
                m_pRoot = delNode->m_pRight;
                delNode->m_pRight = NULL;
                return delNode;
            }
            else
            {
                if (delParent->m_pLeft == delNode)
                    delParent->m_pLeft = delNode->m_pRight;
                else
                    delParent->m_pRight = delNode->m_pRight;
                delNode->m_pLeft = NULL;
                return delNode;
            }
        }

        else 
        {
            EmployeeRecord* del = new EmployeeRecord();
            del->destroyCustomerList();
            
            EmployeeRecord* left = NULL;
            EmployeeRecord* right = NULL;
            
            left = delNode->m_pLeft;
            right = delNode->m_pRight;
            *del = *delNode;
            
            del->m_pLeft = NULL;
            del->m_pRight = NULL;
            temp = delNode->m_pLeft;
            back = delNode;
            while (temp->m_pRight != NULL)
            {
                back = temp;
                temp = temp->m_pRight;
            }
            *delNode = *temp;
            delNode->m_pLeft = left;
            delNode->m_pRight = right;

            delete temp;
            return del;

        }
    }
}






void EmployeeDatabase::printEmployeeRecords() {
    if (m_pRoot == NULL) {
        cout << "-------Employee Databse Empty-------" << endl;
    }
    else {
        printEmployeeRecords(m_pRoot);
    }
}

void EmployeeDatabase::printEmployeeRecords(EmployeeRecord* rt) {
    if (rt != NULL)
    {
        int level;
       
        printEmployeeRecords(rt->m_pLeft );
        
        for (int i = 0; i != level; i++) {
            cout << " ";
        }
        cout << rt->getID() << endl;
        printEmployeeRecords(rt->m_pRight);
    }
}

void EmployeeDatabase::destroyTree(EmployeeRecord* rt)
{
    if (m_pRoot != NULL)
    {
        m_pRoot = NULL;
    }
}

//--------------------------------------------
// GetNextLine() 
// Read a line from a data file.
// Author: Rick Coleman
// Used by permission
//--------------------------------------------
bool EmployeeDatabase::getNextLine(char* line, int lineLen)
{
    int    done = false;
    while (!done)
    {
        inFile.getline(line, 128);

        if (inFile.good())    // If a line was successfully read
        {
            if (strlen(line) == 0)  // Skip any blank lines
                continue;
            else if (line[0] == '#')  // Skip any comment lines
                continue;
            else return true;    // Got a valid data line so return with this line
        }
        else
        {
            strcpy(line, "");
            return false;
        }
    } // end while
    return false;
}


//-----------------------------------------------------
// Build the database
//-----------------------------------------------------
bool EmployeeDatabase::buildDatabase(char* dataFile)
{
    bool OK = true;
    int numEmp, id, dept, numStores, sID;
    double sal;
    EmployeeRecord* empRec;
    CustomerList* theList;
    Store* theStore;
    char inStr[128];
    char fName[32];
    char lName[32];
    char sName[64];
    char sAddr[64];
    char sSt[32];
    char sCity[32];
    char sZip[12];


    inFile.open(dataFile, ifstream::in);
    if (!inFile.is_open())
    {
        // inFile.is_open() returns false if the file could not be found or
        //    if for some other reason the open failed.
        cout << "Unable to open file" << dataFile << "\nProgram terminating...\n";
        cout << "Press Enter to continue...";
        getc(stdin);
        return false;
    }

    // Get number of employees
    getNextLine(inStr, 128);
    numEmp = atoi(inStr);
    for (int i = 0; i < numEmp; i++)
    {
        // Instantiate an EmployeeRecord
        empRec = new EmployeeRecord();
        // Read and set the ID
        getNextLine(inStr, 127);
        id = atoi(inStr);
        empRec->setID(id);
        // Read and set the name
        getNextLine(fName, 31);
        getNextLine(lName, 31);
        empRec->setName(fName, lName);
        // Read and set the Department ID
        getNextLine(inStr, 127);
        dept = atoi(inStr);
        empRec->setDept(dept);
        // Read and set the Salary
        getNextLine(inStr, 127);
        sal = atof(inStr);
        empRec->setSalary(sal);
        // Get the customer list
        theList = empRec->getCustomerList();
        // Get the number of stores
        getNextLine(inStr, 127);
        numStores = atoi(inStr);
        for (int j = 0; j < numStores; j++)
        {
            // Read the store ID
            getNextLine(inStr, 127);
            sID = atoi(inStr);
            // Read the store name
            getNextLine(sName, 63);
            // Read the store address
            getNextLine(sAddr, 63);
            // Read the store city
            getNextLine(sCity, 31);
            // Read the store state
            getNextLine(sSt, 31);
            // Read the store zip
            getNextLine(sZip, 11);
            // Create a new Store object
            theStore = new Store(sID, sName, sAddr, sCity, sSt, sZip);
            theList->addStore(theStore);
        }
        cout.flush();
        addEmployee(empRec);
    }
    inFile.close();
    return true;	// Successfully built the database
}
