//FormAI DATASET v1.0 Category: Robot movement control ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT -2

void moveForward() {
    printf("Moving Forward...\n");
}

void moveBackward() {
    printf("Moving Backward...\n");
}

void turnLeft() {
    printf("Turning Left...\n");
}

void turnRight() {
    printf("Turning Right...\n");
}

int randomMove() {
    int val = (rand()%4)+1;
    return val;
}

void move(int direction) {
    switch(direction) {
        case FORWARD:
            moveForward();
            break;
        case BACKWARD:
            moveBackward();
            break;
        case LEFT:
            turnLeft();
            break;
        case RIGHT:
            turnRight();
            break;
        default:
            printf("Invalid direction...");
    }
}

int main() {
    srand(time(0));
    int x = 0, y = 0, moveCount = 0, maxMoves = 20;
    printf("Starting location: (0, 0)\n");
    while(moveCount < maxMoves) {
        int dir = randomMove();
        switch(dir) {
            case 1:
                x++; // Move Forward
                move(FORWARD);
                break;
            case 2:
                x--; // Move Backward
                move(BACKWARD);
                break;
            case 3:
                y++; // Turn Left
                move(LEFT);
                break;
            case 4:
                y--; // Turn Right
                move(RIGHT);
                break;
            default:
                printf("Invalid move.\n");
        }
        moveCount++;
        printf("New Location: (%d, %d)\n", x, y);
    }
    return 0;
}