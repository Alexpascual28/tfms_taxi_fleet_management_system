CXX = g++
CXXFLAGS = -std=c++20 -Wall
SRC_DIR = src
INCLUDE_DIR = include
OBJ = taxi.o taxi_fleet_management.o main.o
TARGET = fleet_manager

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(OBJ) -o $(TARGET)

taxi.o: $(SRC_DIR)/taxi.cpp $(INCLUDE_DIR)/taxi.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/taxi.cpp -I$(INCLUDE_DIR)

taxi_fleet_management.o: $(SRC_DIR)/taxi_fleet_management.cpp $(INCLUDE_DIR)/taxi_fleet_management.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/taxi_fleet_management.cpp -I$(INCLUDE_DIR)

main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/taxi_fleet_management.h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR)

clean:
	del *.o
	del $(TARGET).exe
