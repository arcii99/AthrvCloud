//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 5
#define COLS 5
#define MAX_NUM 75

// Function prototypes
void generateCard(int card[ROWS][COLS]);
void printCard(int card[ROWS][COLS]);
int drawNumber(int drawnNumbers[MAX_NUM], int numDrawn);
int checkCard(int card[ROWS][COLS], int calledNum);
int checkBingo(int card[ROWS][COLS]);

int main(void) {
    // Seed random number generator
    srand(time(NULL));

    // Declare variables
    int card[ROWS][COLS];
    int drawnNumbers[MAX_NUM] = {0};
    int numDrawn = 0;
    int calledNum;
    int bingo = 0;

    // Generate card
    generateCard(card);

    // Print card
    printCard(card);

    // Game loop
    while (!bingo) {
        // Draw number
        calledNum = drawNumber(drawnNumbers, numDrawn);
        numDrawn++;

        printf("Called number: %d\n", calledNum);

        // Check card
        if (checkCard(card, calledNum)) {
            printf("Number found on card!\n");
        } else {
            printf("Number not found on card.\n");
        }

        // Check for bingo
        if (checkBingo(card)) {
            printf("Bingo! You win!\n");
            bingo = 1;
        }
    }

    return 0;
}

// Function to generate a bingo card
void generateCard(int card[ROWS][COLS]) {
    int i, j;
    int nums[MAX_NUM];

    // Generate list of numbers
    for (i = 0; i < MAX_NUM; i++) {
        nums[i] = i + 1;
    }

    // Shuffle list of numbers
    for (i = 0; i < MAX_NUM; i++) {
        int temp = nums[i];
        int randomIndex = rand() % MAX_NUM;

        nums[i] = nums[randomIndex];
        nums[randomIndex] = temp;
    }

    // Fill in card
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if ((i == 2) && (j == 2)) {
                // Free space in center
                card[i][j] = 0;
            } else {
                // Fill in number
                card[i][j] = nums[(j * ROWS) + i];
            }
        }
    }
}

// Function to print a bingo card
void printCard(int card[ROWS][COLS]) {
    int i, j;

    printf("+----+----+----+----+----+\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                // Free space in center
                printf("|  X ");
            } else {
                printf("|%3d ", card[i][j]);
            }
        }

        printf("|\n");
        printf("+----+----+----+----+----+\n");
    }
}

// Function to draw a random number
int drawNumber(int drawnNumbers[MAX_NUM], int numDrawn) {
    int num;
    int validNum = 0;

    // Keep drawing numbers until a valid number is drawn
    while (!validNum) {
        num = (rand() % MAX_NUM) + 1;

        // Check if number has already been drawn
        if (!drawnNumbers[num - 1]) {
            drawnNumbers[num - 1] = 1;
            validNum = 1;
        }
    }

    return num;
}

// Function to check if a number is on a card
int checkCard(int card[ROWS][COLS], int calledNum) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (card[i][j] == calledNum) {
                card[i][j] = 0; // Mark number as found on card
                return 1;
            }
        }
    }

    return 0;
}

// Function to check for bingo
int checkBingo(int card[ROWS][COLS]) {
    int i, j;
    int rowSum, colSum;
    int diagSum1 = 0, diagSum2 = 0;

    // Check rows for bingo
    for (i = 0; i < ROWS; i++) {
        rowSum = 0;

        for (j = 0; j < COLS; j++) {
            rowSum += card[i][j];
        }

        if (rowSum == 0) {
            return 1;
        }
    }

    // Check columns for bingo
    for (i = 0; i < COLS; i++) {
        colSum = 0;

        for (j = 0; j < ROWS; j++) {
            colSum += card[j][i];
        }

        if (colSum == 0) {
            return 1;
        }
    }

    // Check diagonal for bingo
    for (i = 0; i < ROWS; i++) {
        diagSum1 += card[i][i];
        diagSum2 += card[i][ROWS - i - 1];
    }

    if ((diagSum1 == 0) || (diagSum2 == 0)) {
        return 1;
    }

    // No bingo yet
    return 0;
}