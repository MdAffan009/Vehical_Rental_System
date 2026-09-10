// main_test3.cpp
// Test harness for Module 3 — Rental, Return & Billing.
// Tests all happy paths and all validation/error cases.

#include <iostream>
#include <vector>

#include "Vehicals/Car.h"
#include "Vehicals/Motorcycle.h"
#include "Vehicals/Truck.h"

#include "Customer/Customer.h"
#include "Customer/CustomerManager.h"

#include "Customer/RentalManager.h"

using namespace std;

int main() {

    // -------------------------------------------------------
    // Setup — build a small fleet and customer list
    // (Module 4 will manage these via menus; here we do it directly)
    // -------------------------------------------------------

    vector<Vehicle*> fleet;
    fleet.push_back(new Car       ("V001", "Toyota", "Camry",     2022, 50.0, 5));
    fleet.push_back(new Motorcycle("V002", "Harley", "Sportster", 2021, 40.0, 883));
    fleet.push_back(new Truck     ("V003", "Ford",   "F-750",     2020, 80.0, 5.0));

    CustomerManager cm;
    cm.addCustomer(Customer("C001", "James Carter",   28, "555-0101", "james@email.com",  "DL-2021-10234"));
    cm.addCustomer(Customer("C002", "Sarah Mitchell", 34, "555-0202", "sarah@email.com",  "DL-2019-88571"));

    RentalManager rm;

    cout << "\n============================================" << endl;
    cout << "  MODULE 3 TEST — Rental, Return & Billing  " << endl;
    cout << "============================================" << endl;


    // -------------------------------------------------------
    // TEST 1: Valid rental — Car for 3 days
    // Expected: success, cost = $50 * 1.0 * 3 = $150
    // -------------------------------------------------------
    cout << "\n[TEST 1] Rent Car V001 to C001 for 3 days" << endl;
    rm.rentVehicle("C001", "V001", 3, fleet, cm);


    // -------------------------------------------------------
    // TEST 2: Try to rent the same car again (already Rented)
    // Expected: error — vehicle not Available
    // -------------------------------------------------------
    cout << "\n[TEST 2] Try to rent V001 again (should fail — already Rented)" << endl;
    rm.rentVehicle("C002", "V001", 2, fleet, cm);


    // -------------------------------------------------------
    // TEST 3: Valid rental — Motorcycle for 5 days
    // Expected: success, cost = $40 * 0.8 * 5 = $160
    // -------------------------------------------------------
    cout << "\n[TEST 3] Rent Motorcycle V002 to C002 for 5 days" << endl;
    rm.rentVehicle("C002", "V002", 5, fleet, cm);


    // -------------------------------------------------------
    // TEST 4: Invalid days (0)
    // Expected: error — duration must be > 0
    // -------------------------------------------------------
    cout << "\n[TEST 4] Try to rent with 0 days (should fail)" << endl;
    rm.rentVehicle("C001", "V003", 0, fleet, cm);


    // -------------------------------------------------------
    // TEST 5: Invalid customer ID
    // Expected: error — customer not found
    // -------------------------------------------------------
    cout << "\n[TEST 5] Try to rent with unknown customer C999 (should fail)" << endl;
    rm.rentVehicle("C999", "V003", 2, fleet, cm);


    // -------------------------------------------------------
    // TEST 6: Invalid vehicle ID
    // Expected: error — vehicle not found
    // -------------------------------------------------------
    cout << "\n[TEST 6] Try to rent unknown vehicle V999 (should fail)" << endl;
    rm.rentVehicle("C001", "V999", 2, fleet, cm);


    // -------------------------------------------------------
    // TEST 7: View rental history (2 active rentals so far)
    // -------------------------------------------------------
    cout << "\n[TEST 7] View rental history" << endl;
    rm.viewRentalHistory();


    // -------------------------------------------------------
    // TEST 8: Return V001 (Rental R001)
    // Expected: bill printed, V001 status back to Available
    // -------------------------------------------------------
    cout << "\n[TEST 8] Return rental R001" << endl;
    rm.returnVehicle("R001", fleet, cm);

    cout << "\nV001 status after return: "
         << fleet[0]->getStatus() << endl; // Should be "Available"


    // -------------------------------------------------------
    // TEST 9: Try to return the same rental again
    // Expected: error — already returned
    // -------------------------------------------------------
    cout << "\n[TEST 9] Try to return R001 again (should fail)" << endl;
    rm.returnVehicle("R001", fleet, cm);


    // -------------------------------------------------------
    // TEST 10: Rent V001 again — should work now it's Available
    // Expected: success, cost = $50 * 1.0 * 7 = $350
    // -------------------------------------------------------
    cout << "\n[TEST 10] Rent V001 again after return (should succeed)" << endl;
    rm.rentVehicle("C002", "V001", 7, fleet, cm);


    // -------------------------------------------------------
    // TEST 11: Final rental history — should show 3 rentals
    // -------------------------------------------------------
    cout << "\n[TEST 11] Final rental history" << endl;
    rm.viewRentalHistory();


    // -------------------------------------------------------
    // Cleanup
    // -------------------------------------------------------
    for (auto v : fleet) {
        delete v;
    }

    return 0;
}
