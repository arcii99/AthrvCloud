//FormAI DATASET v1.0 Category: Robot movement control ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random direction of movement
int generateDirection() {
    time_t t;
    srand((unsigned) time(&t));
    return rand() % 4;
}

int main() {
    int x = 0; // Robot's x-coordinate
    int y = 0; // Robot's y-coordinate

    printf("Initial position: (%d, %d)\n", x, y);

    while(1) { // continue moving until stopped
        int direction = generateDirection(); // generate random direction
        switch(direction) {
            case 0: // move up
                y++;
                printf("Moved up. Current position: (%d, %d)\n", x, y);
                break;
            case 1: // move right
                x++;
                printf("Moved right. Current position: (%d, %d)\n", x, y);
                break;
            case 2: // move down
                y--;
                printf("Moved down. Current position: (%d, %d)\n", x, y);
                break;
            case 3: // move left
                x--;
                printf("Moved left. Current position: (%d, %d)\n", x, y);
                break;
            default:
                printf("Invalid direction generated. Stopping movement.\n");
                return 0;
        }
    }

    return 0;
}