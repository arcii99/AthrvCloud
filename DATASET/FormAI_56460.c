//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 20

void printMaze(char maze[][COLS], int rows) {
    for (int i=0; i<rows; i++) {
        printf("%s\n", maze[i]);
    }
}

bool isMoveValid(int x, int y, char maze[][COLS]) {
    if (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == '#') {
        return true;
    }
    return false;
}

int main() {
    char maze[ROWS][COLS];
    srand(time(NULL));

    // Initiallize Maze to all #
    for (int i=0; i<ROWS; i++) {
    for (int j=0; j<COLS; j++) {
            maze[i][j] = '#';
        }
    }

    // Generate Random Starting Point
    int startX = rand() % ROWS;
    int startY = rand() % COLS;

    // Set Starting Point as Open
    maze[startX][startY] = ' ';

    int x = startX;
    int y = startY;

    // Loop to generate maze
    while (true) {
        int ran = rand() % 4;
        if (ran == 0) { // Move up
            if (isMoveValid(x-1, y, maze)) {
                maze[x-1][y] = ' ';
                x--;
            }
        } else if (ran == 1) { // Move down
            if (isMoveValid(x+1, y, maze)) {
                maze[x+1][y] = ' ';
                x++;
            }
        } else if (ran == 2) { // Move left
            if (isMoveValid(x, y-1, maze)) {
                maze[x][y-1] = ' ';
                y--;
            }
        } else if (ran == 3) { // Move right
            if (isMoveValid(x, y+1, maze)) {
                maze[x][y+1] = ' ';
                y++;
            }
        }

        // Check if all moves have been exhausted
        bool allMovesExhausted = true;
        for (int i=0; i<4; i++) {
            int tempX = x;
            int tempY = y;
            if (i == 0) { // Move up
                tempX--;
            } else if (i == 1) { //Move down
                tempX++;
            } else if (i == 2) { // Move left
                tempY--;
            } else { // Move right
                tempY++;
            }

            if (isMoveValid(tempX, tempY, maze)) {
                allMovesExhausted = false;
                break;
            }
        }

        //If all moves have been exhausted, break out of loop
        if (allMovesExhausted) {
            break;
        }
    }

    printMaze(maze, ROWS);

    return 0;
}