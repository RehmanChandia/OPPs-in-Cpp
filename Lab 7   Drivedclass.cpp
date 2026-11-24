//h file
#ifndef DRIVED_H
#define DRIVED_H
class Base {
protected:
    int a;

public:
    Base(int a );

};
class Derived1 : public Base {
protected:
    int b;

public:
    Derived1(int a, int b);
   
};
class Derived2 : public Derived1 {
private:
    int c;
public:
    Derived2(int a, int b, int c);
   void print();
};
#endif

// implementation file
#include <iostream>
#include "drived.h"
using namespace std;
Base::Base(int a) {
    this->a = a;
    cout << "Base Constructor" << endl;
}


Derived1::Derived1(int a, int b):Base(a) {
    this->b = b;
    cout << "Derived1 Constructor" << endl;
}

Derived2::Derived2(int a, int b, int c):Derived1(a, b) 
{
    this->c = c;
    cout << "Derived2 Constructor" << endl;
}
void Derived2::print(){
    cout<<"Base value: "<<a<<endl;
    cout<<"Derived1 value: "<<b<<endl;
    cout<<"Decrived2 value: "<<c<<endl;
}
// main file 
#include "drived.h"
int main(){
	    Derived1 d1(2,4);
	    Derived2 d2(10, 20, 30);
d2.print();				

return 0;
}

// problem 3
ifndef DERIVED_H
#define DERIVED_H

class Base
{
private:
    int a;

public:
    Base(int a);
};

class Derived1 : public Base
{
private:
    int b;

public:
    Derived1(int a, int b);
};

class Derived2 : public Derived1
{
private:
    int c;

public:
    Derived2(int a, int b, int c);
    Derived2(const Derived2& obj);

    // Copy assignment operator
    Derived2& operator=(const Derived2& obj);

    void print();
    void setValue(int value);
};

class Derived3 : public Derived2
{
private:
    int d;

public:
    Derived3(int a, int b, int c, int d);
    Derived3(const Derived3& obj);
};

#endif

// i,plememtatin file

#include <iostream>
#include "Derived.h"
using namespace std;

// Base parameterized constructor
Base::Base(int a)
{
    this->a = a;
    cout << "Base constructor" << endl;
}

// Derived1 parameterized constructor
Derived1::Derived1(int a, int b) : Base(a)
{
    this->b = b;
    cout << "Derived1 constructor" << endl;
}

// Derived2 parameterized constructor
Derived2::Derived2(int a, int b, int c) : Derived1(a, b)
{
    this->c = c;
    cout << "Derived2 constructor" << endl;
}

// Derived2 copy constructor
Derived2::Derived2(const Derived2& obj) : Derived1(obj)
{
    this->c = obj.c;
    cout << "Derived2 copy constructor" << endl;
}

// Derived2 assignment operator
Derived2& Derived2::operator=(const Derived2& obj)
{
    cout << "Derived2 assignment operator" << endl;

    if (this != &obj)
    {
        Derived1::operator=(obj);
        c = obj.c;
    }

    return *this;
}

// Print function
void Derived2::print()
{
    cout << "Derived2 print" << endl;
}

// Set value function
void Derived2::setValue(int value)
{
    c = value;
    cout << "Derived2 setValue" << endl;
}

// Derived3 parameterized constructor
Derived3::Derived3(int a, int b, int c, int d)
    : Derived2(a, b, c)
{
    this->d = d;
    cout << "Derived3 constructor" << endl;
}

// Derived3 copy constructor
Derived3::Derived3(const Derived3& obj)
    : Derived2(obj)
{
    this->d = obj.d;
    cout << "Derived3 copy constructor" << endl;
}
// main
#include <iostream>
#include "Derived.h"
using namespace std;
int main(){
	    Derived2 d2(10, 20, 30);
	    Derived2 d3 {d2};
d2.print();
cout << endl;
d3.print();

d3.setValue(-12);
d2 = d3;

cout << endl;
d2.print();

return 0;
}
