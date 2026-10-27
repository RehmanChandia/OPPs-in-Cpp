// H file
#ifndef NAME_H
#define NAME_H

#include <iostream>
using namespace std;

class Name
{
private:
    char* firstName;
    char middleInitial;
    char* lastName;

public:
    // Set up the name
    Name(const char*, char, const char*);

    // Make a separate copy of a name
    Name(const Name&);

    // Free the memory used by the object
    ~Name();

    // Display the complete name
    friend ostream& operator<<(ostream&, const Name&);
};

#endif
// implementation file 

#include "Name.h"

Name::Name(const char* f, char m, const char* l)
{
    firstName = new char[20];
    int i = 0;

    while (f[i] != '\0')
    {
        firstName[i] = f[i];
        i++;
    }
    firstName[i] = '\0';

    middleInitial = m;

    lastName = new char[20];
    i = 0;

    while (l[i] != '\0')
    {
        lastName[i] = l[i];
        i++;
    }
    lastName[i] = '\0';
}

Name::Name(const Name& n)
{
    firstName = new char[20];
    int i = 0;

    while (n.firstName[i] != '\0')
    {
        firstName[i] = n.firstName[i];
        i++;
    }
    firstName[i] = '\0';

    middleInitial = n.middleInitial;

    lastName = new char[20];
    i = 0;

    while (n.lastName[i] != '\0')
    {
        lastName[i] = n.lastName[i];
        i++;
    }
    lastName[i] = '\0';
}

Name::~Name()
{
    delete[] firstName;
    delete[] lastName;
}

ostream& operator<<(ostream& out, const Name& n)
{
    out << n.firstName << " "
        << n.middleInitial << ". "
        << n.lastName;

    return out;
}
// main file 
#include "Name.h"

void print(Name _name)
{
    cout << "Inside doSomething " << _name << endl;
}

int main()
{
    Name name1("Object", 'O', "Programming");

    cout << name1 << endl;

    print(name1);

    cout << name1 << endl;

    return 0;
