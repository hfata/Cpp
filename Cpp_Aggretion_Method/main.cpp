/**
 * @file main.cpp
 * @brief Simple program for "aggretion" method
 * 
 * @author HFA
 * @date 28/10/2024
 */
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

#define NUMBER_OF_EMPLOYEES    4

using namespace std;

/**
 * @brief Employee class
 */
class Employee {
public:
    Employee(const string& name, const string& task, const uint8_t age) : name(new string(name)), task(new string(task)), age(age) {};
    ~Employee() {
        delete name;
        delete task;
    }
    /**
     * @brief getEmployeeName
     * @return const string&
     */
    const string& getEmployeeName() {
        return *this->name;
    } 
    /**
     * @brief getEmployeeTask
     * @return const string&
     */
    const string& getEmployeeTask() {
        return *this->task;
    }     
private:
    string *name;
    string *task;
    uint8_t age;
};

/**
 * @brief Office class
 */
class Office {
public:
    Office() = default;
    ~Office() {
        clearEmployees(humanResourcesEmployees);
        clearEmployees(engineerEmployees);
    }
    /**
     * @brief clearEmployees
     *
     * @param employees
     *
     * Clear vector of employees, delete each employee and clear the vector
     */
    void clearEmployees(vector<Employee*>& employees) {
        for (auto& employee : employees) {
            delete employee;
        }
        employees.clear();
    }
    /**
     * @brief addEmployee
     * @param employee
     */
    void addEmployee(Employee* employee);
    /**
     * @brief deleteEmployee
     * @param name
     * @param task
     */
    void deleteEmployee(const string& name, const string& task);
    /**
     * @brief dispEmplooyeeGroup
     * @param task
     */
    void dispEmplooyeeGroup(const string& task);
private:
    vector<Employee*> humanResourcesEmployees;
    vector<Employee*> engineerEmployees;
};

/**
 * @brief Office::addEmployee
 * @param employee
 */
void Office::addEmployee(Employee* employee) {
    if (employee->getEmployeeTask() == "engineer") {
        engineerEmployees.push_back(employee);
    } else if (employee->getEmployeeTask() == "human resources") {
        humanResourcesEmployees.push_back(employee);
    } else {
        cout << "fault" << endl;
    }
}

/**
 * @brief Office::deleteEmployee
 * @param name
 * @param task
 */
void Office::deleteEmployee(const string& name, const string& task) {
    if ("engineer" == task) {
        for (auto it = engineerEmployees.begin(); it != engineerEmployees.end(); it++) {
            if ((*it)->getEmployeeName() == name) {
                engineerEmployees.erase(it);
                delete *it;
                break;
            }
        }
    } else if ("human resources" == task) {
        for (auto it = humanResourcesEmployees.begin(); it != humanResourcesEmployees.end(); it++) {
            if ((*it)->getEmployeeName() == name) {
                humanResourcesEmployees.erase(it);
                delete *it;
                break;
            }
        }
    }
    else {
        cout << "fault" << endl;
    }
}

/**
 * @brief Office::dispEmplooyeeGroup
 * @param task
 */
void Office::dispEmplooyeeGroup(const string& task) {
    if ("engineer" == task) {
        for (auto it = engineerEmployees.begin(); it != engineerEmployees.end(); it++) {
            cout << "Name: " << (*it)->getEmployeeName() << "\t\t\t" << "Task: " << task << endl;
        }
    } else if ("human resources" == task) {
        for (auto it = humanResourcesEmployees.begin(); it != humanResourcesEmployees.end(); it++) {
            cout << "Name: " << (*it)->getEmployeeName() << "\t\t\t" << "Task: " << task << endl;
        }
    }
    else {
        cout << "fault" << endl;
    }
}

int main() {
    Employee employee[NUMBER_OF_EMPLOYEES] = {
            {"Namık", "engineer", 26},
            {"Namık", "human resources", 32},
            {"Namık", "engineer", 32},
            {"Hakan", "engineer", 32}
        };
    Office office;
    for (int i = 0; i < NUMBER_OF_EMPLOYEES; i++) {
        office.addEmployee(&employee[i]);
    }

    office.dispEmplooyeeGroup("engineer");
    office.dispEmplooyeeGroup("human resources");
    return 0;
}