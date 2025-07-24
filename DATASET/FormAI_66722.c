//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5

// Function to display the bingo board
void display_board(int board[ROWS][COLS], int num_calls) {
    int row, col;
    printf("Number of calls: %d\n", num_calls);
    printf("   B  I  N  G  O\n");
    for (row = 0; row < ROWS; row++) {
        printf("%d ", row+1);
        for (col = 0; col < COLS; col++) {
            printf("%2d ", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a row, column or diagonal has been matched
int check_winner(int board[ROWS][COLS]) {
    int i, j, full_row, full_col, full_diag;
    // Check rows
    for (i = 0; i < ROWS; i++) {
        full_row = 1;
        for (j = 0; j < COLS; j++) {
            if (board[i][j] != -1) {
                full_row = 0;
                break;
            }
        }
        if (full_row) {
            return 1;
        }
    }
    // Check columns
    for (i = 0; i < COLS; i++) {
        full_col = 1;
        for (j = 0; j < ROWS; j++) {
            if (board[j][i] != -1) {
                full_col = 0;
                break;
            }
        }
        if (full_col) {
            return 1;
        }
    }
    // Check diagonal from top left to bottom right
    full_diag = 1;
    for (i = 0; i < ROWS; i++) {
        if (board[i][i] != -1) {
            full_diag = 0;
            break;
        }
    }
    if (full_diag) {
        return 1;
    }
    // Check diagonal from top right to bottom left
    full_diag = 1;
    for (i = 0; i < ROWS; i++) {
        if (board[i][COLS-i-1] != -1) {
            full_diag = 0;
            break;
        }
    }
    if (full_diag) {
        return 1;
    }
    // If no match found, return 0
    return 0;
}

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the bingo board with -1 to indicate numbers that have not been called yet
    int board[ROWS][COLS];
    int row, col, num, num_calls=0, winner=0;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            board[row][col] = -1;
        }
    }

    // Display the initial bingo board
    display_board(board, num_calls);

    // Game loop
    while (!winner) {

        // Generate a random number between 1 and 25
        num = rand() % 25 + 1;
        num_calls++;

        // Update the bingo board with the called number
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                if (board[row][col] == num) {
                    board[row][col] = -1;
                }
            }
        }
        // Check if number was called before
        int called_before = 0;
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                if (board[row][col] == num) {
                    called_before = 1;
                }
            }
        }
        if (called_before) {
            continue;
        }

        // Update the bingo board with the called number
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                if (board[row][col] == -1) {
                    continue;
                } else if (board[row][col] == num) {
                    board[row][col] = -1;
                    break;
                }
            }
        }
        // Display the updated bingo board
        display_board(board, num_calls);

        // Check for winner
        winner = check_winner(board);
        if (winner) {
            printf("BINGO!! You won in %d calls.\n", num_calls);
            break;
        }
    }

    return 0;
}