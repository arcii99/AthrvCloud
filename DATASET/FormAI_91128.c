//FormAI DATASET v1.0 Category: Robot movement control ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT 1
#define RIGHT 2
#define FORWARD 3
#define BACKWARD 4

int main()
{
    int x = 0; // starting position
    int y = 0; // starting position
    int direction; // current direction

    srand(time(NULL)); // seed random number generator

    while(1) {
        // choose a random direction to move in
        direction = rand() % 4 + 1;

        switch(direction) {
            case LEFT:
                printf("Moving left\n");
                x--;
                break;
            case RIGHT:
                printf("Moving right\n");
                x++;
                break;
            case FORWARD:
                printf("Moving forward\n");
                y++;
                break;
            case BACKWARD:
                printf("Moving backward\n");
                y--;
                break;
        }

        // display current position
        printf("Current position: (%d, %d)\n", x, y);

        // wait for 1 second
        sleep(1);
    }

    return 0;
}