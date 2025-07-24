//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generateBingoBoard(int bingoBoard[ROWS][COLS]);
void printBingoBoard(int bingoBoard[ROWS][COLS]);
int checkBingo(int bingoBoard[ROWS][COLS]);

int main() {
    int bingoBoard[ROWS][COLS];
    int numDrawn, row, col, bingoCount;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate the initial Bingo board
    generateBingoBoard(bingoBoard);

    // Print the generated Bingo board
    printf("Initial Bingo board: \n");
    printBingoBoard(bingoBoard);

    // Draw numbers until Bingo is achieved
    bingoCount = 0;
    while (bingoCount < ROWS + COLS + 2) {
        // Generate a random number from 1 to 25
        numDrawn = rand() % 25 + 1;
        printf("Number drawn: %d\n", numDrawn);

        // Mark the number on the Bingo board, if it exists
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                if (bingoBoard[row][col] == numDrawn) {
                    bingoBoard[row][col] = 0;
                }
            }
        }

        // Check for Bingo
        bingoCount = checkBingo(bingoBoard);
        if (bingoCount > 0) {
            printf("Bingo!\n");
            break;
        }
    }

    // Print the final Bingo board
    printf("Final Bingo board: \n");
    printBingoBoard(bingoBoard);

    return 0;
}

void generateBingoBoard(int bingoBoard[ROWS][COLS]) {
    int nums[ROWS * COLS];
    int num, row, col, i;

    // Initialize the array of possible numbers
    for (i = 0; i < ROWS * COLS; i++) {
        nums[i] = i + 1;
    }

    // Shuffle the array
    for (i = 0; i < ROWS * COLS; i++) {
        int temp = nums[i];
        int randIndex = rand() % (ROWS * COLS);
        nums[i] = nums[randIndex];
        nums[randIndex] = temp;
    }

    // Populate the Bingo board
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            num = nums[row * COLS + col];
            bingoBoard[row][col] = num;
        }
    }
}

void printBingoBoard(int bingoBoard[ROWS][COLS]) {
    int row, col;

    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++)
            printf("%2d ", bingoBoard[row][col]);
        printf("\n");
    }
}

int checkBingo(int bingoBoard[ROWS][COLS]) {
    int row, col, bingoCount;

    // Check rows
    bingoCount = 0;
    for (row = 0; row < ROWS; row++) {
        int bingo = 1;
        for (col = 0; col < COLS; col++) {
            if (bingoBoard[row][col] != 0) {
                bingo = 0;
                break;
            }
        }
        if (bingo) {
            bingoCount++;
        }
    }

    // Check columns
    for (col = 0; col < COLS; col++) {
        int bingo = 1;
        for (row = 0; row < ROWS; row++) {
            if (bingoBoard[row][col] != 0) {
                bingo = 0;
                break;
            }
        }
        if (bingo) {
            bingoCount++;
        }
    }

    // Check diagonals
    int diagBingo1 = 1, diagBingo2 = 1;
    for (row = 0; row < ROWS; row++) {
        if (bingoBoard[row][row] != 0) {
            diagBingo1 = 0;
        }
        if (bingoBoard[row][COLS - row - 1] != 0) {
            diagBingo2 = 0;
        }
    }
    if (diagBingo1) bingoCount++;
    if (diagBingo2) bingoCount++;

    return bingoCount;
}