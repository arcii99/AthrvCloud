//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 3
#define COLUMNS 9
#define TRUE 1
#define FALSE 0

void initialize_board(int board[ROWS][COLUMNS]){
    int i,j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            board[i][j] = 0;
        }
    }

    // Add Bingo header to the board
    board[0][0] = 'B';
    board[0][1] = 'I';
    board[0][2] = 'N';
    board[0][3] = 'G';
    board[0][4] = 'O';
}

void print_board(int board[ROWS][COLUMNS]) {
    int i, j;

    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_bingo(int board[ROWS][COLUMNS]){
    int i, j;
    int bingo = FALSE;

    // Check rows
    for (i = 0; i < ROWS; i++) {
        bingo = TRUE;
        for (j = 1; j < COLUMNS; j++) {
            if (board[i][j] == 0) {
                bingo = FALSE;
                break;
            }
        }

        if (bingo == TRUE) {
            return TRUE;
        }
    }

    // Check columns
    for (j = 1; j < COLUMNS; j++) {
        bingo = TRUE;
        for (i = 0; i < ROWS; i++) {
            if (board[i][j] == 0) {
                bingo = FALSE;
                break;
            }
        }

        if (bingo == TRUE) {
            return TRUE;
        }
    }

    // Check diagonals
    if (board[0][1] != 0 && board[1][2] != 0 && board[2][3] != 0 && board[3][4] != 0) {
        bingo = TRUE;
    }

    if (board[0][4] != 0 && board[1][3] != 0 && board[2][2] != 0 && board[3][1] != 0) {
        bingo = TRUE;
    }

    return bingo;
}

int main() {
    int board[ROWS][COLUMNS];
    int i, j, k;
    int number;
    int done = FALSE;

    // Seed RNG with current time
    srand(time(NULL));

    // Initialize board
    initialize_board(board);

    // Print initial board
    print_board(board);

    // Start game loop
    while (!done) {
        // Generate new random number
        number = rand() % 75 + 1;

        printf("The next number is: %d\n", number);

        // Check if number is already on the board
        for (i = 0; i < ROWS; i++) {
            for (j = 1; j < COLUMNS; j++) {
                if (board[i][j] == number) {
                    printf("%d is already on the board.\n", number);
                    break;
                }
            }

            if (j != COLUMNS) {
                break;
            }
        }

        // Add number to the board if it's not already on it
        if (i == ROWS && j == COLUMNS) {
            for (i = 0; i < ROWS; i++) {
                for (j = 1; j < COLUMNS; j++) {
                    if (board[i][j] == 0) {
                        board[i][j] = number;
                        break;
                    }
                }

                if (j != COLUMNS) {
                    break;
                }
            }
        }

        // Check if there is a bingo
        if (check_bingo(board) == TRUE) {
            printf("Bingo! You win!\n");
            done = TRUE;
        }

        // Print current board
        print_board(board);

        // Pause for dramatic effect
        for (k = 0; k < 100000000; k++) {}
    }

    return 0;
}