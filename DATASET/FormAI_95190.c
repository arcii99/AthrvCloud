//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int destination_x = rand() % 1000; // randomly generated x-coordinate of destination
    int destination_y = rand() % 1000; // randomly generated y-coordinate of destination

    int current_pos_x = 0; // starting x-coordinate
    int current_pos_y = 0; // starting y-coordinate

    printf("Current position: (%d,%d)\n", current_pos_x, current_pos_y);
    printf("Destination: (%d,%d)\n", destination_x, destination_y);

    while (current_pos_x != destination_x || current_pos_y != destination_y) {
        // calculate the direction to move in
        int dx = 0;
        if (current_pos_x < destination_x)
            dx = 1;
        else if (current_pos_x > destination_x)
            dx = -1;

        int dy = 0;
        if (current_pos_y < destination_y)
            dy = 1;
        else if (current_pos_y > destination_y)
            dy = -1;

        printf("Moving in direction: (%d,%d)\n", dx, dy);
        current_pos_x += dx;
        current_pos_y += dy;
        printf("Current position: (%d,%d)\n", current_pos_x, current_pos_y);
    }

    printf("Arrived at destination!\n");
    return 0;
}