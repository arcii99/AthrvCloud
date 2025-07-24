//FormAI DATASET v1.0 Category: Robot movement control ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set the seed for random number generation
    srand(time(0));

    // Initialize variables to store the robot's position and speed
    int x_pos = rand()%101;
    int y_pos = rand()%101;
    int speed = rand()%11;

    // Print the initial position and speed
    printf("Initial position: (%d, %d)\n", x_pos, y_pos);
    printf("Speed: %d\n", speed);

    // Move the robot randomly until it reaches the edge of the grid
    while(x_pos > 0 && x_pos < 100 && y_pos > 0 && y_pos < 100) {
        // Generate a random direction to move in
        int direction = rand()%4;

        // Update the robot's position based on the chosen direction and speed
        switch(direction) {
            case 0: // Move up
                y_pos += speed;
                break;
            case 1: // Move down
                y_pos -= speed;
                break;
            case 2: // Move left
                x_pos -= speed;
                break;
            case 3: // Move right
                x_pos += speed;
                break;
        }

        // Print the new position
        printf("New position: (%d, %d)\n", x_pos, y_pos);
    }

    // Display a message when the robot reaches the edge of the grid
    printf("Robot has reached the edge of the grid!\n");

    return 0;
}