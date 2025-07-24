//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_FLOORS 10 // Number of floors in the building
#define CAPACITY   10 // Capacity of the elevator

/* Function to simulate moving the elevator from the current floor to the target floor */
void move_elevator(int target_floor, int prev_floor) {
    printf("Elevator is moving from floor %d to floor %d...\n", prev_floor, target_floor);
    sleep(abs(target_floor - prev_floor)); // Simulate the time it takes to move between floors
    printf("Elevator has arrived at floor %d.\n", target_floor);
}

/* Main function to run the elevator simulation program */
int main() {
    int current_floor = 1;       // Current floor of the elevator
    int target_floor;            // Target floor requested by a passenger
    int num_passengers = 0;      // Number of passengers currently in the elevator
    bool up_direction = true;    // Direction the elevator is moving in
    bool floor_requests[NUM_FLOORS] = { false }; // Array to store current floor requests

    srand(time(NULL)); // Seed the random number generator with the current time

    printf("Elevator Simulation:\n");

    while (true) { // Loop indefinitely until program is terminated
        if (up_direction) {
            // Check for requests in the upward direction
            for (int i = current_floor; i < NUM_FLOORS; i++) {
                if (floor_requests[i]) { // If there is a request, move to that floor
                    move_elevator(i+1, current_floor);
                    current_floor = i+1;
                    floor_requests[i] = false; // Clear the request for that floor
                    break;
                }
            }
            // If there are no more requests in the upward direction, change direction
            up_direction = false;
        } else {
            // Check for requests in the downward direction
            for (int i = current_floor-2; i >= 0; i--) {
                if (floor_requests[i]) { // If there is a request, move to that floor
                    move_elevator(i+1, current_floor);
                    current_floor = i+1;
                    floor_requests[i] = false; // Clear the request for that floor
                    break;
                }
            }
            // If there are no more requests in the downward direction, change direction
            up_direction = true;
        }

        // Check if the elevator is at capacity, if not ask for more requests
        if (num_passengers < CAPACITY) {
            printf("Elevator is at floor %d with space for %d more passengers.\n", current_floor, CAPACITY-num_passengers);

            // Generate random passenger requests for each floor
            for (int i = 0; i < NUM_FLOORS; i++) {
                if (i != current_floor-1 && rand() % 2 == 1) { // Randomly generate requests for other floors
                    printf("Passenger at floor %d wants to go to floor %d.\n", current_floor, i+1);
                    floor_requests[i] = true; // Add the request to the floor requests array
                }
            }

            // Ask for user input for elevator requests
            printf("Enter target floor (or 0 to exit): ");
            scanf("%d", &target_floor);

            if (target_floor == 0) { // Exit program if user enters 0
                printf("Exiting elevator simulation program.\n");
                return 0;
            }
            else if (target_floor == current_floor) { // If the target is the current floor, no need to move
                printf("Elevator is already at floor %d.\n", current_floor);
            }
            else if (target_floor < 0 || target_floor > NUM_FLOORS) { // Invalid floor number
                printf("Invalid floor number.\n");
            }
            else { // Move elevator to the target floor
                move_elevator(target_floor, current_floor);
                current_floor = target_floor;
            }

            num_passengers++; // Increment the number of passengers in the elevator
        } else {
            printf("Elevator is at capacity on floor %d.\n", current_floor);
        }
    }
}