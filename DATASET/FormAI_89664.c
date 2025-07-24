//FormAI DATASET v1.0 Category: Robot movement control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main() {
    int input;
    while (1) {
        printf("Enter the direction of the robot movement:\n");
        printf("1: Forward\n2: Backward\n3: Left\n4: Right\n5: Stop\n");
        scanf("%d", &input);
        switch (input) {
            case 1:
                printf("The robot is moving forward\n");
                // Code for moving the robot forward
                break;
            case 2:
                printf("The robot is moving backward\n");
                // Code for moving the robot backward
                break;
            case 3:
                printf("The robot is turning left\n");
                // Code for turning the robot left
                break;
            case 4:
                printf("The robot is turning right\n");
                // Code for turning the robot right
                break;
            case 5:
                printf("Stopping the robot\n");
                // Code for stopping the robot
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}