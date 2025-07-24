//FormAI DATASET v1.0 Category: Robot movement control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This function generates a random number between 0 and max
int generate_random_number(int max) {
    srand(time(NULL));
    return rand() % (max + 1);
}

int main() {
    int x = 0, y = 0;
    int moves = 0;
    int max_x = 8; // Width of the robot's movement area
    int max_y = 8; // Height of the robot's movement area
    int max_moves = 100; // Maximum number of moves the robot can make
    
    printf("Starting position: (%d, %d)\n", x, y);
    
    while (moves < max_moves) {
        int direction = generate_random_number(3); // Generates a random number between 0 and 3
        if (direction == 0 && x < max_x) {
            x++; // Move the robot one unit to the right
        } else if (direction == 1 && y < max_y) {
            y++; // Move the robot one unit up
        } else if (direction == 2 && x > 0) {
            x--; // Move the robot one unit to the left
        } else if (direction == 3 && y > 0) {
            y--; // Move the robot one unit down
        }
        printf("New position: (%d, %d)\n", x, y);
        moves++;
    }
    
    printf("Final position: (%d, %d)\n", x, y);
    
    return 0;
}