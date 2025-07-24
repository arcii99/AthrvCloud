//FormAI DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 7
#define EMPTY ' '
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

void initializeBoard(char board[ROWS][COLS]);
void printBoard(char board[ROWS][COLS]);
int playerTurn(char board[ROWS][COLS], char player);
int checkWin(char board[ROWS][COLS], char player);
int checkHorizontal(char board[ROWS][COLS], char player);
int checkVertical(char board[ROWS][COLS], char player);
int checkDiagonal(char board[ROWS][COLS], char player);

int main(void) {
    char board[ROWS][COLS];
    char player = PLAYER_ONE;
    int column, turn;

    srand(time(NULL));

    initializeBoard(board);
    printBoard(board);

    for (turn = 0; turn < ROWS*COLS; turn++) {
        column = playerTurn(board, player);
        printBoard(board);

        if (checkWin(board, player)) {
            printf("Player %c wins!\n", player);
            return 0;
        }

        player = (player == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
    }

    printf("Game over. It's a tie!\n");

    return 0;
}

void initializeBoard(char board[ROWS][COLS]) {
    int row, col;

    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            board[row][col] = EMPTY;
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    int row, col;
    printf("\n");

    for (row = 0; row < ROWS; row++) {
        printf("|");

        for (col = 0; col < COLS; col++) {
            printf("%c|", board[row][col]);
        }

        printf("\n");
    }

    printf(" 1 2 3 4 5 6 7\n");
}

int playerTurn(char board[ROWS][COLS], char player) {
    int column = 0, row;

    do {
        printf("Player %c, choose column (1-7): ", player);

        if (scanf("%d", &column) == EOF) {
            printf("Error: input ended prematurely.");
            exit(1);
        }

        column--;

        for (row = ROWS - 1; row >= 0; row--) { // start from bottom of column
            if (board[row][column] == EMPTY) {
                board[row][column] = player;
                return column;
            }
        }

        printf("That column is full, please choose another.\n");
    } while (1); // loop until valid input received
}

int checkWin(char board[ROWS][COLS], char player) {
    return (checkHorizontal(board, player) || checkVertical(board, player) || checkDiagonal(board, player));
}

int checkHorizontal(char board[ROWS][COLS], char player) {
    int row, col, count;

    for (row = 0; row < ROWS; row++) {
        count = 0;

        for (col = 0; col < COLS; col++) {
            if (board[row][col] == player) {
                count++;

                if (count == 4) {
                    return 1;
                }
            } else {
                count = 0;
            }
        }
    }

    return 0;
}

int checkVertical(char board[ROWS][COLS], char player) {
    int row, col, count;

    for (col = 0; col < COLS; col++) {
        count = 0;

        for (row = 0; row < ROWS; row++) {
            if (board[row][col] == player) {
                count++;

                if (count == 4) {
                    return 1;
                }
            } else {
                count = 0;
            }
        }
    }

    return 0;
}

int checkDiagonal(char board[ROWS][COLS], char player) {
    int row, col, r, c, count;

    // Check bottom-left to top-right diagonals
    for (row = ROWS - 1; row >= 3; row--) {
        for (col = 0; col < COLS - 3; col++) {
            count = 0;
            r = row;
            c = col;

            while (r >= 0 && c < COLS) {
                if (board[r][c] == player) {
                    count++;

                    if (count == 4) {
                        return 1;
                    }
                } else {
                    count = 0;
                }

                r--;
                c++;
            }
        }
    }

    // Check top-left to bottom-right diagonals
    for (row = 0; row < ROWS - 3; row++) {
        for (col = 0; col < COLS - 3; col++) {
            count = 0;
            r = row;
            c = col;

            while (r < ROWS && c < COLS) {
                if (board[r][c] == player) {
                    count++;

                    if (count == 4) {
                        return 1;
                    }
                } else {
                    count = 0;
                }

                r++;
                c++;
            }
        }
    }

    return 0;
}