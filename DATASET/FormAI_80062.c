//FormAI DATASET v1.0 Category: Robot movement control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEFT 0
#define RIGHT 1

int main() {
    int movement[50];
    int current_position = 0;
    bool facing_direction = RIGHT;

    printf("Enter a sequence of robot movements, separated by spaces: ");
    for (int i = 0; i < 50; i++) {
        scanf("%d", &movement[i]);
        if (movement[i] == 0) break;
    }

    for (int i = 0; i < 50; i++) {
        if (movement[i] == 0) break;

        // Move left or right according to the current facing direction
        if (facing_direction == LEFT) {
            current_position -= movement[i];
        } else {
            current_position += movement[i];
        }

        // Change facing direction if necessary
        if (current_position < 0) {
            current_position = abs(current_position);
            facing_direction = RIGHT;
        } else if (current_position > 9) {
            current_position = 9 - (current_position % 10);
            facing_direction = LEFT;
        }
    }

    printf("The robot ended at position %d\n", current_position);
    return 0;
}