//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void fillCard(int card[ROWS][COLS]);
void printCard(int card[ROWS][COLS]);
int checkBingo(int card[ROWS][COLS]);

int main() {
    int card[ROWS][COLS];
    int numberDrawn, bingo;
    srand(time(NULL));
    
    fillCard(card); // fill the card with random numbers
    printCard(card); // print out the card
    
    printf("\nReady to start drawing numbers!\n");
    fflush(stdout);
    
    bingo = 0;
    while (!bingo) {
        // draw a random number between 1 and 75
        numberDrawn = rand() % 75 + 1;
        printf("\n%d!\n", numberDrawn);
        fflush(stdout);
        
        // check if the number is on the card and mark it off
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] == numberDrawn) {
                    card[i][j] = -1;
                }
            }
        }
        printCard(card); // print out the updated card
        
        // check for bingo
        bingo = checkBingo(card);
        if (bingo) {
            printf("\nBINGO!!!\n");
            fflush(stdout);
        }
    }

    return 0;
}

// fill the card with random numbers
void fillCard(int card[ROWS][COLS]) {
    // initialize all values to 0
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            card[i][j] = 0;
        }
    }

    // fill the card with random values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int duplicateFlag = 0;
            int val;
            do {
                duplicateFlag = 0;
                val = rand() % 15 + 1 + (j * 15);
                for (int k = 0; k < ROWS; k++) {
                    for (int l = 0; l < COLS; l++) {
                        if (card[k][l] == val) {
                            duplicateFlag = 1;
                        }
                    }
                }
            } while (duplicateFlag); // keep generating a random value until it is unique
            card[i][j] = val;
        }
    }

    // mark the center cell as free
    card[ROWS / 2][COLS / 2] = -1;
}

// print out the card
void printCard(int card[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == -1) {
                printf(" * ");
            } else {
                printf("%2d ", card[i][j]);
            }
        }
        printf("\n");
    }
    fflush(stdout);
}

// check for bingo
int checkBingo(int card[ROWS][COLS]) {
    // check rows
    for (int i = 0; i < ROWS; i++) {
        int hitCount = 0;
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == -1) {
                hitCount++;
            }
        }
        if (hitCount == COLS) {
            return 1;
        }
    }

    // check columns
    for (int j = 0; j < COLS; j++) {
        int hitCount = 0;
        for (int i = 0; i < ROWS; i++) {
            if (card[i][j] == -1) {
                hitCount++;
            }
        }
        if (hitCount == ROWS) {
            return 1;
        }
    }

    // check diagonals
    int hitCount = 0;
    for (int i = 0; i < ROWS; i++) {
        if (card[i][i] == -1) {
            hitCount++;
        }
    }
    if (hitCount == ROWS) {
        return 1;
    }

    hitCount = 0;
    for (int i = 0; i < ROWS; i++) {
        if (card[i][ROWS - i - 1] == -1) {
            hitCount++;
        }
    }
    if (hitCount == ROWS) {
        return 1;
    }

    // if no bingo, return 0
    return 0;
}