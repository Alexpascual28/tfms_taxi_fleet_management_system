#include "taxi_fleet_management.h"
#include <iostream>

int main() {
    TaxiFleetManagement fleet(5);  // Create a fleet with 5 taxis
    
    int taxi_id1 = fleet.requestTaxi(2, 3);
    if (taxi_id1 != -1) {
        std::cout << "Taxi " << taxi_id1 << " assigned to customer at (2, 3)" << std::endl;
    } else {
        std::cout << "No available taxis" << std::endl;
    }
    
    int taxi_id2 = fleet.requestTaxi(4, 5);
    if (taxi_id2 != -1) {
        std::cout << "Taxi " << taxi_id2 << " assigned to customer at (4, 5)" << std::endl;
    } else {
        std::cout << "No available taxis" << std::endl;
    }

    fleet.updateTaxiLocation(taxi_id1, 7, 8);  // Taxi completes ride and updates location
    fleet.updateTaxiLocation(taxi_id2, 11, 14);  // Taxi completes ride and updates location

    return 0;
}
