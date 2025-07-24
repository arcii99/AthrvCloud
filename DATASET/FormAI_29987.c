//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 20 //Size of the grid
#define THRESHOLD 0.6 //Probability of site being open

int main()
{
    srand(time(0)); //Seed for random number generator
    int grid[DIM][DIM]; //Grid to represent open/closed sites
    int connected[DIM][DIM]; //Array to represent connected sites
    int i, j, k, l, count, open_count = 0, percolation_flag = 0, loop_flag = 1;
    float p;

    //Initialize the grid and connected arrays
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            grid[i][j] = 0;
            connected[i][j] = 0;
        }
    }

    //Open sites in the grid with probability of THRESHOLD
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            p = (float)rand() / (float)RAND_MAX;
            if (p < THRESHOLD) {
                grid[i][j] = 1; //Site is open
                open_count++; //Count number of open sites
            }
        }
    }

    //Print the initial grid
    printf("Initial Grid:\n");
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            if (grid[i][j] == 1) {
                printf("O ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");

    //Loop until percolation occurs or no new sites can be connected
    while (loop_flag) {
        loop_flag = 0; //Assume no new sites can be connected in this iteration
        for (i = 0; i < DIM; i++) {
            for (j = 0; j < DIM; j++) {
                if (grid[i][j] == 1 && connected[i][j] == 0) { //If site is open and not yet connected
                    count = 0;
                    //Check neighboring sites for open and connected sites
                    for (k = i - 1; k <= i + 1; k++) {
                        for (l = j - 1; l <= j + 1; l++) {
                            if (k >= 0 && l >= 0 && k < DIM && l < DIM && !(k == i && l == j)) {
                                if (grid[k][l] == 1 && connected[k][l] == 1) {
                                    count++;
                                }
                            }
                        }
                    }
                    if (count > 0) {
                        connected[i][j] = 1; //Connect site to at least one neighboring site
                        loop_flag = 1; //Set loop flag to continue iterating
                    }
                }
            }
        }
        //Check if percolation has occurred
        for (i = 0; i < DIM; i++) {
            if (connected[0][i]) { //If site is connected to top row
                percolation_flag = 1; //Set percolation flag
                break;
            }
        }
        if (percolation_flag) {
            break; //If percolation has occurred, exit the loop
        }
    }

    //Print the connected grid
    printf("Connected Grid:\n");
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            if (grid[i][j] == 1 && connected[i][j] == 1) {
                printf("X ");
            }
            else if (grid[i][j] == 1 && connected[i][j] == 0) {
                printf("O ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }

    //Print the percolation result
    if (percolation_flag) {
        printf("\nThe grid percolates!\n");
    }
    else {
        printf("\nThe grid does not percolate.\n");
    }

    //Print the statistics
    printf("\nNumber of sites opened: %d\n", open_count);
    printf("Number of sites connected: %d\n", open_count - loop_flag);
    printf("Percolation probability: %f\n", (float)(open_count - loop_flag) / (float)open_count);

    return 0;
}