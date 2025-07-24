//FormAI DATASET v1.0 Category: Robot movement control ; Style: safe
#include <stdio.h>

/* Movement control function */
void moveRobot(int speed, int direction) {
    /* Code to control robot movement */
    printf("Robot is moving at speed %d in direction %d.\n", speed, direction);
}

int main() {
    int robotSpeed = 0;
    int robotDirection = 0;

    printf("Welcome to Robot Control System.\n");
    printf("Please enter the speed of the robot (0-100): ");
    scanf("%d", &robotSpeed);

    /* Check if user input is valid */
    if (robotSpeed < 0 || robotSpeed > 100) {
        printf("Invalid input. Robot speed should be between 0 and 100.\n");
        return 1;
    }

    printf("Please enter the direction of the robot (0-360): ");
    scanf("%d", &robotDirection);

    /* Check if user input is valid */
    if (robotDirection < 0 || robotDirection > 360) {
        printf("Invalid input. Robot direction should be between 0 and 360.\n");
        return 1;
    }

    /* Control robot movement */
    moveRobot(robotSpeed, robotDirection);

    return 0;
}