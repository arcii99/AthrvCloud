//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

/* Function Prototypes */
void print_board(int board[ROWS][COLS]);
void generate_numbers(int board[ROWS][COLS]);
int check_bingo(int board[ROWS][COLS]);

int main(void) {
    int board[ROWS][COLS];
    int num_of_calls = 0;
    srand(time(NULL)); // Seed random number generator

    // Generate the bingo board and print it
    generate_numbers(board);
    print_board(board);

    // Call out numbers until there is a bingo
    while (1) {
        num_of_calls++;
        printf("Next Number: %d\n", rand() % 75 + 1);
        if (check_bingo(board)) {
            printf("Bingo! It took %d calls to win!\n", num_of_calls);
            break;
        }
    }

    return 0;
}

/* Function Definitions */

/*
 * This function generates random numbers for each square of the bingo board
 * Restrictions:
 *  - The numbers in each column must be within a specific range
 *  - There can be no repeated numbers on the same board
 */
void generate_numbers(int board[ROWS][COLS]) {
    int num;
    int min, max;

    // Generate numbers in the first column
    min = 1;
    max = 15;
    for (int i = 0; i < ROWS; i++) {
        num = rand() % (max - min + 1) + min;
        board[i][0] = num;

        // Ensure that there are no repeated numbers in the same column
        for (int j = i - 1; j >= 0; j--) {
            if (board[i][0] == board[j][0]) {
                i--;
                break;
            }
        }
    }

    // Generate numbers in the second column
    min = 16;
    max = 30;
    for (int i = 0; i < ROWS; i++) {
        num = rand() % (max - min + 1) + min;
        board[i][1] = num;

        // Ensure that there are no repeated numbers in the same column
        for (int j = i - 1; j >= 0; j--) {
            if (board[i][1] == board[j][1]) {
                i--;
                break;
            }
        }
    }

    // Generate numbers in the third column
    min = 31;
    max = 45;
    for (int i = 0; i < ROWS; i++) {
        num = rand() % (max - min + 1) + min;
        board[i][2] = num;

        // Ensure that there are no repeated numbers in the same column
        for (int j = i - 1; j >= 0; j--) {
            if (board[i][2] == board[j][2]) {
                i--;
                break;
            }
        }
    }

    // Generate numbers in the fourth column
    min = 46;
    max = 60;
    for (int i = 0; i < ROWS; i++) {
        num = rand() % (max - min + 1) + min;
        board[i][3] = num;

        // Ensure that there are no repeated numbers in the same column
        for (int j = i - 1; j >= 0; j--) {
            if (board[i][3] == board[j][3]) {
                i--;
                break;
            }
        }
    }

    // Generate numbers in the fifth column
    min = 61;
    max = 75;
    for (int i = 0; i < ROWS; i++) {
        num = rand() % (max - min + 1) + min;
        board[i][4] = num;

        // Ensure that there are no repeated numbers in the same column
        for (int j = i - 1; j >= 0; j--) {
            if (board[i][4] == board[j][4]) {
                i--;
                break;
            }
        }
    }
}

/*
 * This function checks if there is a bingo on the board
 * Restrictions:
 *  - There can be a bingo in any row, column, or diagonal
 */
int check_bingo(int board[ROWS][COLS]) {
    int bingo = 0; // Assume no bingo until proven otherwise

    // Check for a bingo in each row
    for (int i = 0; i < ROWS; i++) {
        bingo = 1; // Assume bingo until proven otherwise
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] != -1) {
                bingo = 0; // Not a bingo
            }
        }
        if (bingo) {
            return 1; // Bingo found
        }
    }

    // Check for a bingo in each column
    for (int i = 0; i < COLS; i++) {
        bingo = 1; // Assume bingo until proven otherwise
        for (int j = 0; j < ROWS; j++) {
            if (board[j][i] != -1) {
                bingo = 0; // Not a bingo
            }
        }
        if (bingo) {
            return 1; // Bingo found
        }
    }

    // Check for diagonal bingos (top left to bottom right and top right to bottom left)
    if ((board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) ||
        (board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1)) {
        return 1; // Bingo found
    }

    // No bingo found
    return 0;
}

/*
 * This function prints the current bingo board to the console
 */
void print_board(int board[ROWS][COLS]) {
    printf("Bingo Board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("XX ");
            } else {
                printf("%02d ", board[i][j]);
            }
        }
        printf("\n");
    }
}