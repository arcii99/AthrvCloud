//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10

bool percolated(int arr[N][N], int row, int col) {
    bool visited[N][N] = { false };
    int queue[N*N];
    int front = 0;
    int rear = -1;

    visited[row][col] = true;
    queue[++rear] = row * N + col;

    while (front <= rear) {
        int index = queue[front++];
        int r = index / N;
        int c = index % N;

        if (r == N - 1) {
            return true;
        }

        // Checking for neighboring connections
        if (r+1 < N && arr[r+1][c] == 1 && !visited[r+1][c]) {
            visited[r+1][c] = true;
            queue[++rear] = (r+1) * N + c;
        }
        if (r-1 >= 0 && arr[r-1][c] == 1 && !visited[r-1][c]) {
            visited[r-1][c] = true;
            queue[++rear] = (r-1) * N + c;
        }
        if (c+1 < N && arr[r][c+1] == 1 && !visited[r][c+1]) {
            visited[r][c+1] = true;
            queue[++rear] = r * N + (c+1);
        }
        if (c-1 >= 0 && arr[r][c-1] == 1 && !visited[r][c-1]) {
            visited[r][c-1] = true;
            queue[++rear] = r * N + (c-1);
        }
    }

    return false;
}

void printGrid(int arr[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main(void) {
    int grid[N][N] = {0};
    srand(time(NULL));

    // Introducing percolation barrier
    // Randomly selecting cells to set value as 1, implying open passage
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rand() % 2 == 0) {
                grid[i][j] = 1;
            }
        }   
    }

    // Displaying initial percolation
    printf("Initial percolation:\n");
    printGrid(grid);

    // Checking for percolation
    if (percolated(grid, 0, 0)) {
        printf("Percolation successful!\n");
    } else {
        printf("No percolation.\n");
    }

    return 0;
}