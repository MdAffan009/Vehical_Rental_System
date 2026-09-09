#ifndef BIKE_H
#define BIKE_H
#include "Vehicle.h"
class Bike : public Vehicle
{
private:
    int engineCC;

public:
    Bike(string b, int y, double p, int cc);
    void displayInfo() const override;
};
#endif
