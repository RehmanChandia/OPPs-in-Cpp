
#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int day;
    int month;
    int year;

    bool isValid(int d, int m, int y);

public:
    Date(int d, int m, int y);
    Date(const Date& other);

    void inrementDay();
    void print() const;
    void printLong() const;
};

#endif
// data file

#include "Date.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
using namespace std;

bool Date::isValid(int d, int m, int y)
{
    if (y < 1 || m < 1 || m > 12)
        return false;

    int daysInMonth[] =
    {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    // Check for a leap year
    if ((y % 400 == 0) ||
        (y % 4 == 0 && y % 100 != 0))
    {
        daysInMonth[1] = 29;
    }

    return d >= 1 && d <= daysInMonth[m - 1];
}

Date::Date(int d, int m, int y)
{
    if (!isValid(d, m, y))
        throw invalid_argument("Invalid date!");

    day = d;
    month = m;
    year = y;
}

Date::Date(const Date& other)
{
    day = other.day;
    month = other.month;
    year = other.year;
}

void Date::inrementDay()
{
    day++;

    if (!isValid(day, month, year))
    {
        day = 1;
        month++;

        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
}

void Date::print() const
{
    cout << setfill('0')
         << setw(2) << day << "-"
         << setw(2) << month << "-"
         << year << endl;

    cout << setfill(' ');
}

void Date::printLong() const
{
    string months[] =
    {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    cout << months[month - 1] << " "
         << day << ", " << year << endl;
}
// .main file

#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    try
    {
        Date date1(20, 10, 2026), date2{date1};

        date1.inrementDay();

        date1.print();
        date1.printLong();
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << endl;
    }

    return 0;
}

