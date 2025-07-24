//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Cyberpunk
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

int board[SIZE][SIZE] = { 
     {0, 0, 0, 3, 0, 0, 0, 0, 0},
     {2, 7, 0, 0, 0, 5, 0, 0, 8},
     {0, 0, 8, 1, 0, 0, 0, 3, 0},
     {0, 8, 4, 0, 2, 0, 0, 6, 0},
     {5, 0, 0, 0, 0, 0, 0, 0, 1},
     {0, 3, 0, 0, 7, 0, 5, 8, 0},
     {0, 5, 0, 0, 0, 6, 1, 0, 0},
     {8, 0, 0, 9, 0, 0, 0, 2, 3},
     {0, 0, 0, 0, 0, 1, 0, 0, 0}
};

void print_board() {
    printf("+---+---+---+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("| ");
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                printf(". ");
            } else {
                printf("%d ", board[i][j]);
            }
            if (j % 3 == 2) {
                printf("| ");
            }   
        }
        printf("\n");
        if (i % 3 == 2) {
            printf("+---+---+---+\n");
        }
    }
}

bool find_empty(int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                *row = i;
                *col = j;
                return true;
            }
        }
    }
    return false;
}

bool is_valid(int num, int row, int col) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    int r = row - row % 3;
    int c = col - col % 3;
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve() {
    int row, col;
    if (!find_empty(&row, &col)) {
        return true;
    }
    for (int i = 1; i <= SIZE; i++) {
        if (is_valid(i, row, col)) {
            board[row][col] = i;
            if (solve()) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    printf("Welcome to the Cyberpunk Sudoku Solver 1.0\n");
    printf("========================================\n");

    printf("Original Board:\n");
    print_board();

    printf("\nSolving...\n");
    if (solve()) {
        printf("\nSolved Board:\n");
        print_board();
    } else {
        printf("\nNo solution found.\n");
    }

    return 0;
}