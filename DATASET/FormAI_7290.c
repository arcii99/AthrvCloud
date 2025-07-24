//FormAI DATASET v1.0 Category: Game of Life ; Style: funny
// Welcome to the Game of Life, where life is never boring!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void initialize_board(char board[ROWS][COLS]) {
    // This function initializes the board randomly with 'X's and 'O's
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int rand_num = rand() % 2;
            if (rand_num == 1) {
                board[i][j] = 'X';
            } else {
                board[i][j] = 'O';
            }
        }
    }
}

void print_board(char board[ROWS][COLS]) {
    // This function prints the board with proper formatting
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(char board[ROWS][COLS], int row, int col) {
    // This function counts the number of live neighbors around a cell
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)
                && board[i][j] == 'X') {
                count++;
            }
        }
    }
    return count;
}

void update_board(char board[ROWS][COLS]) {
    // This function updates the board based on the rules of the Game of Life
    char new_board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j] == 'X') {
                if (neighbors < 2 || neighbors > 3) {
                    new_board[i][j] = 'O';
                } else {
                    new_board[i][j] = 'X';
                }
            } else {
                if (neighbors == 3) {
                    new_board[i][j] = 'X';
                } else {
                    new_board[i][j] = 'O';
                }
            }
        }
    }
    // Copy new board to old board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    // Let's play the Game of Life!
    char board[ROWS][COLS];
    initialize_board(board);
    printf("Welcome to the Game of Life!\n");
    printf("Press any key to start or 'q' to quit: ");
    char input = getchar();
    while (input != 'q') {
        print_board(board);
        update_board(board);
        printf("Press any key to continue or 'q' to quit: ");
        input = getchar();
    }
    printf("Thanks for playing the Game of Life! See you again soon!");
    return 0;
}