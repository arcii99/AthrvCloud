//FormAI DATASET v1.0 Category: Robot movement control ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_X 10
#define MAX_Y 10

struct Robot {
    int x, y; // current position
    int target_x, target_y; // target position
    bool reached_target; 
};

void move(struct Robot* robot) {
    if(robot->x == robot->target_x && robot->y == robot->target_y) {
        robot->reached_target = true;
    } else {
        if(robot->x < robot->target_x) {
            robot->x++;
        } else {
            robot->x--;
        }
        if(robot->y < robot->target_y) {
            robot->y++;
        } else {
            robot->y--;
        }
    }
}

int main() {
    struct Robot robot = {0, 0, 4, 5, false};
    printf("Robot starting at %d, %d\n", robot.x, robot.y);
    while(!robot.reached_target) {
        move(&robot);
        printf("Robot moved to %d, %d\n", robot.x, robot.y);
    }
    printf("Robot reached its destination!\n");
    return 0;
}