//FormAI DATASET v1.0 Category: Robot movement control ; Style: standalone
#include <stdio.h>

int main() {
    int robotXPos = 0;
    int robotYPos = 0;

    printf("Welcome to the Robot Control Program!\n");
    printf("Move the robot by entering the distance in the X and Y directions.\n");

    while (1) {
        int distX, distY;
        printf("Distance in X direction: ");
        scanf("%d", &distX);

        printf("Distance in Y direction: ");
        scanf("%d", &distY);

        robotXPos += distX;
        robotYPos += distY;

        if (robotXPos > 10 || robotXPos < -10 || robotYPos > 10 || robotYPos < -10) {
            printf("Robot has moved out of bounds! Stopping...\n");
            break;
        }

        printf("Robot has moved to (%d, %d)\n", robotXPos, robotYPos);
    }

    return 0;
}