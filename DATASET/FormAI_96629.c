//FormAI DATASET v1.0 Category: Robot movement control ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_MOVEMENTS 100

void move_forward(int steps);
void move_backward(int steps);
void turn_left(int degrees);
void turn_right(int degrees);

int main() {
    srand(time(NULL)); // seed random number generator with current time
    
    int movements[MAX_MOVEMENTS];
    int num_movements = 0;
    
    // generate some random movements
    for (int i = 0; i < MAX_MOVEMENTS; i++) {
        movements[i] = rand() % 4; // 0 = forward, 1 = backward, 2 = left, 3 = right
        num_movements++;
    }
    
    // execute movements
    for (int i = 0; i < num_movements; i++) {
        switch (movements[i]) {
            case 0:
                move_forward(10);
                break;
            case 1:
                move_backward(10);
                break;
            case 2:
                turn_left(90);
                break;
            case 3:
                turn_right(90);
                break;
        }
    }
    
    return 0;
}

void move_forward(int steps) {
    printf("Moving forward %d steps...\n", steps);
    // implementation of movement goes here
    usleep(500000); // pause for half a second to simulate movement
}

void move_backward(int steps) {
    printf("Moving backward %d steps...\n", steps);
    // implementation of movement goes here
    usleep(500000); // pause for half a second to simulate movement
}

void turn_left(int degrees) {
    printf("Turning left %d degrees...\n", degrees);
    // implementation of movement goes here
    usleep(500000); // pause for half a second to simulate movement
}

void turn_right(int degrees) {
    printf("Turning right %d degrees...\n", degrees);
    // implementation of movement goes here
    usleep(500000); // pause for half a second to simulate movement
}