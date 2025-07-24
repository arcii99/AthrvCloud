//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: visionary
#include<stdlib.h>
#include<stdio.h>

#define NUM_FLOORS 10   // Number of floors in the building
#define INITIAL_FLOOR 1 // The floor the elevator starts on
#define ELEVATOR_SPEED 500 // Time between floors (in milliseconds)

// Function to display the status of the elevator
void displayStatus(int currentFloor) 
{
    printf("Elevator is currently at floor %d\n", currentFloor);
}

// Function to simulate a floor button press
void pressFloorButton(int floor)
{
    printf("Button for floor %d pressed\n", floor);
}

// Function to simulate the movement of the elevator
void moveToFloor(int currentFloor, int destinationFloor)
{
    if (currentFloor < destinationFloor) {
        for (int i = currentFloor; i <= destinationFloor; i++) {
            displayStatus(i);
            usleep(ELEVATOR_SPEED);
        }
    } else {
        for (int i = currentFloor; i >= destinationFloor; i--) {
            displayStatus(i);
            usleep(ELEVATOR_SPEED);
        }
    }
}

int main() 
{
    int currentFloor = INITIAL_FLOOR;  // The floor the elevator is on
    int destinationFloor;               // The floor the the elevator will go to
    char input[10];                     // Input buffer for user input

    printf("Welcome to the elevator simulator!\n");

    while (1) {
        printf("Which floor would you like to go to? (or q to quit) ");
        fgets(input, 10, stdin);

        if (input[0] == 'q') {
            printf("Quitting elevator simulator...\n");
            exit(0);
        }

        // Convert input to an integer
        destinationFloor = atoi(input);

        if (destinationFloor < 1 || destinationFloor > NUM_FLOORS) {
            printf("Invalid floor number. Please choose a number between 1 and %d\n", NUM_FLOORS);
            continue;
        }

        if (destinationFloor == currentFloor) {
            printf("Elevator is already on floor %d\n", currentFloor);
            continue;
        }

        pressFloorButton(destinationFloor);
        moveToFloor(currentFloor, destinationFloor);
        currentFloor = destinationFloor;
    }

    return 0;
}