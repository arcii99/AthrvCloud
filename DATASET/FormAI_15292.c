//FormAI DATASET v1.0 Category: Robot movement control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize variables
    int position = 0;
    int direction = 1;
    int speed = 10;
    int max_position = 1000;
    int min_position = 0;

    // seed random number generator
    srand(time(NULL));

    // loop 10 times to simulate movement
    for (int i = 0; i < 10; i++) {
        // generate random number between 1 and 10
        int move = rand() % 10 + 1;

        // multiply move by speed to get distance
        int distance = move * speed;

        // change position based on direction
        if (direction == 1) {
            position += distance;
        } else {
            position -= distance;
        }

        // check if robot has reached max or min position
        if (position >= max_position) {
            position = max_position;
            direction = -1;
        } else if (position <= min_position) {
            position = min_position;
            direction = 1;
        }

        // print position and direction
        printf("Position: %d, Direction: %s\n", position, direction == 1 ? "Right" : "Left");
    }

    return 0;
}