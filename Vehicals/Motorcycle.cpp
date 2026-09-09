#include "Motorcycle.h"
#include <iostream>

using namespace std;

Motorcycle::Motorcycle(string id, string b, string m,
                       int y, double rate, int cc, string st)
    : Vehicle(id, b, m, y, rate, st), engineCC(cc)
{
}

int Motorcycle::getEngineCC() const
{
    return engineCC;
}

// Motorcycles are cheaper: dailyRate * 0.8 * days
double Motorcycle::calculateCost(int days) const
{
    return dailyRate * 0.8 * days;
}

void Motorcycle::displayInfo() const
{
    cout << "\n--- Motorcycle Details ---" << endl;
    Vehicle::displayInfo();
    cout << "  Engine      : " << engineCC << " cc" << endl;
    cout << "  Type        : Motorcycle (0.8x rate)" << endl;
}
