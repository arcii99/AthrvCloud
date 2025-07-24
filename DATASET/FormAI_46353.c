//FormAI DATASET v1.0 Category: Game of Life ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void randomize_grid(int grid[ROWS][COLS]) {
    // initialize random seed
    srand(time(NULL));
    
    // randomly set each cell to either 0 or 1
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid(int grid[ROWS][COLS]) {
    // print each cell as either a space or an X
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j] ? 'X' : ' ');
        }
        printf("\n");
    }
}

int count_neighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    
    // count the up to 8 neighbors of a cell
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0) && row+i >= 0 && row+i < ROWS && col+j >= 0 && col+j < COLS) {
                count += grid[row+i][col+j];
            }
        }
    }
    
    return count;
}

void update_grid(int grid[ROWS][COLS]) {
    int newgrid[ROWS][COLS];
    
    // loop through each cell and update its state based on the number of neighbors
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(grid, i, j);
            if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                newgrid[i][j] = 0;
            } else if (!grid[i][j] && neighbors == 3) {
                newgrid[i][j] = 1;
            } else {
                newgrid[i][j] = grid[i][j];
            }
        }
    }
    
    // copy new grid into old grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newgrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    
    randomize_grid(grid);
    printf("INITIAL STATE:\n");
    print_grid(grid);

    for (int i = 0; i < 10; i++) {
        printf("\nGENERATION %d:\n", i+1);
        update_grid(grid);
        print_grid(grid);
    }

    return 0;
}