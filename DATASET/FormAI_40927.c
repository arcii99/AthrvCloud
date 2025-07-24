//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <time.h>

#define N 10 // Grid size
#define P 0.6 // Percolation probability

int grid[N][N]; // Grid for holding the percolation system
bool percolates = false; // Flag indicating if the system has percolated
pthread_barrier_t barrier; // Barrier for synchronization

// Calculate the neighbor indexes of a cell
void getNeighbors(int row, int col, int neighbors[4][2]) {
    // Upper neighbor
    neighbors[0][0] = row-1;
    neighbors[0][1] = col;
    // Lower neighbor
    neighbors[1][0] = row+1;
    neighbors[1][1] = col;
    // Left neighbor
    neighbors[2][0] = row;
    neighbors[2][1] = col-1;
    // Right neighbor
    neighbors[3][0] = row;
    neighbors[3][1] = col+1;
}

// Check if the system has percolated
bool hasPercolated() {
    // Check if the bottom row is connected to the top row
    for (int j = 0; j < N; j++) {
        if (grid[0][j] == 1 && grid[N-1][j] == 1) {
            return true;
        }
    }
    return false;
}

// Thread function for updating the grid
void* updateGrid(void* arg) {
    int id = *(int*)arg;
    int row, col, value;
    int neighbors[4][2];
    int n = (N*1.0)/pthread_getconcurrency(); // Dividing the grid equally among threads
    int start = (id-1)*n;
    int end = (start+n) - 1;
    if (id == pthread_getconcurrency()) {
        end = N-1;
    }
    
    while (!percolates) {
        // Randomly select a cell
        row = start + rand()%(end-start+1);
        col = rand()%N;
        
        // Skip if the cell is already open
        if (grid[row][col] == 1) {
            continue;
        }
        
        // Determine the state of the cell based on its neighbors
        value = 0;
        getNeighbors(row, col, neighbors);
        for (int i = 0; i < 4; i++) {
            if (neighbors[i][0] >= 0 && neighbors[i][0] < N && neighbors[i][1] >= 0 && neighbors[i][1] < N) {
                if (grid[neighbors[i][0]][neighbors[i][1]] == 1) {
                    value = 1;
                    break;
                }
            }
        }
        grid[row][col] = value;
        
        // Synchronize the threads
        pthread_barrier_wait(&barrier);
        
        // Check if the system has percolated
        if (hasPercolated()) {
            percolates = true;
            printf("System percolated!\n");
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int num_threads = 4;
    pthread_t threads[num_threads];
    pthread_barrier_init(&barrier, NULL, num_threads);
    int thread_ids[num_threads];
    
    // Initialize the system
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((double) rand()/RAND_MAX <= P) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    
    // Print the initial grid
    printf("Initial grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    // Create and start threads
    for (int i = 0; i < num_threads; i++) {
        thread_ids[i] = i+1;
        pthread_create(&threads[i], NULL, updateGrid, &thread_ids[i]);
    }
    
    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print the final grid
    printf("Final grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    pthread_barrier_destroy(&barrier);
    return 0;
}