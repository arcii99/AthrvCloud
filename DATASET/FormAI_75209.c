//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {
    int speed = 0, direction = 0;
    printf("Welcome to the remote control vehicle simulation!\n");
    printf("Please select the initial speed (0-100): ");
    scanf("%d", &speed);
    printf("Please select the initial direction (0-359): ");
    scanf("%d", &direction);
    printf("Starting vehicle simulation with initial speed of %d and direction of %d\n", speed, direction);

    while (1) {
        char control;
        printf("\nPlease select a control (f - forward, b - backward, l - left, r - right, q - quit): ");
        scanf(" %c", &control);

        switch (control) {
            case 'f':
                printf("Moving forward...\n");
                break;
            case 'b':
                printf("Moving backward...\n");
                break;
            case 'l':
                printf("Turning left...\n");
                direction = (direction - 10) % 360;
                break;
            case 'r':
                printf("Turning right...\n");
                direction = (direction + 10) % 360;
                break;
            case 'q':
                printf("Quitting simulation...\n");
                exit(0);
            default:
                printf("Invalid control selected. Please try again.\n");
                continue;
        }

        printf("Current speed: %d\n", speed);
        printf("Current direction: %d\n", direction);
    }
}