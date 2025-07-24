//FormAI DATASET v1.0 Category: Robot movement control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    // Initialize random seed
    srand(time(NULL));
    
    // Initialize starting position
    int x = 0;
    int y = 0;
    
    printf("Starting position: (%d,%d)\n", x, y);
    
    // Generate random movements
    for (int i = 0; i < 10; i++) {
        int direction = rand() % 4;
        int distance = rand() % 10 + 1;
        
        // Move robot depending on direction
        switch(direction) {
            case 0:
                x += distance;
                printf("Moved %d units to the right.\n", distance);
                break;
            case 1:
                x -= distance;
                printf("Moved %d units to the left.\n", distance);
                break;
            case 2:
                y += distance;
                printf("Moved %d units up.\n", distance);
                break;
            case 3:
                y -= distance;
                printf("Moved %d units down.\n", distance);
                break;
            default:
                printf("Invalid direction.\n");
        }
        
        printf("Current position: (%d,%d)\n", x, y);
    }
    
    printf("Final position: (%d,%d)\n", x, y);
    
    return 0;
}