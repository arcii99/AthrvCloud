//FormAI DATASET v1.0 Category: Robot movement control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x = 0, y = 0;
    srand(time(NULL)); // seed the random number generator

    for(int i = 0; i < 50; i++) {
        int direction = rand() % 4; // generate a random number between 0 and 3
        // 0 = up, 1 = right, 2 = down, 3 = left

        switch(direction) {
            case 0:
                y++; // move up
                break;
            case 1:
                x++; // move right
                break;
            case 2:
                y--; // move down
                break;
            case 3:
                x--; // move left
                break;
        }

        // check if the robot has gone out of bounds
        if(x < -10 || x > 10 || y < -10 || y > 10) {
            printf("The robot has gone out of bounds!\n");
            break; // exit the loop
        }

        // print the robot's current position
        printf("Robot's current position = (%d, %d)\n", x, y);
    }

    return 0;
}