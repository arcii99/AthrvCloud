//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10
#define MAX_PASSENGERS 8

typedef enum {
    GOING_UP,
    GOING_DOWN,
    IDLE
} State;

typedef struct {
    int floorNumber;
    char direction;
} Passenger;

typedef struct {
    int currentFloor;
    State state;
    Passenger passengers[MAX_PASSENGERS];
} Elevator;

int main() {
    Elevator elevator;
    elevator.currentFloor = 1;
    elevator.state = IDLE;
    int numPassengers = 0;
    Passenger passenger;
    int floorsPressed[MAX_FLOORS];

    for (int i = 0; i < MAX_FLOORS; i++) {
        floorsPressed[i] = 0;
    }

    printf("Welcome to the Elevator Simulator!\n\n");
    printf("Please enter the number of passengers (max 8): ");
    scanf("%d", &numPassengers);

    for (int i = 0; i < numPassengers; i++) {
        printf("Please enter the floor of Passenger %d: ", i+1);
        scanf("%d", &passenger.floorNumber);

        if (passenger.floorNumber > elevator.currentFloor) {
            passenger.direction = 'u';
        } else if (passenger.floorNumber < elevator.currentFloor) {
            passenger.direction = 'd';
        } else {
            passenger.direction = 's';
        }

        elevator.passengers[i] = passenger;
        floorsPressed[passenger.floorNumber-1] = 1;
    }

    printf("\nElevator doors closing...\n\n");

    while (1) {
        if (elevator.state == IDLE) {
            int floorsAbove = 0;
            int floorsBelow = 0;

            for (int i = elevator.currentFloor; i < MAX_FLOORS; i++) {
                if (floorsPressed[i] == 1) {
                    floorsAbove++;
                }
            }

            for (int i = 0; i < elevator.currentFloor-1; i++) {
                if (floorsPressed[i] == 1) {
                    floorsBelow++;
                }
            }

            if (floorsAbove > floorsBelow) {
                elevator.state = GOING_UP;
            } else if (floorsAbove < floorsBelow) {
                elevator.state = GOING_DOWN;
            } else {
                printf("Elevator is idle...\n\n");
                return 0;
            }
        } else if (elevator.state == GOING_UP) {
            for (int i = elevator.currentFloor; i < MAX_FLOORS; i++) {
                if (floorsPressed[i] == 1) {
                    printf("Going up from Floor %d to Floor %d...\n\n", elevator.currentFloor, i+1);
                    elevator.currentFloor = i+1;
                    break;
                }
            }

            if (elevator.currentFloor == MAX_FLOORS) {
                printf("Going down from Floor %d to Floor 1...\n\n", elevator.currentFloor);
                elevator.currentFloor = 1;
                elevator.state = GOING_DOWN;
            }
        } else if (elevator.state == GOING_DOWN) {
            for (int i = elevator.currentFloor-2; i >= 0; i--) {
                if (floorsPressed[i] == 1) {
                    printf("Going down from Floor %d to Floor %d...\n\n", elevator.currentFloor, i+1);
                    elevator.currentFloor = i+1;
                    break;
                }
            }

            if (elevator.currentFloor == 1) {
                printf("Going up from Floor %d to Floor 10...\n\n", elevator.currentFloor);
                elevator.currentFloor = 10;
                elevator.state = GOING_UP;
            }
        }

        for (int i = 0; i < numPassengers; i++) {
            if (elevator.passengers[i].floorNumber == elevator.currentFloor) {
                printf("Passenger %d has reached his/her destination on Floor %d...\n\n", i+1, elevator.currentFloor);
                floorsPressed[elevator.currentFloor-1] = 0;
            }
        }

        int allReached = 1;

        for (int i = 0; i < numPassengers; i++) {
            if (floorsPressed[elevator.passengers[i].floorNumber-1] == 1) {
                allReached = 0;
                break;
            }
        }

        if (allReached == 1) {
            printf("All passengers have reached their destinations on Floor %d...\n\n", elevator.currentFloor);
            return 0;
        }
    }

    return 0;
}