//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x = 0;
    int y = 0;
    int speed = 0; // The speed of the remote control vehicle
    int direction = 0; // The direction of the remote control vehicle
    int battery = 100; // The charge of the battery

    printf("Welcome to the Remote Control Vehicle Simulator\n");
    printf("Use the w, a, s, and d keys to move the vehicle, and q to quit.\n");

    while (1) {
        printf("Coordinates: (%d,%d) | Speed: %d | Battery: %d\n", x, y, speed, battery);

        char input = getchar(); // Read the user's input

        switch (input) {
            case 'w':
                y += speed;
                break;
            case 'a':
                x -= speed;
                break;
            case 's':
                y -= speed;
                break;
            case 'd':
                x += speed;
                break;
            case 'q':
                printf("Goodbye!\n");
                exit(0);
            default:
                break;
        }

        // Update the direction based on the current coordinates
        if (x > 0 && y > 0) {
            direction = 1;
        } else if (x < 0 && y > 0) {
            direction = 2;
        } else if (x < 0 && y < 0) {
            direction = 3;
        } else if (x > 0 && y < 0) {
            direction = 4;
        }

        // Update the speed based on the battery charge
        if (battery >= 75) {
            speed = 10;
        } else if (battery >= 50) {
            speed = 7;
        } else if (battery >= 25) {
            speed = 5;
        } else {
            speed = 3;
        }

        // Decrease the battery charge by a random amount
        battery -= rand() % 5;

        // Make sure the battery charge is not negative
        if (battery < 0) {
            battery = 0;
        }
    }

    return 0;
}