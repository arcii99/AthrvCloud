//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: immersive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define FLOORS 10

void displayElevator(int currentFloor, int destinationFloor);
void simulateElevator(int* currentFloor, int* destinationFloor);

int main()
{
    int currentFloor = 1;
    int destinationFloor = 1;
    int elevatorSpeed = 2000; // In milliseconds
    bool isElevatorMoving = false;

    printf("Welcome to Elevator Simulation!\n");

    while (true)
    {
        if (currentFloor == destinationFloor)
        {
            printf("\nElevator has reached the destination floor!\n");
            isElevatorMoving = false;
        }

        if (!isElevatorMoving)
        {
            simulateElevator(&currentFloor, &destinationFloor); // Simulate a new destination
            isElevatorMoving = true;
        }

        displayElevator(currentFloor, destinationFloor);

        // Move elevator to next floor
        if (currentFloor > destinationFloor)
            currentFloor--;
        else if (currentFloor < destinationFloor)
            currentFloor++;

        // Wait for elevatorSpeed milliseconds before moving to the next floor
        printf("\n");
        usleep(elevatorSpeed * 1000);
    }

    return 0;
}

void displayElevator(int currentFloor, int destinationFloor)
{
    printf("\n");
    printf("+---------------------+\n");
    printf("|     Elevator        |\n");
    printf("|---------------------|\n");
    printf("| Current Floor: %d            |\n", currentFloor);
    printf("| Destination floor: %d        |\n", destinationFloor);
    printf("+---------------------+\n");
}

void simulateElevator(int* currentFloor, int* destinationFloor)
{
    srand(time(NULL));
    *destinationFloor = rand() % FLOORS + 1;

    while (*destinationFloor == *currentFloor)
        *destinationFloor = rand() % FLOORS + 1;

    printf("\nElevator moving from floor %d to floor %d...\n", *currentFloor, *destinationFloor);
}