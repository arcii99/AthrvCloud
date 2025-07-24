//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void generateMaze(int maze[ROWS][COLS], int row_start, int col_start) {
    // Variable to hold the directions we can move in the maze
    int directions[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    int directionOrder[4] = {0,1,2,3};
    // Shuffle the direction order
    for (int i = 0; i < 4; i++) {
        int temp = directionOrder[i];
        int randomIndex = rand() % 4;
        directionOrder[i] = directionOrder[randomIndex];
        directionOrder[randomIndex] = temp;
    }
    // Move in all directions
    for (int i = 0; i < 4; i++) {
        int direction = directionOrder[i];
        int new_row = row_start + directions[direction][0];
        int new_col = col_start + directions[direction][1];
        // Check if we're out of bounds
        if (new_row < 0 || new_row >= ROWS || new_col < 0 || new_col >= COLS) {
            continue;
        }
        // Check if we've already visited this cell
        if (maze[new_row][new_col] == 0) {
            maze[new_row][new_col] = 1;
            // Make a passage
            if (direction == 0) {
                // Up
                maze[row_start][col_start] |= 1;
                maze[new_row][new_col] |= 2;
                generateMaze(maze, new_row, new_col);
            } else if (direction == 1) {
                // Down
                maze[row_start][col_start] |= 2;
                maze[new_row][new_col] |= 1;
                generateMaze(maze, new_row, new_col);
            } else if (direction == 2) {
                // Left
                maze[row_start][col_start] |= 4;
                maze[new_row][new_col] |= 8;
                generateMaze(maze, new_row, new_col);
            } else if (direction == 3) {
                // Right
                maze[row_start][col_start] |= 8;
                maze[new_row][new_col] |= 4;
                generateMaze(maze, new_row, new_col);
            }
        }
    }
}

void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((maze[i][j] & 1) == 0) {
                printf(" _");
            } else {
                printf("  ");
            }
        }
        printf("\n");
        for (int j = 0; j < COLS; j++) {
            if ((maze[i][j] & 8) == 0) {
                printf("|");
            } else {
                printf(" ");
            }
            printf(" ");
            if (j == COLS-1 && (maze[i][j] & 2) == 0) {
                printf("|");
            } else if ((maze[i][j] & 2) == 0) {
                printf("_");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    int maze[ROWS][COLS] = {{0}};
    srand(time(NULL));
    int start_row = rand() % ROWS;
    int start_col = rand() % COLS;
    maze[start_row][start_col] = 1;
    generateMaze(maze, start_row, start_col);
    printMaze(maze);
    return 0;
}