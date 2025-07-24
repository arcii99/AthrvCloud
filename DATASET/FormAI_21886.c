//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 25

int main()
{
    // Initialize game board and markers
    int board[ROWS][COLS] = {0};
    int markers[MAX_NUM] = {0};

    // Seed the random number generator
    srand(time(NULL));

    // Print header
    printf("Welcome to Bingo Simulator!\n\n");

    // Loop until a winning condition is met
    while (1) {
        // Generate a random number between 1 and MAX_NUM
        int num = rand() % MAX_NUM + 1;

        // Check if number has already been called
        if (markers[num-1] == 0) {
            // Mark number as called
            markers[num-1] = 1;

            // Update game board
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (board[i][j] == num) {
                        board[i][j] = 0;
                    }
                }
            }

            // Print updated game board
            printf("Number called: %d\n", num);
            printf("   B  I  N  G  O\n");
            for (int i = 0; i < ROWS; i++) {
                printf("%c ", 'A'+i);
                for (int j = 0; j < COLS; j++) {
                    printf("%2d ", board[i][j]);
                }
                printf("\n");
            }
            printf("\n");

            // Check for winning condition
            int bingo = 0;
            // Check rows
            for (int i = 0; i < ROWS; i++) {
                int row_sum = 0;
                for (int j = 0; j < COLS; j++) {
                    row_sum += board[i][j];
                }
                if (row_sum == 0) {
                    bingo = 1;
                    break;
                }
            }
            // Check columns
            for (int j = 0; j < COLS; j++) {
                int col_sum = 0;
                for (int i = 0; i < ROWS; i++) {
                    col_sum += board[i][j];
                }
                if (col_sum == 0) {
                    bingo = 1;
                    break;
                }
            }
            // Check diagonals
            if (board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 && board[3][3] == 0 && board[4][4] == 0) {
                bingo = 1;
            }
            if (board[0][4] == 0 && board[1][3] == 0 && board[2][2] == 0 && board[3][1] == 0 && board[4][0] == 0) {
                bingo = 1;
            }

            // Check if winning condition is met
            if (bingo) {
                printf("Bingo! You win!\n");
                break;
            }
        }
    }

    return 0;
}