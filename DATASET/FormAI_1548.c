//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPACE '.'
#define CAR 'C'

int main() {
    srand(time(NULL)); //Seed random number generator

    //Initialize traffic flow grid with initial car positions
    char traffic_grid[10][20] = {
        {CAR, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
        {SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, CAR},
        {CAR, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
        {SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, CAR},
        {CAR, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
        {SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, CAR},
        {CAR, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
        {SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, CAR},
        {CAR, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE},
        {SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, CAR}
    };

    int iteration_count = 0;

    while (iteration_count < 100) { //Run simulation for 100 iterations
        //Print current traffic flow grid
        printf("Iteration %d:\n", iteration_count);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 20; j++) {
                printf("%c ", traffic_grid[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        //Move cars forward
        for (int i = 0; i < 10; i++) {
            for (int j = 19; j >= 0; j--) {
                if (traffic_grid[i][j] == CAR) {
                    if (j == 19) {
                        traffic_grid[i][j] = SPACE;
                    } else {
                        //Check if space in front of car is empty
                        if (traffic_grid[i][j+1] == SPACE) {
                            traffic_grid[i][j+1] = CAR;
                            traffic_grid[i][j] = SPACE;
                        }
                    }
                }
            }
        }

        //Randomly add cars to the leftmost lane with probability 0.5
        if (rand() % 2 == 0) {
            int row = rand() % 10;
            if (traffic_grid[row][0] == SPACE) {
                traffic_grid[row][0] = CAR;
            }
        }

        iteration_count++;
    }

    return 0;
}