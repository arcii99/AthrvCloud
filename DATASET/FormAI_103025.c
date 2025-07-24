//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the max and min speed of the RC car
#define MAX_SPEED 100
#define MIN_SPEED 0

int main() {
    int speed = 0;
    char direction;
    srand(time(NULL));

    printf("Welcome to the RC car simulator!\n");

    while(1) {
        printf("Current speed: %d\n", speed);
        printf("Enter direction (F/B): ");
        scanf(" %c", &direction);
        
        // Generate a random speed increase/decrease
        int speed_change = rand() % 10;
        
        // Determine direction and update the speed accordingly
        if (direction == 'F') {
            speed += speed_change;
        } else if (direction == 'B') {
            speed -= speed_change;
        } else {
            printf("Invalid direction. Try again.\n");
            continue;
        }

        // Ensure speed remains within limits
        if (speed > MAX_SPEED) {
            speed = MAX_SPEED;
        } else if (speed < MIN_SPEED) {
            speed = MIN_SPEED;
        }

        // Output current speed and direction
        printf("Current speed: %d, Direction: %c\n", speed, direction);
    }

    return 0;
}