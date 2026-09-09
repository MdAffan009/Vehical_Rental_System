#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"
class Truck : public Vehicle
{
private:
    double payloadCapacity;

public:
    Truck(string b, int y, double p, double load);
    void displayInfo() const override;
};
#endif
