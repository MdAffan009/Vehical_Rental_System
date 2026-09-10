#ifndef RENTAL_H
#define RENTAL_H

#include <string>

// Represents a single rental transaction.
// Links a customer to a vehicle for a set number of days.
class Rental
{
private:
    std::string rentalID;
    std::string customerID;
    std::string vehicleID;
    int numberOfDays;
    double totalCost;
    bool isReturned;

public:
    // Constructor
    Rental(std::string rid, std::string cid,
           std::string vid, int days, double cost);

    // --- Getters ---
    std::string getRentalID() const;
    std::string getCustomerID() const;
    std::string getVehicleID() const;
    int getNumberOfDays() const;
    double getTotalCost() const;
    bool getIsReturned() const;

    // --- Setters ---
    void setIsReturned(bool returned);
    void setTotalCost(double cost);

    // Prints a formatted bill/receipt to console
    void generateBill(const std::string &customerName,
                      const std::string &vehicleBrand,
                      const std::string &vehicleModel) const;
};

#endif
