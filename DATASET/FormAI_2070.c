//FormAI DATASET v1.0 Category: Robot movement control ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct {
    int x;
    int y;
} Position;

void initialize(Position* pos) {
    pos->x = 0;
    pos->y = 0;
}

void move(Position* pos) {
    int direction = rand() % 4;
    switch (direction) {
        case 0:
            pos->x++;
            break;
        case 1:
            pos->x--;
            break;
        case 2:
            pos->y++;
            break;
        case 3:
            pos->y--;
            break;
    }
}

void printCurrentPosition(Position pos) {
    printf("Robot position: (%d, %d)\n", pos.x, pos.y);
}

int main() {
    Position robot;
    initialize(&robot);
    srand(time(0));
    
    printf("Starting position: (0, 0)\n");
    for (int i = 0; i < SIZE; i++) {
        move(&robot);
        printCurrentPosition(robot);
    }
    
    return 0;
}