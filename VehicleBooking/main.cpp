#include <iostream>
#include <string>

#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include "Truck.h"
#include "Customer.h"

using namespace std;

int main()
{
    string name, phone, address, email;
    int age;
    char drivingLicense;

    cout << "================================" << endl;
    cout << "     VEHICLE BOOKING SYSTEM" << endl;
    cout << "================================" << endl;
    cout << "\n===== ENTER CUSTOMER DETAILS =====" << endl;

    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Phone Number: ";
    getline(cin, phone);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Email: ";
    getline(cin, email);
    cout << "Do you have a Driving License? (Y/N): ";
    cin >> drivingLicense;

    Customer customer(name, age, phone, address, email, drivingLicense);

    if (customer.getAge() >= 18)
    {
        cout << "\nAge is valid (18+)." << endl;
        if (customer.getDrivingLicense() == 'Y' || customer.getDrivingLicense() == 'y')
        {
            cout << "Driving License verified." << endl;
            cout << "You are eligible for vehicle booking!" << endl;

            int choice;
            cout << "\n===== SELECT VEHICLE =====" << endl;
            cout << "1. Car" << endl;
            cout << "2. Bike" << endl;
            cout << "3. Truck" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            string brand;
            int year;
            double price;
            cout << "\nEnter Vehicle Brand: ";
            cin.ignore();
            getline(cin, brand);
            cout << "Enter Vehicle Year: ";
            cin >> year;
            cout << "Enter Vehicle Price: ";
            cin >> price;

            Vehicle *vehicle = nullptr;
            if (choice == 1)
            {
                int seatingCapacity;
                cout << "Enter Seating Capacity: ";
                cin >> seatingCapacity;
                vehicle = new Car(brand, year, price, seatingCapacity);
            }
            else if (choice == 2)
            {
                int engineCC;
                cout << "Enter Engine Capacity (CC): ";
                cin >> engineCC;
                vehicle = new Bike(brand, year, price, engineCC);
            }
            else if (choice == 3)
            {
                double payloadCapacity;
                cout << "Enter Payload Capacity (tons): ";
                cin >> payloadCapacity;
                vehicle = new Truck(brand, year, price, payloadCapacity);
            }
            else
            {
                cout << "\nInvalid Vehicle Choice!" << endl;
                return 0;
            }

            cout << "\n================================" << endl;
            cout << "       BOOKING CONFIRMED!" << endl;
            cout << "================================" << endl;
            customer.displayCustomerInfo();
            cout << "\n===== BOOKED VEHICLE =====" << endl;
            vehicle->displayInfo();
            cout << "\nThank you for booking!" << endl;
            delete vehicle;
        }
        else
        {
            cout << "\n================================" << endl;
            cout << "     BOOKING NOT ALLOWED!" << endl;
            cout << "================================" << endl;
            cout << "Valid Driving License is required." << endl;
        }
    }
    else
    {
        cout << "\n================================" << endl;
        cout << "     BOOKING NOT ALLOWED!" << endl;
        cout << "================================" << endl;
        cout << "Customer must be 18 years or older." << endl;
    }
    return 0;
}
