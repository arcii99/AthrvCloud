//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define PERCOLATION_THRESHOLD 0.50

int grid[ROWS][COLS];

int initialize_grid() {
    srand(time(NULL));
    int count = 0;
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if((float)rand()/(float)RAND_MAX < PERCOLATION_THRESHOLD) {
                grid[i][j] = 1;
                count++;
            }
            else {
                grid[i][j] = 0;
            }
        }
    }
    return count;
}

int percolates(){
    int connected[ROWS][COLS] = {0};
    for(int j=0; j<COLS; j++) {
        if(grid[0][j]){
            connected[0][j] = 1;
        }
    }
    for(int i=1; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(grid[i][j]){
                if(j-1 >= 0 && connected[i-1][j-1]){
                    connected[i][j] = 1;
                }
                else if(connected[i-1][j]){
                    connected[i][j] = 1;
                }
                else if(j+1 < COLS && connected[i-1][j+1]){
                    connected[i][j] = 1;
                }
            }
        }
    }
    for(int j=0; j<COLS; j++) {
        if(connected[ROWS-1][j]) {
            return 1;
        }
    }
    return 0;
}

void print_grid() {
    printf("\nGRID\n\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(grid[i][j]) {
                printf("O ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    int count = initialize_grid();
    print_grid();
    if(percolates()){
        printf("\nPercolates with %d open sites.\n", count);
    }
    else{
        printf("\nDoes not percolate with %d open sites.\n", count);
    }
    return 0;
}