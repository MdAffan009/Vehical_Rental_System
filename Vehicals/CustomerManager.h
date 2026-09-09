#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include "Customer.h"
#include <vector>
#include <string>

// Manages the full list of registered customers.
// Module 4 (main menu) will create one instance of this
// and call these methods directly.
class CustomerManager
{
private:
    std::vector<Customer> customers;

public:
    // Register a new customer
    void addCustomer(const Customer &c);

    // Remove a customer by their ID — returns true if found and removed
    bool removeCustomer(const std::string &customerID);

    // Search and return a pointer to a customer by ID
    // Returns nullptr if not found
    Customer *searchCustomer(const std::string &customerID);

    // Display all registered customers
    void displayAllCustomers() const;

    // Check how many customers are registered
    int getCustomerCount() const;
};

#endif
