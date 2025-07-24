//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100

int main() {
    int speed = 0;
    char command;

    printf("Welcome to the C Drone Remote Control Program!\n\n");

    while (1) {
        printf("Current speed: %d\nEnter command (+, -, q): ", speed);
        scanf(" %c", &command);

        switch (command) {
            case '+':
                if (speed < MAX_SPEED) {
                    speed += 10;
                    printf("Speed is now %d\n", speed);
                } else {
                    printf("Max speed reached!\n");
                }
                break;
            case '-':
                if (speed > 0) {
                    speed -= 10;
                    printf("Speed is now %d\n", speed);
                } else {
                    printf("Min speed reached!\n");
                }
                break;
            case 'q':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid command!\n");
        }
    }

    return 0;
}