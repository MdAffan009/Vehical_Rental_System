#include "Car.h"
#include <iostream>

using namespace std;

Car::Car(string id, string b, string m,
         int y, double rate, int cap, string st)
    : Vehicle(id, b, m, y, rate, st), seatingCapacity(cap)
{
}

int Car::getSeatingCapacity() const
{
    return seatingCapacity;
}

// Cars charge standard rate: dailyRate * 1.0 * days
double Car::calculateCost(int days) const
{
    return dailyRate * 1.0 * days;
}

void Car::displayInfo() const
{
    cout << "\n--- Car Details ---" << endl;
    Vehicle::displayInfo();
    cout << "  Seating Cap : " << seatingCapacity << " seats" << endl;
    cout << "  Type        : Car (1.0x rate)" << endl;
}
