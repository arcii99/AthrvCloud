//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// function to print the grid
void printGrid(int grid[ROWS][COLS]) {
    printf("\n");
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            // if cell is filled (1), print black square
            if (grid[i][j] == 1) {
                printf("\u2193 ");
            }
            // if cell is empty (0), print white square
            else {
                printf("\u2191 ");
            }
        }
        printf("\n");
    }
}

// function to fill the grid randomly with a density specified by the user
void fillGrid(int grid[ROWS][COLS], float density) {
    int totalCells = ROWS * COLS;
    int numFilledCells = (int) (density * totalCells);
    
    // randomly fill the grid with 1s and 0s
    for (int i=0; i<numFilledCells; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        grid[row][col] = 1;
    }
}

// function to check if there is a path from top to bottom
int isConnected(int grid[ROWS][COLS]) {
    // create visited array to keep track of which cells have been visited
    int visited[ROWS][COLS] = {0};
    
    // dfs function to traverse the grid and mark all connected cells
    void dfs(int r, int c) {
        if (visited[r][c] == 1 || grid[r][c] == 0) {
            return;
        }
        visited[r][c] = 1;
        if (r+1 < ROWS) dfs(r+1,c);
        if (r-1 >= 0) dfs(r-1,c);
        if (c+1 < COLS) dfs(r,c+1);
        if (c-1 >= 0) dfs(r,c-1);
    }
    
    // start the dfs from the top row
    for (int c=0; c<COLS; c++) {
        if (grid[0][c] == 1) {
            dfs(0,c);
        }
    }
    
    // check if there is a marked cell in the bottom row
    for (int c=0; c<COLS; c++) {
        if (visited[ROWS-1][c] == 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(0)); // seed the random number generator
    
    // initialize the grid to all 0s
    int grid[ROWS][COLS] = {0};
    
    // prompt user for density
    float density;
    printf("Enter a density value between 0 and 1: ");
    scanf("%f", &density);
    if (density < 0 || density > 1) {
        printf("Invalid density value.\n");
        return 1;
    }
    
    // fill the grid randomly
    fillGrid(grid, density);
    
    // print the original grid
    printf("Original Grid:\n");
    printGrid(grid);
    
    // check if there is a path from top to bottom
    int connected = isConnected(grid);
    printf("\n");
    if (connected == 1) {
        printf("There is a path from top to bottom!\n");
    } else {
        printf("There is no path from top to bottom.\n");
    }
    
    // simulate percolation by filling in connected cells and checking for path
    while (connected == 0) {
        // choose a random cell that is not already filled
        int row, col;
        do {
            row = rand() % ROWS;
            col = rand() % COLS;
        } while (grid[row][col] == 1);
        
        // fill in the cell
        grid[row][col] = 1;
        
        // check if there is now a path from top to bottom
        connected = isConnected(grid);
        
        // print the updated grid
        printf("\nUpdated Grid:\n");
        printGrid(grid);
        
        // wait for a bit before updating again
        printf("Press enter to continue...");
        getchar();
    }
    
    // print the final connected grid
    printf("\nFinal Grid:\n");
    printGrid(grid);
    printf("Percolation completed successfully!\n");
    
    return 0;
}