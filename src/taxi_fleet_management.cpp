#include "taxi_fleet_management.h"
#include <cmath>
#include <algorithm>
#include <iostream>

TaxiFleetManagement::TaxiFleetManagement(int num_taxis) {
    for (int i = 0; i < num_taxis; ++i) {
        int x = rand() % 10;
        int y = rand() % 10;
        fleet.emplace_back(i, x, y); // Initialize with random locations

        std::cout << "Taxi " << i <<  " spawned at (" << x << "," << y << ")" << std::endl;
    }
}

int TaxiFleetManagement::requestTaxi(int customer_x, int customer_y) {
    int closest_taxi_id = -1;
    int min_distance = INT_MAX;

    for (auto &taxi : fleet) {
        if (taxi.available) {
            int distance = abs(taxi.current_location.first - customer_x) + abs(taxi.current_location.second - customer_y);
            if (distance < min_distance) {
                min_distance = distance;
                closest_taxi_id = taxi.taxi_id;
            }
        }
    }

    if (closest_taxi_id != -1) {
        fleet[closest_taxi_id].setAvailability(false); // Mark the taxi as unavailable
    }

    return closest_taxi_id;
}

void TaxiFleetManagement::updateTaxiLocation(int taxi_id, int new_x, int new_y) {
    fleet[taxi_id].setLocation(new_x, new_y);
    fleet[taxi_id].setAvailability(true);
}

// Optional: Implement cancelRequest() and getAverageWaitTime() here
