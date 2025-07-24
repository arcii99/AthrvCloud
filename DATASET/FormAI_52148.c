//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

#define MAX_FLOOR 10
#define MIN_FLOOR 1

void displayStatus(int currentFloor, int destFloor) { // Display Elevator Status
    printf("\nElevator is at floor %d, moving to floor %d\n", currentFloor, destFloor);
}

int main() {
    int currentFloor, destFloor, floorsCount;
    char option;
    printf("Welcome to the shape-shifting Elevator Simulation!\n\n");
    printf("Enter current floor of the Elevator (%d-%d): ", MIN_FLOOR, MAX_FLOOR);
    scanf("%d", &currentFloor);
    printf("Enter destination floor of the Elevator (%d-%d): ", MIN_FLOOR, MAX_FLOOR);
    scanf("%d", &destFloor);
    if(currentFloor<MIN_FLOOR || currentFloor>MAX_FLOOR || destFloor<MIN_FLOOR || destFloor>MAX_FLOOR || currentFloor==destFloor) { // Validate Input
        printf("Invalid Input! Please Try Again.");
        return 0;
    }
    if(currentFloor<destFloor) { // Elevator Moving Upwards
        printf("\nElevator is moving up from floor %d to floor %d.", currentFloor, destFloor);
        for(floorsCount=currentFloor; floorsCount<=destFloor; floorsCount++) { // Loop till Elevator reaches Destination
            displayStatus(floorsCount, destFloor);
            if(floorsCount==4 || floorsCount==9) { // Shape-Shifting Feature at Floor 4 and Floor 9
                printf("Elevator is taking a different shape...Please hold on!\n");
                printf("Elevator is now a Vintage Car....Beep-Beep!\n");
            }
        }
        printf("\nElevator has reached the destination floor %d.\n", destFloor); // Destination Reached
    }
    else { // Elevator Moving Downwards
        printf("\nElevator is moving down from floor %d to floor %d.", currentFloor, destFloor);
        for(floorsCount=currentFloor; floorsCount>=destFloor; floorsCount--) { // Loop till Elevator reaches Destination
            displayStatus(floorsCount, destFloor);
            if(floorsCount==5 || floorsCount==2) { // Shape-Shifting Feature at Floor 5 and Floor 2
                printf("Elevator is taking a different shape...Please hold on!\n");
                printf("Elevator is now a Spaceship....Blast-Off!\n");
            }
        }
        printf("\nElevator has reached the destination floor %d.\n", destFloor); // Destination Reached
    }
    printf("\nThank you for using the Shape-Shifting Elevator Simulation!\n");
    printf("Press Enter to Exit.");
    getchar(); // Wait for User Input to Exit
    return 0;
}