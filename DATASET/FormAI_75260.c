//FormAI DATASET v1.0 Category: Robot movement control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// struct to hold the state of the robot
typedef struct {
    int x, y; // coordinates
    char dir; // direction (N, S, E, W)
} RobotState;

RobotState current_state = {0, 0, 'N'}; // set initial state to (0, 0, N)

// function to move the robot one step forward
void move_robot() {
    switch (current_state.dir) {
        case 'N':
            current_state.y++;
            break;
        case 'S':
            current_state.y--;
            break;
        case 'E':
            current_state.x++;
            break;
        case 'W':
            current_state.x--;
            break;
    }

    printf("Moved one step forward.\n");
    printf("Current position: (%d, %d)\n", current_state.x, current_state.y);
}

// function to turn the robot left
void turn_left() {
    switch (current_state.dir) {
        case 'N':
            current_state.dir = 'W';
            break;
        case 'S':
            current_state.dir = 'E';
            break;
        case 'E':
            current_state.dir = 'N';
            break;
        case 'W':
            current_state.dir = 'S';
            break;
    }

    printf("Turned left.\n");
    printf("Current direction: %c\n", current_state.dir);
}

// function to turn the robot right
void turn_right() {
    switch (current_state.dir) {
        case 'N':
            current_state.dir = 'E';
            break;
        case 'S':
            current_state.dir = 'W';
            break;
        case 'E':
            current_state.dir = 'S';
            break;
        case 'W':
            current_state.dir = 'N';
            break;
    }

    printf("Turned right.\n");
    printf("Current direction: %c\n", current_state.dir);
}

// function to control the robot's movements
void* control_robot(void* arg) {
    char* movements = (char*) arg;
    int i = 0;

    while (movements[i] != '\0') {
        switch (movements[i]) {
            case 'F':
                move_robot();
                break;
            case 'L':
                turn_left();
                break;
            case 'R':
                turn_right();
                break;
            default:
                printf("Invalid movement: %c\n", movements[i]);
                break;
        }

        i++;
    }

    return NULL;
}

int main() {
    pthread_t thread_id;
    char movements[] = "FFRFLLRFFFRFRF"; // a sequence of movements for the robot

    if (pthread_create(&thread_id, NULL, &control_robot, movements) != 0) {
        printf("Error creating thread.\n");
        exit(EXIT_FAILURE);
    }

    pthread_join(thread_id, NULL); // wait for the thread to finish

    printf("Final position: (%d, %d)\n", current_state.x, current_state.y);
    printf("Final direction: %c\n", current_state.dir);

    return 0;
}