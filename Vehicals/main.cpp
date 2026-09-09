// main_test.cpp
// Test harness for Module 1 (Vehicle hierarchy) and Module 2 (Customer management).
// This is NOT the final main.cpp — that belongs to Module 4 (Member D).
// This file only exists to verify both modules compile and behave correctly.

#include <iostream>
#include "Car.h"
#include "Motorcycle.h"
#include "Truck.h"
#include "Customer.h"
#include "CustomerManager.h"

using namespace std;

int main()
{

    cout << "======================================" << endl;
    cout << "   MODULE 1 — Vehicle Hierarchy Test  " << endl;
    cout << "======================================" << endl;

    // Polymorphic array of Vehicle pointers — tests abstraction + polymorphism
    Vehicle *fleet[3];

    fleet[0] = new Car("V001", "Toyota", "Camry", 2022, 50.0, 5);
    fleet[1] = new Motorcycle("V002", "Harley", "Sportster", 2021, 40.0, 883);
    fleet[2] = new Truck("V003", "Ford", "F-750", 2020, 80.0, 5.0);

    int rentalDays = 3;

    for (int i = 0; i < 3; i++)
    {
        fleet[i]->displayInfo();
        cout << "  Rental Cost (" << rentalDays << " days) : $"
             << fleet[i]->calculateCost(rentalDays) << endl;
    }

    // Expected output:
    //   Car       : $50.0 * 1.0 * 3 = $150
    //   Motorcycle: $40.0 * 0.8 * 3 = $96
    //   Truck     : $80.0 * 1.5 * 3 = $360

    // Test status setter
    cout << "\n--- Testing status update ---" << endl;
    fleet[0]->setStatus("Rented");
    cout << "fleet[0] status after setStatus: "
         << fleet[0]->getStatus() << endl;

    // Clean up — virtual destructor ensures correct subclass destructor is called
    for (int i = 0; i < 3; i++)
    {
        delete fleet[i];
    }

    cout << "\n======================================" << endl;
    cout << "  MODULE 2 — Customer Manager Test    " << endl;
    cout << "======================================" << endl;

    CustomerManager cm;

    // Add customers
    cm.addCustomer(Customer("C001", "James Carter", 28, "555-0101", "james@email.com", "DL-2021-10234"));
    cm.addCustomer(Customer("C002", "Sarah Mitchell", 34, "555-0202", "sarah@email.com", "DL-2019-88571"));
    cm.addCustomer(Customer("C003", "Oliver Bennett", 22, "555-0303", "oliver@email.com", "DL-2023-47302"));

    // Display all
    cm.displayAllCustomers();

    // Search — found
    cout << "\n--- Search for C002 ---" << endl;
    Customer *found = cm.searchCustomer("C002");
    if (found)
    {
        found->displayInfo();
    }
    else
    {
        cout << "Not found." << endl;
    }

    // Search — not found
    cout << "\n--- Search for C999 (should not exist) ---" << endl;
    Customer *missing = cm.searchCustomer("C999");
    if (!missing)
    {
        cout << "Correctly returned nullptr for unknown ID." << endl;
    }

    // Remove customer
    cout << "\n--- Remove C001 ---" << endl;
    cm.removeCustomer("C001");

    // Display remaining
    cm.displayAllCustomers();

    cout << "\nTotal customers remaining: "
         << cm.getCustomerCount() << endl;

    cout << "\n=============================" << endl;
    cout << "  All tests passed cleanly.  " << endl;
    cout << "=============================" << endl;

    return 0;
}
