//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 30

int maze[MAX_ROWS][MAX_COLS];

void generateMaze() {
    int i, j;

    // Initialize the maze with walls
    for(i = 0; i < MAX_ROWS; i++) {
        for(j = 0; j < MAX_COLS; j++) {
            maze[i][j] = 1; // 1 denotes a wall
        }
    }

    // Set the seed for the random number generator
    srand(time(NULL));

    // Generate the maze
    int row = 1;
    int col = 1;
    maze[row][col] = 0; // 0 denotes the start point

    while(row != MAX_ROWS - 2 || col != MAX_COLS - 2) {
        // Generate a random direction
        int direction = rand() % 4; // 0: up, 1: right, 2: down, 3: left

        switch(direction) {
            case 0: // up
                if(row > 1 && maze[row - 2][col] == 1) {
                    maze[row - 1][col] = 0; // 0 denotes a path
                    maze[row - 2][col] = 0;
                    row -= 2;
                }
                break;
            case 1: // right
                if(col < MAX_COLS - 2 && maze[row][col + 2] == 1) {
                    maze[row][col + 1] = 0;
                    maze[row][col + 2] = 0;
                    col += 2;
                }
                break;
            case 2: // down
                if(row < MAX_ROWS - 2 && maze[row + 2][col] == 1) {
                    maze[row + 1][col] = 0;
                    maze[row + 2][col] = 0;
                    row += 2;
                }
                break;
            case 3: // left
                if(col > 1 && maze[row][col - 2] == 1) {
                    maze[row][col - 1] = 0;
                    maze[row][col - 2] = 0;
                    col -= 2;
                }
                break;
        }
    }

    maze[MAX_ROWS - 2][MAX_COLS - 2] = 0; // 0 denotes the end point
}

void printMaze() {
    int i, j;

    for(i = 0; i < MAX_ROWS; i++) {
        for(j = 0; j < MAX_COLS; j++) {
            if(maze[i][j] == 0) { // Path
                printf("·");
            } else if(maze[i][j] == 1) { // Wall
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    generateMaze();
    printMaze();

    return 0;
}