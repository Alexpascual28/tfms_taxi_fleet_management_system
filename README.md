<p align="center">
  <img src="https://www.svgrepo.com/show/397430/car.svg" width="100" alt="project-logo">
</p>
<p align="center">
    <h1 align="center">Taxi Fleet Management System</h1>
</p>
<p align="center">
    <em><code>This project implements a Taxi Fleet Management System in C++</code></em>
</p>

<br><!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary><br>

- [ Overview](#overview)

</details>
<hr>

##  Project: Taxi Fleet Management System
This project implements a Taxi Fleet Management System in C++, simulating real-time taxi dispatching in a city. The system tracks taxis' locations, assigns the nearest available taxi to a customer request, and updates the state of taxis as they complete rides.

Features
Taxi Management:

Manage a fleet of taxis with unique taxi_id and track their locations using x and y coordinates on a 2D grid.
Mark taxis as available or unavailable based on whether they are on a ride or idle.
Customer Requests:

Customers can request taxis, and the system assigns the closest available taxi using Manhattan distance.
If no taxis are available, the system returns an appropriate message.
Dynamic Updates:

Taxis update their location after completing rides, and they become available for new requests.
Optional Features:

Track average wait times for customer requests.
Allow cancellation of a taxi request before a taxi is dispatched.
Prioritize taxis that have been idle the longest in case of ties when assigning the closest taxi.
Project Structure
Taxi: A struct that holds information about each taxi (taxi_id, current_location, available).
TaxiFleetManagement: A class that manages the entire fleet of taxis, handles customer requests, updates taxi locations, and performs optional features like cancellation and average wait time calculation.
Requirements
Compiler: This project is written in C++20 and should be compiled using GCC 13.2.0 or later with the following flag:
bash
Copy code
g++ -std=c++20 taxi_fleet_management.cpp -o fleet_manager
Function Signatures
TaxiFleetManagement(int num_taxis): Initializes the fleet with a specified number of taxis at random locations.

int requestTaxi(int customer_x, int customer_y):

Handles customer requests by assigning the closest available taxi.
Returns the taxi_id of the assigned taxi, or -1 if no taxis are available.
void updateTaxiLocation(int taxi_id, int new_x, int new_y):

Updates the taxi's location after completing a ride and makes it available for the next request.
Optional:

bool cancelRequest(int customer_x, int customer_y): Allows the customer to cancel a taxi request.
double getAverageWaitTime() const: Returns the average wait time for customers across all requests.
Usage Instructions
Clone the Repository:

bash
Copy code
git clone <repository_url>
cd taxi-fleet-management
Build the Program: Make sure you have GCC 13.2.0 or higher installed and compile the code:

bash
Copy code
g++ -std=c++20 taxi_fleet_management.cpp -o fleet_manager
Run the Program: You can run the program and simulate a fleet of taxis:

bash
Copy code
./fleet_manager
Testing: The main() function includes test cases that demonstrate basic functionality, including:

Taxi requests.
Updating taxi locations.
Handling of unavailable taxis. Modify the main() function to add your own test cases as necessary.
Example Scenario
cpp
Copy code
TaxiFleetManagement fleet(5);       // Create a fleet with 5 taxis
fleet.requestTaxi(2, 3);            // Request a taxi at location (2, 3)
fleet.requestTaxi(5, 6);            // Request a taxi at location (5, 6)
fleet.updateTaxiLocation(1, 7, 8);  // Taxi 1 finishes a ride and updates location
fleet.requestTaxi(4, 5);            // Request a taxi at location (4, 5)
Output:

css
Copy code
Taxi 1 assigned to customer at (2, 3)
Taxi 2 assigned to customer at (5, 6)
Taxi 1 has been updated to location (7, 8)
Taxi 1 assigned to customer at (4, 5)
Performance Considerations
The system is optimized for handling thousands of taxis and customer requests.
Ensure that your data structures are efficient for querying and updating taxi states, particularly when scaling to larger fleets.
Edge Cases Handled
No available taxis when a request is made.
Multiple customer requests in quick succession.
All taxis being in use.
Handling of large fleets and customer coordinate ranges.
Future Improvements
Implement a load-balancing system to distribute requests evenly across taxis.
Add support for concurrent requests and taxi updates using multithreading.
Expand on taxi prioritization for long-idle taxis and optimize cancellation handling.
License
This project is open-source and available under the MIT License.

Contact
For any questions or issues, please open an issue on the repository or contact the project maintainer.

