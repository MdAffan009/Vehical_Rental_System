#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
using namespace std;
class Customer
{
private:
    string name;
    int age;
    string phone;
    string address;
    string email;
    char drivingLicense;

public:
    Customer(string n, int a, string ph, string ad, string em, char dl);
    int getAge() const;
    char getDrivingLicense() const;
    void displayCustomerInfo() const;
};
#endif
