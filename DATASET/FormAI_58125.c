//FormAI DATASET v1.0 Category: Robot movement control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACKWARD 3

#define OIL_CHANGE_INTERVAL 1000

int x_pos = 0;
int y_pos = 0;
int oil_level = 1000;
int distance_travelled = 0;

void move(int direction) {
    switch(direction) {
        case LEFT:
            x_pos--;
            break;
        case RIGHT:
            x_pos++;
            break;
        case FORWARD:
            y_pos++;
            break;
        case BACKWARD:
            y_pos--;
            break;
        default:
            break;
    }
    distance_travelled++;
    if(distance_travelled % OIL_CHANGE_INTERVAL == 0) {
        oil_level = 0;
        printf("Oil changed at (%d,%d)\n", x_pos, y_pos);
    }
}

int main() {
    srand(time(NULL));
    int i;
    for(i = 0; i < 1000; i++) {
        int direction = rand() % 4;
        move(direction);
        printf("Moved %d units in direction %d. Position: (%d,%d). Oil level: %d\n", 1, direction, x_pos, y_pos, oil_level);
        oil_level++;
    }
    return 0;
}