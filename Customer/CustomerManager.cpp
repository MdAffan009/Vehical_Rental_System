#include "CustomerManager.h"
#include <iostream>

using namespace std;

// Add a new customer to the list
void CustomerManager::addCustomer(const Customer &c)
{
    customers.push_back(c);
    cout << "Customer \"" << c.getName()
         << "\" registered successfully." << endl;
}

// Remove customer by ID
// Iterates through the vector and erases the matching entry
bool CustomerManager::removeCustomer(const string &customerID)
{
    for (auto it = customers.begin(); it != customers.end(); ++it)
    {
        if (it->getCustomerID() == customerID)
        {
            cout << "Customer \"" << it->getName()
                 << "\" removed successfully." << endl;
            customers.erase(it);
            return true;
        }
    }
    cout << "Customer with ID \"" << customerID << "\" not found." << endl;
    return false;
}

// Search customer by ID — returns a pointer into the vector
// Caller must NOT store this pointer long-term (vector can reallocate)
Customer *CustomerManager::searchCustomer(const string &customerID)
{
    for (auto &c : customers)
    {
        if (c.getCustomerID() == customerID)
        {
            return &c;
        }
    }
    return nullptr;
}

// Print all registered customers
void CustomerManager::displayAllCustomers() const
{
    if (customers.empty())
    {
        cout << "\nNo customers registered yet." << endl;
        return;
    }
    cout << "\n========== ALL CUSTOMERS ==========" << endl;
    for (const auto &c : customers)
    {
        c.displayInfo();
    }
    cout << "====================================" << endl;
}

int CustomerManager::getCustomerCount() const
{
    return (int)customers.size();
}
