#include "Truck.h"
#include <iostream>

using namespace std;

Truck::Truck(string id, string b, string m,
             int y, double rate, double load, string st)
    : Vehicle(id, b, m, y, rate, st), payloadCapacity(load)
{
}

double Truck::getPayloadCapacity() const
{
    return payloadCapacity;
}

// Trucks cost more: dailyRate * 1.5 * days
double Truck::calculateCost(int days) const
{
    return dailyRate * 1.5 * days;
}

void Truck::displayInfo() const
{
    cout << "\n--- Truck Details ---" << endl;
    Vehicle::displayInfo();
    cout << "  Payload     : " << payloadCapacity << " tons" << endl;
    cout << "  Type        : Truck (1.5x rate)" << endl;
}
