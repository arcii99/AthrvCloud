//FormAI DATASET v1.0 Category: Robot movement control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Setting up randomization
    srand(time(NULL));

    // Generating random initial coordinates
    int x = rand() % 10;
    int y = rand() % 10;

    // Loop for robot movement
    for(int i = 0; i < 50; i++) {
        printf("Current position: (%d,%d)\n", x, y);
        
        // Generating random movement direction
        int dir = rand() % 4;
        
        // Moving the robot based on direction
        if(dir == 0 && x > 0) {
            x--;
            printf("Moved left!\n");
        }
        else if(dir == 1 && x < 9) {
            x++;
            printf("Moved right!\n");
        }
        else if(dir == 2 && y > 0) {
            y--;
            printf("Moved down!\n");
        }
        else if(dir == 3 && y < 9) {
            y++;
            printf("Moved up!\n");
        }
        else {
            // No movement possible in that direction
            printf("No movement in that direction.\n");
        }
    }
    
    // Final position of the robot
    printf("Final position: (%d,%d)\n", x, y);

    return 0;
}