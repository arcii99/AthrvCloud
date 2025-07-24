//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: protected
#include <stdio.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

// Maze
int maze[ROW][COL] = {
    {1, 1, 1, 0, 0},
    {1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 0, 1, 1, 1},
    {0, 0, 1, 1, 1}
};

bool isSafe(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 1);
}

bool mazeUtil(int row, int col, int sol[ROW][COL]) {
    if (row == ROW - 1 && col == COL - 1) {
        sol[row][col] = 1;
        return true;
    }

    if (isSafe(row, col)) {
        sol[row][col] = 1;
        if (mazeUtil(row + 1, col, sol))
            return true;
        if (mazeUtil(row, col + 1, sol))
            return true;
        sol[row][col] = 0;
        return false;
    }
    return false;
}

void printSolution(int sol[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            printf("%d ", sol[i][j]);
        printf("\n");
    }
}

int main() {
    int sol[ROW][COL] = {0};

    if (mazeUtil(0, 0, sol) == false) {
        printf("Solution not found!\n");
        return 0;
    }

    printf("Solution found:\n");
    printSolution(sol);
    
    return 0;
}