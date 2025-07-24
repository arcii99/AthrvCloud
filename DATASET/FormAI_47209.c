//FormAI DATASET v1.0 Category: Robot movement control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize random seed
    srand(time(NULL));

    // generate random x and y coordinates
    int x = rand() % 10;
    int y = rand() % 10;
    
    printf("Initial X location: %d\n", x);
    printf("Initial Y location: %d\n", y);
    
    // loop to simulate robot movement
    int i;
    for (i = 0; i < 10; i++) {
        int direction = rand() % 4; // generate random number between 0 and 3 for direction
        switch(direction) {
            case 0: // move up
                if (y > 0) {
                    y--;
                    printf("Robot moves up\n");
                } else {
                    printf("Robot cannot move up any further\n");
                }
                break;
            case 1: // move down
                if (y < 9) {
                    y++;
                    printf("Robot moves down\n");
                } else {
                    printf("Robot cannot move down any further\n");
                }
                break;
            case 2: // move left
                if (x > 0) {
                    x--;
                    printf("Robot moves left\n");
                } else {
                    printf("Robot cannot move left any further\n");
                }
                break;
            case 3: // move right
                if (x < 9) {
                    x++;
                    printf("Robot moves right\n");
                } else {
                    printf("Robot cannot move right any further\n");
                }
                break;
            default:
                printf("error: invalid direction\n");
                exit(1);
        }
        
        // print current location of robot
        printf("Current X location: %d\n", x);
        printf("Current Y location: %d\n", y);
        
        // add random delay between movements
        int delay = rand() % 3;
        printf("Waiting for %d seconds...\n", delay);
        sleep(delay);
    }
    
    printf("Robot has completed its movement program\n");
    return 0;
}