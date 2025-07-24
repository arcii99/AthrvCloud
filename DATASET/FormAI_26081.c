//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function to represent the elevator
void elevator(int floor, int dest_floor) {
    printf("Elevator is currently on floor %d\n", floor);
    if (floor < dest_floor) {
        printf("Elevator is going up\n");
        for (int i = floor + 1; i <= dest_floor; i++) {
            printf("Elevator is on floor %d\n", i);
        }
    } else {
        printf("Elevator is going down\n");
        for (int i = floor - 1; i >= dest_floor; i--) {
            printf("Elevator is on floor %d\n", i);
        }
    }
}

int main() {
    int current_floor = 1;
    int dest_floor;
    bool valid_floor = false;
    
    while (!valid_floor) {
        printf("Enter destination floor: ");
        scanf("%d", &dest_floor);
        
        if (dest_floor < 1 || dest_floor > 10) {
            printf("Invalid floor number. Please enter a number between 1 and 10.\n");
        } else {
            valid_floor = true;
        }
    }
    
    elevator(current_floor, dest_floor);

    return 0;
}