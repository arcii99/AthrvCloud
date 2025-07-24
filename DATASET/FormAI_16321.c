//FormAI DATASET v1.0 Category: Robot movement control ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random movement
int random_movement(int current_position) {
    int movement = rand() % 2;
    int new_position = current_position + movement;
    if (new_position >= 0 && new_position <= 10) {
        return new_position;
    } else {
        return random_movement(current_position);
    }
}

// Function to display the current position and movement
void display(int current_position, int movement) {
    printf("Current Position: %d\n", current_position);
    if (movement == 0) {
        printf("Movement: Left\n");
    } else {
        printf("Movement: Right\n");
    }
}

int main() {
    srand(time(0)); // Initialize random seed

    int current_position = 5;
    int iterations = 50;

    for (int i = 0; i < iterations; i++) {
        int movement = random_movement(current_position);
        display(current_position, movement);
        current_position = movement;
    }

    return 0;
}