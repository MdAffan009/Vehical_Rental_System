#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

// Abstract base class for all vehicle types.
// Cannot be instantiated directly — must be subclassed.
class Vehicle
{
protected:
    std::string vehicleID;
    std::string brand;
    std::string model;
    int year;
    double dailyRate;
    std::string status; // "Available", "Rented", "Maintenance"

public:
    // Constructor
    Vehicle(std::string id, std::string b, std::string m,
            int y, double rate, std::string st = "Available");

    // --- Getters ---
    std::string getVehicleID() const;
    std::string getBrand() const;
    std::string getModel() const;
    int getYear() const;
    double getDailyRate() const;
    std::string getStatus() const;

    // --- Setters ---
    void setStatus(std::string st);
    void setDailyRate(double rate);

    // Pure virtual — makes Vehicle abstract.
    // Each subclass must implement its own cost logic.
    virtual double calculateCost(int days) const = 0;

    // Virtual display — overridden in subclasses
    virtual void displayInfo() const;

    // Virtual destructor — essential for polymorphic deletion
    virtual ~Vehicle();
};

#endif
