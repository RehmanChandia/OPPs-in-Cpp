// fraction.h
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
private:
    int num;
    int den;

public:
    // Constructors and destructor
    Fraction();
    Fraction(int n, int d = 1);
    Fraction(const Fraction& f);
    ~Fraction();

    // Copy assignment operator
    Fraction& operator=(const Fraction& f);

    // Arithmetic operators
    Fraction operator+(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;
    Fraction operator-() const;

    // Increment operators
    Fraction& operator++();      // Prefix: ++x
    Fraction operator++(int);    // Postfix: x++

    // Comparison operators
    bool operator==(const Fraction& f) const;
    bool operator!=(const Fraction& f) const;
    bool operator<(const Fraction& f) const;
    bool operator>(const Fraction& f) const;
    bool operator<=(const Fraction& f) const;
    bool operator>=(const Fraction& f) const;

    // Input and output operators
    friend std::istream& operator>>(std::istream& in, Fraction& f);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

// Function overloading
Fraction add(Fraction a, Fraction b);
Fraction add(Fraction a, Fraction b, Fraction c);

#endif

// fraction.cpp

#include "fraction.h"

// Default constructor
Fraction::Fraction()
{
    num = 0;
    den = 1;
}

// Parameterized constructor
Fraction::Fraction(int n, int d)
{
    num = n;
    den = d;

    if (den < 0)
    {
        num = -num;
        den = -den;
    }
}

// Copy constructor
Fraction::Fraction(const Fraction& f)
{
    num = f.num;
    den = f.den;
}

// Destructor
Fraction::~Fraction()
{
}

// Assignment operator =
Fraction& Fraction::operator=(const Fraction& f)
{
    num = f.num;
    den = f.den;

    return *this;
}

// Addition +
Fraction Fraction::operator+(const Fraction& f) const
{
    return Fraction(num * f.den + f.num * den,
                    den * f.den);
}

// Subtraction -
Fraction Fraction::operator-(const Fraction& f) const
{
    return Fraction(num * f.den - f.num * den,
                    den * f.den);
}

// Multiplication *
Fraction Fraction::operator*(const Fraction& f) const
{
    return Fraction(num * f.num, den * f.den);
}

// Division /
Fraction Fraction::operator/(const Fraction& f) const
{
    return Fraction(num * f.den, den * f.num);
}

// Unary minus
Fraction Fraction::operator-() const
{
    return Fraction(-num, den);
}

// Prefix increment ++x
Fraction& Fraction::operator++()
{
    num = num + den;
    return *this;
}

// Postfix increment x++
Fraction Fraction::operator++(int)
{
    Fraction temp(*this);
    num = num + den;
    return temp;
}

 // Comparison operators
bool Fraction::operator==(const Fraction& f) const
{
    return num * f.den == f.num * den;
}

bool Fraction::operator!=(const Fraction& f) const
{
    return !(*this == f);
}

bool Fraction::operator<(const Fraction& f) const
{
    return num * f.den < f.num * den;
}

bool Fraction::operator>(const Fraction& f) const
{
    return f < *this;
}

bool Fraction::operator<=(const Fraction& f) const
{
    return !(*this > f);
}

bool Fraction::operator>=(const Fraction& f) const
{
    return !(*this < f);
}

// Output operator <<
std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    out << f.num << "/" << f.den;
    return out;
}

// Input operator >>
std::istream& operator>>(std::istream& in, Fraction& f)
{
    int n, d;
    in >> n >> d;

    if (in && d != 0)
    {
        f.num = n;
        f.den = d;

        if (f.den < 0)
        {
            f.num = -f.num;
            f.den = -f.den;
        }
    }
    else if (in && d == 0)
    {
        in.setstate(std::ios::failbit);
    }

    return in;
}

// Function overloading: add two fractions
Fraction add(Fraction a, Fraction b)
{
    return a + b;
}

// Function overloading: add three fractions
Fraction add(Fraction a, Fraction b, Fraction c)
{
    return a + b + c;
}


// main :
#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
    Fraction f1(1, 2);
    Fraction f2(1, 3);

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    cout << "Addition = " << f1 + f2 << endl;
    cout << "Subtraction = " << f1 - f2 << endl;
    cout << "Multiplication = " << f1 * f2 << endl;
    cout << "Division = " << f1 / f2 << endl;

    cout << "Negative f1 = " << -f1 << endl;

    cout << boolalpha;

    cout << "f1 == f2: " << (f1 == f2) << endl;
    cout << "f1 != f2: " << (f1 != f2) << endl;
    cout << "f1 < f2: " << (f1 < f2) << endl;
    cout << "f1 > f2: " << (f1 > f2) << endl;
    cout << "f1 <= f2: " << (f1 <= f2) << endl;
    cout << "f1 >= f2: " << (f1 >= f2) << endl;

    Fraction x(1, 2);

    cout << "Prefix ++x = " << ++x << endl;
    cout << "Postfix x++ = " << x++ << endl;
    cout << "After x++ = " << x << endl;

    Fraction f3 = f1;
    f3 = f2;

    Fraction whole = 5;

    cout << "Copied fraction = " << f3 << endl;
    cout << "Integer fraction = " << whole << endl;

    cout << "add two = " << add(f1, f2) << endl;
    cout << "add three = " << add(f1, f2, whole) << endl;

    Fraction input;

    cout << "Enter numerator and denominator: ";

    cin >> input;

    cout << "You entered: " << input << endl;

    return 0;
}
