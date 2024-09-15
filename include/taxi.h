#pragma once
#include <utility>

struct Taxi {
    int taxi_id;
    std::pair<int, int> current_location;
    std::pair<int, int> customer_location;
    int distanceToCustomer;
    bool available;
    float speed;

    Taxi(int id, int x, int y);
    void setLocation(int x, int y);
    void setAvailability(bool is_available);
    void setSpeed(float s);
    void setDistanceToCustomer(int distance);

    void assignCustomer(int customer_x, int customer_y);
    void unassignCustomer();
};
