//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*** Main function to run the program ***/

int main()
{
    int current_floor = 1, direction = 1, destination, elevator_action;
    bool door_open = false;
    printf("\nWelcome to the Elevator Simuation Program!\n");
    printf("Enter 0 to exit the program.\n\n");

    while (true) {
        printf("Currently at floor %d. ", current_floor);
        printf("Where would you like to go? (1-10): ");
        scanf("%d", &destination);

        if (destination > 10 || destination < 1) {
            printf("Invalid floor. Please choose a floor between 1 and 10.\n");
            continue;
        } else if (destination == current_floor) {
            printf("You are already on floor %d.\n", current_floor);
            continue;
        } else {
            printf("Going to floor %d...\n", destination);
            elevator_action = destination > current_floor ? 1 : -1;
        }

        while (current_floor != destination) {
            current_floor += direction;
            printf("Passing floor %d.\n", current_floor);
        }

        printf("Arriving at floor %d.\n", current_floor);

        if (!door_open) {
            printf("Doors opening...\n");
            door_open = true;
        }

        printf("Doors closing...\n");
        door_open = false;
    }

    return 0;
}