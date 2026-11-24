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

