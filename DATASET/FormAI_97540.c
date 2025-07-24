//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

#define N 9

int grid[N][N];

int used_row[N][N + 1];
int used_col[N][N + 1];
int used_box[N][N + 1];

typedef struct {
    int row;
    int col;
} parameters;

void print_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int solve_sudoku(int row, int col) {
    if (row == N) {
        return 1;
    }
    if (col == N) {
        return solve_sudoku(row + 1, 0);
    }
    if (grid[row][col]) {
        return solve_sudoku(row, col + 1);
    }
    int i, j, k;
    for (k = 1; k <= N; k++) {
        i = row / 3 * 3 + col / 3;
        j = row % 3 * 3 + col % 3;
        if (!used_row[row][k] && !used_col[col][k] && !used_box[i][k]) {
            used_row[row][k] = used_col[col][k] = used_box[i][k] = 1;
            grid[row][col] = k;
            if (solve_sudoku(row, col + 1)) {
                return 1;
            }
            used_row[row][k] = used_col[col][k] = used_box[i][k] = 0;
            grid[row][col] = 0;
        }
    }
    return 0;
}

void *solve_sudoku_wrap(void *args) {
    parameters *params = (parameters *) args;
    int row = params->row;
    int col = params->col;
    solve_sudoku(row, col);
    return NULL;
}

void solve_multi_threaded() {
    pthread_t threads[N];
    int ret[N];
    parameters params[N];

    for (int i = 0; i < N; i++) {
        params[i].row = i;
        params[i].col = 0;
        ret[i] = pthread_create(&threads[i], NULL, solve_sudoku_wrap, &params[i]);
        if (ret[i]) {
            printf("Error - pthread_create() return code: %d\n", ret[i]);
            return;
        }
    }

    for (int i = 0; i < N; i++) {
        ret[i] = pthread_join(threads[i], NULL);
        if (ret[i]) {
            printf("Error - pthread_join() return code: %d\n", ret[i]);
            return;
        }
    }
}

int main() {
    // Initialize grid with Sudoku problem
    grid[0][3] = 2;
    grid[0][6] = 6;
    grid[0][8] = 7;
    grid[1][1] = 6;
    grid[1][2] = 7;
    grid[1][5] = 6;
    grid[1][6] = 9;
    grid[2][1] = 3;
    grid[2][2] = 4;
    grid[2][6] = 8;
    grid[3][2] = 8;
    grid[3][3] = 9;
    grid[3][5] = 2;
    grid[3][7] = 5;
    grid[4][0] = 6;
    grid[4][2] = 3;
    grid[4][6] = 1;
    grid[4][8] = 4;
    grid[5][1] = 5;
    grid[5][3] = 7;
    grid[5][5] = 1;
    grid[5][6] = 2;
    grid[6][2] = 7;
    grid[6][6] = 2;
    grid[6][7] = 4;
    grid[7][2] = 5;
    grid[7][3] = 2;
    grid[7][6] = 3;
    grid[7][7] = 6;
    grid[8][0] = 8;
    grid[8][2] = 9;
    grid[8][5] = 7;
    grid[8][8] = 5;

    printf("Sudoku problem:\n");
    print_grid();

    printf("Solving Sudoku...\n");
    solve_multi_threaded();

    printf("Sudoku solution:\n");
    print_grid();

    return 0;
}