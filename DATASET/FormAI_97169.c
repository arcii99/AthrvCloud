//FormAI DATASET v1.0 Category: Robot movement control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function to move the robot forward
void move_forward(int robot_position[2], int direction) {
    if (direction == 0) {       // North
        robot_position[1] += 1;
    }
    else if (direction == 1) {  // East
        robot_position[0] += 1;
    }
    else if (direction == 2) {  // South
        robot_position[1] -= 1;
    }
    else {                      // West
        robot_position[0] -= 1;
    }

    printf("Robot moved forward to (%d, %d)\n", robot_position[0], robot_position[1]);
}

// function to turn the robot left
void turn_left(int* direction) {
    *direction -= 1;
    if (*direction < 0) {
        *direction = 3;
    }

    printf("Robot turned left, now facing %d\n", *direction);
}

// function to turn the robot right
void turn_right(int* direction) {
    *direction += 1;
    if (*direction > 3) {
        *direction = 0;
    }

    printf("Robot turned right, now facing %d\n", *direction);
}

int main() {
    int robot_position[2] = {0, 0};  // starting position of robot
    int direction = 0;               // starting direction of robot (North)

    // movement commands for the robot
    char commands[] = {'F', 'F', 'L', 'F', 'R', 'F', 'F', 'L', 'F', 'R', 'F'};

    // execute each command in the commands array
    for (int i = 0; i < sizeof(commands)/sizeof(commands[0]); i++) {
        if (commands[i] == 'F') {
            move_forward(robot_position, direction);
        }
        else if (commands[i] == 'L') {
            turn_left(&direction);
        }
        else if (commands[i] == 'R') {
            turn_right(&direction);
        }
        else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}