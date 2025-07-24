//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x = 0, y = 0;
    char direction;

    srand(time(NULL)); // initialize random seed

    // generate random coordinates 
    x = rand() % 100 + 1;
    y = rand() % 100 + 1;

    printf("Starting point: (%d,%d)\n", x, y);

    // generate random direction
    int dir = rand() % 4;

    switch (dir) {
        case 0:
            direction = 'N';
            break;
        case 1:
            direction = 'E';
            break;
        case 2:
            direction = 'S';
            break;
        case 3:
            direction = 'W';
            break;
        default:
            direction = 'N';
            break;
    }

    printf("Initial direction: %c\n", direction);

    // generate random distance to move in that direction
    int distance = rand() % 10 + 1;

    printf("Distance to move: %d\n", distance);

    // calculate new coordinates based on direction and distance
    switch (direction) {
        case 'N':
            y += distance;
            break;
        case 'E':
            x += distance;
            break;
        case 'S':
            y -= distance;
            break;
        case 'W':
            x -= distance;
            break;
    }

    printf("New point: (%d,%d)\n", x, y);

    return 0;
}