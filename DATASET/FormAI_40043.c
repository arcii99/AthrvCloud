//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];

void initializeMaze() {
    // Set all cells to a wall
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }
}

void generateMaze(int row, int col) {
    // Check if the cell has been visited
    if(maze[row][col] != 1) {
        return;
    }
    // Mark the cell as visited
    maze[row][col] = 0;

    // Create a random order for the directions to move
    int directions[4] = {1,2,3,4};
    for(int i = 0; i < 4; i++) {
        int randomIndex = rand() % 4;
        int tmp = directions[i];
        directions[i] = directions[randomIndex];
        directions[randomIndex] = tmp;
    }

    // Move in each direction
    for(int i = 0; i < 4; i++) {
        switch(directions[i]) {
            case 1: // Move Up
                if(row-2 <= 0) {
                    continue;
                }
                if(maze[row-2][col] != 0) {
                    maze[row-1][col] = 0;
                    generateMaze(row-2, col);
                }
                break;
            case 2: // Move Right
                if(col+2 >= COLS-1) {
                    continue;
                }
                if(maze[row][col+2] != 0) {
                    maze[row][col+1] = 0;
                    generateMaze(row, col+2);
                }
                break;
            case 3: // Move Down
                if(row+2 >= ROWS-1) {
                    continue;
                }
                if(maze[row+2][col] != 0) {
                    maze[row+1][col] = 0;
                    generateMaze(row+2, col);
                }
                break;
            case 4: // Move Left
                if(col-2 <= 0) {
                    continue;
                }
                if(maze[row][col-2] != 0) {
                    maze[row][col-1] = 0;
                    generateMaze(row, col-2);
                }
                break;
        }
    }
}

void printMaze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == 1) {
                printf("█");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Set the seed for the random number generator
    srand(time(NULL));
    initializeMaze();
    generateMaze(1, 1);
    printMaze();
    return 0;
}