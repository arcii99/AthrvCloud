//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 25

void generateBingoCard(int card[][COLS]);
void printBingoCard(int card[][COLS]);
int checkBingo(int card[][COLS]);

int main() {
    int card[ROWS][COLS];
    int numCalled[MAX_NUM] = {0};
    int numCount = 0;
    int bingo = 0;

    // Seed RNG with current time
    srand(time(NULL));

    generateBingoCard(card);
    printBingoCard(card);

    // Main loop
    while (!bingo) {
        // Generate a random number
        int num = rand() % MAX_NUM + 1;
        printf("Number called: %d\n", num);

        // Check if number has already been called
        if (numCalled[num-1]) {
            printf("Number already called.\n");
        }
        else {
            // Mark number as called
            numCalled[num-1] = 1;
            numCount++;

            // Check if number is on player's card
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (card[i][j] == num) {
                        card[i][j] = 0;
                        printf("Number found on card!\n");
                    }
                }
            }

            printBingoCard(card);

            // Check for bingo
            bingo = checkBingo(card);
            if (bingo) {
                printf("BINGO! You win!\n");
            }
            else {
                printf("Numbers called: %d\n", numCount);
            }
        }
    }

    return 0;
}

void generateBingoCard(int card[][COLS]) {
    // Initialize card to zeros
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            card[i][j] = 0;
        }
    }

    // Generate random numbers for card
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Generate random number within range and check if it is already on card
            int num;
            do {
                num = rand() % MAX_NUM + 1;
            } while (card[i][j] == num);
            card[i][j] = num;
        }
    }
}

void printBingoCard(int card[][COLS]) {
    printf("BINGO CARD\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                printf("[X]\t");
            }
            else {
                printf("[%d]\t", card[i][j]);
            }
        }
        printf("\n");
    }
}

int checkBingo(int card[][COLS]) {
    int bingo = 0;

    // Check rows for bingo
    for (int i = 0; i < ROWS; i++) {
        int rowSum = 0;
        for (int j = 0; j < COLS; j++) {
            rowSum += card[i][j];
        }
        if (rowSum == 0) {
            bingo = 1;
            break;  
        }
    }

    if (bingo) return bingo;

    // Check columns for bingo
    for (int i = 0; i < COLS; i++) {
        int colSum = 0;
        for (int j = 0; j < ROWS; j++) {
            colSum += card[j][i];
        }
        if (colSum == 0) {
            bingo = 1;
            break;  
        }
    }

    if (bingo) return bingo;

    // Check diagonal from top-left to bottom-right
    int diag1Sum = 0;
    for (int i = 0; i < ROWS; i++) {
        diag1Sum += card[i][i];
    }
    if (diag1Sum == 0) {
        bingo = 1;
        return bingo;
    }

    // Check diagonal from top-right to bottom-left
    int diag2Sum = 0;
    for (int i = 0; i < ROWS; i++) {
        diag2Sum += card[i][COLS-1-i];
    }
    if (diag2Sum == 0) {
        bingo = 1;
        return bingo;
    }

    return bingo;
}