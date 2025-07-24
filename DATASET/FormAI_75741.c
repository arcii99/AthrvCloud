//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 20    // Grid size
#define p 0.5   // Probability of site being open

bool grid[N][N];    // Grid to represent open sites

void initialize_grid() {
    // Initialize grid with closed sites
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = false;
        }
    }
}

void print_grid() {
    // Print the current state of the grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", grid[i][j] ? 'O' : 'X');
        }
        printf("\n");
    }
    printf("\n");
}

void generate_random_sites() {
    // Generate random open sites based on probability p, using time as seed
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((double)rand() / RAND_MAX < p) {
                grid[i][j] = true;
            }
        }
    }
}

bool percolates() {
    // Check if the top row and bottom row are connected
    bool visited[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    // DFS to find all open sites connected to top row
    int stack[N * N][2];
    int top = -1;
    for (int i = 0; i < N; i++) {
        if (grid[0][i]) {
            top++;
            stack[top][0] = 0;
            stack[top][1] = i;
        }
    }
    while (top != -1) {
        int row = stack[top][0];
        int col = stack[top][1];
        top--;
        if (!visited[row][col]) {
            visited[row][col] = true;
            // Check if connected to bottom row
            if (row == N - 1) {
                return true;
            }
            // Add neighbors to stack
            if (col > 0 && grid[row][col-1]) {
                top++;
                stack[top][0] = row;
                stack[top][1] = col-1;
            }
            if (col < N-1 && grid[row][col+1]) {
                top++;
                stack[top][0] = row;
                stack[top][1] = col+1;
            }
            if (row > 0 && grid[row-1][col]) {
                top++;
                stack[top][0] = row-1;
                stack[top][1] = col;
            }
            if (row < N-1 && grid[row+1][col]) {
                top++;
                stack[top][0] = row+1;
                stack[top][1] = col;
            }
        }
    }
    return false;
}

int main() {
    initialize_grid();
    generate_random_sites();
    printf("Initial Grid:\n");
    print_grid();

    if (percolates()) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }
    return 0;
}