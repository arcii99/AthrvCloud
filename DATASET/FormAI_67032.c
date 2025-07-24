//FormAI DATASET v1.0 Category: Robot movement control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the robot's position and direction
    int x = 0, y = 0;
    char direction = 'N';

    // Loop until the robot reaches the end of the room
    while (y < 10) {
        // Generate a random movement for the robot
        int movement = rand() % 3;

        // Update the robot's position and direction based on the movement
        switch (movement) {
            case 0:
                if (direction == 'N') {
                    y++;
                } else if (direction == 'S') {
                    y--;
                } else if (direction == 'E') {
                    x++;
                } else if (direction == 'W') {
                    x--;
                }
                break;
            case 1:
                if (direction == 'N') {
                    direction = 'E';
                } else if (direction == 'S') {
                    direction = 'W';
                } else if (direction == 'E') {
                    direction = 'S';
                } else if (direction == 'W') {
                    direction = 'N';
                }
                break;
            case 2:
                if (direction == 'N') {
                    direction = 'W';
                } else if (direction == 'S') {
                    direction = 'E';
                } else if (direction == 'E') {
                    direction = 'N';
                } else if (direction == 'W') {
                    direction = 'S';
                }
                break;
        }

        // Check if the robot has reached the end of the room
        if (y == 10) {
            printf("Robot has reached the end of the room!\n");
        }

        // Print the robot's current position and direction
        printf("Robot's position: (%d, %d)\n", x, y);
        printf("Robot's direction: %c\n", direction);

        // Wait for a moment before continuing
        sleep(1);
    }

    return 0;
}