//FormAI DATASET v1.0 Category: Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

/* This program is a simple puzzle game where the player has to match pairs of numbers 
 * hidden under squares to reveal them. The goal is to match all the pairs as fast as 
 * possible. The game ends when all pairs are revealed.
 */

#define ROWS 4
#define COLS 4

void boardInit(int board[][COLS], int rows, int cols);
void boardPrint(int board[][COLS], int rows, int cols);
void prompt(int *row, int *col);
void reveal(int board[][COLS], int row, int col, int *pairsLeft);
int checkPair(int board[][COLS], int row1, int col1, int row2, int col2);

int main(void) {
    int board[ROWS][COLS];
    int pairsLeft = (ROWS * COLS) / 2;
    int row1, col1, row2, col2, moves = 0;

    boardInit(board, ROWS, COLS);

    do {
        system("clear"); // clears the console screen
        boardPrint(board, ROWS, COLS);
        printf("Pairs left: %d\n", pairsLeft);
        prompt(&row1, &col1);
        reveal(board, row1, col1, &pairsLeft);
        boardPrint(board, ROWS, COLS);
        prompt(&row2, &col2);
        reveal(board, row2, col2, &pairsLeft);
        if (checkPair(board, row1, col1, row2, col2)) {
            printf("You found a pair!\n");
        } else {
            printf("Try again!\n");
            board[row1][col1] = 0;
            board[row2][col2] = 0;
        }
        moves++;
        printf("Moves: %d\n", moves);
    } while (pairsLeft > 0);

    printf("Congratulations! You won in %d moves.\n", moves);

    return 0;
}

// Initializes the board array with random numbers in pairs
void boardInit(int board[][COLS], int rows, int cols) {
    int numbers[ROWS * COLS / 2];
    int i, j, k = 0;

    for (i = 0; i < rows * cols / 2; i++) {
        numbers[i] = i + 1;
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            int r;
            do {
                r = rand() % (rows * cols / 2);
            } while (numbers[r] == 0);
            board[i][j] = numbers[r];
            numbers[r] = 0;
        }
    }
}

// Prints the current state of the board array
void boardPrint(int board[][COLS], int rows, int cols) {
    int i, j;

    printf("+");
    for (i = 0; i < cols; i++) {
        printf("---+");
    }
    printf("\n");

    for (i = 0; i < rows; i++) {
        printf("|");
        for (j = 0; j < cols; j++) {
            if (board[i][j] == 0) {
                printf("   |");
            } else {
                printf(" %d |", board[i][j]);
            }
        }
        printf("\n+");
        for (j = 0; j < cols; j++) {
            printf("---+");
        }
        printf("\n");
    }
}

// Prompts the user for row and column input
void prompt(int *row, int *col) {
    do {
        printf("Enter row (1-%d) and column (1-%d): ", ROWS, COLS);
        scanf("%d %d", row, col);
    } while (*row < 1 || *row > ROWS || *col < 1 || *col > COLS);
    *row -= 1;
    *col -= 1;
}

// Reveals a pair of numbers on the board
void reveal(int board[][COLS], int row, int col, int *pairsLeft) {
    if (board[row][col] == 0) {
        *pairsLeft -= 1;
        board[row][col] = -1;
    }
}

// Checks if two squares contain a matching pair of numbers
int checkPair(int board[][COLS], int row1, int col1, int row2, int col2) {
    return board[row1][col1] == board[row2][col2];
}