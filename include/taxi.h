#pragma once
#include <utility>

struct Taxi {
    int taxi_id;
    std::pair<int, int> current_location;
    bool available;

    Taxi(int id, int x, int y);
    void setLocation(int x, int y);
    void setAvailability(bool is_available);
};
