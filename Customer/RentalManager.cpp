#include "RentalManager.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

RentalManager::RentalManager() : nextRentalID(1)
{
}

// Generates IDs like "R001", "R002", etc.
string RentalManager::generateRentalID()
{
    ostringstream oss;
    oss << "R" << setw(3) << setfill('0') << nextRentalID++;
    return oss.str();
}

// -------------------------------------------------------
// rentVehicle
// -------------------------------------------------------
// Validates everything before creating the rental:
//   1. Rental days must be > 0
//   2. Customer must exist in CustomerManager
//   3. Vehicle must exist in the fleet
//   4. Vehicle must be "Available" (not Rented or Maintenance)
// -------------------------------------------------------
bool RentalManager::rentVehicle(const string &customerID,
                                const string &vehicleID,
                                int days,
                                vector<Vehicle *> &fleet,
                                CustomerManager &cm)
{

    // --- Validation 1: days must be positive ---
    if (days <= 0)
    {
        cout << "  [Error] Rental duration must be greater than zero." << endl;
        return false;
    }

    // --- Validation 2: customer must exist ---
    Customer *customer = cm.searchCustomer(customerID);
    if (!customer)
    {
        cout << "  [Error] Customer ID \"" << customerID
             << "\" not found." << endl;
        return false;
    }

    // --- Validation 3: vehicle must exist in fleet ---
    Vehicle *vehicle = nullptr;
    for (auto &v : fleet)
    {
        if (v->getVehicleID() == vehicleID)
        {
            vehicle = v;
            break;
        }
    }

    if (!vehicle)
    {
        cout << "  [Error] Vehicle ID \"" << vehicleID
             << "\" not found." << endl;
        return false;
    }

    // --- Validation 4: vehicle must be Available ---
    if (vehicle->getStatus() != "Available")
    {
        cout << "  [Error] Vehicle \"" << vehicle->getBrand()
             << " " << vehicle->getModel()
             << "\" is currently " << vehicle->getStatus()
             << " and cannot be rented." << endl;
        return false;
    }

    // --- All checks passed — create the rental ---
    double cost = vehicle->calculateCost(days); // polymorphic call
    string rid = generateRentalID();

    rentals.push_back(Rental(rid, customerID, vehicleID, days, cost));

    // Update vehicle status
    vehicle->setStatus("Rented");

    cout << "\n  [Success] Rental confirmed!" << endl;
    cout << "  Rental ID   : " << rid << endl;
    cout << "  Customer    : " << customer->getName() << endl;
    cout << "  Vehicle     : " << vehicle->getBrand()
         << " " << vehicle->getModel() << endl;
    cout << "  Days        : " << days << endl;
    cout << fixed << setprecision(2);
    cout << "  Total Cost  : $" << cost << endl;

    return true;
}

// -------------------------------------------------------
// returnVehicle
// -------------------------------------------------------
// Finds the rental by ID, marks it returned,
// sets the vehicle back to Available, and prints the bill.
// -------------------------------------------------------
bool RentalManager::returnVehicle(const string &rentalID,
                                  vector<Vehicle *> &fleet,
                                  CustomerManager &cm)
{

    // Find the rental
    Rental *rental = nullptr;
    for (auto &r : rentals)
    {
        if (r.getRentalID() == rentalID)
        {
            rental = &r;
            break;
        }
    }

    if (!rental)
    {
        cout << "  [Error] Rental ID \"" << rentalID
             << "\" not found." << endl;
        return false;
    }

    if (rental->getIsReturned())
    {
        cout << "  [Error] Rental \"" << rentalID
             << "\" has already been returned." << endl;
        return false;
    }

    // Find the vehicle to set it back to Available
    Vehicle *vehicle = nullptr;
    for (auto &v : fleet)
    {
        if (v->getVehicleID() == rental->getVehicleID())
        {
            vehicle = v;
            break;
        }
    }

    // Find the customer for the bill
    Customer *customer = cm.searchCustomer(rental->getCustomerID());

    // Mark as returned and free the vehicle
    rental->setIsReturned(true);
    if (vehicle)
    {
        vehicle->setStatus("Available");
    }

    // Print the receipt
    string customerName = customer ? customer->getName() : "Unknown";
    string vehicleBrand = vehicle ? vehicle->getBrand() : "Unknown";
    string vehicleModel = vehicle ? vehicle->getModel() : "Unknown";

    rental->generateBill(customerName, vehicleBrand, vehicleModel);

    return true;
}

// -------------------------------------------------------
// viewRentalHistory
// -------------------------------------------------------
void RentalManager::viewRentalHistory() const
{
    if (rentals.empty())
    {
        cout << "\n  No rentals on record yet." << endl;
        return;
    }

    cout << "\n========== RENTAL HISTORY ==========" << endl;
    for (const auto &r : rentals)
    {
        cout << "\n  Rental ID  : " << r.getRentalID() << endl;
        cout << "  Customer ID: " << r.getCustomerID() << endl;
        cout << "  Vehicle ID : " << r.getVehicleID() << endl;
        cout << "  Days       : " << r.getNumberOfDays() << endl;
        cout << fixed << setprecision(2);
        cout << "  Total Cost : $" << r.getTotalCost() << endl;
        cout << "  Status     : "
             << (r.getIsReturned() ? "Returned" : "Active") << endl;
    }
    cout << "\n====================================" << endl;
}
