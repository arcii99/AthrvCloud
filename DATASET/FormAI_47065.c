//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int grid[SIZE][SIZE], visited[SIZE][SIZE], top[SIZE], bottom[SIZE];

// A function to check if a given cell is valid to visit or not
int is_valid(int row, int col)
{
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE)
        return 1;
    else
        return 0;
}

// A DFS function to visit all the connected cells
void dfs(int row, int col, int label)
{
    visited[row][col] = 1;
    grid[row][col] = label;
    if (row == 0)
        top[col] = label;
    if (row == SIZE - 1)
        bottom[col] = label;
    if (is_valid(row-1, col) && grid[row-1][col] == 1 && visited[row-1][col] == 0)
        dfs(row-1, col, label);
    if (is_valid(row+1, col) && grid[row+1][col] == 1 && visited[row+1][col] == 0)
        dfs(row+1, col, label);
    if (is_valid(row, col-1) && grid[row][col-1] == 1 && visited[row][col-1] == 0)
        dfs(row, col-1, label);
    if (is_valid(row, col+1) && grid[row][col+1] == 1 && visited[row][col+1] == 0)
        dfs(row, col+1, label);
}

// A function to print the grid with labels
void print_grid()
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// A function to check if the grid percolates or not
int does_percolate()
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (top[i] == bottom[j] && top[i] != 0) {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    srand(time(0));
    int num_attempts = 5;
    printf("Detective Holmes is investigating a percolation case in a %d x %d grid.\n", SIZE, SIZE);
    while (num_attempts--) {
        printf("\nAttempt number %d:\n", 5-num_attempts);
        // Initialize the grid randomly
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int random_num = rand() % 2;
                grid[i][j] = random_num;
                visited[i][j] = 0;
            }
        }
        // Run DFS to visit all the connected cells
        int label = 1;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    dfs(i, j, label++);
                }
            }
        }
        // Print the grid with labels
        printf("Grid with labels:\n");
        print_grid();
        // Check if the grid percolates or not
        if (does_percolate()) {
            printf("The grid percolates!\n");
            break;
        }
        else {
            printf("The grid does not percolate.\n");
        }
    }
    printf("\nDetective Holmes has successfully solved the case.\n");
    return 0;
}