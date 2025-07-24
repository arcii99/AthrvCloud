//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int start_i = 1;
int start_j = 1;
int end_i = 8;
int end_j = 8;
int visited[ROW][COL] = {0};
int solution[ROW][COL] = {0};

int solve_maze(int i, int j) {
    if (i == end_i && j == end_j) {
        solution[i][j] = 1;
        return 1;
    }
    if (maze[i][j] == 1 || visited[i][j] == 1) {
        return 0;
    }
    visited[i][j] = 1;
    if (solve_maze(i + 1, j) == 1) {
        solution[i][j] = 1;
        return 1;
    }
    if (solve_maze(i - 1, j) == 1) {
        solution[i][j] = 1;
        return 1;
    }
    if (solve_maze(i, j + 1) == 1) {
        solution[i][j] = 1;
        return 1;
    }
    if (solve_maze(i, j - 1) == 1) {
        solution[i][j] = 1;
        return 1;
    }
    return 0;
}

void print_maze() {
    printf("\nMaze:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void print_solution() {
    printf("\nSolution:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", solution[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("\nMaze Route Finder Example Program\n");
    print_maze();
    printf("\nStarting Point: (%d, %d)", start_i, start_j);
    printf("\nEnding Point: (%d, %d)", end_i, end_j);
    if (solve_maze(start_i, start_j) == 0) {
        printf("\nNo solution exists!\n");
    }
    else {
        print_solution();
    }
    return 0;
}