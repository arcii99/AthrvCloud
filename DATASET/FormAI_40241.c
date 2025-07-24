//FormAI DATASET v1.0 Category: Robot movement control ; Style: Donald Knuth
/* 

This program controls the movement of a robot using a series of predetermined instructions. 
The instructions include moving forward, turning left, turning right and reversing. 
The robot will execute each instruction in the order they are presented. 

*/

#include <stdio.h>
#include <stdlib.h>

#define FORWARD 'F'
#define LEFT 'L'
#define RIGHT 'R'
#define REVERSE 'B'

typedef struct {
    int x;
    int y;
} Position;

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} Direction;

void move_robot(Direction* direction, Position* position) {
    switch (*direction) {
        case EAST:
            position->x++;
            break;
        case WEST:
            position->x--;
            break;
        case NORTH:
            position->y++;
            break;
        case SOUTH:
            position->y--;
            break;
    }
}

void turn_robot_left(Direction* direction) {
    switch (*direction) {
        case EAST:
            *direction = NORTH;
            break;
        case WEST:
            *direction = SOUTH;
            break;
        case NORTH:
            *direction = WEST;
            break;
        case SOUTH:
            *direction = EAST;
            break;
    }
}

void turn_robot_right(Direction* direction) {
    switch (*direction) {
        case EAST:
            *direction = SOUTH;
            break;
        case WEST:
            *direction = NORTH;
            break;
        case NORTH:
            *direction = EAST;
            break;
        case SOUTH:
            *direction = WEST;
            break;
    }
}

void reverse_robot(Direction* direction, Position* position) {
    switch (*direction) {
        case EAST:
            position->x--;
            break;
        case WEST:
            position->x++;
            break;
        case NORTH:
            position->y--;
            break;
        case SOUTH:
            position->y++;
            break;
    }
}

int main() {
    char* instructions = "FFLRFBBRLFBLFFFFFF"; // Example instructions
    int len = strlen(instructions);
    
    Position position = {0, 0};
    Direction direction = EAST;
    
    for (int i = 0; i < len; i++) {
        switch (instructions[i]) {
            case FORWARD:
                move_robot(&direction, &position);
                break;
            case LEFT:
                turn_robot_left(&direction);
                break;
            case RIGHT:
                turn_robot_right(&direction);
                break;
            case REVERSE:
                reverse_robot(&direction, &position);
                break;
        }
    }
    
    printf("Robot position: (%d, %d)\n", position.x, position.y);
    
    return 0;
}