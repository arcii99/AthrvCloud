//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants for the maximum number of floors and elevators
#define MAX_FLOORS 10
#define MAX_ELEVATORS 3

// Struct to represent an elevator
typedef struct {
    int current_floor;
    bool going_up;
    bool doors_open;
} elevator_t;

// Function to move an elevator up or down
void move_elevator(elevator_t* elevator) {
    if (elevator->going_up) {
        elevator->current_floor++;
    } else {
        elevator->current_floor--;
    }
}

// Function to check if an elevator is at its destination floor
bool elevator_at_destination(elevator_t* elevator, int destination_floor) {
    return elevator->current_floor == destination_floor;
}

int main() {
    // Initialize the elevators
    elevator_t elevators[MAX_ELEVATORS];
    for (int i = 0; i < MAX_ELEVATORS; i++) {
        elevators[i].current_floor = 0;
        elevators[i].going_up = true;
        elevators[i].doors_open = false;
    }

    // Initialize the floors
    int floors[MAX_FLOORS];
    for (int i = 0; i < MAX_FLOORS; i++) {
        floors[i] = 0;
    }

    // Main loop for the elevator simulation
    while (true) {
        // Print the current state of each elevator
        for (int i = 0; i < MAX_ELEVATORS; i++) {
            printf("Elevator %d is on floor %d\n", i, elevators[i].current_floor);
        }

        // Get input from the user
        char input[10];
        printf("Where do you want to go? ");
        fgets(input, 10, stdin);
        int destination_floor = atoi(input);

        // Find the closest elevator to the destination floor
        int closest_elevator = 0;
        int min_distance = abs(elevators[0].current_floor - destination_floor);
        for (int i = 1; i < MAX_ELEVATORS; i++) {
            int distance = abs(elevators[i].current_floor - destination_floor);
            if (distance < min_distance) {
                min_distance = distance;
                closest_elevator = i;
            }
        }

        // Move the closest elevator to the destination floor
        elevator_t* elevator = &elevators[closest_elevator];
        while (!elevator_at_destination(elevator, destination_floor)) {
            move_elevator(elevator);
        }
        elevator->doors_open = true;

        // Wait for the user to enter the elevator and close the doors
        printf("Please enter elevator %d\n", closest_elevator);
        printf("Press any key to close the doors\n");
        getchar();
        elevator->doors_open = false;

        // Move the elevator to the destination
        while (!elevator_at_destination(elevator, destination_floor)) {
            move_elevator(elevator);
        }
        elevator->doors_open = true;

        // Wait for the user to exit the elevator and close the doors
        printf("Please exit elevator %d\n", closest_elevator);
        printf("Press any key to close the doors\n");
        getchar();
        elevator->doors_open = false;
    }

    return 0;
}