#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle
{
protected:
    string brand;
    int year;
    double price;

public:
    Vehicle(string b, int y, double p);
    virtual void displayInfo() const;
    virtual ~Vehicle();
};
#endif
