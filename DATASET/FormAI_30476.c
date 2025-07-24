//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>

// function to move the vehicle forward
void moveForward(int speed) {
    printf("Moving forward at speed %d\n", speed);
}

// function to move the vehicle backward
void moveBackward(int speed) {
    printf("Moving backward at speed %d\n", speed);
}

// function to turn the vehicle left
void turnLeft(int angle) {
    printf("Turning left by %d degrees\n", angle);
}

// function to turn the vehicle right
void turnRight(int angle) {
    printf("Turning right by %d degrees\n", angle);
}

int main() {
    char command;
    int speed, angle;

    printf("Welcome to the Remote Control Vehicle Simulation Program!\n");

    // infinite loop to keep taking input from user until the program is stopped
    while(1) {
        printf("Enter command (f: forward, b: backward, l: left, r: right, s: stop): ");
        scanf(" %c", &command);

        switch(command) {
            case 'f':
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                moveForward(speed);
                break;
            
            case 'b':
                printf("Enter speed (1-10): ");
                scanf("%d", &speed);
                moveBackward(speed);
                break;
            
            case 'l':
                printf("Enter angle (1-90): ");
                scanf("%d", &angle);
                turnLeft(angle);
                break;
            
            case 'r':
                printf("Enter angle (1-90): ");
                scanf("%d", &angle);
                turnRight(angle);
                break;
            
            case 's':
                printf("Stopping the vehicle\n");
                return 0;
            
            default:
                printf("Invalid command entered. Please try again.\n");
        }
    }

    return 0;
}