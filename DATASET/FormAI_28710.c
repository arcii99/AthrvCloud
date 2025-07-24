//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int rows = 5;
int cols = 5;

// Create the grid
int grid[5][5] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
};

// Create the pathfinding algorithm
void pathfinding(int start_x, int start_y, int end_x, int end_y) {
    int current_x = start_x;
    int current_y = start_y;

    while(current_x != end_x || current_y != end_y) {
        printf("Current position: (%d, %d)\n", current_x, current_y);

        // Move to the next position
        if(current_x < end_x) {
            current_x++;
        } else if(current_y < end_y) {
            current_y++;
        } else {
            break;
        }
    }

    printf("Final position: (%d, %d)\n", current_x, current_y);
}

int main() {
    printf("Starting pathfinding algorithm...\n");
    pathfinding(0, 0, 4, 4);
    printf("Pathfinding complete!\n");

    return 0;
}