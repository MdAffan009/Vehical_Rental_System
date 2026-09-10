CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.

TARGET = vehicle_rental

SOURCES = main_test3.cpp \
          Customer/Customer.cpp \
          Customer/CustomerManager.cpp \
          Customer/Rental.cpp \
          Customer/RentalManager.cpp \
          Vehicals/Vehicle.cpp \
          Vehicals/Car.cpp \
          Vehicals/Motorcycle.cpp \
          Vehicals/Truck.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run