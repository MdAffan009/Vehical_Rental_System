#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

// Car charges the base daily rate as-is (1.0x multiplier)
class Car : public Vehicle
{
private:
    int seatingCapacity;

public:
    Car(std::string id, std::string b, std::string m,
        int y, double rate, int cap,
        std::string st = "Available");

    // Getters
    int getSeatingCapacity() const;

    // Cost = dailyRate * 1.0 * days
    double calculateCost(int days) const override;

    void displayInfo() const override;
};

#endif
