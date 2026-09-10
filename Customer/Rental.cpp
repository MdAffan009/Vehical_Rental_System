#include "Rental.h"
#include <iostream>
#include <iomanip>

using namespace std;

Rental::Rental(string rid, string cid,
               string vid, int days, double cost)
    : rentalID(rid), customerID(cid), vehicleID(vid),
      numberOfDays(days), totalCost(cost), isReturned(false)
{
}

// --- Getters ---

string Rental::getRentalID() const { return rentalID; }
string Rental::getCustomerID() const { return customerID; }
string Rental::getVehicleID() const { return vehicleID; }
int Rental::getNumberOfDays() const { return numberOfDays; }
double Rental::getTotalCost() const { return totalCost; }
bool Rental::getIsReturned() const { return isReturned; }

// --- Setters ---

void Rental::setIsReturned(bool returned) { isReturned = returned; }
void Rental::setTotalCost(double cost) { totalCost = cost; }

// Prints a formatted receipt to console.
// Called by RentalManager::returnVehicle() after marking the rental returned.
void Rental::generateBill(const string &customerName,
                          const string &vehicleBrand,
                          const string &vehicleModel) const
{
     cout << "\n";
     cout << "============================================" << endl;
     cout << "          VEHICLE RENTAL RECEIPT            " << endl;
     cout << "============================================" << endl;
     cout << "  Rental ID    : " << rentalID << endl;
     cout << "  Customer ID  : " << customerID << endl;
     cout << "  Customer Name: " << customerName << endl;
     cout << "--------------------------------------------" << endl;
     cout << "  Vehicle ID   : " << vehicleID << endl;
     cout << "  Vehicle      : " << vehicleBrand
          << " " << vehicleModel << endl;
     cout << "  Rental Days  : " << numberOfDays << endl;
     cout << "--------------------------------------------" << endl;
     cout << fixed << setprecision(2);
     cout << "  TOTAL COST   : $" << totalCost << endl;
     cout << "  Status       : "
          << (isReturned ? "Returned" : "Active") << endl;
     cout << "============================================" << endl;
}
