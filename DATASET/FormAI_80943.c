//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Declare function prototype
void initialize_game(int bingo_board[ROWS][COLS]);
void print_game(int bingo_board[ROWS][COLS]);
int is_winner(int bingo_board[ROWS][COLS]);

int main(void) {
    // Initialize random seed
    srand(time(NULL));

    // Initialize bingo board
    int bingo_board[ROWS][COLS];
    initialize_game(bingo_board);

    // Show initial bingo board
    printf("Welcome to the Bingo Simulator!\n\n");
    printf("Initial Bingo Board:\n");
    print_game(bingo_board);

    // Play bingo game
    while (!is_winner(bingo_board)) {
        int call_out_num = rand() % 25 + 1;
        printf("Number called out: %d\n", call_out_num);

        // Update bingo board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingo_board[i][j] == call_out_num) {
                    bingo_board[i][j] = 0; // Mark the number as called out
                }
            }
        }

        // Show updated bingo board
        print_game(bingo_board);
    }

    printf("Bingo! Winner found!\n");

    return 0;
}

void initialize_game(int bingo_board[ROWS][COLS]) {
    int nums[25];

    for (int i = 0; i < 25; i++) {
        nums[i] = i + 1;
    }

    // Shuffle array of numbers using Fisher-Yates algorithm
    for (int i = 24; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }

    // Fill in the bingo board with shuffled numbers
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            bingo_board[i][j] = nums[count];
            count++;
        }
    }

    // Mark center square as already called out
    bingo_board[ROWS/2][COLS/2] = 0;
}

void print_game(int bingo_board[ROWS][COLS]) {
    printf("---------------------\n");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (bingo_board[i][j] == 0) {
                printf("|  X  ");
            } else {
                printf("|  %d  ", bingo_board[i][j]);
            }
        }

        printf("|\n");
        printf("---------------------\n");
    }
}

int is_winner(int bingo_board[ROWS][COLS]) {
    int rows[ROWS] = {};
    int cols[COLS] = {};
    int diag1 = 0; // Diagonal from top left to bottom right
    int diag2 = 0; // Diagonal from bottom left to top right

    // Check each row and column
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            rows[i] += bingo_board[i][j];
            cols[j] += bingo_board[i][j];
        }
    }

    // Check diagonal from top left to bottom right
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == j) {
                diag1 += bingo_board[i][j];
            }
        }
    }

    // Check diagonal from bottom left to top right
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((i + j) == (ROWS - 1)) {
                diag2 += bingo_board[i][j];
            }
        }
    }

    // Check if any row, column, or diagonal has all zeros
    for (int i = 0; i < ROWS; i++) {
        if (rows[i] == 0) {
            return 1; // Bingo!
        }
    }

    for (int j = 0; j < COLS; j++) {
        if (cols[j] == 0) {
            return 1; // Bingo!
        }
    }

    if (diag1 == 0 || diag2 == 0) {
        return 1; // Bingo!
    }

    return 0; // Not a winner yet
}