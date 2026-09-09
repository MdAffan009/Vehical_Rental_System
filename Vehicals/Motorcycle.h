#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

// Motorcycle charges 0.8x the base daily rate
class Motorcycle : public Vehicle
{
private:
    int engineCC;

public:
    Motorcycle(std::string id, std::string b, std::string m,
               int y, double rate, int cc,
               std::string st = "Available");

    // Getters
    int getEngineCC() const;

    // Cost = dailyRate * 0.8 * days
    double calculateCost(int days) const override;

    void displayInfo() const override;
};

#endif
