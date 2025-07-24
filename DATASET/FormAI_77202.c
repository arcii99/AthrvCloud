//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: systematic
#include <stdio.h>

int main() {
    int speed = 0, direction = 0;
    char command;

    printf("Welcome to the Remote Control Vehicle Simulation!\n\n");

    while (1) {
        printf("Enter a command (f for forward, b for backward, l for left, r for right, s for stop): ");
        scanf("%c", &command);

        switch (command) {
            case 'f':
                speed += 10;
                direction = 0;
                break;

            case 'b':
                speed -= 10;
                direction = 0;
                break;

            case 'l':
                direction -= 10;
                break;

            case 'r':
                direction += 10;
                break;

            case 's':
                speed = 0;
                break;

            default:
                printf("Invalid command. Try again.\n");
                continue;
        }

        printf("Speed: %d Direction: %d\n\n", speed, direction);    
        // Here you can add code to control a simulated vehicle using the speed and direction values
    }

    return 0;
}