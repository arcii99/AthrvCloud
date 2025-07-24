//FormAI DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x = 0; // Robot's starting x position
    int y = 0; // Robot's starting y position
    int steps = 0; // Number of steps taken by robot
    int dir = 0; // Direction robot moves in (0 = up, 1 = right, 2 = down, 3 = left)
    
    srand(time(NULL)); // Seed random number generator with current time
    
    // Loop until robot reaches goal position at (10, 10)
    while (x != 10 || y != 10) {
        // Print current position of robot
        printf("Robot is at (%d, %d)\n", x, y);
        steps++;
        
        // Determine random direction for robot to move in
        int rand_dir = rand() % 4;
        
        // Update direction of robot
        if (rand_dir != dir) {
            dir = rand_dir;
        }
        
        // Move robot one step in chosen direction
        switch (dir) {
            case 0: // Up
                y++;
                break;
            case 1: // Right
                x++;
                break;
            case 2: // Down
                y--;
                break;
            case 3: // Left
                x--;
                break;
        }
    }
    
    // Print final position of robot and number of steps taken
    printf("Robot has reached goal position at (%d, %d)\n", x, y);
    printf("Robot took %d steps\n", steps);
    
    return 0;
}