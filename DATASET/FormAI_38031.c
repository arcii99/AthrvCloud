//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void printCard(int card[][COLS]);
void generateCard(int card[][COLS]);
int callNumber(int numbers[]);
int checkForBingo(int card[][COLS], int numbers[]);

int main() {
    srand(time(NULL));
    int card[ROWS][COLS];
    int numbers[76] = {0}; // 75 possible numbers
    int numCalled, result;

    generateCard(card);
    printCard(card);

    while (1) {
        numCalled = callNumber(numbers);
        if (numCalled == -1) {
            printf("All numbers called, ending game.\n");
            break;
        }

        printf("Number called: %d\n", numCalled);
        result = checkForBingo(card, numbers);
        if (result == 1) {
            printf("Bingo! You won!\n");
            break;
        }
    }

    return 0;
}

void generateCard(int card[][COLS]) {
    int nums[5][5] = {{0}};
    int row, col, randNum;

    for (col = 0; col < COLS; col++) {
        randNum = (col * 15) + (rand() % 15) + 1;
        nums[2][col] = randNum;
    }

    for (col = 0; col < COLS; col++) {
        if (col == 2) {
            continue;
        }

        randNum = (col * 15) + (rand() % 15) + 1;
        nums[0][col] = randNum;

        while (1) {
            randNum = (col * 15) + (rand() % 15) + 1;
            if (randNum != nums[0][col]) {
                break;
            }
        }

        nums[4][col] = randNum;
    }

    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (nums[row][col] != 0) {
                card[row][col] = nums[row][col];
            }
        }
    }
}

void printCard(int card[][COLS]) {
    int row, col;

    printf("\n==============\n");
    printf(" B  I  N  G  O\n");
    printf("==============\n");

    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (card[row][col] != 0) {
                printf("%2d ", card[row][col]);
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    printf("\n");
}

int callNumber(int numbers[]) {
    int numCalled;

    while (1) {
        numCalled = (rand() % 75) + 1;
        if (numbers[numCalled] == 0) {
            numbers[numCalled] = 1;
            return numCalled;
        }
    }

    if (numbers[75] == 1) {
        return -1; // all numbers called
    }
}

int checkForBingo(int card[][COLS], int numbers[]) {
    int row, col, diag1, diag2, bingo;

    // check rows
    for (row = 0; row < ROWS; row++) {
        bingo = 1;
        for (col = 0; col < COLS; col++) {
            if (numbers[card[row][col]] == 0) {
                bingo = 0;
                break;
            }
        }

        if (bingo == 1) {
            return 1;
        }
    }

    // check columns
    for (col = 0; col < COLS; col++) {
        bingo = 1;
        for (row = 0; row < ROWS; row++) {
            if (numbers[card[row][col]] == 0) {
                bingo = 0;
                break;
            }
        }

        if (bingo == 1) {
            return 1;
        }
    }

    // check diagonal (top left to bottom right)
    bingo = 1;
    diag1 = 0;
    for (row = 0, col = 0; row < ROWS && col < COLS; row++, col++) {
        if (numbers[card[row][col]] == 0) {
            bingo = 0;
            break;
        }

        diag1 += numbers[card[row][col]];
    }

    if (bingo == 1) {
        return 1;
    }

    // check diagonal (top right to bottom left)
    bingo = 1;
    diag2 = 0;
    for (row = 0, col = COLS - 1; row < ROWS && col >= 0; row++, col--) {
        if (numbers[card[row][col]] == 0) {
            bingo = 0;
            break;
        }

        diag2 += numbers[card[row][col]];
    }

    if (bingo == 1) {
        return 1;
    }

    return 0;
}