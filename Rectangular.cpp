// h file 

#ifndef RECTANGULAR_H
#define RECTANGULAR_H
class Rectangular{
    private:
    double length;
    double width;
    public:
void setlength(double );
void setwidth(double );
double getlength()const;
double getwidth()const;
double getarea()const;

};

#endif // RECTANGULAR_H

// implementation file 
#include "rectangular.h"
void Rectangular::setwidth(double w){
    width=w;
}
void Rectangular::setlength(double l){
    length=l;
}
double Rectangular::getlength()const{
    return length;
}
double Rectangular::getwidth()const{
    return width;
}
double Rectangular::getarea()const{
    return length*width;
}

/// main file 
#include <iostream>
#include "rectangular.h"
using namespace std;
int main(){
    Rectangular r;
double l,w;
cout<<"Enter length and width of rectangle: ";
cin>>l>>w;
r.setlength(l);
r.setwidth(w);
cout<<"Here is the data of rectangle: "<<endl;
cout<<"Area of rectangle: "<<r.getarea()<<endl;
cout<<"Length of rectangle: "<<r.getlength()<<endl;
cout<<"Width of rectangle: "<<r.getwidth()<<endl;
return 0;
}
