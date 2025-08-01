//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
// C program to find the route in a maze

#include <stdio.h>
#include <stdbool.h>

#define N 4

bool mazeSolver(int maze[N][N], int x, int y, int sol[N][N]);

void printSolution(int sol[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

bool isSafe(int maze[N][N], int x, int y) {
    if(x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;
    return false;
}

bool mazeRouteFinder(int maze[N][N]) {
    int sol[N][N] = {{0,0,0,0},
                     {0,0,0,0},
                     {0,0,0,0},
                     {0,0,0,0}};
    if(mazeSolver(maze, 0, 0, sol) == false) {
        printf("Solution doesn't exist!");
        return false;
    }
    printSolution(sol);
    return true;
}

bool mazeSolver(int maze[N][N], int x, int y, int sol[N][N]) {
    if(x == N-1 && y == N-1) {
        sol[x][y] = 1;
        return true;
    }
    if(isSafe(maze, x, y) == true) {
        sol[x][y] = 1;
        if(mazeSolver(maze, x+1, y, sol) == true)
            return true;
        if(mazeSolver(maze, x, y+1, sol) == true)
            return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

// Main method
int main() {
    int maze[N][N] = {{1, 0, 0, 0},
                      {1, 1, 0, 1},
                      {0, 1, 0, 0},
                      {1, 1, 1, 1}};
    mazeRouteFinder(maze);
    return 0;
}