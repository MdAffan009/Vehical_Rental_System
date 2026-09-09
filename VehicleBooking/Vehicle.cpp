#include "Vehicle.h"
#include <iostream>
using namespace std;
Vehicle::Vehicle(string b, int y, double p) : brand(b), year(y), price(p) {}
void Vehicle::displayInfo() const
{
    cout << "Brand: " << brand << endl;
    cout << "Year: " << year << endl;
    cout << "Price: $" << price << endl;
}
Vehicle::~Vehicle() {}
