//FormAI DATASET v1.0 Category: Computer Biology ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 4           // Number of threads
#define N 100               // Number of cells in grid
#define GENERATIONS 100     // Number of generations to simulate

int grid[N][N];             // Grid to simulate
int temp_grid[N][N];        // Temporary grid for updated values
int thread_data[THREADS];   // Data for each thread

// Function to initialize the grid randomly
void initialize_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the current generation of the grid
void print_grid() {
    printf("Grid:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the number of live neighbors for a given cell
int count_neighbors(int i, int j) {
    int count = 0;
    for (int x = i - 1; x <= i + 1; x++) {
        for (int y = j - 1; y <= j + 1; y++) {
            if (x >= 0 && y >= 0 && x < N && y < N && !(x == i && y == j)) {
                count += grid[x][y];
            }
        }
    }
    return count;
}

// Function to update the grid for a given range of rows
void update_grid(int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = 0; j < N; j++) {
            int neighbors = count_neighbors(i, j);
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                temp_grid[i][j] = 0;
            }
            else if (grid[i][j] == 0 && neighbors == 3) {
                temp_grid[i][j] = 1;
            }
            else {
                temp_grid[i][j] = grid[i][j];
            }
        }
    }
}

// Function for the worker thread
void* worker_thread(void* arg) {
    int thread_id = *((int*) arg);
    int start = thread_id * (N / THREADS);
    int end = (thread_id + 1) * (N / THREADS);
    update_grid(start, end);
    thread_data[thread_id] = 1;
    return NULL;
}

int main() {
    pthread_t threads[THREADS];
    initialize_grid();
    print_grid();
    for (int gen = 0; gen < GENERATIONS; gen++) {
        for (int i = 0; i < THREADS; i++) {
            thread_data[i] = 0;
            pthread_create(&threads[i], NULL, worker_thread, &i);
        }
        for (int i = 0; i < THREADS; i++) {
            pthread_join(threads[i], NULL);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                grid[i][j] = temp_grid[i][j];
            }
        }
        printf("Generation: %d\n", gen+1);
        print_grid();
    }
    return 0;
}