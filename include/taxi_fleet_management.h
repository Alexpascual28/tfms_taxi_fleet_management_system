#pragma once
#include "taxi.h"
#include <vector>

class TaxiFleetManagement {
public:
    TaxiFleetManagement(int num_taxis);
    TaxiFleetManagement();

    void createFleet(int num_taxis);

    int requestTaxi(int customer_x, int customer_y);
    void updateTaxiLocation(int taxi_id, int new_x, int new_y);
    
    // Optional features
    bool cancelRequest(int customer_x, int customer_y);
    double getTaxiWaitTime(int taxi_id);
    double getAverageWaitTime() const;

    std::vector<Taxi> getFleet() const;
    void setFleet(std::vector<Taxi> new_fleet);

private:
    std::vector<Taxi> fleet;
};
