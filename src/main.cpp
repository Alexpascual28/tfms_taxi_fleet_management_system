#include "taxi_fleet_management.h"
#include <iostream>

enum State {
    START,
    CREATE_FLEET,
    REQUEST_TAXI,
    MAIN_MENU,
    CANCEL_TAXI,
    GET_WAIT_TIME,
    GET_AVERAGE_WAIT_TIME,
    DROP_OFF,
    END
};

int main() {
    State currentstate;

    currentstate = START;

    TaxiFleetManagement fleetManager; // Create an empty taxi fleet

    switch (currentstate)
    {
        case START:
            std::cout << "\n##### TAXI FLEET MANAGEMENT SYSTEM #####\n" << std::endl;
            std::cout << "Press any key to create a fleet of taxis...\n" << std::endl;
            std::cout << "Or press 'q' to quit the program: \n" << std::endl;

            char input;
            std::cin >> input;

            if (input == 'q' || input == 'Q') {
                currentstate = END;
            } else {
                currentstate = CREATE_FLEET;
            }

        case CREATE_FLEET:
            std::cout << "Enter the number of taxis in the fleet: " << std::endl;
            int num_taxis;
            std::cin >> num_taxis;

            fleetManager.createFleet(num_taxis);
            std::cout << "Fleet of " << num_taxis << " taxis created successfully!\n" << std::endl;

            std::cout << "Press 'R' to request a taxi for a customer..." << std::endl;
            std::cout << "Or press 'q' to quit the program: " << std::endl;

            // char input;
            std::cin >> input;

            if (input == 'R' || input == 'r') {
                currentstate = REQUEST_TAXI;
            } else {
                currentstate = END;
            }
        
        case REQUEST_TAXI:
            {
                std::cout << "Enter the x-coordinate of the customer's location: " << std::endl;
                int customer_x;
                std::cin >> customer_x;

                std::cout << "Enter the y-coordinate of the customer's location: " << std::endl;
                int customer_y;
                std::cin >> customer_y;

                int taxi_id = fleetManager.requestTaxi(customer_x, customer_y);

                if (taxi_id != -1) {
                    std::cout << "Taxi " << taxi_id << " assigned to customer at (" << customer_x << ", " << customer_y << ")\n" << std::endl;
                } else {
                    std::cout << "No available taxis found for the customer at (" << customer_x << ", " << customer_y << ")\n" << std::endl;
                }

                currentstate = MAIN_MENU;
            }

        case MAIN_MENU:
            {
                std::cout << "Press 'R' to request another taxi..." << std::endl;
                std::cout << "Press 'C' to cancel a taxi request..." << std::endl;
                std::cout << "Press 'W' to get the wait time for a taxi..." << std::endl;
                std::cout << "Press 'A' to get the average wait time for all taxis..." << std::endl;
                std::cout << "Press 'D' to drop off a customer..." << std::endl;
                std::cout << "Or press 'q' to quit the program: " << std::endl;
            
                char input;
                std::cin >> input;

                if (input == 'R' || input == 'r') {
                    currentstate = REQUEST_TAXI;
                } else if (input == 'C' || input == 'c') {
                    currentstate = CANCEL_TAXI;
                } else if (input == 'W' || input == 'w') {
                    currentstate = GET_WAIT_TIME;
                } else if (input == 'A' || input == 'a') {
                    currentstate = GET_AVERAGE_WAIT_TIME;
                } else if (input == 'D' || input == 'd') {
                    currentstate = DROP_OFF;
                } else {
                    currentstate = END;
                }
            }

        case CANCEL_TAXI:
            {
                std::cout << "Enter the x-coordinate of the customer's location to cancel the taxi request: " << std::endl;
                int cancel_x;
                std::cin >> cancel_x;

                std::cout << "Enter the y-coordinate of the customer's location to cancel the taxi request: " << std::endl;
                int cancel_y;
                std::cin >> cancel_y;

                bool is_cancelled = fleetManager.cancelRequest(cancel_x, cancel_y);

                if (is_cancelled) {
                    std::cout << "Taxi request cancelled successfully for customer at (" << cancel_x << ", " << cancel_y << ")\n" << std::endl;
                } else {
                    std::cout << "No taxi request found for the customer at (" << cancel_x << ", " << cancel_y << ")\n" << std::endl;
                }

                currentstate = MAIN_MENU;
            }

        case GET_WAIT_TIME:
            {
                std::cout << "Enter the taxi ID to get the wait time: " << std::endl;
                int taxi_id;
                std::cin >> taxi_id;

                double wait_time = fleetManager.getTaxiWaitTime(taxi_id);

                if (wait_time >= 0) {
                    std::cout << "Wait time for taxi " << taxi_id << ": " << wait_time << " minutes\n" << std::endl;
                } else {
                    std::cout << "Invalid taxi ID entered\n" << std::endl;
                }

                currentstate = MAIN_MENU;
            }

        case GET_AVERAGE_WAIT_TIME:
            {
                std::cout << "Average wait time for all taxis: " << fleetManager.getAverageWaitTime() << " minutes\n" << std::endl;

                currentstate = MAIN_MENU;
            }

        case DROP_OFF:
            {
                std::cout << "Enter the taxi ID to drop off the customer: " << std::endl;
                int dropoff_id;
                std::cin >> dropoff_id;

                std::cout << "Enter the x-coordinate of the drop-off location: " << std::endl;
                int dropoff_x;
                std::cin >> dropoff_x;

                std::cout << "Enter the y-coordinate of the drop-off location: " << std::endl;
                int dropoff_y;
                std::cin >> dropoff_y;

                fleetManager.updateTaxiLocation(dropoff_id, dropoff_x, dropoff_y);

                std::cout << "Customer in taxi " << dropoff_id << " dropped off successfully at (" << dropoff_x << ", " << dropoff_y << ")\n" << std::endl;

                currentstate = MAIN_MENU;
            }

        case END:
            {
                std::cout << "Exiting the program...\n" << std::endl;
                break;
            }

        default:
            break;
    }
}
