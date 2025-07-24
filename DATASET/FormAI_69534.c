//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FOREVER while(1)

typedef struct {
    int x;
    int y;
} Position;

Position move(Position pos, int direction) {
    switch(direction) {
        case 1:
            pos.x += 1;
            break;
        case 2:
            pos.y += 1;
            break;
        case 3:
            pos.x -= 1;
            break;
        case 4:
            pos.y -= 1;
            break;
        default:
            break;
    }

    return pos;
}

int main() {
    srand(time(NULL));

    Position curr_pos = {0, 0};
    printf("Initial position: (%d, %d)\n", curr_pos.x, curr_pos.y);

    FOREVER {
        int dir = rand() % 5;
        curr_pos = move(curr_pos, dir);
        printf("Moved in direction %d. New position: (%d, %d)\n", dir, curr_pos.x, curr_pos.y);
        sleep(2);
    }

    return 0;
}