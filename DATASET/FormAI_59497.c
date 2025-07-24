//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 25
#define COL 25

int main() {
    srand(time(NULL)); // Seed random number generator with current time

    // Initialize maze grid
    int maze[ROW][COL] = {0};

    // Choose random start and end points
    int start_row = rand() % ROW;
    int start_col = 0;
    int end_row = rand() % ROW;
    int end_col = COL - 1;
    maze[start_row][start_col] = 1;
    maze[end_row][end_col] = 1;

    // Generate maze
    int row = start_row;
    int col = start_col;
    while (row != end_row || col != end_col) {
        maze[row][col] = 1;
        int r = rand() % 4; // Choose random direction to move
        if (r == 0 && row > 0 && maze[row-1][col] != 1) { // Move up
            row--;
        } else if (r == 1 && row < ROW-1 && maze[row+1][col] != 1) { // Move down
            row++;
        } else if (r == 2 && col > 0 && maze[row][col-1] != 1) { // Move left
            col--;
        } else if (r == 3 && col < COL-1 && maze[row][col+1] != 1) { // Move right
            col++;
        }
    }
    maze[row][col] = 1;

    // Print maze
    printf(" ");
    for (int i = 0; i < COL*2-1; i++) {
        printf("_");
    }
    printf("\n");
    for (int i = 0; i < ROW; i++) {
        printf("|");
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 1) {
                printf(" ");
            } else {
                printf("_");
            }
            if (j < COL-1) {
                if (maze[i][j] == 1 && maze[i][j+1] == 1) {
                    printf(" ");
                } else {
                    printf("|");
                }
            }
        }
        printf("|\n");
    }
    return 0;
}