// h file for Csting class
#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;

class String
{
    char* str{};
    int length{};

public:
    String();
    String(const char*);
    String(const String&);

    int getLength(const char*) const;
    const char* getString() const;

    void setString(const char*);
    void setLength(int);

    char& operator[](int);

    String& operator+=(const String&);
    bool operator==(const String&) const;
    bool operator>(const String&) const;
    bool operator<(const String&) const;

    String& operator=(const String&);

    ~String();

    friend String operator+(const String&, const String&);
    friend ostream& operator<<(ostream&, const String&);
    friend istream& operator>>(istream&, String&);
};

#endif
// impllementation file for CString
#include "String.h"

// Default Constructor
String::String()
{
    length = 0;

    str = new char[1];

    str[0] = '\0';
}

// Parameterized Constructor
String::String(const char* s)
{
    length = 0;

    while (s[length] != '\0')
    {
        length++;
    }

    str = new char[length + 1];

    for (int i = 0; i < length; i++)
    {
        str[i] = s[i];
    }

    str[length] = '\0';
}

// Copy Constructor
String::String(const String& s)
{
    length = s.length;

    str = new char[length + 1];

    for (int i = 0; i < length; i++)
    {
        str[i] = s.str[i];
    }

    str[length] = '\0';
}

// Get Length
int String::getLength(const char* s) const
{
    int count = 0;

    while (s[count] != '\0')
    {
        count++;
    }

    return count;
}

// Get String
const char* String::getString() const
{
    return str;
}

// Set String
void String::setString(const char* s)
{
    int newLength = 0;

    while (s[newLength] != '\0')
    {
        newLength++;
    }

    char* temp = new char[newLength + 1];

    for (int i = 0; i < newLength; i++)
    {
        temp[i] = s[i];
    }

    temp[newLength] = '\0';

    delete[] str;

    str = temp;
    length = newLength;
}

// Set Length
void String::setLength(int l)
{
    length = l;
}

// Subscript Operator
char& String::operator[](int index)
{
    return str[index];
}

// Addition Assignment Operator
String& String::operator+=(const String& s)
{
    char* temp = new char[length + s.length + 1];

    int i = 0;

    for (; i < length; i++)
    {
        temp[i] = str[i];
    }

    for (int j = 0; j < s.length; j++)
    {
        temp[i] = s.str[j];
        i++;
    }

    temp[i] = '\0';

    delete[] str;

    str = temp;
    length = length + s.length;

    return *this;
}

// Equality Operator
bool String::operator==(const String& s) const
{
    if (length != s.length)
        return false;

    for (int i = 0; i < length; i++)
    {
        if (str[i] != s.str[i])
            return false;
    }

    return true;
}

// Greater Than Operator
bool String::operator>(const String& s) const
{
    int i = 0;

    while (str[i] == s.str[i] && str[i] != '\0')
    {
        i++;
    }

    return str[i] > s.str[i];
}

// Less Than Operator
bool String::operator<(const String& s) const
{
    int i = 0;

    while (str[i] == s.str[i] && str[i] != '\0')
    {
        i++;
    }

    return str[i] < s.str[i];
}

// Assignment Operator
String& String::operator=(const String& s)
{
    if (this != &s)
    {
        char* temp = new char[s.length + 1];

        for (int i = 0; i < s.length; i++)
        {
            temp[i] = s.str[i];
        }

        temp[s.length] = '\0';

        delete[] str;

        str = temp;
        length = s.length;
    }

    return *this;
}

// Destructor
String::~String()
{
    delete[] str;
}

// Addition Operator
String operator+(const String& a, const String& b)
{
    String temp;

    delete[] temp.str;

    temp.length = a.length + b.length;

    temp.str = new char[temp.length + 1];

    int i = 0;

    for (; i < a.length; i++)
    {
        temp.str[i] = a.str[i];
    }

    for (int j = 0; j < b.length; j++)
    {
        temp.str[i] = b.str[j];
        i++;
    }

    temp.str[i] = '\0';

    return temp;
}

// Output Operator
ostream& operator<<(ostream& os, const String& s)
{
    os << s.str;

    return os;
}

// Input Operator
istream& operator>>(istream& is, String& s)
{
    char buffer[1000];

    is.width(1000);
    is >> buffer;

    if (is)
    {
        s.setString(buffer);
    }

    return is;
}

// main file for CString 
#include "String.h"
#include <iostream>
using namespace std;

int main()
{
    // Creating String objects
    String str1("Rehman");
    String str2("Chandia");

    // Displaying strings
    cout << "First String: " << str1 << endl;
    cout << "Second String: " << str2 << endl;

    // Finding length
    cout << "Length of First String: "
         << str1.getLength(str1.getString()) << endl;

    // Accessing a character
    cout << "Character at index 0: " << str1[0] << endl;

    // Addition operator
    String str3 = str1 + str2;
    cout << "After Addition: " << str3 << endl;

    // Addition assignment operator
    str1 += str2;
    cout << "After += : " << str1 << endl;

    // Equality operator
    if (str1 == str3)
        cout << "Both strings are equal" << endl;

    // Greater than operator
    if (str1 > str2)
        cout << "First string is greater" << endl;

    // Less than operator
    if (str2 < str1)
        cout << "Second string is smaller" << endl;

    // Assignment operator
    String str4;
    str4 = str1;

    cout << "Assigned String: " << str4 << endl;

    // Changing string
    str4.setString("Hello");

    cout << "After setString: " << str4 << endl;

    // Taking input
    cout << "Enter a string: ";
    cin >> str4;

    cout << "You entered: " << str4 << endl;

    return 0;
}
