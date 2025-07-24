//FormAI DATASET v1.0 Category: Robot movement control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 20

// Function declarations
int generate_random_number(int min, int max);
void move_forward(int steps);
void turn_left();
void turn_right();

// Main function
int main() {
    int steps_taken = 0;

    printf("Starting robot movement...\n");

    // Randomly generate movement path
    for (int i = 0; i < MAX_STEPS; i++) {
        int direction = generate_random_number(0, 2);
        if (direction == 0) {
            move_forward(1);
            steps_taken++;
        } else if (direction == 1) {
            turn_left();
        } else {
            turn_right();
        }
    }

    printf("Robot movement complete.\n");
    printf("Total steps taken: %d\n", steps_taken);

    return 0;
}

// Generate a random number between min and max (inclusive)
int generate_random_number(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

// Move the robot forward the specified number of steps
void move_forward(int steps) {
    printf("Moving forward %d steps...\n", steps);
}

// Turn the robot left
void turn_left() {
    printf("Turning left...\n");
}

// Turn the robot right
void turn_right() {
    printf("Turning right...\n");
}