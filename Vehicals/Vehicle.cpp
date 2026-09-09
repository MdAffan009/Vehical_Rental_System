#include "Vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle(string id, string b, string m,
                 int y, double rate, string st)
    : vehicleID(id), brand(b), model(m),
      year(y), dailyRate(rate), status(st)
{
}

// --- Getters ---

string Vehicle::getVehicleID() const { return vehicleID; }
string Vehicle::getBrand() const { return brand; }
string Vehicle::getModel() const { return model; }
int Vehicle::getYear() const { return year; }
double Vehicle::getDailyRate() const { return dailyRate; }
string Vehicle::getStatus() const { return status; }

// --- Setters ---

void Vehicle::setStatus(string st)
{
    status = st;
}

void Vehicle::setDailyRate(double rate)
{
    dailyRate = rate;
}

// Base displayInfo — called by subclasses via Vehicle::displayInfo()
void Vehicle::displayInfo() const
{
    cout << "  Vehicle ID  : " << vehicleID << endl;
    cout << "  Brand       : " << brand << endl;
    cout << "  Model       : " << model << endl;
    cout << "  Year        : " << year << endl;
    cout << "  Daily Rate  : $" << dailyRate << "/day" << endl;
    cout << "  Status      : " << status << endl;
}

Vehicle::~Vehicle()
{
}
