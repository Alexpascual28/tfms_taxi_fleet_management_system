#include "taxi.h"
#include <cmath>

/**
 * @brief Construct a new Taxi:: Taxi object
 * 
 * @param id 
 * @param x 
 * @param y 
 */
Taxi::Taxi(int id, int x, int y) : taxi_id(id), current_location(std::make_pair(x, y)), available(true) {
    speed = 1.0; // Set speed of all taxis to 1.0 by default
}

/**
 * @brief set the location of the taxi
 * 
 * @param x x coordinate
 * @param y y coordinate
 */
void Taxi::setLocation(int x, int y) {
    current_location = std::make_pair(x, y);
}

/**
 * @brief set if the taxi is available or not
 * 
 * @param is_available availability state of the taxi
 */
void Taxi::setAvailability(bool is_available) {
    available = is_available;
}

/**
 * @brief sets the speed of the taxi
 * 
 * @param s speed of the taxi
 */
void Taxi::setSpeed(float s) {
    speed = s;
}

/**
 * @brief sets distance to the customer
 * 
 * @param distance calculated distance to the customer
 */
void Taxi::setDistanceToCustomer(int distance) {
    distanceToCustomer = distance;
}

/**
 * @brief assigns the customer to the taxi by setting the distance to the customer and making the taxi unavailable
 * 
 * @param distance distance to the customer
 */
void Taxi::assignCustomer(int customer_x, int customer_y) {
    customer_location = std::make_pair(customer_x, customer_y);
    available = false;
    distanceToCustomer = abs(current_location.first - customer_x) + abs(current_location.second - customer_y); // Calculate Manhattan distance
}

/**
 * @brief unassigns the customer from the taxi
 * 
 */
void Taxi::unassignCustomer() {
    available = true;
    distanceToCustomer = 0;
    customer_location = std::make_pair(0, 0);
}
