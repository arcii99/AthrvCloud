//FormAI DATASET v1.0 Category: Game of Life ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 10

void initialize_grid(int grid[][COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid(int grid[][COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%c ", (grid[i][j] == 0) ? ' ' : 'X');
        }
        printf("\n");
    }
}

int count_neighbors(int grid[][COLS], int rows, int cols, int x, int y) {
    int neighbors = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int row = (x + i + rows) % rows;
            int col = (y + j + cols) % cols;
            neighbors += grid[row][col];
        }
    }
    neighbors -= grid[x][y];
    return neighbors;
}

void update_grid(int grid[][COLS], int rows, int cols) {
    int new_grid[ROWS][COLS];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int neighbors = count_neighbors(grid, rows, cols, i, j);
            if(grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1;
            } else if(grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    srand(time(NULL));
    initialize_grid(grid, ROWS, COLS);
    printf("Initial Grid:\n");
    print_grid(grid, ROWS, COLS);
    printf("\n");
    for(int i=0; i<10; i++) {
        update_grid(grid, ROWS, COLS);
        printf("Generation %d:\n", i+1);
        print_grid(grid, ROWS, COLS);
        printf("\n");
    }
    return 0;
}