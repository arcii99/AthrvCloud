//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROWS 15
#define COLS 25

// grid structure
typedef struct grid_t {
    bool visited;
    bool walls[4];
} grid_t;

// create a grid
void createGrid(grid_t grid[][COLS]) {
    // initialize the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j].visited = false;
            for (int k = 0; k < 4; k++) {
                grid[i][j].walls[k] = true;
            }
        }
    }
}

// print the grid
void printGrid(grid_t grid[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("+");
            if (grid[i][j].walls[0]) {
                printf("---");
            } else {
                printf("   ");
            }
        }
        printf("+\n");
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j].walls[1]) {
                printf("|   ");
            } else {
                printf("    ");
            }
        }
        printf("|\n");
    }
    for (int j = 0; j < COLS; j++) {
        printf("+---");
    }
    printf("+\n");
}

// check if a neighboring cell is valid
bool isValid(int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return false;
    }
    return true;
}

// get a random neighboring cell
void getRandomNeighbor(int *row, int *col) {
    int directions[4][2] = {
        {1, 0}, // down
        {0, 1}, // right
        {-1, 0}, // up
        {0, -1} // left
    };
    int dir = rand() % 4;
    int newRow = *row + directions[dir][0];
    int newCol = *col + directions[dir][1];
    if (isValid(newRow, newCol)) {
        *row = newRow;
        *col = newCol;
    }
}

// remove a wall
void removeWall(grid_t grid[][COLS], int row1, int col1, int row2, int col2) {
    if (row1 == row2) {
        if (col1 < col2) {
            grid[row1][col1].walls[1] = false;
            grid[row2][col2].walls[3] = false;
        } else {
            grid[row1][col1].walls[3] = false;
            grid[row2][col2].walls[1] = false;
        }
    } else {
        if (row1 < row2) {
            grid[row1][col1].walls[0] = false;
            grid[row2][col2].walls[2] = false;
        } else {
            grid[row1][col1].walls[2] = false;
            grid[row2][col2].walls[0] = false;
        }
    }
}

// generate the maze
void generateMaze(grid_t grid[][COLS], int row, int col) {
    grid[row][col].visited = true;

    while (true) {
        int newRow = row;
        int newCol = col;
        getRandomNeighbor(&newRow, &newCol);

        if (grid[newRow][newCol].visited == false) {
            removeWall(grid, row, col, newRow, newCol);
            generateMaze(grid, newRow, newCol);
        }

        if (grid[0][0].visited && grid[0][COLS-1].visited && grid[ROWS-1][0].visited && grid[ROWS-1][COLS-1].visited) {
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    grid_t grid[ROWS][COLS];
    createGrid(grid);

    generateMaze(grid, 0, 0);

    printGrid(grid);

    return 0;
}