//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

void generateMaze(int maze[][COLS]);
void printMaze(int maze[][COLS]);

int main() {
    srand(time(NULL));
    
    int maze[ROWS][COLS];
    
    generateMaze(maze);
    printMaze(maze);
    
    return 0;
}

// Generates a random maze
void generateMaze(int maze[][COLS]) {
    // Fill maze with walls
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }
    
    // Set starting point
    int currentRow = 1;
    int currentCol = 1;
    maze[currentRow][currentCol] = 0;
    
    // Algorithm for generating maze
    do {
        int direction = rand() % 4;
        switch(direction) {
            case 0: // Move up
                if(currentRow - 2 < 0) {
                    continue;
                }
                if(maze[currentRow - 2][currentCol] == 1) {
                    maze[currentRow - 2][currentCol] = 0;
                    maze[currentRow - 1][currentCol] = 0;
                    currentRow -= 2;
                }
                break;
            case 1: // Move down
                if(currentRow + 2 >= ROWS) {
                    continue;
                }
                if(maze[currentRow + 2][currentCol] == 1) {
                    maze[currentRow + 2][currentCol] = 0;
                    maze[currentRow + 1][currentCol] = 0;
                    currentRow += 2;
                }
                break;
            case 2: // Move left
                if(currentCol - 2 < 0) {
                    continue;
                }
                if(maze[currentRow][currentCol - 2] == 1) {
                    maze[currentRow][currentCol - 2] = 0;
                    maze[currentRow][currentCol - 1] = 0;
                    currentCol -= 2;
                }
                break;
            case 3: // Move right
                if(currentCol + 2 >= COLS) {
                    continue;
                }
                if(maze[currentRow][currentCol + 2] == 1) {
                    maze[currentRow][currentCol + 2] = 0;
                    maze[currentRow][currentCol + 1] = 0;
                    currentCol += 2;
                }
                break;
        }
    } while(currentRow != 1 || currentCol != 1); // Stop when back at starting point
}

// Prints the maze
void printMaze(int maze[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}