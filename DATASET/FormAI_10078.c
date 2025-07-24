//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the remote control vehicle
#define SIZE 10

// Define the initial position of the vehicle
#define INIT_POS_X SIZE/2
#define INIT_POS_Y SIZE/2

// Define the maximum number of steps allowed for the vehicle
#define MAX_STEPS 15

int main() {
    // Seed random number generator
    srand(time(NULL));
   
    // Initialize the grid for the remote control vehicle
    char grid[SIZE][SIZE];
    int i,j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    // Set the initial positionn of the vehicle on the grid
    grid[INIT_POS_X][INIT_POS_Y] = 'X';
    int pos_x = INIT_POS_X;
    int pos_y = INIT_POS_Y;

    // Generate a sequence of random steps for the vehicle
    int step_count = 0;
    while(step_count < MAX_STEPS) {
        // Generate a random direction for the vehicle to move in
        int direction = rand() % 4;
        switch(direction) {
            case 0: // Move up
                if(pos_x > 0) {
                    pos_x--;
                    step_count++;
                    grid[pos_x][pos_y] = 'X';
                }
                break;
            case 1: // Move down
                if(pos_x < SIZE-1) {
                    pos_x++;
                    step_count++;
                    grid[pos_x][pos_y] = 'X';
                }
                break;
            case 2: // Move left
                if(pos_y > 0) {
                    pos_y--;
                    step_count++;
                    grid[pos_x][pos_y] = 'X';
                }
                break;
            case 3: // Move right
                if(pos_y < SIZE-1) {
                    pos_y++;
                    step_count++;
                    grid[pos_x][pos_y] = 'X';
                }
                break;
        }
    }

    // Print the final grid with the vehicle's path
    printf("Final grid:\n");
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}