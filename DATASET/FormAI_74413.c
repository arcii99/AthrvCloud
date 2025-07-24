//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 10
#define COL_SIZE 10

int maze[ROW_SIZE][COL_SIZE];

void printMaze() {
    int i, j;
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COL_SIZE; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(int row, int col) {
    int i, j;
    // Edge cases
    if (row < 0 || col < 0 || row >= ROW_SIZE || col >= COL_SIZE) {
        return;
    }
    if (maze[row][col] == 1) {
        return;
    }
    // Set current cell to visited
    maze[row][col] = 1;
    // Generate random numbers to determine next cell
    int randNum = rand() % 4;
    int nextRow = row;
    int nextCol = col;
    switch(randNum) {
        case 0:
            nextCol++; // Go east
            break;
        case 1:
            nextRow++; // Go south
            break;
        case 2:
            nextCol--; // Go west
            break;
        case 3:
            nextRow--; // Go north
            break;
    }
    // Move to next cell if not visited and within bounds of maze
    if (nextRow >= 0 && nextRow < ROW_SIZE && nextCol >= 0 && nextCol < COL_SIZE && maze[nextRow][nextCol] != 1) {
        // Open path between current cell and next cell
        if (nextRow < row) {
            maze[row][col] |= (1 << 0); // Open north path
            maze[nextRow][nextCol] |= (1 << 1); // Open south path
        }
        else if (nextRow > row) {
            maze[row][col] |= (1 << 1); // Open south path
            maze[nextRow][nextCol] |= (1 << 0); // Open north path
        }
        else if (nextCol < col) {
            maze[row][col] |= (1 << 2); // Open west path
            maze[nextRow][nextCol] |= (1 << 3); // Open east path
        }
        else if (nextCol > col) {
            maze[row][col] |= (1 << 3); // Open east path
            maze[nextRow][nextCol] |= (1 << 2); // Open west path
        }
        // Recursively generate next cell
        generateMaze(nextRow, nextCol);
    }
    // Recursively visit neighboring cells
    generateMaze(row, col+1); // Go east
    generateMaze(row+1, col); // Go south
    generateMaze(row, col-1); // Go west
    generateMaze(row-1, col); // Go north
}

int main() {
    int randRow = rand() % ROW_SIZE;
    int randCol = rand() % COL_SIZE;
    srand(time(NULL));
    generateMaze(randRow, randCol);
    printMaze();
    return 0;
}