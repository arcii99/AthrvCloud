//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 20

int maze[ROWS][COLUMNS];

void generateMaze(int r, int c, int sr, int sc) {
    int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left, right
    int i, row, col, tmpR, tmpC;
    
    for (i = 0; i < 4; i++) {
        row = sr + moves[i][0];
        col = sc + moves[i][1];
        
        if (row < 0 || col < 0 || row >= r || col >= c || maze[row][col] != 0) {
            continue;
        }
        
        maze[row][col] = i + 1;
        
        tmpR = sr + 2 * moves[i][0];
        tmpC = sc + 2 * moves[i][1];
        
        if (tmpR >= 0 && tmpR < r && tmpC >= 0 && tmpC < c) {
            maze[tmpR][tmpC] = i + 1;
            generateMaze(r, c, tmpR, tmpC);
        }
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    
    // Initialize maze with all 0s
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            maze[i][j] = 0;
        }
    }
    
    // Generate maze starting from the center of the maze
    int startRow = ROWS / 2;
    int startCol = COLUMNS / 2;
    maze[startRow][startCol] = -1; // start cell
    
    generateMaze(ROWS, COLUMNS, startRow, startCol);
    
    // Print maze
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (maze[i][j] == 0) {
                printf("#");
            } else if (maze[i][j] == -1) {
                printf("S"); // start cell
            } else {
                printf(" "); // empty space
            }
        }
        printf("\n");
    }
    
    return 0;
}