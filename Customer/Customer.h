#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer
{
private:
    std::string customerID;
    std::string name;
    int age;
    std::string phone;
    std::string email;
    std::string licenseNumber; // Actual license number string

public:
    // Constructor
    Customer(std::string id, std::string n, int a,
             std::string ph, std::string em, std::string lic);

    // --- Getters ---
    std::string getCustomerID() const;
    std::string getName() const;
    int getAge() const;
    std::string getPhone() const;
    std::string getEmail() const;
    std::string getLicenseNumber() const;

    // --- Setters ---
    void setPhone(std::string ph);
    void setEmail(std::string em);
    void setLicenseNumber(std::string lic);

    // Display formatted customer info
    void displayInfo() const;
};

#endif
