// ============================================================================
// VEHICLE RENTAL SYSTEM — Complete Single-File Implementation
// ============================================================================
// This is a consolidated version of the entire Vehicle Rental System
// containing all 4 modules (Vehicle Hierarchy, Customer Management,
// Rental/Billing, and Main Menu) in a single .cpp file for easy documentation.
// ============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

// ============================================================================
// MODULE 1: VEHICLE HIERARCHY (Abstract Base Class + Subclasses)
// ============================================================================

// Abstract base class for all vehicles
class Vehicle
{
protected:
    string vehicleID;
    string brand;
    string model;
    int year;
    double dailyRate;
    string status; // "Available", "Rented", "Maintenance"

public:
    Vehicle(string id, string b, string m, int y, double rate, string st = "Available")
        : vehicleID(id), brand(b), model(m), year(y), dailyRate(rate), status(st) {}

    // Getters
    string getVehicleID() const { return vehicleID; }
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getDailyRate() const { return dailyRate; }
    string getStatus() const { return status; }

    // Setters
    void setStatus(string st) { status = st; }
    void setDailyRate(double rate) { dailyRate = rate; }

    // Pure virtual function — each subclass implements its own cost logic
    virtual double calculateCost(int days) const = 0;

    // Display vehicle info
    virtual void displayInfo() const
    {
        cout << "  Vehicle ID  : " << vehicleID << endl;
        cout << "  Brand       : " << brand << endl;
        cout << "  Model       : " << model << endl;
        cout << "  Year        : " << year << endl;
        cout << "  Daily Rate  : $" << dailyRate << "/day" << endl;
        cout << "  Status      : " << status << endl;
    }

    virtual ~Vehicle() {}
};

// Car subclass — charges standard rate (1.0x multiplier)
class Car : public Vehicle
{
private:
    int seatingCapacity;

public:
    Car(string id, string b, string m, int y, double rate, int cap, string st = "Available")
        : Vehicle(id, b, m, y, rate, st), seatingCapacity(cap) {}

    int getSeatingCapacity() const { return seatingCapacity; }

    double calculateCost(int days) const override
    {
        return dailyRate * 1.0 * days;
    }

    void displayInfo() const override
    {
        cout << "\n--- Car Details ---" << endl;
        Vehicle::displayInfo();
        cout << "  Seating Cap : " << seatingCapacity << " seats" << endl;
        cout << "  Type        : Car (1.0x rate)" << endl;
    }
};

// Motorcycle subclass — charges 0.8x multiplier (cheaper)
class Motorcycle : public Vehicle
{
private:
    int engineCC;

public:
    Motorcycle(string id, string b, string m, int y, double rate, int cc, string st = "Available")
        : Vehicle(id, b, m, y, rate, st), engineCC(cc) {}

    int getEngineCC() const { return engineCC; }

    double calculateCost(int days) const override
    {
        return dailyRate * 0.8 * days;
    }

    void displayInfo() const override
    {
        cout << "\n--- Motorcycle Details ---" << endl;
        Vehicle::displayInfo();
        cout << "  Engine      : " << engineCC << " cc" << endl;
        cout << "  Type        : Motorcycle (0.8x rate)" << endl;
    }
};

// Truck subclass — charges 1.5x multiplier (more expensive)
class Truck : public Vehicle
{
private:
    double payloadCapacity;

public:
    Truck(string id, string b, string m, int y, double rate, double load, string st = "Available")
        : Vehicle(id, b, m, y, rate, st), payloadCapacity(load) {}

    double getPayloadCapacity() const { return payloadCapacity; }

    double calculateCost(int days) const override
    {
        return dailyRate * 1.5 * days;
    }

    void displayInfo() const override
    {
        cout << "\n--- Truck Details ---" << endl;
        Vehicle::displayInfo();
        cout << "  Payload     : " << payloadCapacity << " tons" << endl;
        cout << "  Type        : Truck (1.5x rate)" << endl;
    }
};

// ============================================================================
// MODULE 2: CUSTOMER MANAGEMENT
// ============================================================================

// Customer class — stores customer information
class Customer
{
private:
    string customerID;
    string name;
    int age;
    string phone;
    string email;
    string licenseNumber;

public:
    Customer(string id, string n, int a, string ph, string em, string lic)
        : customerID(id), name(n), age(a), phone(ph), email(em), licenseNumber(lic) {}

    // Getters
    string getCustomerID() const { return customerID; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getPhone() const { return phone; }
    string getEmail() const { return email; }
    string getLicenseNumber() const { return licenseNumber; }

    // Setters
    void setPhone(string ph) { phone = ph; }
    void setEmail(string em) { email = em; }
    void setLicenseNumber(string lic) { licenseNumber = lic; }

    void displayInfo() const
    {
        cout << "\n===== CUSTOMER DETAILS =====" << endl;
        cout << "  Customer ID : " << customerID << endl;
        cout << "  Name        : " << name << endl;
        cout << "  Age         : " << age << endl;
        cout << "  Phone       : " << phone << endl;
        cout << "  Email       : " << email << endl;
        cout << "  License No  : " << licenseNumber << endl;
    }
};

// CustomerManager — manages all registered customers
class CustomerManager
{
private:
    vector<Customer> customers;

public:
    void addCustomer(const Customer &c)
    {
        customers.push_back(c);
        cout << "Customer \"" << c.getName() << "\" registered successfully." << endl;
    }

    bool removeCustomer(const string &customerID)
    {
        for (auto it = customers.begin(); it != customers.end(); ++it)
        {
            if (it->getCustomerID() == customerID)
            {
                cout << "Customer \"" << it->getName() << "\" removed successfully." << endl;
                customers.erase(it);
                return true;
            }
        }
        cout << "Customer with ID \"" << customerID << "\" not found." << endl;
        return false;
    }

    Customer *searchCustomer(const string &customerID)
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

    bool searchCustomerByName(const string &name) const
    {
        string queryLower = name;
        transform(queryLower.begin(), queryLower.end(), queryLower.begin(), ::tolower);

        bool found = false;
        for (const auto &c : customers)
        {
            string nameLower = c.getName();
            transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);
            if (nameLower.find(queryLower) != string::npos)
            {
                c.displayInfo();
                found = true;
            }
        }
        return found;
    }

    void displayAllCustomers() const
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

    int getCustomerCount() const { return (int)customers.size(); }
};

// ============================================================================
// MODULE 3: RENTAL, RETURN & BILLING
// ============================================================================

// Rental class — represents a single rental transaction
class Rental
{
private:
    string rentalID;
    string customerID;
    string vehicleID;
    int numberOfDays;
    double totalCost;
    bool isReturned;

public:
    Rental(string rid, string cid, string vid, int days, double cost)
        : rentalID(rid), customerID(cid), vehicleID(vid),
          numberOfDays(days), totalCost(cost), isReturned(false) {}

    // Getters
    string getRentalID() const { return rentalID; }
    string getCustomerID() const { return customerID; }
    string getVehicleID() const { return vehicleID; }
    int getNumberOfDays() const { return numberOfDays; }
    double getTotalCost() const { return totalCost; }
    bool getIsReturned() const { return isReturned; }

    // Setters
    void setIsReturned(bool returned) { isReturned = returned; }
    void setTotalCost(double cost) { totalCost = cost; }

    void generateBill(const string &customerName,
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
        cout << "  Vehicle      : " << vehicleBrand << " " << vehicleModel << endl;
        cout << "  Rental Days  : " << numberOfDays << endl;
        cout << "--------------------------------------------" << endl;
        cout << fixed << setprecision(2);
        cout << "  TOTAL COST   : $" << totalCost << endl;
        cout << "  Status       : " << (isReturned ? "Returned" : "Active") << endl;
        cout << "============================================" << endl;
    }
};

// RentalManager — manages all rental transactions
class RentalManager
{
private:
    vector<Rental> rentals;
    int nextRentalID;

    string generateRentalID()
    {
        ostringstream oss;
        oss << "R" << setw(3) << setfill('0') << nextRentalID++;
        return oss.str();
    }

public:
    RentalManager() : nextRentalID(1) {}

    bool rentVehicle(const string &customerID, const string &vehicleID, int days,
                     vector<Vehicle *> &fleet, CustomerManager &cm)
    {

        if (days <= 0)
        {
            cout << "  [Error] Rental duration must be greater than zero." << endl;
            return false;
        }

        Customer *customer = cm.searchCustomer(customerID);
        if (!customer)
        {
            cout << "  [Error] Customer ID \"" << customerID << "\" not found." << endl;
            return false;
        }

        Vehicle *vehicle = nullptr;
        for (auto &v : fleet)
        {
            if (v->getVehicleID() == vehicleID)
            {
                vehicle = v;
                break;
            }
        }

        if (!vehicle)
        {
            cout << "  [Error] Vehicle ID \"" << vehicleID << "\" not found." << endl;
            return false;
        }

        if (vehicle->getStatus() != "Available")
        {
            cout << "  [Error] Vehicle \"" << vehicle->getBrand() << " "
                 << vehicle->getModel() << "\" is currently " << vehicle->getStatus()
                 << " and cannot be rented." << endl;
            return false;
        }

        double cost = vehicle->calculateCost(days);
        string rid = generateRentalID();

        rentals.push_back(Rental(rid, customerID, vehicleID, days, cost));
        vehicle->setStatus("Rented");

        cout << "\n  [Success] Rental confirmed!" << endl;
        cout << "  Rental ID   : " << rid << endl;
        cout << "  Customer    : " << customer->getName() << endl;
        cout << "  Vehicle     : " << vehicle->getBrand() << " " << vehicle->getModel() << endl;
        cout << "  Days        : " << days << endl;
        cout << fixed << setprecision(2);
        cout << "  Total Cost  : $" << cost << endl;

        return true;
    }

    bool returnVehicle(const string &rentalID, vector<Vehicle *> &fleet, CustomerManager &cm)
    {

        Rental *rental = nullptr;
        for (auto &r : rentals)
        {
            if (r.getRentalID() == rentalID)
            {
                rental = &r;
                break;
            }
        }

        if (!rental)
        {
            cout << "  [Error] Rental ID \"" << rentalID << "\" not found." << endl;
            return false;
        }

        if (rental->getIsReturned())
        {
            cout << "  [Error] Rental \"" << rentalID << "\" has already been returned." << endl;
            return false;
        }

        Vehicle *vehicle = nullptr;
        for (auto &v : fleet)
        {
            if (v->getVehicleID() == rental->getVehicleID())
            {
                vehicle = v;
                break;
            }
        }

        Customer *customer = cm.searchCustomer(rental->getCustomerID());

        rental->setIsReturned(true);
        if (vehicle)
        {
            vehicle->setStatus("Available");
        }

        string customerName = customer ? customer->getName() : "Unknown";
        string vehicleBrand = vehicle ? vehicle->getBrand() : "Unknown";
        string vehicleModel = vehicle ? vehicle->getModel() : "Unknown";

        rental->generateBill(customerName, vehicleBrand, vehicleModel);

        return true;
    }

    void viewRentalHistory() const
    {
        if (rentals.empty())
        {
            cout << "\n  No rentals on record yet." << endl;
            return;
        }

        cout << "\n========== RENTAL HISTORY ==========" << endl;
        for (const auto &r : rentals)
        {
            cout << "\n  Rental ID  : " << r.getRentalID() << endl;
            cout << "  Customer ID: " << r.getCustomerID() << endl;
            cout << "  Vehicle ID : " << r.getVehicleID() << endl;
            cout << "  Days       : " << r.getNumberOfDays() << endl;
            cout << fixed << setprecision(2);
            cout << "  Total Cost : $" << r.getTotalCost() << endl;
            cout << "  Status     : " << (r.getIsReturned() ? "Returned" : "Active") << endl;
        }
        cout << "\n====================================" << endl;
    }

    void viewRentalsByCustomer(const string &customerID, const vector<Vehicle *> &fleet) const
    {
        vector<const Rental *> customerRentals;

        for (const auto &r : rentals)
        {
            if (r.getCustomerID() == customerID)
            {
                customerRentals.push_back(&r);
            }
        }

        if (customerRentals.empty())
        {
            cout << "\n  You have no rental history." << endl;
            return;
        }

        cout << "\n========== YOUR RENTAL HISTORY ==========" << endl;

        for (const auto &rental : customerRentals)
        {
            Vehicle *vehicle = nullptr;
            for (auto &v : fleet)
            {
                if (v->getVehicleID() == rental->getVehicleID())
                {
                    vehicle = v;
                    break;
                }
            }

            cout << "\n  Rental ID      : " << rental->getRentalID() << endl;
            cout << "  Vehicle        : ";
            if (vehicle)
            {
                cout << vehicle->getBrand() << " " << vehicle->getModel()
                     << " (" << vehicle->getYear() << ")" << endl;
            }
            else
            {
                cout << "Unknown Vehicle" << endl;
            }
            cout << "  Rental Period  : " << rental->getNumberOfDays() << " days" << endl;
            cout << fixed << setprecision(2);
            cout << "  Total Cost     : $" << rental->getTotalCost() << endl;
            cout << "  Status         : " << (rental->getIsReturned() ? "Returned" : "Currently Rented") << endl;
        }

        cout << "\n========================================" << endl;
    }
};

// ============================================================================
// MODULE 4: MAIN MENU & HELPER FUNCTIONS
// ============================================================================

// Helper — get vehicle type by checking dynamic type
static string getVehicleType(const Vehicle *v)
{
    if (dynamic_cast<const Car *>(v))
        return "Car";
    if (dynamic_cast<const Motorcycle *>(v))
        return "Motorcycle";
    if (dynamic_cast<const Truck *>(v))
        return "Truck";
    return "Unknown";
}

// Safe integer input
int getIntInput(const string &prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "  [Error] Please enter a valid number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Safe double input
double getDoubleInput(const string &prompt)
{
    double value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "  [Error] Please enter a valid number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Safe string input
string getStringInput(const string &prompt)
{
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

// Auto-generate customer IDs
static int customerCounter = 1;
string generateCustomerID()
{
    ostringstream oss;
    oss << "C" << setw(3) << setfill('0') << customerCounter++;
    return oss.str();
}

// Display available vehicles by type
void displayAvailableVehicles(const vector<Vehicle *> &fleet)
{
    cout << "\n===== AVAILABLE VEHICLES =====" << endl;

    if (fleet.empty())
    {
        cout << "  No vehicles available." << endl;
        return;
    }

    cout << "\n--- CARS ---" << endl;
    bool foundCar = false;
    for (size_t i = 0; i < fleet.size(); i++)
    {
        if (getVehicleType(fleet[i]) == "Car" && fleet[i]->getStatus() == "Available")
        {
            cout << "  [" << i + 1 << "] " << fleet[i]->getBrand() << " "
                 << fleet[i]->getModel() << " (" << fleet[i]->getYear() << ") - $"
                 << fixed << setprecision(2) << fleet[i]->getDailyRate() << "/day" << endl;
            foundCar = true;
        }
    }
    if (!foundCar)
        cout << "  No cars available." << endl;

    cout << "\n--- MOTORCYCLES ---" << endl;
    bool foundBike = false;
    for (size_t i = 0; i < fleet.size(); i++)
    {
        if (getVehicleType(fleet[i]) == "Motorcycle" && fleet[i]->getStatus() == "Available")
        {
            cout << "  [" << i + 1 << "] " << fleet[i]->getBrand() << " "
                 << fleet[i]->getModel() << " (" << fleet[i]->getYear() << ") - $"
                 << fixed << setprecision(2) << fleet[i]->getDailyRate() << "/day" << endl;
            foundBike = true;
        }
    }
    if (!foundBike)
        cout << "  No motorcycles available." << endl;

    cout << "\n--- TRUCKS ---" << endl;
    bool foundTruck = false;
    for (size_t i = 0; i < fleet.size(); i++)
    {
        if (getVehicleType(fleet[i]) == "Truck" && fleet[i]->getStatus() == "Available")
        {
            cout << "  [" << i + 1 << "] " << fleet[i]->getBrand() << " "
                 << fleet[i]->getModel() << " (" << fleet[i]->getYear() << ") - $"
                 << fixed << setprecision(2) << fleet[i]->getDailyRate() << "/day" << endl;
            foundTruck = true;
        }
    }
    if (!foundTruck)
        cout << "  No trucks available." << endl;

    cout << "\n==============================" << endl;
}

// Register customer
void menuRegisterCustomer(CustomerManager &cm)
{
    cout << "\n--- Customer Registration ---" << endl;

    string id = generateCustomerID();
    string name = getStringInput("  Full Name: ");
    int age = getIntInput("  Age: ");
    string phone = getStringInput("  Phone Number: ");
    string email = getStringInput("  Email Address: ");
    string license = getStringInput("  Driving License Number: ");

    if (age < 18)
    {
        cout << "\n  [Error] You must be 18 or older to rent a vehicle." << endl;
        return;
    }

    cm.addCustomer(Customer(id, name, age, phone, email, license));
    cout << "\n  [Success] Registration complete! Your Customer ID is: " << id << endl;
}

// Rent a vehicle
void menuRentVehicle(vector<Vehicle *> &fleet, CustomerManager &cm, RentalManager &rm)
{

    cout << "\n--- Rent a Vehicle ---" << endl;

    displayAvailableVehicles(fleet);

    string customerID = getStringInput("  Enter your Customer ID (e.g., C001): ");
    Customer *customer = cm.searchCustomer(customerID);
    if (!customer)
    {
        cout << "  [Error] Customer ID not found. Please register first." << endl;
        return;
    }

    cout << "  Hello, " << customer->getName() << "!" << endl;

    cout << "\n  Which vehicle type would you like?" << endl;
    cout << "    1. Car" << endl;
    cout << "    2. Motorcycle" << endl;
    cout << "    3. Truck" << endl;

    int typeChoice = getIntInput("  Enter choice: ");
    string selectedType;
    if (typeChoice == 1)
        selectedType = "Car";
    else if (typeChoice == 2)
        selectedType = "Motorcycle";
    else if (typeChoice == 3)
        selectedType = "Truck";
    else
    {
        cout << "  [Error] Invalid choice." << endl;
        return;
    }

    cout << "\n  Available " << selectedType << "s:" << endl;
    vector<Vehicle *> matchingVehicles;
    int counter = 1;

    for (auto v : fleet)
    {
        if (getVehicleType(v) == selectedType && v->getStatus() == "Available")
        {
            matchingVehicles.push_back(v);
            cout << "  [" << counter << "] " << v->getBrand() << " " << v->getModel()
                 << " (" << v->getYear() << ") - $" << fixed << setprecision(2)
                 << v->getDailyRate() << "/day" << endl;
            counter++;
        }
    }

    if (matchingVehicles.empty())
    {
        cout << "  [Error] No " << selectedType << "s available at the moment." << endl;
        return;
    }

    int vehicleChoice = getIntInput("  Choose vehicle [enter number]: ");
    if (vehicleChoice < 1 || vehicleChoice > (int)matchingVehicles.size())
    {
        cout << "  [Error] Invalid selection." << endl;
        return;
    }

    Vehicle *selectedVehicle = matchingVehicles[vehicleChoice - 1];

    int days = getIntInput("  How many days do you want to rent? ");

    rm.rentVehicle(customerID, selectedVehicle->getVehicleID(), days, fleet, cm);
}

// Return a vehicle
void menuReturnVehicle(vector<Vehicle *> &fleet, CustomerManager &cm, RentalManager &rm)
{

    cout << "\n--- Return a Vehicle ---" << endl;
    cout << "  Your active rentals:" << endl;

    rm.viewRentalHistory();

    string rentalID = getStringInput("  Enter your Rental ID (e.g., R001): ");
    rm.returnVehicle(rentalID, fleet, cm);
}

// View my rentals
void menuViewMyRentals(RentalManager &rm, CustomerManager &cm, const vector<Vehicle *> &fleet)
{

    cout << "\n--- My Rental History ---" << endl;

    string customerID = getStringInput("  Enter your Customer ID (e.g., C001): ");
    Customer *customer = cm.searchCustomer(customerID);

    if (!customer)
    {
        cout << "  [Error] Customer ID not found." << endl;
        return;
    }

    cout << "  Hello, " << customer->getName() << "!" << endl;

    rm.viewRentalsByCustomer(customerID, fleet);
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main()
{

    // Pre-populate fleet with sample vehicles
    vector<Vehicle *> fleet;
    fleet.push_back(new Car("V001", "Toyota", "Camry", 2022, 50.0, 5));
    fleet.push_back(new Car("V002", "Honda", "Accord", 2021, 48.0, 5));
    fleet.push_back(new Motorcycle("V003", "Harley", "Sportster", 2021, 40.0, 883));
    fleet.push_back(new Motorcycle("V004", "Yamaha", "MT-07", 2022, 35.0, 689));
    fleet.push_back(new Truck("V005", "Ford", "F-750", 2020, 80.0, 5.0));
    fleet.push_back(new Truck("V006", "Peterbilt", "579", 2021, 85.0, 6.5));

    CustomerManager cm;
    RentalManager rm;

    int choice;

    cout << "\n========================================" << endl;
    cout << "   WELCOME TO VEHICLE RENTAL SYSTEM     " << endl;
    cout << "========================================" << endl;

    do
    {
        cout << "\n========== MAIN MENU ==========" << endl;
        cout << "  1. Register" << endl;
        cout << "  2. Browse Available Vehicles" << endl;
        cout << "  3. Rent a Vehicle" << endl;
        cout << "  4. Return a Vehicle" << endl;
        cout << "  5. View My Rentals" << endl;
        cout << "  6. Exit" << endl;
        cout << "================================" << endl;

        choice = getIntInput("  Enter choice: ");

        switch (choice)
        {
        case 1:
            menuRegisterCustomer(cm);
            break;
        case 2:
            displayAvailableVehicles(fleet);
            break;
        case 3:
            menuRentVehicle(fleet, cm, rm);
            break;
        case 4:
            menuReturnVehicle(fleet, cm, rm);
            break;
        case 5:
            menuViewMyRentals(rm, cm, fleet);
            break;
        case 6:
            cout << "\n  Thank you for using Vehicle Rental System. Goodbye!" << endl;
            break;
        default:
            cout << "  [Error] Invalid choice. Please enter 1–6." << endl;
        }

    } while (choice != 6);

    // Cleanup
    for (auto v : fleet)
    {
        delete v;
    }

    return 0;
}
