//FormAI DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 7

int checkWinner(int board[ROWS][COLS]);

void printBoard(int board[ROWS][COLS])
{
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("| ");
            if (board[row][col] == 1) {
                printf("X ");
            } else if (board[row][col] == 2) {
                printf("O ");
            } else {
                printf("  ");
            }
        }
        printf("|\n");
    }
    printf("+");
    for (int col = 0; col < COLS; col++) {
        printf("--+");
    }
    printf("\n ");
    for (int col = 0; col < COLS; col++) {
        printf("%2d ", col+1);
    }
    printf("\n");
}

void updateBoard(int board[ROWS][COLS], int col, int player)
{
    for (int row = ROWS - 1; row >= 0; row--) {
        if (board[row][col] == 0) {
            board[row][col] = player;
            break;
        }
    }
}

int main(void)
{
    int board[ROWS][COLS] = {0};

    srand(time(NULL));

    int player = rand() % 2 + 1;
    printf("Player %d goes first.\n", player);

    int moves = 0;

    while (1) {
        printBoard(board);

        int col;
        do {
            printf("Player %d, choose a column (1-7): ", player);
            scanf("%d", &col);
            col--;
        } while (col < 0 || col >= COLS || board[0][col] != 0);

        updateBoard(board, col, player);

        int winner = checkWinner(board);

        if (winner) {
            printBoard(board);
            printf("Player %d wins!\n", winner);
            break;
        }

        moves++;
        if (moves == ROWS * COLS) {
            printBoard(board);
            printf("It's a tie!\n");
            break;
        }

        player = player % 2 + 1;
    }

    return 0;
}

int checkWinner(int board[ROWS][COLS])
{
    // horizontal
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS - 3; col++) {
            if (board[row][col] == 0) continue;
            if (board[row][col] == board[row][col+1] &&
                    board[row][col] == board[row][col+2] &&
                    board[row][col] == board[row][col+3]) {
                return board[row][col];
            }
        }
    }

    // vertical
    for (int row = 0; row < ROWS - 3; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == 0) continue;
            if (board[row][col] == board[row+1][col] &&
                    board[row][col] == board[row+2][col] &&
                    board[row][col] == board[row+3][col]) {
                return board[row][col];
            }
        }
    }

    // diagonal from top left to bottom right
    for (int row = 0; row < ROWS - 3; row++) {
        for (int col = 0; col < COLS - 3; col++) {
            if (board[row][col] == 0) continue;
            if (board[row][col] == board[row+1][col+1] &&
                    board[row][col] == board[row+2][col+2] &&
                    board[row][col] == board[row+3][col+3]) {
                return board[row][col];
            }
        }
    }

    // diagonal from top right to bottom left
    for (int row = 0; row < ROWS - 3; row++) {
        for (int col = 3; col < COLS; col++) {
            if (board[row][col] == 0) continue;
            if (board[row][col] == board[row+1][col-1] &&
                    board[row][col] == board[row+2][col-2] &&
                    board[row][col] == board[row+3][col-3]) {
                return board[row][col];
            }
        }
    }

    return 0; // no winner yet
}