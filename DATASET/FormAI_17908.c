//FormAI DATASET v1.0 Category: Robot movement control ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int current_direction = NORTH;

void move_forward() {
    printf("Moving forward...\n");
    // Code here for robot to move forward
}

void turn_left() {
    printf("Turning left...\n");
    // Code here for robot to turn left
    if (current_direction == NORTH) {
        current_direction = WEST;
    }
    else {
        current_direction--;
    }
}

void turn_right() {
    printf("Turning right...\n");
    // Code here for robot to turn right
    if (current_direction == WEST) {
        current_direction = NORTH;
    }
    else {
        current_direction++;
    }
}

int main() {
    srand(time(NULL));
    int num_moves = rand() % 25 + 1; // Generates random number of moves between 1 and 25
    printf("Number of moves: %d\n", num_moves);

    for (int i = 0; i < num_moves; i++) {
        int direction = rand() % 3; // Generates random direction between 0 and 3
        printf("Direction: %d\n", direction);
        if (direction == 0) {
            move_forward();
        }
        else if (direction == 1) {
            turn_left();
        }
        else {
            turn_right();
        }
    }

    printf("Final direction: %d\n", current_direction);
    return 0;
}