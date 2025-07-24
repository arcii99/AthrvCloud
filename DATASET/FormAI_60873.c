//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <omp.h>

#define N 100
#define p 0.6

bool is_percolated[N][N];

// Function to initialize the grid randomly with probability p
void initialize_grid(int grid[N][N]) {
    int i, j;
    double rand_num;
    srand(time(NULL));
    #pragma omp parallel for private(i, j, rand_num)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            rand_num = (double) rand() / RAND_MAX;
            if (rand_num < p) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

// Function to print the grid
void print_grid(int grid[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Function to check if the system has percolated
bool has_percolated(int grid[N][N], int row, int col) {
    bool is_visited[N][N];
    int i, j;
    // Initialize is_visited array to false
    #pragma omp parallel for private(i, j)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            is_visited[i][j] = false;
        }
    }
    // Create a queue for BFS
    int queue[2 * N * N];
    int queue_size = 0;
    // Add the starting cell to queue and mark as visited
    queue[queue_size++] = row * N + col;
    is_visited[row][col] = true;
    // BFS begins here
    while (queue_size > 0) {
        int curr_cell = queue[0];
        queue_size--;
        // Get coordinates of current cell
        int curr_row = curr_cell / N;
        int curr_col = curr_cell % N;
        // Check if current cell is at the bottom of the grid
        if (curr_row == N - 1) {
            return true;
        }
        // Check neighboring cells
        if (curr_row > 0 && grid[curr_row - 1][curr_col] == 1 && !is_visited[curr_row - 1][curr_col]) {
            queue[queue_size++] = (curr_row - 1) * N + curr_col;
            is_visited[curr_row - 1][curr_col] = true;
        }
        if (curr_row < N - 1 && grid[curr_row + 1][curr_col] == 1 && !is_visited[curr_row + 1][curr_col]) {
            queue[queue_size++] = (curr_row + 1) * N + curr_col;
            is_visited[curr_row + 1][curr_col] = true;
        }
        if (curr_col > 0 && grid[curr_row][curr_col - 1] == 1 && !is_visited[curr_row][curr_col - 1]) {
            queue[queue_size++] = curr_row * N + (curr_col - 1);
            is_visited[curr_row][curr_col - 1] = true;
        }
        if (curr_col < N - 1 && grid[curr_row][curr_col + 1] == 1 && !is_visited[curr_row][curr_col + 1]) {
            queue[queue_size++] = curr_row * N + (curr_col + 1);
            is_visited[curr_row][curr_col + 1] = true;
        }
    }
    return false;
}

int main() {
    int i, j;
    int grid[N][N];
    // Initialize the grid randomly with given probability
    initialize_grid(grid);
    // Print the grid
    printf("Initial Grid:\n");
    print_grid(grid);
    // Check if the system has percolated for each cell in the top row
    #pragma omp parallel for private(i, j)
    for (i = 0; i < N; i++) {
        if (grid[0][i] == 1 && has_percolated(grid, 0, i)) {
            is_percolated[0][i] = true;
        }
    }
    // Check if the system has percolated for each cell in the remaining rows
    #pragma omp parallel for private(i, j)
    for (i = 1; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (grid[i][j] == 1 && (is_percolated[i - 1][j] || (j > 0 && is_percolated[i - 1][j - 1]) || (j < N - 1 && is_percolated[i - 1][j + 1]))) {
                is_percolated[i][j] = true;
            }
        }
    }
    // Print the results
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (is_percolated[i][j]) {
                printf("(%d,%d) ", i, j);
            }
        }
    }
    printf("percolate.\n");
    return 0;
}