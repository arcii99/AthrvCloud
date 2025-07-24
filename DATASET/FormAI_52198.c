//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

#define N 20 // Size of the grid
#define THREAD_COUNT 5 // Number of threads

// Global variables
int grid[N][N] = {0};
bool percolates = false;

// Struct to be passed to the threads
struct thread_data
{
    int thread_id;
    int start_row;
    int end_row;
};

// Function to print the grid
void printGrid()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the system percolates
void checkPercolation()
{
    for(int i=0; i<N; i++)
    {
        if(grid[0][i] == 1 && grid[N-1][i] == 1)
        {
            percolates = true;
            break;
        }
    }
}

// Function to perform percolation with a single thread
void* percolationThread(void* arg)
{
    int row_start = ((struct thread_data*)arg)->start_row;
    int row_end = ((struct thread_data*)arg)->end_row;
    
    for(int i=row_start; i<=row_end; i++)
    {
        for(int j=0; j<N; j++)
        {
            int neighbors[4][2] = {{i-1, j}, {i+1, j}, {i, j-1}, {i, j+1}};
            int count = 0;
            for(int k=0; k<4; k++)
            {
                if(neighbors[k][0] >= 0 && neighbors[k][0] < N && neighbors[k][1] >= 0 && neighbors[k][1] < N)
                {
                    if(grid[neighbors[k][0]][neighbors[k][1]] == 1)
                    {
                        count++;
                    }
                }
            }
            if(count >= 2)
            {
                grid[i][j] = 1;
            }
        }
    }
    return NULL;
}

// Main function
int main()
{
    // Initialize the grid
    srand(time(NULL));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if((rand() % 100) < 60)
            {
                grid[i][j] = 1;
            }
        }
    }
    
    printGrid();
    
    // Create threads
    pthread_t threads[THREAD_COUNT];
    int thread_row_count = N / THREAD_COUNT;
    struct thread_data td[THREAD_COUNT];
    for(int i=0; i<THREAD_COUNT; i++)
    {
        td[i].thread_id = i;
        td[i].start_row = i * thread_row_count;
        td[i].end_row = (i+1) * thread_row_count - 1;
        if(i == (THREAD_COUNT-1))
        {
            td[i].end_row = N-1;
        }
        pthread_create(&threads[i], NULL, percolationThread, (void*)&td[i]);
    }
    
    // Wait for threads to finish
    for(int i=0; i<THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    printGrid();
    
    // Check if the system percolates
    checkPercolation();
    if(percolates)
    {
        printf("System percolates!\n");
    }
    else
    {
        printf("System does not percolate.\n");
    }
    
    return 0;
}