//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: romantic
#include <stdio.h>

int main() {
    int speed = 0;
    char direction = 'N';

    printf("Remote control vehicle simulation program\n");
    printf("Starting speed: %d\n", speed);
    printf("Starting direction: %c\n", direction);

    while (1) {
        printf("Enter a command (speed, direction, exit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "speed") == 0) {
            printf("Enter a speed (0-100): ");
            scanf("%d", &speed);
            printf("Speed set to %d\n", speed);
        } else if (strcmp(command, "direction") == 0) {
            printf("Enter a direction (N/S/E/W): ");
            scanf(" %c", &direction);
            printf("Direction set to %c\n", direction);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program\n");
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}