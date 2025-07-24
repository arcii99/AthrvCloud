//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define RANGE 75

void initialize_board(bool board[ROWS][COLS]);
void print_board(bool board[ROWS][COLS]);
int generate_random_number(void);
bool is_number_already_called(bool called_numbers[RANGE], int number);
void mark_number(bool board[ROWS][COLS], int number);
bool is_bingo(bool board[ROWS][COLS]);

int main(void) {
    bool board[ROWS][COLS];
    bool called_numbers[RANGE] = {false}; // Initialize all elements to false
    int current_number;
    int num_calls = 0;
    srand(time(NULL));

    // Start game
    printf("--- Welcome to Bingo Simulator! ---\n\n");
    initialize_board(board);
    print_board(board);

    // Keep calling numbers until there is a winning board
    while (!is_bingo(board)) {
        current_number = generate_random_number();
        num_calls++;
        printf("Number called: %d\n", current_number);

        // Check if number has already been called
        if (is_number_already_called(called_numbers, current_number)) {
            printf("Sorry, that number has already been called. Try again.\n");
        } else {
            called_numbers[current_number-1] = true;
            mark_number(board, current_number);
            print_board(board);
        }
    }

    printf("\nBINGO! Congratulations, you win!\n");
    printf("It took %d calls to win.\n", num_calls);

    return 0;
}

void initialize_board(bool board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = false;
        }
    }
    // Mark the center square as already called
    board[2][2] = true;
}

void print_board(bool board[ROWS][COLS]) {
    int i, j;
    printf("\nCurrent Board:\n");
    printf("---------------\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j]) {
                printf("| X ");
            } else {
                printf("| %d ", i*ROWS+j+1); // Convert 2D indices to 1D number
            }
        }
        printf("|\n");
        printf("---------------\n");
    }
}

int generate_random_number(void) {
    return rand() % RANGE + 1; // Generate a random number from 1-75
}

bool is_number_already_called(bool called_numbers[RANGE], int number) {
    return called_numbers[number-1];
}

void mark_number(bool board[ROWS][COLS], int number) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == false && (i*ROWS+j+1) == number) { // Convert 2D indices to 1D number
                board[i][j] = true;
                return;
            }
        }
    }
}

bool is_bingo(bool board[ROWS][COLS]) {
    int i, j;
    bool bingo_rows = false;
    bool bingo_cols = false;
    bool bingo_diagonal1 = true;
    bool bingo_diagonal2 = true;

    // Check for completed rows
    for (i = 0; i < ROWS; i++) {
        bool row_completed = true;
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == false) {
                row_completed = false;
                break;
            }
        }
        if (row_completed) {
            bingo_rows = true;
            break;
        }
    }

    // Check for completed columns
    for (j = 0; j < COLS; j++) {
        bool col_completed = true;
        for (i = 0; i < ROWS; i++) {
            if (board[i][j] == false) {
                col_completed = false;
                break;
            }
        }
        if (col_completed) {
            bingo_cols = true;
            break;
        }
    }

    // Check for completed diagonals
    for (i = 0; i < ROWS; i++) {
        if (board[i][i] == false) {
            bingo_diagonal1 = false;
        }
        if (board[i][COLS-1-i] == false) {
            bingo_diagonal2 = false;
        }
        if (!bingo_diagonal1 && !bingo_diagonal2) {
            break;
        }
    }

    // Return true if there is a completed row, column, or diagonal
    return bingo_rows || bingo_cols || bingo_diagonal1 || bingo_diagonal2;
}