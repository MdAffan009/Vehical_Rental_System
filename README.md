# 🚗 Vehicle Rental System
### A C++ Object-Oriented Programming Micro-Project

---

## 📌 About the Project

The **Vehicle Rental System** is a console-based C++ application that simulates the core operations of a vehicle rental business. It allows staff to manage vehicles, register customers, handle rentals and returns, and generate billing — all through a menu-driven interface. The project is built around the core principles of **Object-Oriented Programming (OOP)**, making it a practical, hands-on demonstration of how C++ is used in real-world software design.

---

## 🎯 Aims

- Design a clean, modular C++ system using OOP principles (encapsulation, inheritance, polymorphism, and abstraction).
- Manage a fleet of vehicles with details like type, model, and daily rate.
- Maintain customer records including name, contact, and license details.
- Handle the full rental lifecycle — booking, returning, and billing.
- Calculate rental costs based on vehicle type and duration.
- Track vehicle availability in real time (Available / Rented / Under Maintenance).
- Store and retrieve data using file handling for basic persistence.

---

## ✅ Features

| Feature | Description |
|---|---|
| **Vehicle Management** | Add, remove, update, and display vehicles |
| **Customer Management** | Register and view customer profiles |
| **Rent a Vehicle** | Book an available vehicle for a set number of days |
| **Return a Vehicle** | Return a vehicle and auto-update its status |
| **Cost Calculation** | Compute rental charges based on type and duration |
| **Payment & Billing** | Generate a simple bill/receipt on return |
| **Availability Tracking** | View which vehicles are available, rented, or in maintenance |
| **Rental History** | View past rentals for record-keeping |
| **Search & Filter** | Find vehicles by type, model, or availability |
| **File Storage** | Save and load data using `.txt` files |

---

## 🧱 OOP Concepts Used

| Concept | Where It Appears |
|---|---|
| **Encapsulation** | Private data members in all classes with public getters/setters |
| **Inheritance** | `Car`, `Truck`, and `Motorcycle` inherit from base `Vehicle` class |
| **Polymorphism** | `calculateCost()` overridden in each vehicle subclass |
| **Abstraction** | Abstract base class `Vehicle` with pure virtual functions |
| **Composition** | `Rental` class contains `Vehicle` and `Customer` objects |

---

## 👥 Team Division & Steps to Complete

The project is divided into **4 modules**, each assigned to a team member or pair. All modules should be built in parallel and integrated in the final step.

---

### 🔷 Module 1 — Vehicle & Class Hierarchy *(Member A)*

**Goal:** Build the core class structure for all vehicles.

**Tasks:**
1. Create an abstract base class `Vehicle` with:
   - Attributes: `vehicleID`, `brand`, `model`, `year`, `dailyRate`, `status` (Available / Rented / Maintenance)
   - Pure virtual method: `calculateCost(int days)`
   - Getters and setters for all attributes
2. Create derived classes: `Car`, `Truck`, `Motorcycle`
   - Each overrides `calculateCost()` with its own rate logic (e.g., trucks cost 1.5× base rate)
3. Write and test each class independently using a small `main()` test file

**Deliverable:** `vehicle.h`, `car.h`, `truck.h`, `motorcycle.h` + their `.cpp` files

---

### 🔷 Module 2 — Customer Management *(Member B)*

**Goal:** Handle all customer-related data and operations.

**Tasks:**
1. Create a `Customer` class with:
   - Attributes: `customerID`, `name`, `phone`, `email`, `licenseNumber`
   - Getters, setters, and a `displayInfo()` method
2. Create a `CustomerManager` class that supports:
   - `addCustomer()` — register a new customer
   - `removeCustomer(id)` — delete a customer record
   - `searchCustomer(id or name)` — find a customer
   - `displayAllCustomers()` — list all registered customers
3. Store the customer list in a `vector<Customer>`

**Deliverable:** `customer.h`, `customerManager.h` + their `.cpp` files

---

### 🔷 Module 3 — Rental, Return & Billing *(Member C)*

**Goal:** Manage the rental lifecycle and generate bills.

**Tasks:**
1. Create a `Rental` class with:
   - Attributes: `rentalID`, `customerID`, `vehicleID`, `startDate`, `numberOfDays`, `totalCost`, `isPaid`
   - Method: `generateBill()` — prints a formatted receipt
2. Create a `RentalManager` class that supports:
   - `rentVehicle(customerID, vehicleID, days)` — book a vehicle, change its status to "Rented"
   - `returnVehicle(rentalID)` — mark vehicle as "Available", calculate and display the bill
   - `viewRentalHistory()` — list all past and active rentals
3. Validate that a vehicle is available before booking

**Deliverable:** `rental.h`, `rentalManager.h` + their `.cpp` files

---

### 🔷 Module 4 — File Handling, Search & Main Menu *(Member D)*

**Goal:** Connect everything together with a menu, search system, and file storage.

**Tasks:**
1. Implement file handling using `fstream`:
   - Save and load `vehicles.txt` and `customers.txt` on startup/exit
   - Save rental records to `rentals.txt`
2. Implement search and filter functions:
   - Search vehicles by type, model, or availability status
   - Search customers by name or ID
3. Build the main console menu with options like:
   ```
   ===== Vehicle Rental System =====
   1. Manage Vehicles
   2. Manage Customers
   3. Rent a Vehicle
   4. Return a Vehicle
   5. View Rental History
   6. Search Vehicles
   7. Exit
   ```
4. Integrate all modules and test end-to-end scenarios

**Deliverable:** `fileHandler.h`, `search.h`, `main.cpp`

---

## 🔗 Integration & Testing (All Members Together)

Once individual modules are ready:

1. Merge all files into a single project folder
2. Resolve any naming conflicts or dependencies
3. Test the full flow: Add vehicle → Register customer → Rent → Return → View bill → Check history
4. Fix any bugs found during integration
5. Clean up the code and add comments

---

## 📁 Suggested Project Structure

```
VehicleRentalSystem/
│
├── main.cpp
├── vehicle.h / vehicle.cpp
├── car.h / car.cpp
├── truck.h / truck.cpp
├── motorcycle.h / motorcycle.cpp
├── customer.h / customer.cpp
├── customerManager.h / customerManager.cpp
├── rental.h / rental.cpp
├── rentalManager.h / rentalManager.cpp
├── fileHandler.h / fileHandler.cpp
├── search.h / search.cpp
│
└── data/
    ├── vehicles.txt
    ├── customers.txt
    └── rentals.txt
```

---

## 🛠️ Tools & Requirements

- **Language:** C++ (C++11 or later)
- **Compiler:** g++ / MinGW / MSVC
- **IDE:** VS Code, Code::Blocks, or Dev-C++
- **Libraries:** Standard C++ STL (`vector`, `fstream`, `string`, `iostream`)

---
