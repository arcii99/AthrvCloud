//FormAI DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define constant values
#define ROWS 5
#define COLS 5
#define MAX_WORD_LENGTH 20
#define WORDS_COUNT 10

// Function to print the game board
void printBoard(char board[][COLS]) {
    printf("\n  ");
    for (int i = 0; i < COLS; i++)
        printf("%d ", i + 1);
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to get a random integer between min and max
int getRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to check if a word can be placed horizontally starting at given coordinates
int checkHorizontal(char board[][COLS], int row, int col, char* word) {
    int i = col;

    while (*word != '\0') {
        if (i >= COLS || board[row][i] != ' ') {
            return 0;
        }
        i++;
        word++;
    }

    if (i == COLS || board[row][i] != ' ') {
        return 0;
    }

    return 1;
}

// Function to check if a word can be placed vertically starting at given coordinates
int checkVertical(char board[][COLS], int row, int col, char* word) {
    int i = row;

    while (*word != '\0') {
        if (i >= ROWS || board[i][col] != ' ') {
            return 0;
        }
        i++;
        word++;
    }

    if (i == ROWS || board[i][col] != ' ') {
        return 0;
    }

    return 1;
}

// Function to place a word horizontally starting at given coordinates
void placeHorizontal(char board[][COLS], int row, int col, char* word) {
    while (*word != '\0') {
        board[row][col] = *word;
        col++;
        word++;
    }
}

// Function to place a word vertically starting at given coordinates
void placeVertical(char board[][COLS], int row, int col, char* word) {
    while (*word != '\0') {
        board[row][col] = *word;
        row++;
        word++;
    }
}

int main() {
    char words[WORDS_COUNT][MAX_WORD_LENGTH] = {"hello", "world", "chatbot", "game", "curious", "programming", "example", "unique", "creative", "snippet"};

    char board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    srand(time(NULL));

    // Place words horizontally
    for (int i = 0; i < WORDS_COUNT; i++) {
        int success = 0;

        while (!success) {
            int row = getRandom(0, ROWS - 1);
            int col = getRandom(0, COLS - 1);

            success = checkHorizontal(board, row, col, words[i]);

            if (success) {
                placeHorizontal(board, row, col, words[i]);
            }
        }
    }

    // Place words vertically
    for (int i = 0; i < WORDS_COUNT; i++) {
        int success = 0;

        while (!success) {
            int row = getRandom(0, ROWS - 1);
            int col = getRandom(0, COLS - 1);

            success = checkVertical(board, row, col, words[i]);

            if (success) {
                placeVertical(board, row, col, words[i]);
            }
        }
    }

    printBoard(board);

    return 0;
}