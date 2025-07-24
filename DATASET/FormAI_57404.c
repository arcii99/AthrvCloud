//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX 75

void printCard(int card[ROWS][COLS]);
void generateNumbers(int numbers[MAX]);
int checkWin(int card[ROWS][COLS]);

int main() {
    int card[ROWS][COLS] = {0};
    int numbers[MAX] = {0};
    int numCalled;
    int numCount = 0;
    int win;

    srand(time(NULL));

    // Generate bingo card
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 2 && j == 2) {
                card[i][j] = -1; // Free space in center
                continue;
            }
            card[i][j] = rand() % 15 + (j * 15) + 1;
        }
    }

    printf("Welcome to Bingo!\n");

    // Print initial card
    printf("Your card is:\n");
    printCard(card);

    // Generate numbers and call them
    while (numCount < MAX) {
        generateNumbers(numbers);
        numCalled = numbers[numCount];
        numCount++;

        printf("The number called is: %d\n", numCalled);

        // Scan card for called number
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] == numCalled) {
                    card[i][j] = -1; // Mark as called
                }
            }
        }

        // Print updated card
        printf("Your updated card is:\n");
        printCard(card);

        // Check for win
        win = checkWin(card);
        if (win) {
            printf("BINGO!!! You win!!\n");
            break;
        }
    }

    if (!win) {
        printf("You did not win. Better luck next time!\n");
    }

    return 0;
}

// Print bingo card
void printCard(int card[ROWS][COLS]) {
    printf("================\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == -1) {
                printf("F ");
            } else {
                printf("%d ", card[i][j]);
            }
        }
        printf("\n");
    }
    printf("================\n");
}

// Generate numbers
void generateNumbers(int numbers[MAX]) {
    int randNum;
    int isDuplicate;

    do {
        randNum = rand() % MAX + 1;
        isDuplicate = 0;

        // Check if number is duplicate
        for (int i = 0; i < MAX; i++) {
            if (numbers[i] == randNum) {
                isDuplicate = 1;
            }
        }
    } while (isDuplicate);

    // Add number to array
    numbers[MAX] = randNum;
}

// Check for win
int checkWin(int card[ROWS][COLS]) {
    int rowSum;
    int colSum;
    int diagSum1 = 0;
    int diagSum2 = 0;

    // Check rows and columns for completed rows and columns
    for (int i = 0; i < ROWS; i++) {
        rowSum = 0;
        colSum = 0;
        for (int j = 0; j < COLS; j++) {
            rowSum += card[i][j];
            colSum += card[j][i];
        }
        if (rowSum == -5 || colSum == -5) {
            return 1;
        }
    }

    // Check diagonals for completed diagonals
    for (int i = 0; i < ROWS; i++) {
        diagSum1 += card[i][i];
        diagSum2 += card[i][ROWS - 1 - i];
    }
    if (diagSum1 == -5 || diagSum2 == -5) {
        return 1;
    }

    return 0;
}