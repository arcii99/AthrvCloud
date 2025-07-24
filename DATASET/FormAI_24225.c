//FormAI DATASET v1.0 Category: Robot movement control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int x = 0;
    int y = 0;
    int direction = 0;
    int steps = 0;
    srand(time(NULL)); // initialize random seed
 
    printf("Starting position: x=%d, y=%d\n", x, y);
    
    // loop to make 10 random movements
    for(int i = 0; i < 10; i++) {
        direction = rand() % 4 + 1; // random number between 1 and 4
        steps = rand() % 10 + 1; // random number between 1 and 10
        printf("Movement %d: ", i + 1); // print the movement number
        
        // switch statement to move the robot based on the random direction
        switch(direction) {
            case 1:
                x += steps;
                printf("Move right %d steps to x=%d, y=%d\n", steps, x, y);
                break;
            case 2:
                x -= steps;
                printf("Move left %d steps to x=%d, y=%d\n", steps, x, y);
                break;
            case 3:
                y += steps;
                printf("Move up %d steps to x=%d, y=%d\n", steps, x, y);
                break;
            case 4:
                y -= steps;
                printf("Move down %d steps to x=%d, y=%d\n", steps, x, y);
                break;
            default:
                printf("Error: Invalid direction\n");
        }
    }

    printf("Final position: x=%d, y=%d\n", x, y);

    return 0;
}