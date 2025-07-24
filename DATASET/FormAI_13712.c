//FormAI DATASET v1.0 Category: Sudoku solver ; Style: asynchronous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

// size of the sudoku puzzle
#define SIZE 9

// struct to store coordinate pairs
typedef struct {
    int row;
    int col;
} Coordinate;

// struct to pass data to thread functions
typedef struct {
    int** puzzle;
    Coordinate start;
    bool* result;
} ThreadData;

// check if a given value is valid in a given cell
bool isValid(int** puzzle, int row, int col, int val) {
    // check row
    for (int c = 0; c < SIZE; c++) {
        if (puzzle[row][c] == val && c != col)
            return false;
    }

    // check column
    for (int r = 0; r < SIZE; r++) {
        if (puzzle[r][col] == val && r != row)
            return false;
    }

    // check 3x3 box
    int boxStartRow = (row / 3) * 3;
    int boxStartCol = (col / 3) * 3;
    for (int r = boxStartRow; r < boxStartRow + 3; r++) {
        for (int c = boxStartCol; c < boxStartCol + 3; c++) {
            if (puzzle[r][c] == val && r != row && c != col)
                return false;
        }
    }
    
    // if all checks pass, the value is valid
    return true;
}

// function to solve a sudoku puzzle
void* solvePuzzle(void* data) {
    // get thread data
    ThreadData* threadData = (ThreadData*) data;
    int** puzzle = threadData->puzzle;
    Coordinate start = threadData->start;
    bool* result = threadData->result;

    // check if puzzle is complete
    bool complete = true;
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (puzzle[r][c] == 0) {
                complete = false;
                break;
            }
        }
        if (!complete)
            break;
    }

    // if puzzle is complete, set result flag and exit thread
    if (complete) {
        *result = true;
        pthread_exit(NULL);
    }

    // iterate through possible values for the starting cell
    for (int i = 1; i <= SIZE; i++) {
        // check if value is valid
        if (isValid(puzzle, start.row, start.col, i)) {
            // create copy of puzzle to modify
            int** copy = malloc(SIZE * sizeof(int*));
            for (int r = 0; r < SIZE; r++) {
                copy[r] = malloc(SIZE * sizeof(int));
                for (int c = 0; c < SIZE; c++) {
                    copy[r][c] = puzzle[r][c];
                }
            }

            // set valid value in copy
            copy[start.row][start.col] = i;

            // create thread data for next cell
            ThreadData nextData = {copy, start, result};
            if (start.col < SIZE - 1) {
                nextData.start.col = start.col + 1;
            }
            else {
                nextData.start.col = 0;
                nextData.start.row = start.row + 1;
            }

            // create thread for next cell
            pthread_t nextThread;
            pthread_create(&nextThread, NULL, solvePuzzle, &nextData);

            // wait for thread to complete
            pthread_join(nextThread, NULL);

            // check if puzzle is solved
            if (*result) {
                // free memory and exit thread
                for (int r = 0; r < SIZE; r++) {
                    free(copy[r]);
                }
                free(copy);
                pthread_exit(NULL);
            }
            else {
                // free memory and continue to next value
                for (int r = 0; r < SIZE; r++) {
                    free(copy[r]);
                }
                free(copy);
            }
        }
    }

    // if no valid values are found, set result flag and exit thread
    *result = false;
    pthread_exit(NULL);
}

int main() {
    // initialize puzzle (0 = empty cell)
    int puzzle[SIZE][SIZE] = {
        {0, 6, 0, 3, 0, 0, 8, 0, 4},
        {5, 3, 7, 0, 9, 0, 0, 0, 0},
        {0, 4, 0, 0, 0, 6, 3, 0, 7},
        {0, 9, 0, 0, 5, 1, 2, 3, 8},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {7, 1, 3, 6, 2, 0, 0, 4, 0},
        {3, 0, 6, 4, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 6, 0, 5, 2, 3},
        {1, 0, 2, 0, 0, 9, 0, 8, 0}
    };

    // print initial puzzle
    printf("Initial puzzle:\n");
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            printf("%d ", puzzle[r][c]);
        }
        printf("\n");
    }
    printf("\n");

    // create thread data for starting cell
    Coordinate start = {0, 0};
    bool result = false;
    ThreadData data = {(int**) puzzle, start, &result};
    solvePuzzle(&data);

    // print solution
    if (result) {
        printf("Solution:\n");
        int** solution = data.puzzle;
        for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                printf("%d ", solution[r][c]);
            }
            printf("\n");
        }
    }
    else {
        printf("No solution found.\n");
    }

    return 0;
}