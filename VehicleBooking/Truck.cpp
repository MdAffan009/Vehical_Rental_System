#include "Truck.h"
#include <iostream>
using namespace std;
Truck::Truck(string b, int y, double p, double load) : Vehicle(b, y, p), payloadCapacity(load) {}
void Truck::displayInfo() const
{
    cout << "\n--- Truck Details ---" << endl;
    Vehicle::displayInfo();
    cout << "Payload Capacity: " << payloadCapacity << " tons" << endl;
}
