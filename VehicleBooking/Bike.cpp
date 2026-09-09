#include "Bike.h"
#include <iostream>
using namespace std;
Bike::Bike(string b, int y, double p, int cc) : Vehicle(b, y, p), engineCC(cc) {}
void Bike::displayInfo() const
{
    cout << "\n--- Bike Details ---" << endl;
    Vehicle::displayInfo();
    cout << "Engine Capacity: " << engineCC << " cc" << endl;
}
