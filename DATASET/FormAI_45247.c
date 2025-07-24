//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0));

    int x = 0, y = 0, dest_x = rand()%1000, dest_y = rand()%1000, moves = 0;

    printf("Current location: (%d,%d)\n\n", x, y);

    while (x != dest_x || y != dest_y) {
        
        int dir_x = 0, dir_y = 0;

        if (x < dest_x) dir_x = 1;
        else if (x > dest_x) dir_x = -1;

        if (y < dest_y) dir_y = 1;
        else if (y > dest_y) dir_y = -1;

        if (dir_x == 0) {
            printf("Move in the y-direction!\n");
            y += dir_y;
        }
        else if (dir_y == 0) {
            printf("Move in the x-direction!\n");
            x += dir_x;
        }
        else if (rand() % 2 == 0) {
            printf("Move in the x-direction!\n");
            x += dir_x;
        }
        else {
            printf("Move in the y-direction!\n");
            y += dir_y;
        }

        moves++;
        printf("Current location: (%d,%d)\n\n", x, y);

    }

    printf("Congratulations, you have arrived at your destination!\n");
    printf("Number of moves taken: %d\n", moves);

    return 0;
}