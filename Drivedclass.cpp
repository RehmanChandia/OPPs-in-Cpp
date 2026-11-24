//h file
#ifndef DRIVED_H
#define DRIVED_H
class Base {
private:
    int a;

public:
    Base();
 ~Base();
};
class Derived1 : public Base {
private:
    int b;

public:
    Derived1();
    ~Derived1();
};
class Derived2 : public Derived1 {
private:
    int c;
public:
    Derived2();
    ~Derived2();
};
#endif
// implementation file
#include <iostream>
#include "drived.h"
using namespace std;
Base::Base() {
    a={};
    cout << "Base Constructor" << endl;
}
Base::~Base() {
    cout << "Base Destructor" << endl;
}
Derived1::Derived1() {
    b={};
    cout << "Derived1 Constructor" << endl;
}
Derived1::~Derived1() {
    cout << "Derived1 Destructor" << endl;
}
Derived2::Derived2() {
    c={};
    cout << "Derived2 Constructor" << endl;
}
Derived2::~Derived2() {
    cout << "Derived2 Destructor" << endl;
}
// main file 
#include "drived.h"

int main() {
    Base base1;
    Derived1 d1;
    Derived2 d2;

    return 0;
}
