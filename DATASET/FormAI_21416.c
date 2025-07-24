//FormAI DATASET v1.0 Category: Robot movement control ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define Robot Movement Instruction constants */
#define MOVE_FORWARD 1
#define MOVE_BACKWARD 2
#define TURN_LEFT 3
#define TURN_RIGHT 4

/* Define Robot Movement struct */
struct Robot {
    int x_position;
    int y_position;
    int facing_direction;
};

/* Function to execute robot movement instruction */
void execute_instruction(struct Robot *robot, int instruction) {
    switch(instruction) {
        case MOVE_FORWARD:
            switch(robot->facing_direction) {
                case 0: /* North */
                    robot->y_position += 1;
                    break;
                case 1: /* East */
                    robot->x_position += 1;
                    break;
                case 2: /* South */
                    robot->y_position -= 1;
                    break;
                case 3: /* West */
                    robot->x_position -= 1;
                    break;
            }
            break;
        case MOVE_BACKWARD:
            switch(robot->facing_direction) {
                case 0: /* North */
                    robot->y_position -= 1;
                    break;
                case 1: /* East */
                    robot->x_position -= 1;
                    break;
                case 2: /* South */
                    robot->y_position += 1;
                    break;
                case 3: /* West */
                    robot->x_position += 1;
                    break;
            }
            break;
        case TURN_LEFT:
            robot->facing_direction -= 1;
            if(robot->facing_direction < 0) {
                robot->facing_direction = 3;
            }
            break;
        case TURN_RIGHT:
            robot->facing_direction += 1;
            if(robot->facing_direction > 3) {
                robot->facing_direction = 0;
            }
            break;
        default:
            printf("Invalid instruction!\n");
            break;
    }
}

int main() {
    /* Initialize robot */
    struct Robot my_robot;
    my_robot.x_position = 0;
    my_robot.y_position = 0;
    my_robot.facing_direction = 0; /* North-facing */
    
    /* Execute example robot movement instructions */
    execute_instruction(&my_robot, MOVE_FORWARD);
    execute_instruction(&my_robot, TURN_LEFT);
    execute_instruction(&my_robot, MOVE_FORWARD);
    execute_instruction(&my_robot, TURN_RIGHT);
    execute_instruction(&my_robot, MOVE_BACKWARD);
    
    /* Print out final position and direction */
    printf("Final position: (%d, %d)\n", my_robot.x_position, my_robot.y_position);
    switch(my_robot.facing_direction) {
        case 0:
            printf("Facing direction: North\n");
            break;
        case 1:
            printf("Facing direction: East\n");
            break;
        case 2:
            printf("Facing direction: South\n");
            break;
        case 3:
            printf("Facing direction: West\n");
            break;
    }
    
    return 0;
}