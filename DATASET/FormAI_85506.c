//FormAI DATASET v1.0 Category: Sudoku solver ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 9

int sudoku[SIZE][SIZE] = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
                           { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
                           { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
                           { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
                           { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
                           { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
                           { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
                           { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
                           { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };

// Define struct for passing information into threads
typedef struct {
    int row;
    int col;
    int isValid;
} thread_arg;

// Check row for validity
void *check_row(void *arg) {
    thread_arg *t_arg = (thread_arg *) arg;

    int unique[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        int val = sudoku[t_arg->row][i];
        if (unique[val-1] != 0) {
            t_arg->isValid = 0;
            pthread_exit(NULL);
        }
        unique[val-1] = 1;
    }

    t_arg->isValid = 1;
    pthread_exit(NULL);
}

// Check column for validity
void *check_col(void *arg) {
    thread_arg *t_arg = (thread_arg *) arg;

    int unique[SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        int val = sudoku[i][t_arg->col];
        if (unique[val-1] != 0) {
            t_arg->isValid = 0;
            pthread_exit(NULL);
        }
        unique[val-1] = 1;
    }

    t_arg->isValid = 1;
    pthread_exit(NULL);
}

// Check subgrid for validity
void *check_subgrid(void *arg) {
    thread_arg *t_arg = (thread_arg *) arg;

    int unique[SIZE] = {0};

    int start_row = t_arg->row / 3 * 3;
    int start_col = t_arg->col / 3 * 3;

    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            int val = sudoku[i][j];
            if (unique[val-1] != 0) {
                t_arg->isValid = 0;
                pthread_exit(NULL);
            }
            unique[val-1] = 1;
        }
    }

    t_arg->isValid = 1;
    pthread_exit(NULL);
}

int main() {

    // Create threads
    pthread_t threads[27];

    // Create structs for passing information into threads
    thread_arg args[27];

    // Initialize thread arguments
    for (int i = 0; i < SIZE; i++) {
        args[i].row = i;
        args[i].col = i;
        args[i+SIZE].row = i;
        args[i+SIZE].col = i;
        args[i+SIZE*2].row = (i % 3) * 3;
        args[i+SIZE*2].col = (i / 3) * 3;
    }

    // Execute threads for checking rows, columns, and subgrids
    int counter = 0;

    for (int i = 0; i < SIZE; i++) {
        pthread_create(&threads[counter++], NULL, check_row, &args[i]);
        pthread_create(&threads[counter++], NULL, check_col, &args[i+SIZE]);
        pthread_create(&threads[counter++], NULL, check_subgrid, &args[i+SIZE*2]);
    }

    // Wait for threads to finish
    for (int i = 0; i < 27; i++) {
        pthread_join(threads[i], NULL);
    }

    // Check validity
    int valid = 1;

    for (int i = 0; i < 27; i++) {
        if (args[i].isValid == 0) {
            valid = 0;
            break;
        }
    }

    if (valid) {
        printf("Sudoku solution is valid.\n");
    } else {
        printf("Sudoku solution is invalid.\n");
    }

    return 0;
}