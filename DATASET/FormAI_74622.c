//FormAI DATASET v1.0 Category: Robot movement control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define robot structure
struct Robot {
    int x, y;
    char direction;
};

// Declare functions
void moveForward(struct Robot *robot);
void turnLeft(struct Robot *robot);
void turnRight(struct Robot *robot);

int main() {
    struct Robot robot = {0, 0, 'N'};
    char input[100];

    printf("Enter instructions for robot movement:\n");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; input[i] != '\n'; i++) {
        switch (input[i]) {
            case 'F':
                moveForward(&robot);
                break;
            case 'L':
                turnLeft(&robot);
                break;
            case 'R':
                turnRight(&robot);
                break;
            default:
                printf("Invalid input. Robot did not move.\n");
        }
    }

    printf("Robot final position: (%d, %d), facing %c\n", robot.x, robot.y, robot.direction);
    return 0;
}

void moveForward(struct Robot *robot) {
    switch (robot->direction) {
        case 'N':
            robot->y++;
            break;
        case 'S':
            robot->y--;
            break;
        case 'E':
            robot->x++;
            break;
        case 'W':
            robot->x--;
            break;
        default:
            printf("Error: invalid direction.\n");
    }
}

void turnLeft(struct Robot *robot) {
    switch (robot->direction) {
        case 'N':
            robot->direction = 'W';
            break;
        case 'S':
            robot->direction = 'E';
            break;
        case 'E':
            robot->direction = 'N';
            break;
        case 'W':
            robot->direction = 'S';
            break;
        default:
            printf("Error: invalid direction.\n");
    }
}

void turnRight(struct Robot *robot) {
    switch (robot->direction) {
        case 'N':
            robot->direction = 'E';
            break;
        case 'S':
            robot->direction = 'W';
            break;
        case 'E':
            robot->direction = 'S';
            break;
        case 'W':
            robot->direction = 'N';
            break;
        default:
            printf("Error: invalid direction.\n");
    }
}