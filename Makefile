CXX = g++
CXXFLAGS = -std=c++20 -Wall

SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests

TAXIOBJ = taxi
FLEETOBJ = taxi_fleet_management
MAINOBJ = main

TEST1OBJ = requestTaxi
TEST2OBJ = updateTaxiLocation
TEST3OBJ = getAverageWaitTime
TEST4OBJ = cancelRequest

TARGET = fleet_manager
TEST1 = test-request
TEST2 = test-update
TEST3 = test-waittime
TEST4 = test-cancel

# Default and test compilations
all: $(TARGET) $(TEST1) $(TEST2) $(TEST3) $(TEST4)
main: $(TARGET)
tests: $(TEST1) $(TEST2) $(TEST3) $(TEST4)

# Executable file compilation
$(TARGET): $(TAXIOBJ).o $(FLEETOBJ).o $(MAINOBJ).o
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(TAXIOBJ).o $(FLEETOBJ).o $(MAINOBJ).o -o $(TARGET)

$(TEST1): $(TAXIOBJ).o $(FLEETOBJ).o $(TEST1OBJ).o
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(TAXIOBJ).o $(FLEETOBJ).o $(TEST1OBJ).o -o $(TEST1)

$(TEST2): $(TAXIOBJ).o $(FLEETOBJ).o $(TEST2OBJ).o
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(TAXIOBJ).o $(FLEETOBJ).o $(TEST2OBJ).o -o $(TEST2)

$(TEST3): $(TAXIOBJ).o $(FLEETOBJ).o $(TEST3OBJ).o
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(TAXIOBJ).o $(FLEETOBJ).o $(TEST3OBJ).o -o $(TEST3)

$(TEST4): $(TAXIOBJ).o $(FLEETOBJ).o $(TEST4OBJ).o
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(TAXIOBJ).o $(FLEETOBJ).o $(TEST4OBJ).o -o $(TEST4)

# Object file compilation
$(TAXIOBJ).o: $(SRC_DIR)/$(TAXIOBJ).cpp $(INCLUDE_DIR)/$(TAXIOBJ).h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/$(TAXIOBJ).cpp -I$(INCLUDE_DIR)

$(FLEETOBJ).o: $(SRC_DIR)/$(FLEETOBJ).cpp $(INCLUDE_DIR)/$(FLEETOBJ).h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/$(FLEETOBJ).cpp -I$(INCLUDE_DIR)

$(MAINOBJ).o: $(SRC_DIR)/$(MAINOBJ).cpp $(INCLUDE_DIR)/$(FLEETOBJ).h
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/$(MAINOBJ).cpp -I$(INCLUDE_DIR)

# Test object comp0liation
$(TEST1OBJ).o: $(TEST_DIR)/$(TEST1OBJ).cpp $(INCLUDE_DIR)/$(FLEETOBJ).h
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/$(TEST1OBJ).cpp -I$(INCLUDE_DIR)

$(TEST2OBJ).o: $(TEST_DIR)/$(TEST2OBJ).cpp $(INCLUDE_DIR)/$(FLEETOBJ).h
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/$(TEST2OBJ).cpp -I$(INCLUDE_DIR)

$(TEST3OBJ).o: $(TEST_DIR)/$(TEST3OBJ).cpp $(INCLUDE_DIR)/$(FLEETOBJ).h
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/$(TEST3OBJ).cpp -I$(INCLUDE_DIR)

$(TEST4OBJ).o: $(TEST_DIR)/$(TEST4OBJ).cpp $(INCLUDE_DIR)/$(FLEETOBJ).h
	$(CXX) $(CXXFLAGS) -c $(TEST_DIR)/$(TEST4OBJ).cpp -I$(INCLUDE_DIR)

# Clean up
clean:
	del *.o
	del *.exe

