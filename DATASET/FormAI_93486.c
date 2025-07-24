//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

#define TOTAL_FLOORS 10   // Total number of floors in the building

// Elevator struct to represent elevator
typedef struct Elevator {
    int current_floor;    // Current floor where elevator is
    int direction;        // Direction of where elevator is headed
    int min_floor;        // Minimum floor that elevator can reach
    int max_floor;        // Maximum floor that elevator can reach
    int capacity;         // Maximum capacity of elevator
    int current_capacity; // Current number of passengers in the elevator
    int is_moving;        // Check if elevator is moving
} Elevator;

// Passenger struct to represent passenger
typedef struct Passenger {
    int current_floor;  // Current floor where passenger is
    int destination;    // Destination floor of passenger
    int is_waiting;     // Check if passenger is waiting
    int is_inside;      // Check if passenger is inside the elevator
} Passenger;

// Function to move elevator to a certain floor
void moveElevator(Elevator *elevator, int floor) {
    elevator->is_moving = 1;
    printf("Elevator moving from floor %d to floor %d\n", elevator->current_floor, floor);
    elevator->current_floor = floor;
    elevator->is_moving = 0;
}

// Function to add passenger to elevator
void addPassengerToElevator(Elevator *elevator, Passenger *passenger) {
    passenger->is_inside = 1;
    elevator->current_capacity++;
}

// Function to remove passenger from elevator
void removePassengerFromElevator(Elevator *elevator, Passenger *passenger) {
    passenger->is_inside = 0;
    elevator->current_capacity--;
}

// Main function to start elevator simulation
int main() {
    printf("Grateful Elevator Simulation Program\n\n");

    // Create elevator object
    Elevator elevator = {1, 1, 1, TOTAL_FLOORS, 15, 0, 0};

    // Create array of passengers
    Passenger passengers[elevator.capacity];

    // Generate random number of passengers
    int num_of_passengers = rand() % elevator.capacity;

    printf("Number of passengers: %d\n", num_of_passengers);

    // Assign passengers to random floors
    for(int i = 0; i < num_of_passengers; i++) {
        passengers[i].current_floor = rand() % TOTAL_FLOORS + 1;
        passengers[i].destination = rand() % TOTAL_FLOORS + 1;

        // Check if passenger is assigned to same floor as destination, reassign if so
        while(passengers[i].destination == passengers[i].current_floor) {
            passengers[i].destination = rand() % TOTAL_FLOORS + 1;
        }

        passengers[i].is_waiting = 1;
        passengers[i].is_inside = 0;

        printf("Passenger %d assigned to floor %d going to floor %d\n", i+1, passengers[i].current_floor, passengers[i].destination);
    }

    printf("\n");

    // Elevator simulation loop
    for(int i = 1; i <= TOTAL_FLOORS; i++) {

        // Check if there are passengers waiting on this floor
        for(int j = 0; j < num_of_passengers; j++) {

            // If there is at least 1 waiting passenger and elevator is not full, open doors
            if(passengers[j].current_floor == i && passengers[j].is_waiting && elevator.current_capacity < elevator.capacity) {

                printf("Elevator opening doors at floor %d\n", i);

                // Add passenger to elevator and mark as not waiting
                addPassengerToElevator(&elevator, &passengers[j]);
                passengers[j].is_waiting = 0;

                // If elevator is not going up, and passenger destination is up from current floor, go up
                if(!elevator.direction && elevator.current_floor < passengers[j].destination) {
                    elevator.direction = 1;
                }

                // If elevator is not going down, and passenger destination is down from current floor, go down
                if(!elevator.direction && elevator.current_floor > passengers[j].destination) {
                    elevator.direction = -1;
                }
            }
        }

        // Check if there are passengers inside the elevator
        for(int j = 0; j < num_of_passengers; j++) {

            // If passenger is inside the elevator and destination is current floor, exit elevator
            if(passengers[j].is_inside && passengers[j].destination == i) {

                printf("Passenger %d exiting elevator at floor %d\n", j+1, i);

                // Remove passenger from elevator
                removePassengerFromElevator(&elevator, &passengers[j]);
            }
        }

        // Move elevator if not already moving
        if(!elevator.is_moving) {
            if(elevator.direction == 1 && elevator.current_floor < elevator.max_floor) {
                moveElevator(&elevator, elevator.current_floor+1);
            }
            else if(elevator.direction == 1 && elevator.current_floor == elevator.max_floor) {
                elevator.direction = -1;
            }
            else if(elevator.direction == -1 && elevator.current_floor > elevator.min_floor) {
                moveElevator(&elevator, elevator.current_floor-1);
            }
            else if(elevator.direction == -1 && elevator.current_floor == elevator.min_floor) {
                elevator.direction = 1;
            }
        }
    }

    return 0;
}