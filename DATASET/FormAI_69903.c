//FormAI DATASET v1.0 Category: Memory Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_GUESSES 8

// Function to print the game board
void printBoard(char board[][COLS], int rows, int cols) {
    printf("\nCurrent Board:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {

    // Declare variables
    char board[ROWS][COLS];
    char letters[] = {'A','B','C','D','E','F','G','H'};
    int numTiles = ROWS * COLS;
    int index, row, col, remaining, guessCount = 1;
    int guessesLeft = MAX_GUESSES;
    char guess1, guess2;
    int guess1_row, guess1_col, guess2_row, guess2_col;

    // Initialize board with question marks
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '?';
        }
    }

    // Randomly assign letters to tiles
    srand(time(NULL));
    for (int i = 0; i < numTiles; i+=2) {
        remaining = numTiles - i;
        index = rand() % remaining;
        row = index / COLS;
        col = index % COLS;
        board[row][col] = letters[i/2];
        remaining--;
        index = rand() % remaining;
        while (board[index/COLS][index%COLS] != '?') {
            index = rand() % remaining;
        }
        board[index/COLS][index%COLS] = letters[i/2];
    }

    // Game loop
    while (guessesLeft > 0) {
        printf("\nGuess %d of %d\n", guessCount, MAX_GUESSES);
        printBoard(board, ROWS, COLS);

        // Get first guess
        printf("\nEnter first guess (row column): ");
        scanf(" %d %d", &guess1_row, &guess1_col);
        guess1 = board[guess1_row][guess1_col];
        printf("Guess: %c\n", guess1);

        // Get second guess
        printf("Enter second guess (row column): ");
        scanf(" %d %d", &guess2_row, &guess2_col);
        guess2 = board[guess2_row][guess2_col];
        printf("Guess: %c\n", guess2);

        // Check if guesses match
        if (guess1 == guess2) {
            printf("\nCorrect!\n");
            board[guess1_row][guess1_col] = guess1;
            board[guess2_row][guess2_col] = guess2;
        }
        else {
            printf("\nIncorrect!\n");
            board[guess1_row][guess1_col] = '?';
            board[guess2_row][guess2_col] = '?';
            guessesLeft--;
        }

        guessCount++;

        // Check if game is over
        int numRevealed = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] != '?') {
                    numRevealed++;
                }
            }
        }
        if (numRevealed == numTiles) {
            printBoard(board, ROWS, COLS);
            printf("\nYou win!\n");
            return 0;
        }
    }

    // Game over
    printBoard(board, ROWS, COLS);
    printf("\nYou lose...\n");

    return 0;
}