//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include <stdio.h>

#define NUM_FLOORS 10
#define NUM_ELEVATORS 3

// Function to calculate the distance between two floors
int distance(int fromFloor, int toFloor) {
    return (fromFloor > toFloor) ? (fromFloor - toFloor) : (toFloor - fromFloor);
}

// Struct to represent a request for an elevator
typedef struct {
    int floor;
    int direction; // 1 for up, -1 for down
} Request;

// Struct to represent an elevator
typedef struct {
    int currentFloor;
    int direction; // 1 for up, -1 for down, 0 for still
    int destination; // -1 if no destination
    Request requests[NUM_FLOORS][2]; // 2 is for up and down requests
} Elevator;

int main() {
    // Initialize elevators
    Elevator elevators[NUM_ELEVATORS];
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators[i].currentFloor = 0;
        elevators[i].direction = 0;
        elevators[i].destination = -1;
        for (int j = 0; j < NUM_FLOORS; j++) {
            elevators[i].requests[j][0].floor = j;
            elevators[i].requests[j][0].direction = 0;
            elevators[i].requests[j][1].floor = j;
            elevators[i].requests[j][1].direction = 0;
        }
    }

    // Keep track of request queue
    Request requests[NUM_FLOORS][2]; // 2 is for up and down requests
    for (int i = 0; i < NUM_FLOORS; i++) {
        requests[i][0].floor = i;
        requests[i][0].direction = 0;
        requests[i][1].floor = i;
        requests[i][1].direction = 0;
    }

    // Run simulation loop
    int numRequests = 0;
    while (1) {
        // Check for new requests
        int floor;
        char direction;
        printf("Enter a new request (floor and direction): ");
        scanf("%d %c", &floor, &direction);
        int d;
        if (direction == 'u') d = 1;
        else if (direction == 'd') d = -1;
        else {
            printf("Invalid direction, please enter 'u' or 'd'\n");
            continue;
        }
        requests[floor][d == 1 ? 0 : 1].direction = d;
        numRequests++;

        // Handle elevator movement and pickups/dropoffs
        for (int i = 0; i < NUM_ELEVATORS; i++) {
            // Handle pickups and dropoffs
            if (elevators[i].destination == elevators[i].currentFloor) {
                elevators[i].direction = 0;
                printf("Elevator %d arrived at floor %d\n", i, elevators[i].destination);
                elevators[i].destination = -1;
                for (int j = 0; j < NUM_FLOORS; j++) {
                    if (elevators[i].requests[j][elevators[i].direction == 1 ? 0 : 1].direction != 0) {
                        printf("Elevator %d picked up a passenger at floor %d\n", i, j);
                        elevators[i].destination = j;
                        elevators[i].requests[j][elevators[i].direction == 1 ? 0 : 1].direction = 0;
                        break;
                    }
                }
            }
            // Handle movement
            if (elevators[i].destination == -1) {
                int minDist = NUM_FLOORS;
                int newDest = -1;
                for (int j = 0; j < NUM_FLOORS; j++) {
                    if (distance(elevators[i].currentFloor, j) < minDist && elevators[i].requests[j][0].direction != 0) {
                        minDist = distance(elevators[i].currentFloor, j);
                        newDest = j;
                        elevators[i].direction = 1;
                    }
                    if (distance(elevators[i].currentFloor, j) < minDist && elevators[i].requests[j][1].direction != 0) {
                        minDist = distance(elevators[i].currentFloor, j);
                        newDest = j;
                        elevators[i].direction = -1;
                    }
                }
                elevators[i].destination = newDest;
                printf("Elevator %d is now headed to floor %d (direction %c)\n", i, elevators[i].destination, elevators[i].direction == 1 ? 'u' : 'd');
            }
            if (elevators[i].destination > elevators[i].currentFloor) {
                elevators[i].currentFloor++;
                printf("Elevator %d is now at floor %d (direction %c)\n", i, elevators[i].currentFloor, elevators[i].direction == 1 ? 'u' : 'd');
            }
            else if (elevators[i].destination < elevators[i].currentFloor) {
                elevators[i].currentFloor--;
                printf("Elevator %d is now at floor %d (direction %c)\n", i, elevators[i].currentFloor, elevators[i].direction == 1 ? 'u' : 'd');
            }
        }

        // Check if simulation should end
        if (numRequests == NUM_FLOORS * 2) {
            printf("All floors have been requested, ending simulation.\n");
            break;
        }
    }

    return 0;
}