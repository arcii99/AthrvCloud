//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: recursive
#include<stdio.h>

#define N 4

int maze[N][N] = {
    { 1, 0, 0, 0 },
    { 1, 1, 0, 1 },
    { 0, 1, 0, 0 },
    { 1, 1, 1, 1 }
};

int sol[N][N] = {
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 }
};

void printSol();
int solve(int x, int y, int des_x, int des_y);

int main() {
    int start_x = 0, start_y = 0;
    int des_x = 3, des_y = 3;

    if (solve(start_x, start_y, des_x, des_y) == 0) {
        printf("No solution exists\n");
    } else {
        printSol();
    }

    return 0;
}

int solve(int x, int y, int des_x, int des_y) {
    if (x == des_x && y == des_y) {
        sol[x][y] = 1;
        return 1;
    }

    if (x >= N || x < 0 || y >= N || y < 0 || maze[x][y] == 0 || sol[x][y] == 1) {
        return 0;
    }

    sol[x][y] = 1;

    if (solve(x+1, y, des_x, des_y)) {
        return 1;
    }

    if (solve(x, y+1, des_x, des_y)) {
        return 1;
    }

    if (solve(x-1, y, des_x, des_y)) {
        return 1;
    }

    if (solve(x, y-1, des_x, des_y)) {
        return 1;
    }

    sol[x][y] = 0;
    return 0;
}

void printSol() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
}