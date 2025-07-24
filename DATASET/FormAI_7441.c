//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 15
#define NUM_CARS 10

int main() {
    int grid[GRID_SIZE][GRID_SIZE]; // 2D array to represent grid
    int car_positions[NUM_CARS][2]; // array to keep track of each car's position
    int i, j, car_num, move;
    char c;

    srand(time(NULL)); // seed random number generator

    // initialize grid with all 0s
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    // randomly place cars on grid
    for (car_num = 0; car_num < NUM_CARS; car_num++) {
        i = rand() % GRID_SIZE;
        j = rand() % GRID_SIZE;
        // if cell is already occupied or car ends up on edge of grid, try again
        while (grid[i][j] == 1 || i == 0 || i == GRID_SIZE-1 || j == 0 || j == GRID_SIZE-1) {
            i = rand() % GRID_SIZE;
            j = rand() % GRID_SIZE;
        }
        // place car on grid and add to car_positions array
        grid[i][j] = 1;
        car_positions[car_num][0] = i;
        car_positions[car_num][1] = j;
    }

    // print initial state of grid
    printf("Initial grid:\n");
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("C ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }

    // simulate traffic flow for 10 time steps
    for (int t = 1; t <= 10; t++) {
        printf("Time step %d:\n", t);
        // iterate through each car and determine movement
        for (car_num = 0; car_num < NUM_CARS; car_num++) {
            i = car_positions[car_num][0];
            j = car_positions[car_num][1];
            move = rand() % 3 - 1; // randomly move 1 cell left, right, or stay in same column
            if (move == -1 && j == 0) { // if car tries to move left off grid, stay in same column
                move = 0;
            } else if (move == 1 && j == GRID_SIZE-1) { // if car tries to move right off grid, stay in same column
                move = 0;
            }
            // check if cell car wants to move to is already occupied
            if (grid[i+move][j+1] == 1) {
                printf("Car %d stays in place.\n", car_num+1);
                continue; // skip to next car
            }
            // move car to new location in grid and update car_positions array
            grid[i][j] = 0;
            grid[i+move][j+1] = 1;
            car_positions[car_num][0] = i+move;
            car_positions[car_num][1] = j+1;

            printf("Car %d moves from (%d, %d) to (%d, %d).\n", car_num+1, i, j, i+move, j+1);
        }
        // print updated state of grid
        for (i = 0; i < GRID_SIZE; i++) {
            for (j = 0; j < GRID_SIZE; j++) {
                if (grid[i][j] == 1) {
                    printf("C ");
                } else {
                    printf(". ");
                }
            }
            printf("\n");
        }
        // wait for user to press Enter before continuing
        printf("Press Enter to continue...");
        while ((c = getchar()) != '\n' && c != EOF);
    }

    return 0;
}