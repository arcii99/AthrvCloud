//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to check if a number already exists in the board
int checkAlreadyExist(int board[][COLS], int num) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to generate a random number
int generateRandomNumber(int board[][COLS], int lower, int upper) {
    int num = (rand() % (upper - lower + 1)) + lower;
    while (checkAlreadyExist(board, num)) {
        num = (rand() % (upper - lower + 1)) + lower;
    }
    return num;
}

// Function to print the board
void printBoard(int board[][COLS], int hidden) {
    printf("\n\n");
    printf("    B  I  N  G  O\n");
    for (int i = 0; i < ROWS; i++) {
        printf("\n");
        for (int j = 0; j < COLS; j++) {
            if (hidden && i == ROWS / 2 && j == COLS / 2) {
                printf("    X ");
            } else {
                printf("  %2d ", board[i][j]);
            }
        }
    }
    printf("\n\n");
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];
    int usedNums[ROWS * COLS];
    int numCount = 0;
    int numComponents[5] = {0, 0, 1, 2, 3};

    // Fill the board with random numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = generateRandomNumber(board, numComponents[i] * 10 + 1, (numComponents[i] + 1) * 10);
            usedNums[numCount++] = board[i][j];
        }
    }

    // Shuffle the usedNums array
    for (int i = 0; i < numCount - 1; i++) {
        int j = i + rand() / (RAND_MAX / (numCount - i) + 1);
        int temp = usedNums[j];
        usedNums[j] = usedNums[i];
        usedNums[i] = temp;
    }

    // Print the board with the center cell hidden
    printBoard(board, 1);

    // Play the game
    int currentNum = usedNums[0];
    int numCalls = 1;
    char input[10];
    while (1) {
        printf("Enter 'b' when you have a Bingo: ");
        scanf("%s", input);
        if (input[0] == 'b') {
            printf("\nYou have won after %d calls!\n\n", numCalls);
            break;
        } else {
            printf("\nYou must enter 'b' to end the game.\n\n");
        }
    }
    return 0;
}