//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 5
#define COLS 5
#define MAX_NUM 75
#define FREE_SPACE 0

// Function Declarations
void initializeBoard(int board[ROWS][COLS]);
void printBoard(int board[ROWS][COLS]);
int callNumber(int calledNumbers[MAX_NUM], int numCalled);
int checkBoard(int board[ROWS][COLS]);

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize board
    int board[ROWS][COLS];
    initializeBoard(board);
    
    // Print initial board
    printf("Welcome to Bingo!\n\n");
    printf("Here is your starting board:\n");
    printBoard(board);
    
    // Play game
    int calledNumbers[MAX_NUM] = {0};
    int numCalled = 0;
    int num = -1;
    while (numCalled < MAX_NUM && checkBoard(board) != 1) {
        // Call number
        num = callNumber(calledNumbers, numCalled);
        calledNumbers[numCalled] = num;
        numCalled++;
        
        // Print number
        printf("The next number is: %d\n", num);
        
        // Mark board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = FREE_SPACE;
                }
            }
        }
        
        // Print updated board
        printf("Here is your updated board:\n");
        printBoard(board);
    }
    
    // Print final board and end game
    printf("Congratulations, you won!\n");
    printBoard(board);
    return 0;
}

void initializeBoard(int board[ROWS][COLS]) {
    // Initialize board with random numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = (i * 15) + rand() % 15 + 1;
        }
    }
    
    // Mark middle space as free
    board[2][2] = FREE_SPACE;
}

void printBoard(int board[ROWS][COLS]) {
    // Print board
    printf("  B  I  N  G  O\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == FREE_SPACE) {
                printf("   ");
            } else {
                printf("%2d ", board[i][j]);    
            }
        }
        printf("\n");
    }
    printf("\n");
}

int callNumber(int calledNumbers[MAX_NUM], int numCalled) {
    // Generate random number and check if it has already been called
    int num = rand() % MAX_NUM + 1;
    while (1) {
        int isCalled = 0;
        for (int i = 0; i < numCalled; i++) {
            if (calledNumbers[i] == num) {
                isCalled = 1;
                break;
            }
        }
        if (isCalled == 0) {
            break;
        }
        num = rand() % MAX_NUM + 1;
    }
    return num;
}

int checkBoard(int board[ROWS][COLS]) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        int isComplete = 1;
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] != FREE_SPACE) {
                isComplete = 0;
                break;
            }
        }
        if (isComplete == 1) {
            return 1;
        }
    }
    
    // Check columns
    for (int j = 0; j < COLS; j++) {
        int isComplete = 1;
        for (int i = 0; i < ROWS; i++) {
            if (board[i][j] != FREE_SPACE) {
                isComplete = 0;
                break;
            }
        }
        if (isComplete == 1) {
            return 1;
        }
    }
    
    // Check diagonals
    if (board[0][0] == FREE_SPACE && board[1][1] == FREE_SPACE && board[2][2] == FREE_SPACE && board[3][3] == FREE_SPACE && board[4][4] == FREE_SPACE) {
        return 1;
    }
    if (board[0][4] == FREE_SPACE && board[1][3] == FREE_SPACE && board[2][2] == FREE_SPACE && board[3][1] == FREE_SPACE && board[4][0] == FREE_SPACE) {
        return 1;
    }
    
    // Board is not complete
    return 0;
}