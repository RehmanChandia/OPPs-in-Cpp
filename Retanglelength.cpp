
#include <iostream>
#include <cstdlib>
using namespace std;

// Rectangle class
class Rectangle
{
    // Private data members
    double width{};
    double length{};

public:

    // Constructor
    Rectangle()
    {
        width = 0;
        length = 0;
    }

    // Setter function for length
    void setlength(double l)
    {
        if (l >= 0)
            length = l;
        else
        {
            cout << "Invalid length" << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Setter function for width
    void setwidth(double w)
    {
        if (w >= 0)
            width = w;
        else
        {
            cout << "Invalid width" << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Getter function for length
    double getlength() const
    {
        return length;
    }

    // Getter function for width
    double getwidth() const
    {
        return width;
    }

    // Function to calculate area
    double getArea() const
    {
        return length * width;
    }
};

// Main function
int main()
{
    // Creating Rectangle object
    Rectangle box;

    // Setting values
    box.setlength(10);
    box.setwidth(5);

    // Displaying length
    cout << "Length: " << box.getlength() << endl;

    // Displaying width
    cout << "Width: " << box.getwidth() << endl;

    // Displaying area
    cout << "Area: " << box.getArea() << endl;

    return 0;
}
