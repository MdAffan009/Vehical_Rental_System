#ifndef RENTALMANAGER_H
#define RENTALMANAGER_H

#include "Rental.h"
#include "Vehicals/Vehicle.h"
#include "CustomerManager.h"
#include <vector>
#include <string>

// Manages all rental transactions.
// Depends on Vehicle pointers and CustomerManager to validate
// and update state when renting or returning vehicles.
class RentalManager {
private:
    std::vector<Rental> rentals;
    int nextRentalID; // Auto-increments to generate unique rental IDs

    // Internal helper — generates the next rental ID string e.g. "R001"
    std::string generateRentalID();

public:
    RentalManager();

    // Book a vehicle for a customer for a given number of days.
    // Validates: vehicle exists, vehicle is Available, days > 0, customer exists.
    // On success: creates a Rental, sets vehicle status to "Rented".
    // Returns true if booking succeeded.
    bool rentVehicle(const std::string& customerID,
                     const std::string& vehicleID,
                     int days,
                     std::vector<Vehicle*>& fleet,
                     CustomerManager& cm);

    // Return a rented vehicle by rental ID.
    // On success: sets vehicle status back to "Available", prints bill.
    // Returns true if return succeeded.
    bool returnVehicle(const std::string& rentalID,
                       std::vector<Vehicle*>& fleet,
                       CustomerManager& cm);

    // Display all rentals — both active and returned.
    void viewRentalHistory() const;
};

#endif
