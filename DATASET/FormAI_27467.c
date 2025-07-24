//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Linus Torvalds
#include <stdio.h>

enum Direction {
    STOP,
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

void move(enum Direction dir) {
    switch (dir) {
        case STOP:
            printf("Vehicle stopped.\n");
            break;
        case FORWARD:
            printf("Vehicle moving forward.\n");
            break;
        case BACKWARD:
            printf("Vehicle moving backward.\n");
            break;
        case LEFT:
            printf("Vehicle turning left.\n");
            break;
        case RIGHT:
            printf("Vehicle turning right.\n");
            break;
        default:
            printf("Invalid direction.\n");
    }
}

int main() {
    printf("Press 'w' to move forward.\n");
    printf("Press 's' to move backward.\n");
    printf("Press 'a' to turn left.\n");
    printf("Press 'd' to turn right.\n");
    printf("Press 'x' to stop.\n");

    char input;
    enum Direction dir = STOP;

    do {
        input = getchar();

        switch (input) {
            case 'w':
                dir = FORWARD;
                break;
            case 's':
                dir = BACKWARD;
                break;
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'x':
                dir = STOP;
                break;
            default:
                dir = STOP;
        }

        move(dir);
    } while (input != 'q');

    printf("Exiting program...\n");

    return 0;
}