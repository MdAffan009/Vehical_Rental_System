#include "Car.h"
#include <iostream>
using namespace std;
Car::Car(string b, int y, double p, int cap) : Vehicle(b, y, p), seatingCapacity(cap) {}
void Car::displayInfo() const
{
    cout << "\n--- Car Details ---" << endl;
    Vehicle::displayInfo();
    cout << "Seating Capacity: " << seatingCapacity << " seats" << endl;
}
