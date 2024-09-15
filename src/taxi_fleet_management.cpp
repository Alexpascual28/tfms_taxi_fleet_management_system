#include "taxi_fleet_management.h"
#include <cmath>
#include <algorithm>
#include <iostream>

/**
 * @brief Constructor to initialize the taxi fleet with the specified number of taxis.
 * 
 * @param num_taxis The number of taxis in the fleet.
 */
TaxiFleetManagement::TaxiFleetManagement(int num_taxis) {
    for (int i = 0; i < num_taxis; ++i) {
        int x = rand() % 10; // Random x-coordinate between 0 and 9
        int y = rand() % 10; // Random y-coordinate between 0 and 9
        fleet.emplace_back(i, x, y); // Initialize with random locations

        // std::cout << "Taxi " << i <<  " spawned at (" << x << "," << y << ")" << std::endl;
    }
}

/**
 * @brief Empty constructor to initialize the taxi fleet with no taxis.
 */
TaxiFleetManagement::TaxiFleetManagement() { }

/**
 * @brief Creates a fleet of taxis with the specified number of taxis.
 * 
 * @param num_taxis The number of taxis in the fleet.
 */
void TaxiFleetManagement::createFleet(int num_taxis) {
    for (int i = 0; i < num_taxis; ++i) {
        int x = rand() % 10; // Random x-coordinate between 0 and 9
        int y = rand() % 10; // Random y-coordinate between 0 and 9
        fleet.emplace_back(i, x, y); // Initialize with random locations

        // std::cout << "Taxi " << i <<  " spawned at (" << x << "," << y << ")" << std::endl;
    }
}

/**
 * @brief Requests a taxi for a customer at the specified coordinates.
 * 
 * @param customer_x The x-coordinate of the customer's location.
 * @param customer_y The y-coordinate of the customer's location.
 * @return The ID of the closest available taxi to the customer, or -1 if no available taxi is found.
 */
int TaxiFleetManagement::requestTaxi(int customer_x, int customer_y) {
    int closest_taxi_id = -1;
    int min_distance = INT_MAX;

    for (auto &taxi : fleet) {
        if (taxi.available) {
            // Calculate closest taxi by iterating through all taxis in fleet and updated minimum distance from the customer
            int distance = abs(taxi.current_location.first - customer_x) + abs(taxi.current_location.second - customer_y); // Calculate Manhattan distance
            
            // If the distance is less than the minimum distance, update the minimum distance and closest taxi ID
            if (distance < min_distance) {
                min_distance = distance; // Update minimum distance
                closest_taxi_id = taxi.taxi_id; // Update closest taxi ID
            }
        }
    }

    // Assign the closest taxi to the customer
    if (closest_taxi_id != -1) {
        fleet[closest_taxi_id].assignCustomer(customer_x, customer_y); // Assigns closest taxi to the customer
        fleet[closest_taxi_id].setDistanceToCustomer(min_distance); // Set distance to customer for the taxi
    }

    return closest_taxi_id;
}

/**
 * @brief updates the location of the taxi with the new coordinates, after dropping off the customer.
 * 
 * @param taxi_id id of the taxi
 * @param new_x dropped off location x
 * @param new_y dropped off location y
 */
void TaxiFleetManagement::updateTaxiLocation(int taxi_id, int new_x, int new_y) {
    fleet[taxi_id].setLocation(new_x, new_y);
    fleet[taxi_id].setAvailability(true);
    fleet[taxi_id].setDistanceToCustomer(0);
    fleet[taxi_id].assignCustomer(0, 0);
}


bool TaxiFleetManagement::cancelRequest(int customer_x, int customer_y){
    for(auto &taxi : fleet){
        if(taxi.customer_location.first == customer_x && taxi.customer_location.second == customer_y){
            taxi.unassignCustomer();
            return true;
        }
    }
    return false;
}

double TaxiFleetManagement::getTaxiWaitTime(int taxi_id) {
    if (taxi_id < 0 || taxi_id >= int(fleet.size())) {
        throw std::invalid_argument("Invalid taxi ID, taxi_id must be between 0 and " + std::to_string(fleet.size() - 1));
        return -1; // Invalid taxi ID
    }

    else if (fleet[taxi_id].available) {
        std::cout << "Taxi " << taxi_id << " is unassigned to a customer, wait time is 0" << std::endl;
        return 0; // Taxi is available, so no wait time
    }

    else {
        // Calculate wait time based on distance from customer and speed of the taxi
        double wait_time = fleet[taxi_id].distanceToCustomer / fleet[taxi_id].speed;
        return wait_time;
    }
}

/**
 * @brief calculates the average wait time of all the taxis that are currently assigned to customers.
 * 
 * @return double with the average wait time of the taxi fleet
 */
double TaxiFleetManagement::getAverageWaitTime() const {
    double total_wait_time = 0;
    int num_assigned_taxis = 0;

    for (const auto &taxi : fleet) {
        if (!taxi.available) {
            total_wait_time += taxi.distanceToCustomer / taxi.speed;
            num_assigned_taxis++;
        }
    }

    if (num_assigned_taxis == 0) {
        std::cout << "No taxis are currently assigned to customers" << std::endl;
        return 0;
    }

    double average_wait_time = total_wait_time / num_assigned_taxis;
    return average_wait_time;
}

/**
 * @brief Getter method that returns the fleet of taxis
 * 
 * @return std::vector<Taxi> the fleet of taxis
 */
std::vector<Taxi> TaxiFleetManagement::getFleet() const {
    return fleet;
}

/**
 * @brief Setter method that sets the fleet of taxis
 * 
 * @param new_fleet the new fleet of taxis
 */
void TaxiFleetManagement::setFleet(std::vector<Taxi> new_fleet) {
    fleet = new_fleet;
}
