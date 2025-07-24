//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: creative
#include <stdio.h>

#define MAX_SPEED 50
#define MIN_SPEED 0

int main() {
    int speed = 0;
    char command;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");

    while(1) {
        printf("\nEnter a command (w = forward, s = backward, a = left, d = right, x = stop): ");
        scanf(" %c", &command);

        if(command == 'w') {
            printf("Moving forward...\n");
            speed++;
            if(speed > MAX_SPEED) {
                speed = MAX_SPEED;
            } else {
                printf("Current Speed: %d\n", speed);
            }
        } else if(command == 's') {
            printf("Moving backward...\n");
            speed--;
            if(speed < MIN_SPEED) {
                speed = MIN_SPEED;
            } else {
                printf("Current Speed: %d\n", speed);
            }
        } else if(command == 'a') {
            printf("Turning left...\n");
        } else if(command == 'd') {
            printf("Turning right...\n");
        } else if(command == 'x') {
            printf("Stopping...\n");
            speed = 0;
        } else {
            printf("Invalid command! Please enter a valid command.\n");
        }
    }

    return 0;
}