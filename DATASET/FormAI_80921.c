//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 21

int maze[ROWS][COLS];

void generateMaze(int row, int col) {
    // Set the random seed
    srand(time(NULL));
    
    // Initialize the maze with all walls
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            maze[i][j] = 1;
        }
    }
    
    // Choose a random starting point
    int startX = rand() % row;
    int startY = rand() % col;
    
    // Mark the starting point as visited
    maze[startX][startY] = 0;
    
    // Create a stack to keep track of visited cells
    int stackX[row * col];
    int stackY[row * col];
    int top = 0;
    stackX[top] = startX;
    stackY[top] = startY;
    
    // Continue until all cells have been visited
    while (top >= 0) {
        // Pick a random neighbor
        int x = stackX[top];
        int y = stackY[top];
        int dir = rand() % 4;
        int count = 0;
        while (count < 4) {
            if (dir == 0 && x > 0 && maze[x - 1][y] == 1) {
                maze[x][y] = 0;
                maze[x - 1][y] = 0;
                stackX[top + 1] = x - 1;
                stackY[top + 1] = y;
                top++;
                break;
            } else if (dir == 1 && x < row - 1 && maze[x + 1][y] == 1) {
                maze[x][y] = 0;
                maze[x + 1][y] = 0;
                stackX[top + 1] = x + 1;
                stackY[top + 1] = y;
                top++;
                break;
            } else if (dir == 2 && y > 0 && maze[x][y - 1] == 1) {
                maze[x][y] = 0;
                maze[x][y - 1] = 0;
                stackX[top + 1] = x;
                stackY[top + 1] = y - 1;
                top++;
                break;
            } else if (dir == 3 && y < col - 1 && maze[x][y + 1] == 1) {
                maze[x][y] = 0;
                maze[x][y + 1] = 0;
                stackX[top + 1] = x;
                stackY[top + 1] = y + 1;
                top++;
                break;
            } else {
                dir = (dir + 1) % 4;
                count++;
            }
        }
        if (count == 4) {
            top--;
        }
    }
}

void printMaze(int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    generateMaze(ROWS, COLS);
    printMaze(ROWS, COLS);
    return 0;
}