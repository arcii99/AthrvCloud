//FormAI DATASET v1.0 Category: Robot movement control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Define robot movement commands
#define LEFT 'L'
#define RIGHT 'R'
#define FORWARD 'F'
#define BACKWARD 'B'
#define TURN_LEFT 'T'
#define TURN_RIGHT 'U'

// Define robot types
#define FIRST_ROBOT 1
#define SECOND_ROBOT 2

// Define robot state types
#define IDLE 0
#define MOVING 1
#define TURNING 2

// Define robot movement constants
#define MIN_DISTANCE 1
#define MAX_DISTANCE 10
#define MIN_TURN_ANGLE 5
#define MAX_TURN_ANGLE 90

// Define robot state variables
bool first_robot_idle = true;
bool second_robot_idle = true;

// Define robot movement functions
void move_forward(int robot_type, int distance);
void move_backward(int robot_type, int distance);
void turn_left(int robot_type, int angle);
void turn_right(int robot_type, int angle);

// Define main function to test robot movements
int main() {
    srand(time(NULL)); // Seed random number generator
    int robot_type = random()%2 + 1; // Select random robot type
    int state = IDLE; // Initialize robot state to idle
    int command_count = 0; // Initialize command count to 0
    printf("Selected robot type: %d\n", robot_type);
    while (command_count < 20) { // Execute 20 random movement commands
        int distance = random()%(MAX_DISTANCE - MIN_DISTANCE + 1) + MIN_DISTANCE;
        int angle = random()%(MAX_TURN_ANGLE - MIN_TURN_ANGLE + 1) + MIN_TURN_ANGLE;
        char command = random()%6 + 'A'; // Generate random movement command
        switch (command) { // Execute corresponding movement function
            case LEFT:
                if (robot_type == FIRST_ROBOT) {
                    if (first_robot_idle) {
                        printf("First robot is not moving, cannot execute command: %c\n", command);
                    }
                    else {
                        state = TURNING;
                        turn_left(robot_type, angle);
                        state = MOVING;
                        move_backward(robot_type, distance);
                        state = TURNING;
                        turn_right(robot_type, angle);
                        state = IDLE;
                    }
                }
                else {
                    if (second_robot_idle) {
                        printf("Second robot is not moving, cannot execute command: %c\n", command);
                    }
                    else {
                        state = TURNING;
                        turn_left(robot_type, angle);
                        state = MOVING;
                        move_forward(robot_type, distance);
                        state = TURNING;
                        turn_right(robot_type, angle);
                        state = IDLE;
                    }
                }
                command_count++;
                break;
            case RIGHT:
                if (robot_type == FIRST_ROBOT) {
                    if (first_robot_idle) {
                        printf("First robot is not moving, cannot execute command: %c\n", command);
                    }
                    else {
                        state = TURNING;
                        turn_right(robot_type, angle);
                        state = MOVING;
                        move_backward(robot_type, distance);
                        state = TURNING;
                        turn_left(robot_type, angle);
                        state = IDLE;
                    }
                }
                else {
                    if (second_robot_idle) {
                        printf("Second robot is not moving, cannot execute command: %c\n", command);
                    }
                    else {
                        state = TURNING;
                        turn_right(robot_type, angle);
                        state = MOVING;
                        move_forward(robot_type, distance);
                        state = TURNING;
                        turn_left(robot_type, angle);
                        state = IDLE;
                    }
                }
                command_count++;
                break;
            case FORWARD:
                if (robot_type == FIRST_ROBOT) {
                    state = MOVING;
                    move_forward(robot_type, distance);
                    state = IDLE;
                    first_robot_idle = false;
                }
                else {
                    state = MOVING;
                    move_backward(robot_type, distance);
                    state = IDLE;
                    second_robot_idle = false;
                }
                command_count++;
                break;
            case BACKWARD:
                if (robot_type == FIRST_ROBOT) {
                    state = MOVING;
                    move_backward(robot_type, distance);
                    state = IDLE;
                    first_robot_idle = false;
                }
                else {
                    state = MOVING;
                    move_forward(robot_type, distance);
                    state = IDLE;
                    second_robot_idle = false;
                }
                command_count++;
                break;
            case TURN_LEFT:
                if (robot_type == FIRST_ROBOT) {
                    state = TURNING;
                    turn_left(robot_type, angle);
                    state = IDLE;
                    first_robot_idle = true;
                }
                else {
                    state = TURNING;
                    turn_right(robot_type, angle);
                    state = IDLE;
                    second_robot_idle = true;
                }
                command_count++;
                break;
            case TURN_RIGHT:
                if (robot_type == FIRST_ROBOT) {
                    state = TURNING;
                    turn_right(robot_type, angle);
                    state = IDLE;
                    first_robot_idle = true;
                }
                else {
                    state = TURNING;
                    turn_left(robot_type, angle);
                    state = IDLE;
                    second_robot_idle = true;
                }
                command_count++;
                break;
            default:
                printf("Unknown command: %c\n", command);
                break;
        }
    }
    printf("Test complete.\n");
    return 0;
}

// Define function to move robot forward
void move_forward(int robot_type, int distance) {
    if (robot_type == FIRST_ROBOT) {
        printf("First robot moves forward %d units.\n", distance);
    }
    else {
        printf("Second robot moves forward %d units.\n", distance);
    }
}

// Define function to move robot backward
void move_backward(int robot_type, int distance) {
    if (robot_type == FIRST_ROBOT) {
        printf("First robot moves backward %d units.\n", distance);
    }
    else {
        printf("Second robot moves backward %d units.\n", distance);
    }
}

// Define function to turn robot left
void turn_left(int robot_type, int angle) {
    if (robot_type == FIRST_ROBOT) {
        printf("First robot turns left %d degrees.\n", angle);
    }
    else {
        printf("Second robot turns right %d degrees.\n", angle);
    }
}

// Define function to turn robot right
void turn_right(int robot_type, int angle) {
    if (robot_type == FIRST_ROBOT) {
        printf("First robot turns right %d degrees.\n", angle);
    }
    else {
        printf("Second robot turns left %d degrees.\n", angle);
    }
}