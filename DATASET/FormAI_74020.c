//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main(void) {
    srand(time(NULL));
    int bingo[ROWS][COLS];
    int i, j;
    int minValue = 1, maxValue = 75;

    // Fill Bingo Table with Unique Values between 1 and 75
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            int value = rand() % (maxValue - minValue + 1) + minValue;
            // Check for Unique Value
            while(hasValue(bingo, ROWS, COLS, value)) {
                value = rand() % (maxValue - minValue + 1) + minValue;
            }
            bingo[i][j] = value;
        }
    }
    // Fill Middle Square with Free Space (Number 0)
    bingo[2][2] = 0;

    // Display Bingo table
    printf("Welcome to Bingo Game\n");
    printf("--------------------\n\n");
    displayBingo(bingo, ROWS, COLS);
    
    // Play Bingo
    int numCalled, matches;
    printf("\n\nLET'S PLAY BINGO!!!\n\n");
    while(1) {
        printf("Enter call number (1-75): ");
        scanf("%d", &numCalled);
        // Check for Valid Input
        while(numCalled < 1 || numCalled > 75) {
            printf("Invalid input! Enter call number (1-75): ");
            scanf("%d", &numCalled);
        }
        // Mark Called Number in Bingo Table
        matches = markNumber(bingo, ROWS, COLS, numCalled);
        // Display Updated Bingo Table
        displayBingo(bingo, ROWS, COLS);
        if(matches > 0) {
            printf("You have %d matches!\n", matches);
        }
        if(checkWin(bingo, ROWS, COLS)) {
            printf("BINGO!!! You Won!!!\n");
            break;
        }
    }

    return 0;
}

// Helper Functions

int hasValue(int bingo[][COLS], int rows, int cols, int value) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(bingo[i][j] == value) {
                return 1;
            }
        }
    }
    return 0;
}

int markNumber(int bingo[][COLS], int rows, int cols, int value) {
    int i, j, matches = 0;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(bingo[i][j] == value) {
                bingo[i][j] = -1;
                matches++;
            }
        }
    }
    return matches;
}

int checkWin(int bingo[][COLS], int rows, int cols) {
    int i, j;
    int rowCount, colCount, diagCount1 = 0, diagCount2 = 0;
    for(i = 0; i < rows; i++) {
        rowCount = 0;
        colCount = 0;
        for(j = 0; j < cols; j++) {
            if(bingo[i][j] == -1 || bingo[i][j] == 0) {
                rowCount++;
            }
            if(bingo[j][i] == -1 || bingo[j][i] == 0) {
                colCount++;
            }
            if(i == j && (bingo[i][j] == -1 || bingo[i][j] == 0)) {
                diagCount1++;
            }
            if(i + j == ROWS - 1 && (bingo[i][j] == -1 || bingo[i][j] == 0)) {
                diagCount2++;
            }
        }
        if(rowCount == ROWS || colCount == COLS || diagCount1 == ROWS || diagCount2 == ROWS) {
            return 1;
        }
    }
    return 0;
}

void displayBingo(int bingo[][COLS], int rows, int cols) {
    int i, j;
    printf("\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(bingo[i][j] == -1) {
                printf(" XX ");
            } else {
                printf(" %02d ", bingo[i][j]);
            }
        }
        printf("\n");
    }
}