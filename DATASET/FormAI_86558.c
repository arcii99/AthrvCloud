//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 30

int matrix[SIZE][SIZE];
bool visited[SIZE][SIZE];
int counter = 0;

void percolate(int row, int col)
{
    if (row < 0 || col < 0 || row >= SIZE || col >= SIZE)
        return;
    if (visited[row][col] || matrix[row][col] == 0)
        return;
    visited[row][col] = true;
    counter++;
    percolate(row + 1, col);
    percolate(row - 1, col);
    percolate(row, col + 1);
    percolate(row, col - 1);
}

int main()
{
    // Initialize random number generator
    srand(time(NULL));

    // Generate matrix with random 0s and 1s
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }

    // Print initial matrix
    printf("Initial Matrix:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

    // Simulate percolation
    for (int i = 0; i < SIZE; i++)
    {
        if (matrix[0][i] == 1 && !visited[0][i])
        {
            percolate(0, i);
        }
    }

    // Print final matrix with percolation
    printf("Final Matrix:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (visited[i][j])
                printf("%d", matrix[i][j]);
            else
                printf("0");
        }
        printf("\n");
    }

    // Print number of sites visited
    printf("Number of sites visited: %d\n", counter);

    return 0;
}