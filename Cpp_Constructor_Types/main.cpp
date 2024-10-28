/**
 * @file main.cpp
 * @brief Simple program for show constructors
 * 
 * @author HFA
 * @date 28/10/2024
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class myClass {
public:
    myClass() {
        constructorName = "default constructor"; 
        cout << "myClass default constructor" << endl;
    }
    myClass(const myClass &leftRef) { 
        constructorName = "copy constructor"; 
        cout << "myClass copy constructor" << endl;
    }
    myClass(const myClass &&rightRef) {
        constructorName = "move constructor"; 
        cout << "myClass move constructor" << endl;
    }
    const string &getConstructorType() {
        return constructorName;
    }
private:
    string constructorName;
};

int main() {
    // we declared a vector of myClass but it is not initialized.
    // so, before we initialize it, the constructor will not be called
    vector<myClass> myVector; 
    // we initialize the vector and the constructor will be called.
    // then we push a new object into the vector
    myVector.push_back(myClass());
    // we declaring a myLocalClass of myClass
    // and initialize it with a default constructor
    myClass myLocalClass;
    // we declaring "myLocalClass2" of myClass
    // and initialize it with a copy constructor
    myClass myLocalClass2(myLocalClass);
    // we declaring "myLocalClass3" of myClass
    // and initialize it with a move constructor
    myClass myLocalClass3(std::move(myLocalClass2));
    
    return 0;
}