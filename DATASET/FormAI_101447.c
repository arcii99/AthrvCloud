//FormAI DATASET v1.0 Category: Robot movement control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

int main() {
    int x = 0, y = 0; // initial position of the robot
    int direction = RIGHT; // initial direction

    printf("Robot starts at position (%d, %d) facing RIGHT\n", x, y);

    // move forward 5 steps
    for (int i = 0; i < 5; i++) {
        switch (direction) {
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
            default: // invalid direction
                printf("Error: invalid direction\n");
                exit(1);
        }
        printf("Robot moves forward 1 step to position (%d, %d)\n", x, y);
    }

    // turn left and move forward 3 steps
    direction = UP;
    printf("Robot turns left and faces UP\n");
    for (int i = 0; i < 3; i++) {
        switch (direction) {
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
            default: // invalid direction
                printf("Error: invalid direction\n");
                exit(1);
        }
        printf("Robot moves forward 1 step to position (%d, %d)\n", x, y);
    }

    // turn right and move forward 2 steps
    direction = RIGHT;
    printf("Robot turns right and faces RIGHT\n");
    for (int i = 0; i < 2; i++) {
        switch (direction) {
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
            default: // invalid direction
                printf("Error: invalid direction\n");
                exit(1);
        }
        printf("Robot moves forward 1 step to position (%d, %d)\n", x, y);
    }

    // turn around and move forward 4 steps
    direction = DOWN;
    printf("Robot turns around and faces DOWN\n");
    for (int i = 0; i < 4; i++) {
        switch (direction) {
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
            default: // invalid direction
                printf("Error: invalid direction\n");
                exit(1);
        }
        printf("Robot moves forward 1 step to position (%d, %d)\n", x, y);
    }

    printf("Robot reaches the destination at position (%d, %d)\n", x, y);

    return 0;
}