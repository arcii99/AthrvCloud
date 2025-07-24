//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: visionary
#include <stdio.h>

#define DRONE_LIMIT 10

int main() {
    int droneX[DRONE_LIMIT], droneY[DRONE_LIMIT];

    // Initialize drone positions
    for (int i = 0; i < DRONE_LIMIT; i++) {
        droneX[i] = 0;
        droneY[i] = 0;
    }

    printf("--- C Drone Remote Control ---\n");

    while (1) {
        int choice;

        // Display menu options
        printf("\n1. View drone positions\n");
        printf("2. Move a drone\n");
        printf("3. Add a new drone\n");
        printf("4. Quit\n\n");

        // Get user choice
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Display drone positions
                printf("\n--- Drone Positions ---\n");
                for (int i = 0; i < DRONE_LIMIT; i++) {
                    printf("Drone %d - X: %d, Y: %d\n", i + 1, droneX[i], droneY[i]);
                }
                break;

            case 2:
                // Move a drone
                int droneIndex, moveX, moveY;

                // Get drone index and movement values
                printf("\nEnter drone index: ");
                scanf("%d", &droneIndex);
                printf("Enter X movement: ");
                scanf("%d", &moveX);
                printf("Enter Y movement: ");
                scanf("%d", &moveY);

                // Move drone
                droneX[droneIndex - 1] += moveX;
                droneY[droneIndex - 1] += moveY;

                printf("\nMoved drone %d - X: %d, Y: %d\n", droneIndex, droneX[droneIndex - 1], droneY[droneIndex - 1]);
                break;

            case 3:
                // Add a new drone
                int newDroneIndex, newDroneX, newDroneY;

                // Find first empty spot for new drone
                for (int i = 0; i < DRONE_LIMIT; i++) {
                    if (droneX[i] == 0 && droneY[i] == 0) {
                        newDroneIndex = i + 1;
                        break;
                    }
                }

                // Get position for new drone
                printf("\nEnter X position: ");
                scanf("%d", &newDroneX);
                printf("Enter Y position: ");
                scanf("%d", &newDroneY);

                // Add new drone
                droneX[newDroneIndex - 1] = newDroneX;
                droneY[newDroneIndex - 1] = newDroneY;

                printf("\nAdded new drone at index %d - X: %d, Y: %d\n", newDroneIndex, newDroneX, newDroneY);
                break;

            case 4:
                // Quit program
                printf("\nShutting down...\n");
                return 0;

            default:
                // Invalid input
                printf("\nInvalid input. Please try again.\n");
                break;
        }
    }

    return 0;
}