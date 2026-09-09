# 🚗 Vehicle Rental System

### A C++ Object-Oriented Programming Micro-Project

---

## 📌 About the Project

The **Vehicle Rental System** is a console-based C++ application that simulates the core operations of a vehicle rental business. It allows staff to manage vehicles, register customers, handle rentals and returns, and generate billing — all through a menu-driven interface. The project is built around the core principles of **Object-Oriented Programming (OOP)**, making it a practical, hands-on demonstration of how C++ is used in real-world software design.

> All data is stored in-memory during the program's runtime using STL containers. No external database or file storage is required.

---

## 🎯 Aims

- Design a clean, modular C++ system using OOP principles (encapsulation, inheritance, polymorphism, and abstraction).
- Manage a fleet of vehicles with details like type, model, and daily rate.
- Maintain customer records including name, contact, and license details.
- Handle the full rental lifecycle — booking, returning, and billing.
- Calculate rental costs based on vehicle type and duration.
- Track vehicle availability in real time (Available / Rented / Under Maintenance).

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

---

## 🧱 OOP Concepts Used

| Concept | Where It Appears |
|---|---|
| **Encapsulation** | Private data members in all classes with public getters/setters |
| **Inheritance** | `Car`, `Truck`, and `Motorcycle` inherit from the base `Vehicle` class |
| **Polymorphism** | `calculateCost()` is overridden in each vehicle subclass |
| **Abstraction** | Abstract base class `Vehicle` with pure virtual functions |
| **Composition** | `Rental` class contains `Vehicle` and `Customer` objects |

---

## 👥 Team Division & Steps to Complete

The project is split into **4 modules + integration**. Module 1 must be completed first since the other modules depend on it. Modules 2 and 3 can then be built in parallel. Module 4 should be started after the core modules are mostly complete.

---

### 🔷 Module 1 — Vehicle & Class Hierarchy *(Member A)*

> ⚠️ Start here first. All other modules depend on this one.

**Estimated Lines:** ~150–200

**Tasks:**

1. Create an abstract base class `Vehicle` with:
   - Attributes: `vehicleID`, `brand`, `model`, `year`, `dailyRate`, `status`
   - Status options: `Available`, `Rented`, `Maintenance`
   - Pure virtual method: `calculateCost(int days)`
   - Getters and setters for all attributes
   - `displayInfo()` method to print vehicle details

2. Create derived classes: `Car`, `Truck`, `Motorcycle`
   - Each overrides `calculateCost()` with its own logic
   - Example: Trucks charge 1.5× the base daily rate, while Motorcycles charge 0.8×

3. Test each class with a small standalone `main()` before handing off.

**Deliverable:** `vehicle.h`, `car.h`, `truck.h`, `motorcycle.h` + their `.cpp` files

---

### 🔷 Module 2 — Customer Management *(Member B)*

> Can be started once Module 1's `vehicle.h` is ready.

**Estimated Lines:** ~120–160

**Tasks:**

1. Create a `Customer` class with:
   - Attributes: `customerID`, `name`, `phone`, `email`, `licenseNumber`
   - Getters, setters, and a `displayInfo()` method

2. Create a `CustomerManager` class with a `vector<Customer>` internally, supporting:
   - `addCustomer()` — register a new customer
   - `removeCustomer(id)` — delete by ID
   - `searchCustomer(id)` — find and return a customer
   - `displayAllCustomers()` — list everyone

**Deliverable:** `customer.h`, `customerManager.h` + their `.cpp` files

---

### 🔷 Module 3 — Rental, Return & Billing *(Member C)*

> Can be started once Module 1's `vehicle.h` is ready.

**Estimated Lines:** ~200–250

**Tasks:**

1. Create a `Rental` class with:
   - Attributes: `rentalID`, `customerID`, `vehicleID`, `numberOfDays`, `totalCost`, `isReturned`
   - Method: `generateBill()` — prints a formatted receipt to the console

2. Create a `RentalManager` class with a `vector<Rental>` internally, supporting:
   - `rentVehicle(customerID, vehicleID, days)` — book a vehicle and set its status to `Rented`
   - `returnVehicle(rentalID)` — mark the vehicle as `Available`, calculate and display the bill
   - `viewRentalHistory()` — list all active and past rentals

3. Add validation:
   - Check that the vehicle exists.
   - Check that the vehicle status is `Available` before allowing a booking.
   - Validate that the rental duration is greater than zero.

**Deliverable:** `rental.h`, `rentalManager.h` + their `.cpp` files

---

### 🔷 Module 4 — Search, Filter & Main Menu *(Member D)*

> Start after Modules 1, 2, and 3 are mostly done.

**Estimated Lines:** ~150–180

**Tasks:**

1. Implement search and filter functions:
   - Search vehicles by type (`Car`, `Truck`, `Motorcycle`)
   - Filter vehicles by availability status
   - Search customers by name or ID

2. Build the main console menu loop:

```text
===== Vehicle Rental System =====

1. Manage Vehicles
2. Manage Customers
3. Rent a Vehicle
4. Return a Vehicle
5. View Rental History
6. Search Vehicles
7. Exit
```

3. Wire up all managers (`CustomerManager`, `RentalManager`, and vehicle lists) inside `main.cpp`.

4. Handle invalid inputs gracefully, including:
   - Wrong vehicle ID
   - Wrong customer ID
   - Unavailable vehicle
   - Invalid rental duration
   - Invalid menu choice

**Deliverable:** `search.h`, `search.cpp`, `main.cpp`

---

## 🔗 Integration & Testing (All Members Together)

Once all modules are ready:

1. Merge all files into a single project folder.
2. Resolve any naming conflicts or include dependencies.
3. Test the full flow end-to-end:

   **Add a vehicle → Register a customer → Rent → Return → View bill → Check history**

4. Fix any bugs found during integration.
5. Add comments and clean up the code.
6. Verify that all modules compile successfully together.

---

## 📁 Suggested Project Structure

```text
VehicleRentalSystem/
│
├── main.cpp
│
├── vehicle.h
├── vehicle.cpp
├── car.h
├── car.cpp
├── truck.h
├── truck.cpp
├── motorcycle.h
├── motorcycle.cpp
│
├── customer.h
├── customer.cpp
├── customerManager.h
├── customerManager.cpp
│
├── rental.h
├── rental.cpp
├── rentalManager.h
├── rentalManager.cpp
│
├── search.h
└── search.cpp
```

---

## 📊 Estimated Line Count

| Module | Owner | Estimated Lines |
|---|---|---:|
| Vehicle & Class Hierarchy | Member A | 150–200 |
| Customer Management | Member B | 120–160 |
| Rental, Return & Billing | Member C | 200–250 |
| Search, Filter & Main Menu | Member D | 150–180 |
| **Total** | | **~620–790 lines** |

---

## 🛠️ Tools & Requirements

- **Language:** C++ (C++11 or later)
- **Compiler:** g++ / MinGW / MSVC
- **IDE:** VS Code, Code::Blocks, or Dev-C++
- **Libraries:** Standard C++ STL only (`vector`, `string`, `iostream`)

---