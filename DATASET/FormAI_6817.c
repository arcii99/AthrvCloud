//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 10

int matrix[MATRIX_SIZE][MATRIX_SIZE];
int visited[MATRIX_SIZE][MATRIX_SIZE];

void initialize_matrix()
{
    srand(time(NULL));

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix[i][j] = rand() % 2; // Randomly generate 0 or 1
        }
    }
}

void print_matrix()
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void initialize_visited()
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            visited[i][j] = 0;
        }
    }
}

int percolation_dfs(int x, int y)
{
    if (x < 0 || x >= MATRIX_SIZE || y < 0 || y >= MATRIX_SIZE) // out of bounds
    {
        return 0;
    }

    if (visited[x][y] == 1) // already visited
    {
        return 0;
    }

    visited[x][y] = 1; // mark as visited

    if (matrix[x][y] == 0) // blocked
    {
        return 0;
    }

    if (x == MATRIX_SIZE - 1) // bottom row
    {
        return 1;
    }

    return percolation_dfs(x + 1, y)
           || percolation_dfs(x - 1, y)
           || percolation_dfs(x, y + 1)
           || percolation_dfs(x, y - 1); // check adjacent cells
}

int main()
{
    int count = 0;

    initialize_matrix();
    initialize_visited();

    printf("Welcome to Percolation Simulator!\n");
    printf("We have generated a random matrix for you:\n\n");
    print_matrix();

    printf("\nPress enter to start the simulation...\n");
    getchar();

    printf("\nRunning simulation...\n");

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        if (percolation_dfs(0, i))
        {
            count++;
        }
    }

    printf("\nYour matrix has %d percolations!\n", count);

    return 0;
}