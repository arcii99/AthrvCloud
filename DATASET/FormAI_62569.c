//FormAI DATASET v1.0 Category: Robot movement control ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

//function to recursively move robot
void moveRobot(int steps) {
    //base case: if steps=0, stop moving
    if(steps <= 0)
        return;
    //move forward
    printf("Robot moved forward one step.\n");
    //recursive call to keep moving
    moveRobot(steps-1);
    //move backward
    printf("Robot moved backward one step.\n");
}

int main() {
    int steps;
    printf("Enter the number of steps for the robot to move: ");
    scanf("%d", &steps);
    //call recursive function to move robot
    moveRobot(steps);
    return 0;
}