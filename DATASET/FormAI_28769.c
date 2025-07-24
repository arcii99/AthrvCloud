//FormAI DATASET v1.0 Category: Robot movement control ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator
    int i = 0;
    int max_moves = 10; // Max number of moves the robot can make
    int move_count = 0; // Counter for the number of moves the robot has made
    int x_pos = 0; // Current x position of the robot
    int y_pos = 0; // Current y position of the robot
    int direction = 0; // Current direction the robot is facing (0 = North, 1 = East, 2 = South, 3 = West)
    int move_dist = 0; // Distance the robot moves

    while (move_count < max_moves) {
        printf("Move #%d\n", move_count + 1);
        direction = rand() % 4; // Choose a random direction
        move_dist = rand() % 5 + 1; // Choose a random distance to move
        printf("Direction: %d\n", direction);
        printf("Distance: %d\n", move_dist);
        switch (direction) {
            case 0: // Move North
                printf("Moving North...\n");
                y_pos += move_dist;
                break;
            case 1: // Move East
                printf("Moving East...\n");
                x_pos += move_dist;
                break;
            case 2: // Move South
                printf("Moving South...\n");
                y_pos -= move_dist;
                break;
            case 3: // Move West
                printf("Moving West...\n");
                x_pos -= move_dist;
                break;
            default:
                printf("Invalid direction");
                break;
        }
        move_count++;
        printf("Current Position: (%d,%d)\n", x_pos, y_pos);
        printf("-------------------------\n");
    }
    printf("Robot has completed %d moves\n", move_count);
    return 0;
}