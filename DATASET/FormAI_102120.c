//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: detailed
#include <stdio.h>

/*
 * Elevator simulator program that moves up and down
 * a building based on user input.
 */

#define MAX_FLOORS 10

int main() {
    int currentFloor = 1; // Start on ground floor
    int destinationFloor = 1;
    int floorsTraversed = 0;
    int direction = 0; // 0 = Idle, 1 = Up, -1 = Down
    int floors[MAX_FLOORS] = {0}; // Initialize all floors to empty
    int i;

    printf("Welcome to the Elevator Simulator!\n");

    while (1) { // Continue running until the program is exited
        printf("\nCurrent floor: %d\n", currentFloor);
        printf("Destination floor: %d\n", destinationFloor);
        printf("Floors traversed: %d\n", floorsTraversed);
        printf("Direction: %s\n", direction == 0 ? "Idle" : (direction == 1 ? "Up" : "Down"));
        printf("\n");

        // Check if the elevator has reached its destination
        if (currentFloor == destinationFloor) {
            printf("Elevator has arrived at floor %d.\n", currentFloor);
            printf("Opening doors...\n");

            // Unload any passengers on this floor
            if (floors[currentFloor - 1] > 0) {
                printf("Unloading %d passengers.\n", floors[currentFloor - 1]);
                floorsTraversed += floors[currentFloor - 1];
                floors[currentFloor - 1] = 0;
            }

            // Check for any passengers waiting to go in the same direction
            for (i = 0; i < MAX_FLOORS; i++) {
                if (i == currentFloor - 1) {
                    continue; // Skip current floor
                }

                if (floors[i] == 0) {
                    continue; // Skip empty floors
                }

                if (direction == 1 && i > currentFloor - 1) {
                    destinationFloor = i + 1;
                    printf("Passenger(s) on floor %d pressing up button.\n", i + 1);
                    break;
                } else if (direction == -1 && i < currentFloor - 1) {
                    destinationFloor = i + 1;
                    printf("Passenger(s) on floor %d pressing down button.\n", i + 1);
                    break;
                }
            }

            // If there are no passengers waiting, go back to idle state
            if (currentFloor == destinationFloor) {
                direction = 0;
                printf("No passengers waiting, elevator is now idle.\n");
            } else if (destinationFloor > currentFloor) {
                direction = 1;
            } else {
                direction = -1;
            }

            printf("Closing doors...\n");

            continue; // Go to next iteration of the loop
        }

        // Move the elevator towards its destination
        if (direction == 1) {
            currentFloor++;
            floorsTraversed++;
        } else {
            currentFloor--;
            floorsTraversed--;
        }

        printf("Elevator moving %s to floor %d...\n", direction == 1 ? "up" : "down", currentFloor);

        // Check if any passengers on this floor want to go in the same direction
        if (floors[currentFloor - 1] > 0) {
            if (direction == 1) {
                printf("%d passenger(s) on floor %d pressing up button.\n", floors[currentFloor - 1], currentFloor);
            } else if (direction == -1) {
                printf("%d passenger(s) on floor %d pressing down button.\n", floors[currentFloor - 1], currentFloor);
            }

            // Update the destination floor if necessary
            if (direction == 1 && currentFloor < destinationFloor) {
                destinationFloor = currentFloor;
            } else if (direction == -1 && currentFloor > destinationFloor) {
                destinationFloor = currentFloor;
            }
        }
    }

    return 0;
}