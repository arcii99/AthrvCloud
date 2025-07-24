//FormAI DATASET v1.0 Category: Robot movement control ; Style: peaceful
#include <stdio.h>

#define STOP 0
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

int currentDirection = STOP;

void moveRobot(int direction) {
    if(currentDirection == direction) {
        printf("Robot is already moving in that direction...\n");
        return;
    }

    currentDirection = direction;

    switch(direction) {
        case STOP:
            printf("Stopping the robot...\n");
            break;
        case FORWARD:
            printf("Robot is moving forward...\n");
            break;
        case BACKWARD:
            printf("Robot is moving backward...\n");
            break;
        case LEFT:
            printf("Robot is turning left...\n");
            break;
        case RIGHT:
            printf("Robot is turning right...\n");
            break;
        default:
            printf("Invalid direction, stopping the robot...\n");
            currentDirection = STOP;
    }
}

int main() {
    char input;

    printf("Welcome to the peaceful robot movement control program!\n");

    do {
        printf("\nWhich direction do you want the robot to move?\n");
        printf("(f)orward, (b)ackward, (l)eft, (r)ight or (s)top: ");

        input = getchar();
        while(getchar() != '\n'); // clear input buffer

        switch(input) {
            case 'f':
                moveRobot(FORWARD);
                break;
            case 'b':
                moveRobot(BACKWARD);
                break;
            case 'l':
                moveRobot(LEFT);
                break;
            case 'r':
                moveRobot(RIGHT);
                break;
            case 's':
                moveRobot(STOP);
                break;
            default:
                printf("Invalid input, please try again...\n");
        }
    } while(input != 's');

    printf("Exiting program, have a peaceful day!\n");
    return 0;
}