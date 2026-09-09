#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
class Car : public Vehicle
{
private:
    int seatingCapacity;

public:
    Car(string b, int y, double p, int cap);
    void displayInfo() const override;
};
#endif
