//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define P 0.6 // Default percolation probability

char grid[N][N];
char visited[N][N];

void initialize_grid() {
    srand(time(NULL)); // Seed the random number generator with the current time
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float r = (float) rand() / RAND_MAX; // Generate a random float between 0 and 1
            if (r < P) {
                grid[i][j] = ' '; // Empty cell
            } else {
                grid[i][j] = '#'; // Blocked cell
            }
            visited[i][j] = 0; // Not yet visited
        }
    }
}

void print_grid() {
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int percolates(int row, int col) {
    if (visited[row][col]) {
        return 0; // Already visited this cell
    }
    visited[row][col] = 1; // Mark cell as visited
    if (row == N - 1) {
        return 1; // Found a path to the bottom of the grid
    }
    if (grid[row][col] == '#') {
        return 0; // This cell is blocked
    }
    int left_percolates = 0, right_percolates = 0, down_percolates = 0;
    if (col > 0) {
        left_percolates = percolates(row, col - 1);
    }
    if (col < N - 1) {
        right_percolates = percolates(row, col + 1);
    }
    if (row < N - 1) {
        down_percolates = percolates(row + 1, col);
    }
    return left_percolates || right_percolates || down_percolates;
}

int main() {
    printf("Welcome to the Percolation Simulator!\n");
    printf("Initializing grid with percolation probability P = %f\n", P);
    initialize_grid();
    print_grid();
    int percolates_flag = 0;
    for (int j = 0; j < N; j++) {
        if (percolates(0, j)) {
            percolates_flag = 1;
            break;
        }
    }
    if (percolates_flag) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }
    return 0;
}