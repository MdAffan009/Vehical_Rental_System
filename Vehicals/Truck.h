#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

// Truck charges 1.5x the base daily rate
class Truck : public Vehicle
{
private:
    double payloadCapacity; // in tons

public:
    Truck(std::string id, std::string b, std::string m,
          int y, double rate, double load,
          std::string st = "Available");

    // Getters
    double getPayloadCapacity() const;

    // Cost = dailyRate * 1.5 * days
    double calculateCost(int days) const override;

    void displayInfo() const override;
};

#endif
