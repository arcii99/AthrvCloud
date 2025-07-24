//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: medieval
#include <stdio.h>

#define FLOORS 10

int main() {
    int current_floor = 1;
    int destination_floor;
    
    printf("Welcome to the elevator!\n");

    while(1) {
        printf("\nCurrent floor: %d\n", current_floor);
        printf("Enter destination floor (1-%d): ", FLOORS);
        scanf("%d", &destination_floor);
        
        if(destination_floor < 1 || destination_floor > FLOORS) {
            printf("Invalid floor number. Please try again.\n");
            continue;
        }

        printf("Going up...\n");

        while(current_floor < destination_floor) {
            current_floor++;
            printf("Floor %d\n", current_floor);
        }

        printf("You have arrived at floor %d\n", current_floor);
        current_floor = destination_floor;
    }

    return 0;
}