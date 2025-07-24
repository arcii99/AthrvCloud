//FormAI DATASET v1.0 Category: Robot movement control ; Style: scalable
#include <stdio.h>

// define the directions and their numeric values
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// define the robot struct
typedef struct robot {
    int x, y;
    int dir;
} Robot;

// function to move the robot one step forward in its current direction
void move_forward(Robot* bot) {
    switch(bot->dir) {
        case NORTH:
            bot->y++;
            break;
        case EAST:
            bot->x++;
            break;
        case SOUTH:
            bot->y--;
            break;
        case WEST:
            bot->x--;
            break;
    }
}

// function to turn the robot left
void turn_left(Robot* bot) {
    bot->dir = (bot->dir + 3) % 4;
}

// function to turn the robot right
void turn_right(Robot* bot) {
    bot->dir = (bot->dir + 1) % 4;
}

int main(void) {
    // create a new robot at position (0,0) facing north
    Robot myRobot = {0, 0, NORTH};

    // move the robot forward one step and turn it left
    move_forward(&myRobot);
    turn_left(&myRobot);

    // move the robot forward two steps and turn it right
    move_forward(&myRobot);
    move_forward(&myRobot);
    turn_right(&myRobot);

    // print out the final location and direction of the robot
    printf("The robot is located at (%d,%d) facing ", myRobot.x, myRobot.y);
    switch(myRobot.dir) {
        case NORTH:
            printf("north.\n");
            break;
        case EAST:
            printf("east.\n");
            break;
        case SOUTH:
            printf("south.\n");
            break;
        case WEST:
            printf("west.\n");
            break;
    }

    return 0;
}