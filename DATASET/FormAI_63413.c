//FormAI DATASET v1.0 Category: Sudoku solver ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define GRID_SIZE 9
#define NUM_THREADS 9

int grid[GRID_SIZE][GRID_SIZE] = {
    {0, 3, 0, 0, 8, 0, 4, 0, 0},
    {7, 0, 0, 0, 0, 0, 0, 0, 9},
    {0, 0, 0, 4, 0, 7, 2, 6, 0},
    {0, 0, 6, 1, 0, 0, 0, 0, 4},
    {8, 0, 0, 0, 0, 0, 0, 0, 5},
    {5, 0, 0, 0, 0, 6, 3, 0, 0},
    {0, 7, 5, 9, 0, 8, 0, 0, 0},
    {4, 0, 0, 0, 0, 0, 0, 0, 3},
    {0, 0, 8, 0, 3, 0, 0, 4, 0}
};

bool used_in_row(int row, int num) {
    for(int col = 0; col < GRID_SIZE; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool used_in_col(int col, int num) {
    for(int row = 0; row < GRID_SIZE; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool used_in_square(int start_row, int start_col, int num) {
    for(int row = start_row; row < start_row+3; row++) {
        for(int col = start_col; col < start_col+3; col++) {
            if (grid[row][col] == num) {
                return true;
            }
        }
    }
    return false;
}

bool is_valid(int row, int col, int num) {
    return !used_in_row(row, num) && !used_in_col(col, num) && !used_in_square(row-row%3, col-col%3, num);
}

bool find_unassigned_location(int *row, int *col) {
    for(*row = 0; *row < GRID_SIZE; (*row)++) {
        for(*col = 0; *col < GRID_SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

void *solve_sudoku(void *threadid) {
    int tid = (int)(long)threadid;
    int row, col;
    
    if (find_unassigned_location(&row, &col) == false) {
        pthread_exit(NULL);
    }
    
    for(int num = 1; num <= GRID_SIZE; num++) {
        if (is_valid(row, col, num)) {
            grid[row][col] = num;
            solve_sudoku(threadid);
            grid[row][col] = 0;
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    
    for(int tid = 0; tid < NUM_THREADS; tid++) {
        rc = pthread_create(&threads[tid], NULL, solve_sudoku, (void *)(long)tid);
        if (rc) {
            fprintf(stderr, "Error creating thread: %d\n", rc);
            exit(-1);
        }
    }
    
    for(int tid = 0; tid < NUM_THREADS; tid++) {
        pthread_join(threads[tid], NULL);
    }
    
    printf("Solution:\n");
    for(int row = 0; row < GRID_SIZE; row++) {
        for(int col = 0; col < GRID_SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
    
    return 0;
}