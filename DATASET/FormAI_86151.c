//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int grid[N][N];
int visited[N][N];
int openSites = 0;

void initializeGrid();
void printGrid();
void percolate();
int dfs(int row, int col);
int isOpen(int row, int col);
int isFull(int row, int col);

int main()
{
    srand(time(0));
    initializeGrid();
    printf("Initial Grid:\n");
    printGrid();

    percolate();
    printf("Percolated Grid:\n");
    printGrid();

    printf("Percolation threshold = %f\n", (float) openSites / (N * N));
}

void initializeGrid()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void printGrid()
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf(" # ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void percolate()
{
    int success = 0;
    while (success == 0) {
        int start = rand() % N;
        if (dfs(start, 0) == 1) {
            success = 1;
        }
    }
}

int dfs(int row, int col)
{
    if (row < 0 || row >= N || col < 0 || col >= N) {
        return 0;
    }
    if (visited[row][col] == 1) {
        return 0;
    }
    visited[row][col] = 1;
    if (isOpen(row, col) == 0) {
        return 0;
    }
    if (col == N - 1) {
        return 1;
    }
    openSites++;
    int result = dfs(row - 1, col) || dfs(row + 1, col) || dfs(row, col - 1) || dfs(row, col + 1);
    if (result == 1) {
        return 1;
    }
    return 0;
}

int isOpen(int row, int col)
{
    return grid[row][col] == 1;
}

int isFull(int row, int col)
{
    if (visited[row][col] == 1) {
        return 0;
    }
    if (grid[row][col] == 0) {
        return 0;
    }
    visited[row][col] = 1;
    int result = isFull(row - 1, col) || isFull(row + 1, col) || isFull(row, col - 1) || isFull(row, col + 1);
    if (col == N - 1) {
        return result;
    }
    if (result == 1) {
        return 1;
    }
    return 0;
}