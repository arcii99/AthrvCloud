//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void generateMaze(int maze[ROWS][COLS], int row, int col);
void printMaze(int maze[ROWS][COLS]);

int main() {
    int maze[ROWS][COLS];
    srand(time(NULL));
    
    generateMaze(maze, 0, 0);
    printMaze(maze);
    
    return 0;
}

void generateMaze(int maze[ROWS][COLS], int row, int col) {
    int i, j;
    maze[row][col] = 1;
    
    // Shuffle the directions
    int directions[4] = {0, 1, 2, 3};
    for (i = 0; i < 4; i++) {
        int temp = directions[i];
        int swapIndex = rand() % 4;
        directions[i] = directions[swapIndex];
        directions[swapIndex] = temp;
    }
    
    for (i = 0; i < 4; i++) {
        int direction = directions[i];
        int newRow = row;
        int newCol = col;
        
        switch (direction) {
            case 0: // Up
                newRow--;
                break;
            case 1: // Right
                newCol++;
                break;
            case 2: // Down
                newRow++;
                break;
            case 3: // Left
                newCol--;
                break;
        }
        
        if (newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLS || maze[newRow][newCol] != 0) {
            continue;
        }
        
        // Knock down the wall in between
        if (direction == 0) { // Up
            maze[row][col] &= ~1;
            maze[newRow][newCol] &= ~4;
        } else if (direction == 1) { // Right
            maze[row][col] &= ~2;
            maze[newRow][newCol] &= ~8;
        } else if (direction == 2) { // Down
            maze[row][col] &= ~4;
            maze[newRow][newCol] &= ~1;
        } else if (direction == 3) { // Left
            maze[row][col] &= ~8;
            maze[newRow][newCol] &= ~2;
        }
        
        generateMaze(maze, newRow, newCol);
    }
}

void printMaze(int maze[ROWS][COLS]) {
    int i, j;
    printf(" ");
    for (i = 0; i < COLS * 2 - 1; i++) {
        printf("_");
    }
    printf("\n");
    
    for (i = 0; i < ROWS; i++) {
        printf("|");
        for (j = 0; j < COLS; j++) {
            if ((maze[i][j] & 2) == 0) {
                printf(" ");
            } else {
                printf("|");
            }
            
            if ((maze[i][j] & 4) == 0) {
                printf(" ");
            } else {
                printf("_");
            }
        }
        printf("\n");
    }
}