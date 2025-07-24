//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

bool is_bingo(int board[ROWS][COLS], int row, int col) {
    // Check row
    int count = 0;
    for (int i = 0; i < COLS; i++) {
        if (board[row][i] == 0) {
            count++;
        }
    }
    if (count == COLS) {
        return true;
    }

    // Check column
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (board[i][col] == 0) {
            count++;
        }
    }
    if (count == ROWS) {
        return true;
    }

    // Check diagonal if the square belongs to it
    if (row == col) {
        count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (board[i][i] == 0) {
                count++;
            }
        }
        if (count == ROWS) {
            return true;
        }
    }

    // Check anti-diagonal if the square belongs to it
    if (row + col == ROWS - 1) {
        count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (board[i][ROWS - i - 1] == 0) {
                count++;
            }
        }
        if (count == ROWS) {
            return true;
        }
    }

    return false;
}

int main(void) {
    // Bingo board with randomly generated numbers from 1 to 25
    int board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = (i * COLS + j) + 1;
        }
    }

    // Shuffle the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int random_row = rand() % ROWS;
            int random_col = rand() % COLS;
            int temp = board[i][j];
            board[i][j] = board[random_row][random_col];
            board[random_row][random_col] = temp;
        }
    }

    // Mark the center square as a free space
    board[ROWS/2][COLS/2] = 0;

    // Print the shuffled board
    printf("Bingo board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }

    // Play the game
    bool game_over = false;
    while (!game_over) {
        // Ask the user to enter a number
        int number;
        printf("Enter a number between 1 and 25 (0 to quit): ");
        scanf("%d", &number);

        if (number == 0) {
            game_over = true;
        } else {
            // Mark the number on the board
            bool found = false;
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (board[i][j] == number) {
                        board[i][j] = 0;
                        found = true;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (!found) {
                printf("Number not found on the board.\n");
            }

            // Check for a bingo
            bool bingo = false;
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (board[i][j] == 0 && is_bingo(board, i, j)) {
                        bingo = true;
                        break;
                    }
                }
                if (bingo) {
                    break;
                }
            }
            if (bingo) {
                printf("Bingo!\n");
                game_over = true;
            }
        }
    }

    // Print the final board
    printf("Final board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}