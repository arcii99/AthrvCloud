//FormAI DATASET v1.0 Category: Robot movement control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT -2

typedef struct robot {
    int x;
    int y;
    int direction;
} Robot;

void move_robot(Robot *robot, int distance) {
    switch(robot->direction) {
        case FORWARD:
            robot->y += distance;
            break;
        case BACKWARD:
            robot->y -= distance;
            break;
        case LEFT:
            robot->x -= distance;
            break;
        case RIGHT:
            robot->x += distance;
            break;
        default:
            printf("Unknown direction\n");
            break;
    }
}

void turn_robot(Robot *robot, int direction) {
    switch(robot->direction) {
        case FORWARD:
            if(direction == LEFT) {
                robot->direction = LEFT;
            } else if(direction == RIGHT) {
                robot->direction = RIGHT;
            }
            break;
        case BACKWARD:
            if(direction == LEFT) {
                robot->direction = RIGHT;
            } else if(direction == RIGHT) {
                robot->direction = LEFT;
            }
            break;
        case LEFT:
            if(direction == LEFT) {
                robot->direction = BACKWARD;
            } else if(direction == RIGHT) {
                robot->direction = FORWARD;
            }
            break;
        case RIGHT:
            if(direction == LEFT) {
                robot->direction = FORWARD;
            } else if(direction == RIGHT) {
                robot->direction = BACKWARD;
            }
            break;
        default:
            printf("Unknown direction\n");
            break;
    }
}

int main() {
    Robot robot = {0, 0, FORWARD};
    move_robot(&robot, 5);
    turn_robot(&robot, LEFT);
    move_robot(&robot, 3);
    turn_robot(&robot, RIGHT);
    move_robot(&robot, 2);
    turn_robot(&robot, RIGHT);
    move_robot(&robot, 1);
    printf("New position: (%d, %d) facing ", robot.x, robot.y);
    switch(robot.direction) {
        case FORWARD:
            printf("FORWARD\n");
            break;
        case BACKWARD:
            printf("BACKWARD\n");
            break;
        case LEFT:
            printf("LEFT\n");
            break;
        case RIGHT:
            printf("RIGHT\n");
            break;
        default:
            printf("Unknown direction\n");
            break;
    }
    return 0;
}