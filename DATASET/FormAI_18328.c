//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int sites[N][N];
int opened[N][N];
int num_open = 0;
int root_found = 0;

void print_sites() 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            printf("%d ", sites[i][j]);
        }
        printf("\n");
    }
}

void print_opened() 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            printf("%d ", opened[i][j]);
        }
        printf("\n");
    }
}

void open(int row, int col) 
{
    if (row >= 0 && row < N && col >= 0 && col < N) 
    {
        if (sites[row][col] == 1 && opened[row][col] == 0) 
        {
            opened[row][col] = 1;
            num_open++;
            if (row == N - 1) 
            {
                root_found = 1;
            }
            open(row - 1, col);
            open(row + 1, col);
            open(row, col - 1);
            open(row, col + 1);
        }
    }
}

void percolate() 
{
    while (!root_found) 
    {
        int row = rand() % N;
        int col = rand() % N;
        open(row, col);
    }
}

int main() 
{
    srand(time(NULL));
    // Initialize sites randomly
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            sites[i][j] = rand() % 2;
        }
    }
    printf("Initial Sites:\n");
    print_sites();
    printf("\n");
    percolate();
    printf("Percolation Complete:\n");
    print_opened();
    printf("\nNumber of open sites: %d\n", num_open);
    return 0;
}