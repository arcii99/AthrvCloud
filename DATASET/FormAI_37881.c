//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FLOOR_COUNT 10 // Number of floors
#define ELEVATOR_COUNT 2 // Number of elevators
#define SIMULATION_TIME 10 // Duration of simulation in seconds
#define MAX_OCCUPANTS 10 // Maximum number of occupants in an elevator

// Structure to represent an elevator
struct Elevator {
    int id; // Elevator ID
    int currentFloor; // Current floor
    bool goingUp; // Direction of travel
    int occupants[MAX_OCCUPANTS]; // Array of occupant IDs
    int numOccupants; // Number of occupants in the elevator
} elevators[ELEVATOR_COUNT];

// Structure to represent a floor
struct Floor {
    int id; // Floor ID
    int numOccupants; // Number of occupants on the floor
} floors[FLOOR_COUNT];

// Function to randomly generate occupants on floors
void generateOccupants() {
    srand(time(NULL)); // Seed random number generator

    for(int i = 0; i < FLOOR_COUNT; i++) {
        int numOccupants = rand() % 10; // Generate a random number of occupants
        floors[i].numOccupants = numOccupants; // Set number of occupants on floor

        // Assign occupants to elevator if one arrives on the floor
        if(numOccupants > 0) {
            int elevatorID = rand() % ELEVATOR_COUNT; // Generate a random elevator ID
            elevators[elevatorID].numOccupants += numOccupants; // Add occupants to elevator
            for(int j = 0; j < numOccupants; j++) {
                elevators[elevatorID].occupants[j] = rand() % 1000; // Generate a random occupant ID
            }
        }
    }
}

// Function to move the elevator between floors
void moveElevator(struct Elevator *elevator) {
    if(elevator->goingUp) { // If elevator is going up
        elevator->currentFloor++; // Move elevator up one floor
        if(elevator->currentFloor == FLOOR_COUNT - 1) { // If elevator has reached the top floor
            elevator->goingUp = false; // Change direction of travel to down
        }
    } else { // If elevator is going down
        elevator->currentFloor--; // Move elevator down one floor
        if(elevator->currentFloor == 0) { // If elevator has reached the bottom floor
            elevator->goingUp = true; // Change direction of travel to up
        }
    }
}

int main() {
    // Initialize elevators
    for(int i = 0; i < ELEVATOR_COUNT; i++) {
        elevators[i].id = i;
        elevators[i].currentFloor = 0;
        elevators[i].goingUp = true;
        elevators[i].numOccupants = 0;
    }

    // Initialize floors
    for(int i = 0; i < FLOOR_COUNT; i++) {
        floors[i].id = i;
        floors[i].numOccupants = 0;
    }

    // Generate occupants on floors
    generateOccupants();

    // Run simulation for specified duration
    for(int t = 0; t < SIMULATION_TIME; t++) {
        printf("Time: %d seconds\n", t);

        // Move elevators between floors
        for(int i = 0; i < ELEVATOR_COUNT; i++) {
            moveElevator(&elevators[i]);
            printf("Elevator %d is at floor %d\n", elevators[i].id, elevators[i].currentFloor);
        }

        // Load and unload occupants from elevators
        for(int i = 0; i < FLOOR_COUNT; i++) {
            if(floors[i].numOccupants > 0) {
                for(int j = 0; j < ELEVATOR_COUNT; j++) {
                    if(elevators[j].currentFloor == i) {
                        printf("Elevator %d is loading %d occupants from floor %d\n", elevators[j].id, floors[i].numOccupants, i);
                        elevators[j].numOccupants += floors[i].numOccupants; // Add occupants to elevator
                        for(int k = 0; k < floors[i].numOccupants; k++) {
                            elevators[j].occupants[k + elevators[j].numOccupants - floors[i].numOccupants] = rand() % 1000; // Generate a random occupant ID
                        }
                        floors[i].numOccupants = 0; // Empty floor of occupants
                    }
                }
            }
        }

        // Unload occupants from elevators
        for(int i = 0; i < ELEVATOR_COUNT; i++) {
            for(int j = 0; j < elevators[i].numOccupants; j++) {
                if(rand() % 2 == 0) { // Randomly decide whether occupant leaves elevator on their destination floor
                    printf("Occupant %d has left elevator %d on floor %d\n", elevators[i].occupants[j], elevators[i].id, elevators[i].currentFloor);
                    elevators[i].occupants[j] = -1; // Remove occupant from elevator
                }
            }

            // Remove occupants who left the elevator
            int numRemoved = 0;
            for(int j = 0; j < elevators[i].numOccupants; j++) {
                if(elevators[i].occupants[j] == -1) { // If occupant has left the elevator
                    numRemoved++;
                } else { // If occupant is still in the elevator
                    elevators[i].occupants[j - numRemoved] = elevators[i].occupants[j]; // Shift occupants left to fill empty slots
                }
            }
            elevators[i].numOccupants -= numRemoved; // Update number of occupants in the elevator
        }

        printf("\n");
        sleep(1);
    }

    return 0;
}