//FormAI DATASET v1.0 Category: Robot movement control ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int leftMotorSpeed = 0;
    int rightMotorSpeed = 0;
    char command[50];

    printf("Enter a command to move the robot: \n");
    fgets(command, 50, stdin);

    if(strstr(command, "forward")) {
        leftMotorSpeed = 50;
        rightMotorSpeed = 50;
    } else if(strstr(command, "backward")) {
        leftMotorSpeed = -50;
        rightMotorSpeed = -50;
    } else if(strstr(command, "left")) {
        leftMotorSpeed = -50;
        rightMotorSpeed = 50;
    } else if(strstr(command, "right")) {
        leftMotorSpeed = 50;
        rightMotorSpeed = -50;
    } else {
        printf("Invalid command\n");
    }

    printf("Left motor speed: %d\n", leftMotorSpeed);
    printf("Right motor speed: %d\n", rightMotorSpeed);

    return 0;
}