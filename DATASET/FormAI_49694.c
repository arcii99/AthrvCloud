//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

int main() {
    int bingoCard[ROWS][COLS];
    int numbersCalled[MAX_NUM] = {0};
    int numCounter = 0;
    int num;
    int row, col;
    int gameOver = 0;

    srand(time(NULL));

    // Initialize Bingo Card
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (row == 2 && col == 2) {
                bingoCard[row][col] = -1; // Free space in middle
            } else {
                bingoCard[row][col] = rand() % 15 + (15 * col) + 1;
            }
        }
    }

    // Display Bingo Card
    printf("Welcome to Bingo!\n\n");
    printf("Here is your Bingo Card:\n\n");
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            printf("%3d ", bingoCard[row][col]);
        }
        printf("\n");
    }

    printf("\nPress ENTER to start calling numbers.\n");
    getchar();

    // Call Numbers
    while (!gameOver) {
        num = rand() % MAX_NUM + 1;
        numCounter++;

        // Check if number has already been called
        if (numbersCalled[num - 1]) {
            continue;
        } else {
            numbersCalled[num - 1] = 1;
        }

        printf("\nNumber called: %d\n", num);

        // Check if number is on card
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                if (bingoCard[row][col] == num) {
                    bingoCard[row][col] = -1;
                    printf("Number found at Row %d, Column %d!\n", row+1, col+1);
                    break;
                }
            }
        }

        // Check for BINGO
        if (bingoCard[0][0] == -1 && bingoCard[1][1] == -1 && bingoCard[2][2] == -1 && bingoCard[3][3] == -1 && bingoCard[4][4] == -1) {
            printf("\nBINGO! You won in %d numbers called.\n", numCounter);
            gameOver = 1;
        } else if (bingoCard[0][4] == -1 && bingoCard[1][3] == -1 && bingoCard[2][2] == -1 && bingoCard[3][1] == -1 && bingoCard[4][0] == -1) {
            printf("\nBINGO! You won in %d numbers called.\n", numCounter);
            gameOver = 1;
        } else {
            int rowSum = 0;
            int colSum = 0;
            int diag1Sum = 0;
            int diag2Sum = 0;
            int bingoFound = 0;

            // Check rows
            for (row = 0; row < ROWS; row++) {
                for (col = 0; col < COLS; col++) {
                    rowSum += bingoCard[row][col];
                }
                if (rowSum == -5) {
                    printf("\nBINGO! You won in %d numbers called.\n", numCounter);
                    gameOver = 1;
                    bingoFound = 1;
                    break;
                } else {
                    rowSum = 0;
                }
            }

            if (bingoFound) {
                break;
            }

            // Check columns
            for (col = 0; col < COLS; col++) {
                for (row = 0; row < ROWS; row++) {
                    colSum += bingoCard[row][col];
                }
                if (colSum == -5) {
                    printf("\nBINGO! You won in %d numbers called.\n", numCounter);
                    gameOver = 1;
                    bingoFound = 1;
                    break;
                } else {
                    colSum = 0;
                }
            }

            if (bingoFound) {
                break;
            }

            // Check diagonal 1
            for (row = 0; row < ROWS; row++) {
                col = row;
                diag1Sum += bingoCard[row][col];
            }
            if (diag1Sum == -5) {
                printf("\nBINGO! You won in %d numbers called.\n", numCounter);
                gameOver = 1;
                bingoFound = 1;
                break;
            } else {
                diag1Sum = 0;
            }

            // Check diagonal 2
            for (row = 0; row < ROWS; row++) {
                col = COLS - 1 - row;
                diag2Sum += bingoCard[row][col];
            }
            if (diag2Sum == -5) {
                printf("\nBINGO! You won in %d numbers called.\n", numCounter);
                gameOver = 1;
                bingoFound = 1;
                break;
            } else {
                diag2Sum = 0;
            }
        }
    }

    printf("\nThank you for playing Bingo!\n");

    return 0;
}