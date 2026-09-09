#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(string id, string n, int a,
                   string ph, string em, string lic)
    : customerID(id), name(n), age(a),
      phone(ph), email(em), licenseNumber(lic)
{
}

// --- Getters ---

string Customer::getCustomerID() const { return customerID; }
string Customer::getName() const { return name; }
int Customer::getAge() const { return age; }
string Customer::getPhone() const { return phone; }
string Customer::getEmail() const { return email; }
string Customer::getLicenseNumber() const { return licenseNumber; }

// --- Setters ---

void Customer::setPhone(string ph) { phone = ph; }
void Customer::setEmail(string em) { email = em; }
void Customer::setLicenseNumber(string lic) { licenseNumber = lic; }

void Customer::displayInfo() const
{
    cout << "\n===== CUSTOMER DETAILS =====" << endl;
    cout << "  Customer ID : " << customerID << endl;
    cout << "  Name        : " << name << endl;
    cout << "  Age         : " << age << endl;
    cout << "  Phone       : " << phone << endl;
    cout << "  Email       : " << email << endl;
    cout << "  License No  : " << licenseNumber << endl;
}
