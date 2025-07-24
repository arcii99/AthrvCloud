//FormAI DATASET v1.0 Category: Robot movement control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    int x = 0; // initial x position
    int y = 0; // initial y position

    printf("Robot starting at position (%d,%d)\n", x, y);
    printf("---------------------------------\n");

    for (int i = 0; i < 50; i++) {
        int move_direction = rand() % 4; // generate a random number from 0-3 to determine direction

        if (move_direction == 0) { // move up
            y++;
            printf("Robot moves up to position (%d,%d)\n", x, y);
        } else if (move_direction == 1) { // move down
            y--;
            printf("Robot moves down to position (%d,%d)\n", x, y);
        } else if (move_direction == 2) { // move right
            x++;
            printf("Robot moves right to position (%d,%d)\n", x, y);
        } else if (move_direction == 3) { // move left
            x--;
            printf("Robot moves left to position (%d,%d)\n", x, y);
        }

        // check if robot has gone out of bounds
        if (x < -10 || x > 10 || y < -10 || y > 10) {
            printf("Robot has gone out of bounds and needs to be reset.\n");
            x = 0;
            y = 0;
            printf("Robot is reset to position (%d,%d)\n", x, y);
        }

        printf("---------------------------------\n");
    }

    printf("Robot reached the end of the program.\n");

    return 0;
}