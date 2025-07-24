//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: beginner-friendly
#include <stdio.h>

// Function to move the elevator
void move_elevator(int current_floor, int destination_floor) {
    printf("Moving elevator from floor %d to floor %d...\n", current_floor, destination_floor);
    // Simulating the time taken to move the elevator
    for (int i = 0; i < 5; i++) {
        printf("...");
    }
    printf("\nElevator has arrived at floor %d\n", destination_floor);
}

int main() {
    int current_floor = 1;
    int destination_floor;
    char choice;

    do {
        printf("\nCurrent floor: %d\n", current_floor);
        printf("Select destination floor (1-10): ");
        scanf("%d", &destination_floor);

        // Checking if the destination floor is within range
        if (destination_floor < 1 || destination_floor > 10) {
            printf("Invalid floor selected!\n");
            continue;
        }

        // Moving the elevator
        move_elevator(current_floor, destination_floor);

        // Updating the current floor to the destination floor
        current_floor = destination_floor;

        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    printf("Elevator simulation ended.\n");

    return 0;
}