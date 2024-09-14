#pragma once
#include "taxi.h"
#include <vector>

class TaxiFleetManagement {
public:
    TaxiFleetManagement(int num_taxis);

    int requestTaxi(int customer_x, int customer_y);
    void updateTaxiLocation(int taxi_id, int new_x, int new_y);
    
    // Optional features
    bool cancelRequest(int customer_x, int customer_y);
    double getAverageWaitTime() const;

private:
    std::vector<Taxi> fleet;
};
