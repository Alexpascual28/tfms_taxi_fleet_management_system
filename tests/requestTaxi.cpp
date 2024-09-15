#include "taxi_fleet_management.h"
#include <iostream>
#include <vector>

void testRequestTaxi(int testNum, TaxiFleetManagement &fleet, int x, int y, int expectedId) {
    // Display information about the test
    std::cout << "Test " << testNum << ": Requesting taxi at location (" << x << ", " << y << ")" << std::endl;
    std::cout << "Expected taxi ID: " << expectedId << std::endl;

    int taxi_id = fleet.requestTaxi(x, y);
    std::cout << "Calculated taxi ID: " << taxi_id << std::endl;

    if (taxi_id == expectedId) {
        std::cout << "Test " << testNum << " passed\n" << std::endl;
    } else {
        std::cout << "Test " << testNum << " failed\n" << std::endl;
    }
}

int main() {
    TaxiFleetManagement fleetManager(5);  // Create a fleet with 5 taxis

    std::vector<Taxi> fleet = fleetManager.getFleet();

    fleet[0].setLocation(2, 3);
    fleet[1].setLocation(4, 5);
    fleet[2].setLocation(6, 7);
    fleet[3].setLocation(8, 9);
    fleet[4].setLocation(10, 11);

    fleetManager.setFleet(fleet);

    int test1ExpectedId = 0;
    int test2ExpectedId = 1;
    int test3ExpectedId = 2;
    int test4ExpectedId = 3;
    int test5ExpectedId = 4;

    testRequestTaxi(1, fleetManager, 2, 2, test1ExpectedId);
    testRequestTaxi(2, fleetManager, 4, 4, test2ExpectedId);
    testRequestTaxi(3, fleetManager, 6, 6, test3ExpectedId);
    testRequestTaxi(4, fleetManager, 8, 8, test4ExpectedId);
    testRequestTaxi(5, fleetManager, 10, 10, test5ExpectedId);
}
