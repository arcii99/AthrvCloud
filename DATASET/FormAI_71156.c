//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: romantic
#include <stdio.h>

int main() {
    int speed = 0;
    char direction = 'S';
    printf("Welcome to Remote Control Vehicle Simulation!\n");
    printf("Press 'W' to move forward, 'A' to turn left, 'D' to turn right, and 'S' to stop.\n");
    printf("Enter your desired speed (0-5): ");
    scanf("%d", &speed);
    while (1) {
        printf("Current speed: %d\n", speed);
        printf("Current direction: %c\n", direction);
        printf("Enter a command: ");
        scanf(" %c", &direction);
        if (direction == 'W') {
            printf("Moving forward!\n");
        } else if (direction == 'A') {
            printf("Turning left!\n");
        } else if (direction == 'D') {
            printf("Turning right!\n");
        } else if (direction == 'S') {
            printf("Stopping!\n");
        } else {
            printf("Invalid command!\n");
        }
        printf("\n");
    }
    return 0;
}