//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: happy
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Defining floor constants
#define FLOOR_ONE 1
#define FLOOR_TWO 2
#define FLOOR_THREE 3
#define FLOOR_FOUR 4
#define FLOOR_FIVE 5

// Defining direction constants
#define UP true
#define DOWN false

// Elevator struct definition
typedef struct {
    int currentFloor;
    bool direction;
} Elevator;

// Initializing the elevator
void initializeElevator(Elevator* elevator) {
    elevator->currentFloor = FLOOR_ONE;
    elevator->direction = UP;
}

// Printing current floor and direction of elevator
void printElevatorStatus(const Elevator* elevator) {
    const char* direction = elevator->direction ? "Up" : "Down";
    printf("Elevator is currently on floor %d and going %s.\n", elevator->currentFloor, direction);
}

// Moving the elevator up or down
void moveElevator(Elevator* elevator, const int floor) {
    int currentFloor = elevator->currentFloor;
    if (floor > currentFloor) {
        elevator->direction = UP;
        for (int i = currentFloor; i < floor; i++) {
            printf("Elevator moving up to floor %d...\n", i + 1);
        }
    } else if (floor < currentFloor) {
        elevator->direction = DOWN;
        for (int i = currentFloor; i > floor; i--) {
            printf("Elevator moving down to floor %d...\n", i - 1);
        }
    }
    elevator->currentFloor = floor;
}

// Main function to simulate elevator operation
int main() {
    printf("Welcome to the Happy Elevator Simulation!\n\n");

    Elevator elevator;
    initializeElevator(&elevator);

    // Starting the elevator loop
    while (true) {
        printElevatorStatus(&elevator);
        printf("Please enter the floor you'd like to go to (1-5): ");
        char input[10];
        fgets(input, sizeof(input), stdin);

        // Checking if input is valid
        bool validInput = true;
        int floor;
        if (strlen(input) == 2) {
            floor = input[0] - '0';
            if (floor < 1 || floor > 5) {
                validInput = false;
            }
        } else {
            validInput = false;
        }

        if (validInput) {
            moveElevator(&elevator, floor);

            printf("You have arrived at floor %d! Have a nice day!\n\n", floor);
        } else {
            printf("Invalid input. Please try again.\n\n");
        }
    }

    return 0;
}