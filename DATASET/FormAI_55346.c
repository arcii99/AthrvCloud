//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10   //size of the grid
#define p 0.5  //probability of a site being open

bool open[N][N];   //to store whether a site is open or closed
bool full[N][N];   //to store whether a site is full or not

void percolate(int row, int column) {
    if (row < 0 || row >= N || column < 0 || column >= N) {
        return;   //base case
    }
    if (!open[row][column] || full[row][column]) {  
        return;
    }
    full[row][column] = true;
    percolate(row - 1, column);  //check top site
    percolate(row + 1, column);  //check bottom site
    percolate(row, column - 1);  //check left site
    percolate(row, column + 1);  //check right site
}

int main() {
    //initialize open sites
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((double)rand() / (double)RAND_MAX <= p) {
                open[i][j] = true;
            }
            else {
                open[i][j] = false;
            }
            full[i][j] = false;
        }
    }
    //print initial grid
    printf("Initial Grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (open[i][j]) {
                printf("O ");
            }
            else {
                printf("X ");
            }
        }
        printf("\n");
    }
    //percolation
    for (int i = 0; i < N; i++) {
        if (open[0][i]) {
            percolate(0, i);
        }
    }
    //print final grid
    printf("Final Grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (full[i][j]) {
                printf("F ");
            }
            else if (open[i][j]) {
                printf("O ");
            }
            else {
                printf("X ");
            }
        }
        printf("\n");
    }
    //check if percolation occurred
    bool percolates = false;
    for (int i = 0; i < N; i++) {
        if (full[N - 1][i]) {
            percolates = true;
            break;
        }
    }
    if (percolates) {
        printf("Percolation occurred!\n");
    }
    else {
        printf("Percolation did not occur.\n");
    }
    return 0;
}