//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/* Definition of Elevator struct */
typedef struct {
    int currentFloor;
    bool isMoving;
} Elevator;

/* Constants */
const int MAX_FLOORS = 10;

/* Print out the menu for the user */
void printMenu() {
    printf("\n");
    printf("Choose from the following options:\n");
    printf("A) Move the elevator to a floor.\n");
    printf("B) Check the current floor.\n");
    printf("C) Quit the program.\n");
    printf("\n");
}

/* Move the elevator to the specified floor */
void moveElevator(Elevator *elevator, int floor) {
    if (floor >= 1 && floor <= MAX_FLOORS) {
        printf("Moving elevator from floor %d to floor %d...\n", elevator->currentFloor, floor);
        elevator->currentFloor = floor;
    } else {
        printf("Invalid floor number. Please select a floor between 1 and %d.\n", MAX_FLOORS);
    }
}

/* Check the current floor of the elevator */
void checkFloor(Elevator *elevator) {
    printf("The current floor of the elevator is %d.\n", elevator->currentFloor);
}

/* Main function */
int main() {
    /* Initialize the elevator */
    Elevator elevator = {1, false};

    /* Print out the welcome message */
    printf("Welcome to the Elevator Simulator!\n");

    /* Keep running until the user chooses to quit */
    bool isRunning = true;
    while (isRunning) {
        /* Print out the menu */
        printMenu();

        /* Get user input */
        char input[100];
        printf("Enter your selection: ");
        fgets(input, sizeof(input), stdin);

        /* Convert the input to uppercase */
        for (int i = 0; i < sizeof(input); i++) {
            input[i] = toupper(input[i]);
        }

        /* Parse the user input */
        if (strncmp(input, "A", 1) == 0) {
            int floor;
            printf("Enter the floor you want to move to: ");
            scanf("%d", &floor);
            fflush(stdin);
            moveElevator(&elevator, floor);
        } else if (strncmp(input, "B", 1) == 0) {
            checkFloor(&elevator);
        } else if (strncmp(input, "C", 1) == 0) {
            isRunning = false;
        } else {
            printf("Invalid selection. Please try again.\n");
        }
    }

    /* Print out the goodbye message */
    printf("Thank you for using the Elevator Simulator!\n");

    return 0;
}