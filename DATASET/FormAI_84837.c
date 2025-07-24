//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define SIZE 10
#define THRESHOLD 0.6

// Function declarations
int percolate(int grid[SIZE][SIZE]);
void print_grid(int grid[SIZE][SIZE]);

int main()
{
    // Initialize grid with random values
    int grid[SIZE][SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = (double) rand() / RAND_MAX < THRESHOLD;
        }
    }

    // Print initial grid
    printf("Initial grid:\n");
    print_grid(grid);

    // Percolate the grid
    int percolated = percolate(grid);

    // Print final grid and whether it percolated
    printf("\nFinal grid:\n");
    print_grid(grid);
    if (percolated) {
        printf("The grid percolated!\n");
    } else {
        printf("The grid did not percolate.\n");
    }

    return 0;
}

/* Function to percolate the grid */
int percolate(int grid[SIZE][SIZE])
{
    int top[SIZE], bottom[SIZE], visited[SIZE][SIZE];
    // Set all cells as unvisited
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            visited[i][j] = 0;
        }
    }

    // Check top to bottom
    for (int i = 0; i < SIZE; i++) {
        if (grid[0][i]) {
            visited[0][i] = 1;
            top[i] = 1;
        }
        if (grid[SIZE-1][i]) {
            visited[SIZE-1][i] = 1;
            bottom[i] = 1;
        }
    }

    int percolated = 0;
    int queue[SIZE*SIZE], front = 0, rear = -1;
    for (int i = 0; i < SIZE; i++) {
        if (top[i]) {
            queue[++rear] = i;
        }
    }
    while (front <= rear) {
        int current = queue[front], row = 1, col = current;
        front++;
        if (bottom[current]) {
            // Found a percolating path
            percolated = 1;
            break;
        }
        if (col < SIZE-1 && grid[row][col+1] && !visited[row][col+1]) {
            visited[row][col+1] = 1;
            queue[++rear] = col+1;
        }
        if (col > 0 && grid[row][col-1] && !visited[row][col-1]) {
            visited[row][col-1] = 1;
            queue[++rear] = col-1;
        }
        if (row < SIZE-1 && grid[row+1][col] && !visited[row+1][col]) {
            visited[row+1][col] = 1;
            queue[++rear] = col;
        }
        if (row > 0 && grid[row-1][col] && !visited[row-1][col]) {
            visited[row-1][col] = 1;
            queue[++rear] = col;
        }
    }

    return percolated;
}

/* Function to print the grid */
void print_grid(int grid[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}