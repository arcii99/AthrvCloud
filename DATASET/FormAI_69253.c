//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // Assume the drone is connected and ready to fly
    int connected = 1;

    // Initialize the drone's current coordinates and speed
    float x_pos = 0.0;
    float y_pos = 0.0;
    float z_pos = 0.0;
    float speed = 0.0;

    printf("Welcome to the Futuristic C Drone Remote Control Program!\n");

    while (connected) {
        printf("\nCurrent Coordinates: (%.2f, %.2f, %.2f)\n", x_pos, y_pos, z_pos);
        printf("Current Speed: %.2f m/s\n", speed);

        // Prompt the user for input
        printf("\nChoose an action:\n");
        printf("1. Move Drone\n");
        printf("2. Change Drone Speed\n");
        printf("3. Disconnect Drone and Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Move the drone in a random direction
                int direction = rand() % 6 + 1;

                switch (direction) {
                    case 1:
                        x_pos += 1.0;
                        printf("Moving drone right...\n");
                        break;
                    case 2:
                        x_pos -= 1.0;
                        printf("Moving drone left...\n");
                        break;
                    case 3:
                        y_pos += 1.0;
                        printf("Moving drone up...\n");
                        break;
                    case 4:
                        y_pos -= 1.0;
                        printf("Moving drone down...\n");
                        break;
                    case 5:
                        z_pos += 1.0;
                        printf("Moving drone forward...\n");
                        break;
                    case 6:
                        z_pos -= 1.0;
                        printf("Moving drone backward...\n");
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                // Change the drone's speed to a random value between 0.5-5.0 m/s
                speed = ((float)rand()/(float)(RAND_MAX)) * 4.5 + 0.5;
                printf("Drone speed changed to %.2f m/s\n", speed);
                break;
            case 3:
                // Disconnect the drone and exit the program
                printf("Disconnecting drone...\n");
                connected = 0;
                break;
            default:
                break;
        }
    }

    printf("\nGoodbye! Thanks for using the Futuristic C Drone Remote Control Program.\n");

    return 0;
}