//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int findPath(int maze[ROW][COL], int x, int y, int sol[ROW][COL]);

// A utility function to print solution matrix sol[N][N]
void print_sol(int sol[ROW][COL]) {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
}

/* A utility function to check if x, y is valid index for N*N maze */
int isSafe(int maze[ROW][COL], int x, int y) {
    // if (x, y outside maze) return false
    if (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1)
        return 1;

    return 0;
}

/* This function solves the Maze problem using Backtracking. It mainly uses
   solveMazeUtil() to solve the problem. It returns false if no path is possible,
   otherwise return true and prints the path in the form of 1s. Please note that
   there may be more than one solutions, this function prints one of the feasible solutions.*/
int solveMaze(int maze[ROW][COL]) {
    int sol[ROW][COL] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    if (findPath(maze, 0, 0, sol) == 0) {
        printf("This maze has no solution\n");
        return 0;
    }

    printf("Following is the path:\n");
    print_sol(sol);
    return 1;
}

int findPath(int maze[ROW][COL], int x, int y, int sol[ROW][COL]) {
    if (x == ROW - 1 && y == COL - 1) {
        sol[x][y] = 1;
        return 1;
    }

    if (isSafe(maze, x, y) == 1) {
        sol[x][y] = 1;

        /* Move forward in x direction */
        if (findPath(maze, x + 1, y, sol) == 1) {
            return 1;
        }

        /* If moving in x direction doesn't give solution then Move down in y direction */
        if (findPath(maze, x, y + 1, sol) == 1) {
            return 1;
        }

        /* If none of the above movements work then BACKTRACK: unmark x,y as part of solution path */
        sol[x][y] = 0;
        return 0;
    }

    return 0;
}

int main() {
    int maze[ROW][COL] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 1, 1, 1, 1, 1, 0, 1, 1, 0},
                          {0, 0, 0, 1, 0, 1, 0, 0, 1, 0},
                          {1, 1, 0, 1, 0, 1, 1, 1, 1, 0},
                          {1, 1, 0, 0, 0, 0, 0, 0, 1, 0},
                          {1, 1, 0, 1, 1, 1, 1, 0, 1, 0},
                          {1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
                          {1, 1, 1, 1, 0, 1, 1, 0, 1, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    solveMaze(maze);

    return 0;
}