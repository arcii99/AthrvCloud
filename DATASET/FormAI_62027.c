//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants
#define ELEVATOR_CAPACITY 5
#define NUM_FLOORS 7

// Enumeration for the elevator direction
enum Direction {
    UP,
    DOWN,
    IDLE
};

// Elevator structure to keep track of relevant properties
struct Elevator {
    enum Direction direction;
    bool stops[NUM_FLOORS];
    int currentFloor;
    int passengers[ELEVATOR_CAPACITY];
    int numPassengers;
};

// Function to simulate the arrival of a new passenger
void passengerArrives(struct Elevator* elevator, int floor) {
    // Check if the passenger can fit in the elevator
    if (elevator->numPassengers < ELEVATOR_CAPACITY) {
        elevator->passengers[elevator->numPassengers] = floor;
        elevator->stops[floor] = true;
        elevator->numPassengers++;
        printf("Passenger arrives on floor %d and enters the elevator.\n", floor);
    }
    else {
        printf("Passenger arrives on floor %d but the elevator is full.\n", floor);
    }
}

// Main function to simulate the elevator
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Create the elevator and initialize its properties
    struct Elevator elevator;
    elevator.direction = IDLE;
    elevator.currentFloor = 0;
    elevator.numPassengers = 0;
    for (int i = 0; i < NUM_FLOORS; i++) {
        elevator.stops[i] = false;
    }

    // Loop through each floor and simulate the elevator's behavior
    for (int i = 0; i < NUM_FLOORS; i++) {
        printf("----- Floor %d -----\n", i);

        // Randomly simulate the arrival of new passengers
        int numNewPassengers = rand() % 3;
        for (int j = 0; j < numNewPassengers; j++) {
            passengerArrives(&elevator, i);
        }

        // Update the elevator's direction based on the stops
        if (elevator.direction == UP) {
            bool shouldContinue = false;
            for (int j = elevator.currentFloor + 1; j < NUM_FLOORS; j++) {
                if (elevator.stops[j]) {
                    shouldContinue = true;
                    break;
                }
            }
            if (!shouldContinue) {
                elevator.direction = DOWN;
                printf("Elevator changes direction to DOWN.\n");
            }
        }
        else if (elevator.direction == DOWN) {
            bool shouldContinue = false;
            for (int j = elevator.currentFloor - 1; j >= 0; j--) {
                if (elevator.stops[j]) {
                    shouldContinue = true;
                    break;
                }
            }
            if (!shouldContinue) {
                elevator.direction = UP;
                printf("Elevator changes direction to UP.\n");
            }
        }
        else {
            bool shouldContinue = false;
            for (int j = elevator.currentFloor + 1; j < NUM_FLOORS; j++) {
                if (elevator.stops[j]) {
                    shouldContinue = true;
                    elevator.direction = UP;
                    printf("Elevator changes direction to UP.\n");
                    break;
                }
            }
            if (!shouldContinue) {
                for (int j = elevator.currentFloor - 1; j >= 0; j--) {
                    if (elevator.stops[j]) {
                        shouldContinue = true;
                        elevator.direction = DOWN;
                        printf("Elevator changes direction to DOWN.\n");
                        break;
                    }
                }
            }
        }

        // Update the elevator's current floor based on its direction
        if (elevator.direction == UP) {
            for (int j = elevator.currentFloor + 1; j < NUM_FLOORS; j++) {
                if (elevator.stops[j]) {
                    printf("Elevator moves UP to floor %d.\n", j);
                    elevator.currentFloor = j;

                    // Unload passengers
                    for (int k = 0; k < elevator.numPassengers; k++) {
                        if (elevator.passengers[k] == j) {
                            printf("Passenger exits the elevator on floor %d.\n", j);
                            elevator.stops[j] = false;
                            elevator.numPassengers--;
                            for (int l = k; l < elevator.numPassengers; l++) {
                                elevator.passengers[l] = elevator.passengers[l + 1];
                            }
                        }
                    }

                    // Load passengers
                    for (int k = 0; k < ELEVATOR_CAPACITY - elevator.numPassengers; k++) {
                        if (elevator.stops[j]) {
                            passengerArrives(&elevator, j);
                        }
                    }
                }
            }
        }
        else if (elevator.direction == DOWN) {
            for (int j = elevator.currentFloor - 1; j >= 0; j--) {
                if (elevator.stops[j]) {
                    printf("Elevator moves DOWN to floor %d.\n", j);
                    elevator.currentFloor = j;

                    // Unload passengers
                    for (int k = 0; k < elevator.numPassengers; k++) {
                        if (elevator.passengers[k] == j) {
                            printf("Passenger exits the elevator on floor %d.\n", j);
                            elevator.stops[j] = false;
                            elevator.numPassengers--;
                            for (int l = k; l < elevator.numPassengers; l++) {
                                elevator.passengers[l] = elevator.passengers[l + 1];
                            }
                        }
                    }

                    // Load passengers
                    for (int k = 0; k < ELEVATOR_CAPACITY - elevator.numPassengers; k++) {
                        if (elevator.stops[j]) {
                            passengerArrives(&elevator, j);
                        }
                    }
                }
            }
        }
        else {
            int closestFloor = -1;
            int closestDistance = NUM_FLOORS;
            for (int j = 0; j < NUM_FLOORS; j++) {
                if (elevator.stops[j]) {
                    int distance = abs(j - elevator.currentFloor);
                    if (distance < closestDistance) {
                        closestFloor = j;
                        closestDistance = distance;
                    }
                }
            }
            if (closestFloor > elevator.currentFloor) {
                elevator.direction = UP;
                printf("Elevator changes direction to UP.\n");
            }
            else if (closestFloor < elevator.currentFloor) {
                elevator.direction = DOWN;
                printf("Elevator changes direction to DOWN.\n");
            }
            else {
                printf("Elevator remains IDLE on floor %d.\n", elevator.currentFloor);
            }
        }
    }

    return 0;
}