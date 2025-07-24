//FormAI DATASET v1.0 Category: Robot movement control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

//define robot coordinates
int x_pos = 0;
int y_pos = 0;

// function for moving the robot
void moveRobot(int x_change, int y_change) {

    // update coordinates based on given changes
    x_pos += x_change;
    y_pos += y_change;

    printf("Robot moved to (%d,%d)\n", x_pos, y_pos);
}

int main() {

    //initial position of robot
    printf("Robot is at (0,0)\n");

    // take user input for movement
    int x_change, y_change;
    printf("Enter x movement:");
    scanf("%d", &x_change);
    printf("Enter y movement:");
    scanf("%d", &y_change);

    //move robot with given values
    moveRobot(x_change, y_change);

    return 0;

}