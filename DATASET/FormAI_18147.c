//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>

#define N 9
#define UNASSIGNED 0

int sudoku[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                     { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                     { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                     { 0, 0, 3, 0, 0, 0, 0, 2, 0 },
                     { 9, 0, 0, 8, 0, 0, 0, 0, 5 },
                     { 0, 5, 0, 0, 0, 0, 6, 0, 0 },
                     { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                     { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                     { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

typedef struct {
    int row;
    int col;
} parameters;

bool find_unassigned(int *row, int *col){
    for (*row = 0; *row < N; ++*row){
        for (*col = 0; *col < N; ++*col){
            if(sudoku[*row][*col] == UNASSIGNED)
                return true;
        }
    }
    return false;
}

bool is_row_safe(int row, int num){
    for(int col = 0; col < N; ++col){
        if(sudoku[row][col] == num)
            return false;
    }
    return true;
}

bool is_col_safe(int col, int num){
    for(int row = 0; row < N; ++row){
        if(sudoku[row][col] == num)
            return false;
    }
    return true;
}

bool is_square_safe(int box_start_row, int box_start_col, int num){
    for(int row = 0; row < 3; ++row){
        for(int col = 0; col < 3; ++col){
            if(sudoku[box_start_row + row][box_start_col + col] == num)
                return false;
        }
    }
    return true;
}

bool is_safe(int row, int col, int num){
    return is_row_safe(row, num) && is_col_safe(col, num) && is_square_safe(row - row % 3, col - col % 3, num);
}

void *solve_sudoku(void *arg){
    parameters *data = arg;
    int row = data -> row;
    int col = data -> col;
    if(col == N){
        col = 0;
        ++row;
    }
    if(row == N)
        return NULL;
    if(sudoku[row][col] != UNASSIGNED)
        return solve_sudoku(&(parameters){row, col + 1});
    for(int num = 1; num <= 9; ++num){
        if(is_safe(row, col, num)){
            sudoku[row][col] = num;
            if(solve_sudoku(&(parameters){row, col + 1}))
                return true;
            sudoku[row][col] = UNASSIGNED;
        }
    }
    return false;
}

void print_sudoku(){
    for(int i = 0; i < N; ++i){
        if(i%3 == 0 && i != 0)
            printf("-----------------------\n");
        for(int j = 0; j < N; ++j){
            if(j%3 == 0 && j != 0)
                printf("| ");
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    print_sudoku();

    pthread_t thread_sudoku_solver;
    pthread_create(&thread_sudoku_solver, NULL, solve_sudoku, &(parameters){0, 0});
    pthread_join(thread_sudoku_solver, NULL);

    print_sudoku();

    return 0;
}