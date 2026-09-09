#include "Customer.h"
#include <iostream>
using namespace std;
Customer::Customer(string n, int a, string ph, string ad, string em, char dl) : name(n), age(a), phone(ph), address(ad), email(em), drivingLicense(dl) {}
int Customer::getAge() const { return age; }
char Customer::getDrivingLicense() const { return drivingLicense; }
void Customer::displayCustomerInfo() const
{
    cout << "\n===== CUSTOMER DETAILS =====" << endl;
    cout << "Name    : " << name << endl;
    cout << "Age     : " << age << endl;
    cout << "Phone   : " << phone << endl;
    cout << "Address : " << address << endl;
    cout << "Email   : " << email << endl;
    cout << "Driving License: " << (drivingLicense == 'Y' || drivingLicense == 'y' ? "Yes" : "No") << endl;
}
