# Taxi Fleet Management System

## Overview

The Taxi Fleet Management System is a C++ application designed to manage a fleet of taxis. It allows users to create a fleet, request taxis, update taxi locations, cancel requests, and get wait times. The system is built with modularity in mind, making it easy to extend and maintain.

## Features

- **Create Fleet**: Initialize a fleet of taxis.
- **Request Taxi**: Request a taxi for a customer at a specific location.
- **Update Taxi Location**: Update the location of a specific taxi.
- **Cancel Request**: Cancel a taxi request for a customer.
- **Get Wait Time**: Retrieve the wait time for a specific taxi.
- **Get Average Wait Time**: Calculate the average wait time for all taxis.

## Project Structure

```
.vscode/
    settings.json
    tasks.json
doc/
include/
    taxi_fleet_management.h
    taxi.h
Makefile
src/
    main.cpp
    taxi_fleet_management.cpp
    taxi.cpp
tests/
    cancelRequest.cpp
    getAverageWaitTime.cpp
    helloworld.cpp
    requestTaxi.cpp
    updateTaxiLocation.cpp
```

## Getting Started

### Prerequisites

- C++ compiler (e.g., [`g++`])
- Make

### Building the Project

To build the project, navigate to the root directory and run:

```sh
make
```

This will compile the main application and all test executables.

### Running the Application

To run the main application, execute:

```sh
./fleet_manager
```

### Running Tests

To run the tests, execute the corresponding test binaries:

```sh
./test-request
./test-update
./test-waittime
./test-cancel
```

## Code Overview

### Main Application

The main application logic is implemented in [`src/main.cpp`]. It handles user input and interacts with the [`TaxiFleetManagement`] class to perform various operations.

### Taxi Fleet Management

The core functionality is provided by the [`TaxiFleetManagement`] class, defined in [`include/taxi_fleet_management.h`] and implemented in [`src/taxi_fleet_management.cpp`]. This class manages the fleet of taxis and provides methods to request, update, and cancel taxi services.

### Tests

Unit tests are located in the [`tests`] directory. Each test file focuses on a specific functionality of the [`TaxiFleetManagement`] class.

- [`tests/requestTaxi.cpp`]
- [`tests/updateTaxiLocation.cpp`]
- [`tests/getAverageWaitTime.cpp`]
- [`tests/cancelRequest.cpp`]

---

This README provides a comprehensive overview of the Taxi Fleet Management System, including its features, project structure, and instructions for building and running the application.