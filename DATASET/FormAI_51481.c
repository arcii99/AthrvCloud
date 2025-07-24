//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 41

char maze[ROWS][COLS];

void generateMaze() {
    int i, j;

    // Set all cells to walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i % 2 == 0 || j % 2 == 0) {
                maze[i][j] = '#';
            } else {
                maze[i][j] = ' ';
            }
        }
    }

    // Randomly select a cell to start from
    srand(time(NULL));
    int startX = rand() % (ROWS / 2) * 2 + 1;
    int startY = rand() % (COLS / 2) * 2 + 1;
    maze[startX][startY] = 'S';

    // Generate the maze using depth-first search
    int visited[ROWS][COLS] = { 0 };
    int stackX[ROWS*COLS] = { 0 };
    int stackY[ROWS*COLS] = { 0 };
    int stackSize = 0;

    stackX[stackSize] = startX;
    stackY[stackSize] = startY;
    visited[startX][startY] = 1;
    stackSize++;

    while (stackSize > 0) {
        int currentX = stackX[stackSize - 1];
        int currentY = stackY[stackSize - 1];
        stackSize--;

        int possibleDirections[4][2] = { {-2, 0}, {2, 0}, {0, -2}, {0, 2} };
        int numPossibleDirections = 4;

        while (numPossibleDirections > 0) {
            int index = rand() % numPossibleDirections;
            int newX = currentX + possibleDirections[index][0];
            int newY = currentY + possibleDirections[index][1];

            if (newX < 0 || newY < 0 || newX >= ROWS || newY >= COLS || visited[newX][newY]) {
                possibleDirections[index][0] = possibleDirections[numPossibleDirections - 1][0];
                possibleDirections[index][1] = possibleDirections[numPossibleDirections - 1][1];
                numPossibleDirections--;
            } else {
                maze[newX][newY] = ' ';
                visited[newX][newY] = 1;
                stackX[stackSize] = newX;
                stackY[stackSize] = newY;
                stackSize++;
                break;
            }
        }
    }

    // Randomly select a cell to end at
    int endX = rand() % (ROWS / 2) * 2 + 1;
    int endY = rand() % (COLS / 2) * 2 + 1;
    maze[endX][endY] = 'E';
}

void printMaze() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generateMaze();
    printMaze();
    return 0;
}