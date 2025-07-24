//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: inquisitive
#include <stdio.h>
#define N 8 // size of the maze
int maze[N][N] = {
    {1, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 1, 0, 1, 1, 1, 1},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 0, 0, 1}
};
int sol[N][N] = {0}; // solution matrix
int move_x[4] = {0, 1, 0, -1}; // all possible moves
int move_y[4] = {1, 0, -1, 0};
// function to print solution
void printSolution() {
    printf("\nSolution:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", sol[i][j]);
        printf("\n");
    }
}
// function to check if a move is valid
int isValidMove(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0);
}
// function to find the route
int findRoute(int x, int y) {
    if (x == N - 1 && y == N - 1) { // reached destination
        sol[x][y] = 1;
        printSolution();
        return 1;
    }
    if (isValidMove(x, y)) { // check if move is valid
        sol[x][y] = 1;
        for (int i = 0; i < 4; i++) { // try all possible moves
            int next_x = x + move_x[i];
            int next_y = y + move_y[i];
            if (findRoute(next_x, next_y) == 1) // if found a solution return 1
                return 1;
        }
        sol[x][y] = 0; // backtrack
        return 0;
    }
    return 0;
}
// main function to test the program
int main() {
    printf("Maze Route Finder\n");
    printf("-----------------\n");
    if (findRoute(0, 0) == 0) // if no solution found
        printf("\nNo solution found!\n");

    return 0;
}