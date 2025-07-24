//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: introspective
#include <stdio.h>
#define ROWS 4
#define COLS 5

int maze[ROWS][COLS] = {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0}
};

int visited[ROWS][COLS];

void printSolution() {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
}

int isValid(int row, int col) {
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 1 && visited[row][col] == 0)
        return 1;

    return 0;
}

int solveMaze(int row, int col) {
    if(row == ROWS - 1 && col == COLS - 1) {
        visited[row][col] = 1;
        return 1;
    }

    if(isValid(row, col)) {
        visited[row][col] = 1;

        if(solveMaze(row, col+1) == 1)
            return 1;
        if(solveMaze(row+1, col) == 1)
            return 1;

        visited[row][col] = 0;
        return 0;
    }

    return 0;
}

int main()
{
    int i, j;

    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++)
            visited[i][j] = 0;
    }

    if (solveMaze(0, 0) == 1)
        printSolution();
    else
        printf("No solution found\n");

    return 0;
}