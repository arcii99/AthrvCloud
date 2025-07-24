//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct vehicle {
    int x_pos;
    int y_pos;
    int speed;
    char direction;
};

void moveForward(struct vehicle* v) {
    switch (v->direction) {
        case 'N':
            v->y_pos += v->speed;
            break;
        case 'S':
            v->y_pos -= v->speed;
            break;
        case 'E':
            v->x_pos += v->speed;
            break;
        case 'W':
            v->x_pos -= v->speed;
            break;
        default:
            printf("Invalid direction: %c", v->direction);
            break;
    }
}

void turnRight(struct vehicle* v) {
    switch (v->direction) {
        case 'N':
            v->direction = 'E';
            break;
        case 'E':
            v->direction = 'S';
            break;
        case 'S':
            v->direction = 'W';
            break;
        case 'W':
            v->direction = 'N';
            break;
        default:
            printf("Invalid direction: %c", v->direction);
            break;
    }
}

void turnLeft(struct vehicle* v) {
    switch (v->direction) {
        case 'N':
            v->direction = 'W';
            break;
        case 'W':
            v->direction = 'S';
            break;
        case 'S':
            v->direction = 'E';
            break;
        case 'E':
            v->direction = 'N';
            break;
        default:
            printf("Invalid direction: %c", v->direction);
            break;
    }
}

int main() {
    struct vehicle v1 = {0, 0, 1, 'N'};
    struct vehicle v2 = {10, 10, 2, 'S'};
    
    printf("Initial positions:\n");
    printf("Vehicle 1: (%d, %d) facing %c\n", v1.x_pos, v1.y_pos, v1.direction);
    printf("Vehicle 2: (%d, %d) facing %c\n\n", v2.x_pos, v2.y_pos, v2.direction);
    
    printf("Vehicle 1 turns right and moves forward:\n");
    turnRight(&v1);
    moveForward(&v1);
    printf("Vehicle 1: (%d, %d) facing %c\n", v1.x_pos, v1.y_pos, v1.direction);
    
    printf("Vehicle 2 turns left and moves forward twice:\n");
    turnLeft(&v2);
    moveForward(&v2);
    moveForward(&v2);
    printf("Vehicle 2: (%d, %d) facing %c\n", v2.x_pos, v2.y_pos, v2.direction);
    
    return 0;
}