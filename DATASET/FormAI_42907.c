//FormAI DATASET v1.0 Category: Memory Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 4
#define COLS 4
#define MAX_MOVES 8

// Function prototypes
void initializeBoard(char board[][COLS], int rows, int cols);
void printBoard(char board[][COLS], int rows, int cols);
int playGame(char board[][COLS], char guesses[][COLS], int rows, int cols, int moveCount, int prevRow1, int prevCol1, int prevRow2, int prevCol2);
void shuffle(char nums[], int length);
void delay(int milliseconds);

// Main function
int main() {

    srand(time(NULL));
    
    char board[ROWS][COLS], guesses[ROWS][COLS];
    
    initializeBoard(board, ROWS, COLS);
    initializeBoard(guesses, ROWS, COLS);
    
    int moveCount = 0;
    int result = playGame(board, guesses, ROWS, COLS, moveCount, -1, -1, -1, -1);
    
    if(result == -1) {
        printf("\nGame over! You lost :(\n");
    } else {
        printf("\nCongratulations! You won with %d moves.\n", result);
    }

    return 0;
}

// Initializes the game board with random letters
void initializeBoard(char board[][COLS], int rows, int cols) {
    
    char nums[ROWS * COLS / 2] = {'A','B','C','D','E','F','G','H'};
    shuffle(nums, ROWS * COLS / 2);
    
    int index = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            board[i][j] = nums[index];
            index++;
        }
    }
}

// Prints the game board
void printBoard(char board[][COLS], int rows, int cols) {
    printf("  0 1 2 3\n");
    printf("  -------\n");
    for(int i=0; i<rows; i++) {
        printf("%d |%c %c %c %c\n", i, board[i][0], board[i][1], board[i][2], board[i][3]);
    }
    printf("\n");
}

// Plays the game recursively
int playGame(char board[][COLS], char guesses[][COLS], int rows, int cols, int moveCount, int prevRow1, int prevCol1, int prevRow2, int prevCol2) {
    
    if(moveCount > MAX_MOVES) {
        return -1;
    }
    
    printBoard(guesses, rows, cols);
    
    int row1, col1, row2, col2;
    printf("Enter two coordinates to guess (e.g. '2 3 1 2'): ");
    scanf("%d %d %d %d", &row1, &col1, &row2, &col2);
    
    // Replace the guessed coordinates with the actual letter on the board
    guesses[row1][col1] = board[row1][col1];
    guesses[row2][col2] = board[row2][col2];
    
    printBoard(guesses, rows, cols);
    
    if(board[row1][col1] == board[row2][col2]) {
        printf("Match found!\n");
        delay(1000);
        moveCount++;
        if(moveCount == MAX_MOVES) {
            return moveCount;
        }
        return playGame(board, guesses, rows, cols, moveCount, -1, -1, -1, -1);
    } else {
        printf("No match. Try again.\n");
        delay(1000);
        guesses[row1][col1] = '-';
        guesses[row2][col2] = '-';
        printBoard(guesses, rows, cols);
        delay(1000);
        if(prevRow1 != -1 && prevCol1 != -1 && prevRow2 != -1 && prevCol2 != -1) {
            guesses[prevRow1][prevCol1] = '-';
            guesses[prevRow2][prevCol2] = '-';
            printBoard(guesses, rows, cols);
            delay(1000);
        }
        int result = playGame(board, guesses, rows, cols, moveCount, row1, col1, row2, col2);
        return result;
    }
}

// Shuffles an array of characters
void shuffle(char nums[], int length) {
    for(int i=0; i<length-1; i++) {
        int j = rand() % (length - i) + i;
        char temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

// Delays program execution for a given number of milliseconds
void delay(int milliseconds) {
    clock_t start = clock();
    while((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds) {}
}