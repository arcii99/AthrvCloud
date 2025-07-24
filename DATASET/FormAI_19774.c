//FormAI DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Initialize Function
void initialize(int rows, int columns, int grid[rows][columns]) {
    for(int row=0; row<rows; row++) {
        for(int column=0; column<columns; column++) {
            grid[row][column] = rand()%2;
        }
    }
}

// Print Function
void print(int rows, int columns, int grid[rows][columns]) {
    for(int row=0; row<rows; row++) {
        for(int column=0; column<columns; column++) {
            if(grid[row][column] == 1) {
                printf("\u25A0 "); // black square
            } else {
                printf("\u25A1 "); // white square
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

// Count neighbors function
int count_neighbors(int rows, int columns, int grid[rows][columns],
                    int row, int column) {
    int count = 0;
    for(int i=row-1; i<=row+1; i++) {
        for(int j=column-1; j<=column+1; j++) {
            if(i<0 || i>=rows || j<0 || j>=columns) continue;
            if(i==row && j==column) continue;
            count += grid[i][j];
        }
    }
    return count;
}

// Update Function
void update(int rows, int columns, int grid[rows][columns]) {
    int newgrid[rows][columns];
    for(int row=0; row<rows; row++) {
        for(int column=0; column<columns; column++) {
            int count = count_neighbors(rows, columns, grid, row, column);
            if(grid[row][column] == 1) {
                if(count < 2 || count > 3) {
                    newgrid[row][column] = 0; // die
                } else {
                    newgrid[row][column] = 1; // stay alive
                }
            } else {
                if(count == 3) {
                    newgrid[row][column] = 1; // born
                } else {
                    newgrid[row][column] = 0; // stay dead
                }
            }
        }
    }

    // copy new grid to old grid
    for(int row=0; row<rows; row++) {
        for(int column=0; column<columns; column++) {
            grid[row][column] = newgrid[row][column];
        }
    }
}

int main() {
    srand(time(NULL));
    int rows = 30, columns = 50;
    int grid[rows][columns];
    initialize(rows, columns, grid);

    for(int i=0; i<100; i++) {
        print(rows, columns, grid);
        update(rows, columns, grid);
        sleep(1);
        system("clear");
    }

    return 0;
}