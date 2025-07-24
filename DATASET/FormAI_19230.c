//FormAI DATASET v1.0 Category: Robot movement control ; Style: shape shifting
#include <stdio.h>

int main() {

    int shape = 0; // starting shape is the first shape
    int direction = 1; // starting direction is forward

    // loop until shape 3 is reached
    while (shape < 3) {

        if (shape == 0) {
            printf("I am a square, moving ");
        } else if (shape == 1) {
            printf("I am a triangle, moving ");
        } else if (shape == 2) {
            printf("I am a circle, moving ");
        }

        if (direction == 1) {
            printf("forward.\n");
        } else {
            printf("backward.\n");
        }

        // switch direction when reaching the end of the line
        if (direction == 1 && shape == 2) {
            direction = -1;
        } else if (direction == -1 && shape == 0) {
            direction = 1;
        }

        // increase or decrease shape depending on direction
        shape += direction;
    }

    printf("I have achieved my final form!");

    return 0;
}