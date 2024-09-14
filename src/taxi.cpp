#include "taxi.h"

Taxi::Taxi(int id, int x, int y) : taxi_id(id), current_location(std::make_pair(x, y)), available(true) {}

void Taxi::setLocation(int x, int y) {
    current_location = std::make_pair(x, y);
}

void Taxi::setAvailability(bool is_available) {
    available = is_available;
}
