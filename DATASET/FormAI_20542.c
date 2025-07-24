//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Constants */

#define FLOORS 10
#define ELEVATORS 3
#define SLEEP_TIME 2000000

/* Variables */

static int elevators[ELEVATORS] = {0, 0, 0};
static int elevatorRequests[ELEVATORS][FLOORS];
static int direction[ELEVATORS] = {1,1,1};

/* Function Declarations */

void *operate(void *elevatorNumber);
bool shouldStop(int currentFloor, int elevatorNumber);
int getNextFloor(int currentFloor, int elevatorNumber);

/* Main Function */

int main() {
    int i, j;

    pthread_t elevatorThreads[ELEVATORS];
    for (i = 0; i < ELEVATORS; i++) {
        pthread_create(&elevatorThreads[i], NULL, operate, (void *) &elevators[i]);
    }

    bool running = true;
    while (running) {

    /* UI */
        printf("\n");
        for (i = FLOORS; i > 0; i--) {
            printf("|");
            for (j = 0; j < ELEVATORS; j++) {
                if (elevators[j] == i) {
                    printf("-%d-", (elevatorRequests[j][i-1] > 0) ? elevatorRequests[j][i-1] : 0);
                } else {
                    printf("   ");
                }
            }
            printf("|\n");
        }
        printf("\n");

        char input;
        printf("Enter 'q' to quit or 'r' to request an elevator: ");
        scanf(" %c", &input);
        if (input == 'q') {
            running = false;
        } else if (input == 'r') {
            printf("Enter your starting floor (1-%d): ", FLOORS);
            int startFloor;
            scanf("%d", &startFloor);
            if (startFloor < 1 || startFloor > FLOORS) {
                printf("Invalid floor number.\n");
                continue;
            }
            printf("Enter your destination floor (1-%d): ", FLOORS);
            int destinationFloor;
            scanf("%d", &destinationFloor);
            if (destinationFloor < 1 || destinationFloor > FLOORS) {
                printf("Invalid floor number.\n");
                continue;
            }
            printf("Requesting elevator from floor %d to %d.\n", startFloor, destinationFloor);

            bool foundElevator = false;
            for (i = 0; i < ELEVATORS; i++) {
                if (elevatorRequests[i][startFloor-1] == 0) {
                    elevatorRequests[i][startFloor-1] = destinationFloor;
                    foundElevator = true;
                    break;
                }
            }
            if (!foundElevator) {
                printf("All elevators busy. Please try again later.\n");
            }
        }
    }

    for (i = 0; i < ELEVATORS; i++) {
        pthread_join(elevatorThreads[i], NULL);
    }

    return 0;
}

/* Elevator operations */

void *operate(void *elevatorNumber) {
    while (true) {
        int *elevatorNum = (int *) elevatorNumber;
        int currentFloor = elevators[*elevatorNum];
        bool moving = false;

        /* Determine direction */
        int i, directionSum = 0;
        for (i = 0; i < FLOORS; i++) {
            directionSum += elevatorRequests[*elevatorNum][i];
        }
        if (directionSum == 0) {
            direction[*elevatorNum] = 0;
        } else if (currentFloor == 1) {
            direction[*elevatorNum] = 1;
        } else if (currentFloor == FLOORS) {
            direction[*elevatorNum] = -1;
        }

        /* Move */
        elevators[*elevatorNum] += direction[*elevatorNum];
        currentFloor = elevators[*elevatorNum];
        if (shouldStop(currentFloor, *elevatorNum)) {
            elevatorRequests[*elevatorNum][currentFloor-1] = 0;
            printf("Elevator %d stopping at floor %d.\n", (*elevatorNum)+1, currentFloor);
            usleep(SLEEP_TIME);
        } else {
            printf("Elevator %d at floor %d.\n", (*elevatorNum)+1, currentFloor);
            moving = true;
        }

        /* Determine next floor */
        int nextFloor = getNextFloor(currentFloor, *elevatorNum);
        if (nextFloor > 0) {
            direction[*elevatorNum] = (nextFloor > currentFloor) ? 1 : -1;
        } else {
            moving = false;
        }

        if (moving) {
            printf("Elevator %d moving %s.\n", (*elevatorNum)+1, (direction[*elevatorNum] > 0) ? "up" : "down");
            usleep(SLEEP_TIME);
        }
    }
}

bool shouldStop(int currentFloor, int elevatorNumber) {
    return (elevatorRequests[elevatorNumber][currentFloor-1] > 0);
}

int getNextFloor(int currentFloor, int elevatorNumber) {
    int i, directionCount = 0;
    for (i = (direction[elevatorNumber] > 0) ? currentFloor+1 : currentFloor-1;
            (direction[elevatorNumber] > 0) ? i <= FLOORS : i >= 1;
            i += direction[elevatorNumber]) {
        if (elevatorRequests[elevatorNumber][i-1] > 0) {
            return i;
        }
        directionCount += direction[elevatorNumber];
        if (directionCount == 0) {
            return -1;
        }
    }
    return -1;
}