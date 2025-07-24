//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
// Shape-shifting elevator simulation 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of floors in the building
#define NUM_FLOORS 10

// Define the number of elevators in the building
#define NUM_ELEVATORS 3

// Define the maximum capacity of each elevator
#define MAX_CAPACITY 10

// Define the maximum number of people waiting for the elevator at a time
#define MAX_WAITING 50

// Define the possible states of an elevator
typedef enum {
    IDLE,
    MOVING_UP,
    MOVING_DOWN,
    DOORS_OPEN
} ElevatorState;

// Define the possible directions a passenger can choose to go
typedef enum {
    UP,
    DOWN
} PassengerDirection;

// Define the structure for a passenger
typedef struct {
    int currentFloor;
    PassengerDirection direction;
} Passenger;

// Define the structure for an elevator
typedef struct {
    int currentFloor;
    int capacity;
    ElevatorState state;
    Passenger passengers[MAX_CAPACITY];
} Elevator;

// Define the structure for a floor
typedef struct {
    int waiting;
    Passenger waitingPassengers[MAX_WAITING];
} Floor;

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the floors
    Floor floors[NUM_FLOORS];

    // Create the elevators
    Elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].currentFloor = 0;
        elevators[i].capacity = 0;
        elevators[i].state = IDLE;
    }

    // Main simulation loop
    while (1) {
        // Print the current state of each elevator
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            printf("Elevator %d: ", i+1);
            switch (elevators[i].state) {
                case IDLE:
                    printf("Idle on floor %d\n", elevators[i].currentFloor);
                    break;
                case MOVING_UP:
                    printf("Moving up to floor %d\n", elevators[i].currentFloor+1);
                    break;
                case MOVING_DOWN:
                    printf("Moving down to floor %d\n", elevators[i].currentFloor-1);
                    break;
                case DOORS_OPEN:
                    printf("Doors open on floor %d\n", elevators[i].currentFloor);
                    break;
            }
        }

        // Generate new passengers on each floor
        for (int i = 0; i < NUM_FLOORS; i++) {
            int newPassengers = rand() % 3;
            for (int j = 0; j < newPassengers; j++) {
                PassengerDirection direction = rand() % 2;
                floors[i].waitingPassengers[floors[i].waiting].currentFloor = i;
                floors[i].waitingPassengers[floors[i].waiting].direction = direction;
                floors[i].waiting++;
            }
        }

        // Move each elevator
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            switch (elevators[i].state) {
                case IDLE:
                    // If there are passengers waiting on this floor, open the doors and let them in
                    if (floors[elevators[i].currentFloor].waiting > 0) {
                        elevators[i].state = DOORS_OPEN;
                    }
                    // Otherwise, choose a random direction and move
                    else {
                        int direction = rand() % 2;
                        if (direction == 0 && elevators[i].currentFloor < NUM_FLOORS-1) {
                            elevators[i].state = MOVING_UP;
                        }
                        else if (elevators[i].currentFloor > 0) {
                            elevators[i].state = MOVING_DOWN;
                        }
                    }
                    break;
                case MOVING_UP:
                    if (elevators[i].currentFloor < NUM_FLOORS-1) {
                        elevators[i].currentFloor++;
                    }
                    else {
                        elevators[i].state = MOVING_DOWN;
                    }
                    break;
                case MOVING_DOWN:
                    if (elevators[i].currentFloor > 0) {
                        elevators[i].currentFloor--;
                    }
                    else {
                        elevators[i].state = MOVING_UP;
                    }
                    break;
                case DOORS_OPEN:
                    // Determine how many passengers can fit into the elevator
                    int numPassengers = 0;
                    for (int j = 0; j < floors[elevators[i].currentFloor].waiting; j++) {
                        if (floors[elevators[i].currentFloor].waitingPassengers[j].direction == UP &&
                                elevators[i].state == MOVING_UP) {
                            numPassengers++;
                        }
                        else if (floors[elevators[i].currentFloor].waitingPassengers[j].direction == DOWN &&
                                elevators[i].state == MOVING_DOWN) {
                            numPassengers++;
                        }
                    }
                    int availableCapacity = MAX_CAPACITY - elevators[i].capacity;
                    numPassengers = (numPassengers < availableCapacity) ? numPassengers : availableCapacity;

                    // Add passengers to the elevator
                    for (int j = 0; j < numPassengers; j++) {
                        for (int k = 0; k < floors[elevators[i].currentFloor].waiting; k++) {
                            if (elevators[i].capacity < MAX_CAPACITY) {
                                if (floors[elevators[i].currentFloor].waitingPassengers[k].direction == UP &&
                                        elevators[i].state == MOVING_UP) {
                                    elevators[i].passengers[elevators[i].capacity] =
                                            floors[elevators[i].currentFloor].waitingPassengers[k];
                                    elevators[i].capacity++;
                                    floors[elevators[i].currentFloor].waiting--;
                                }
                                else if (floors[elevators[i].currentFloor].waitingPassengers[k].direction == DOWN &&
                                        elevators[i].state == MOVING_DOWN) {
                                    elevators[i].passengers[elevators[i].capacity] =
                                            floors[elevators[i].currentFloor].waitingPassengers[k];
                                    elevators[i].capacity++;
                                    floors[elevators[i].currentFloor].waiting--;
                                }
                            }
                        }
                    }

                    // Close the doors
                    elevators[i].state = (elevators[i].capacity > 0) ? DOORS_OPEN : IDLE;
                    break;
            }
        }
    }

    return 0;
}