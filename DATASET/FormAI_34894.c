//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Constants */
#define ROWS 10
#define COLS 10
#define MAX_GUESSES 15

/* Function Declarations */
void generateBoard(int board[][COLS], int rows, int cols);
void printBoard(int board[][COLS], int rows, int cols);
void playGame(int board[][COLS], int rows, int cols);
int getGuess(int guess[][2], int guessNum);
int checkGuess(int board[][COLS], int guessRow, int guessCol);
void updateBoard(int board[][COLS], int guessRow, int guessCol, int result);
int checkWin(int board[][COLS], int rows, int cols);

/* Main Function */
int main() {
    int board[ROWS][COLS];
    
    srand(time(NULL));  // Seed random number generator
    
    generateBoard(board, ROWS, COLS);
    printBoard(board, ROWS, COLS);
    playGame(board, ROWS, COLS);
    
    return 0;
}

/* Function Definitions */

/* generates a random board with values of 0 or 1 */
void generateBoard(int board[][COLS], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

/* prints the current state of the board */
void printBoard(int board[][COLS], int rows, int cols) {
    int i, j;
    printf("    ");
    for (i = 0; i < cols; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < rows; i++) {
        printf("%2d: ", i);
        for (j = 0; j < cols; j++) {
            if (board[i][j] == 0) {
                printf("~ ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

/* runs the game loop */
void playGame(int board[][COLS], int rows, int cols) {
    int guess[MAX_GUESSES][2];  // 2D array to store all guesses
    int i, guessNum, guessRow, guessCol, result;
    
    for (guessNum = 0; guessNum < MAX_GUESSES; guessNum++) {
        result = getGuess(guess, guessNum);
        guessRow = guess[guessNum][0];
        guessCol = guess[guessNum][1];
        result = checkGuess(board, guessRow, guessCol);
        updateBoard(board, guessRow, guessCol, result);
        printBoard(board, rows, cols);
        if (checkWin(board, rows, cols)) {
            printf("Congratulations, you won!\n");
            return;
        }
    }
    printf("Sorry, you have run out of guesses. Game Over!\n");
}

/* prompts the user for a guess and returns a 2-element array with the row and column numbers */
int getGuess(int guess[][2], int guessNum) {
    int guessRow, guessCol;
    printf("Guess #%d: Enter row and column (eg. 2 5): ", guessNum+1);
    scanf("%d %d", &guessRow, &guessCol);
    guess[guessNum][0] = guessRow;
    guess[guessNum][1] = guessCol;
    return 0;
}

/* checks the guess at the specified row and column and returns 1 if it is a hit and 0 if it is a miss */
int checkGuess(int board[][COLS], int guessRow, int guessCol) {
    if (board[guessRow][guessCol] == 1) {
        printf("Hit!\n");
        return 1;
    } else {
        printf("Miss!\n");
        return 0;
    }
}

/* updates the board with the result of the guess */
void updateBoard(int board[][COLS], int guessRow, int guessCol, int result) {
    if (result == 1) {
        board[guessRow][guessCol] = -1;  // hit
    } else {
        board[guessRow][guessCol] = 2;  // miss
    }
}

/* checks if the player has won by hitting all targets */
int checkWin(int board[][COLS], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (board[i][j] == 1) {
                return 0;  // not all targets have been hit
            }
        }
    }
    return 1;  // all targets have been hit
}