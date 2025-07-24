//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

void populateCard(int card[ROWS][COLUMNS]);
void printCard(int card[ROWS][COLUMNS]);
int checkWon(int card[ROWS][COLUMNS], int numbers[75]);

int main() {
    int card[ROWS][COLUMNS];
    int numbers[75], randomNumber;
    int drawCount = 0;

    // Populate card with random numbers
    populateCard(card);

    // Generate array of all possible numbers
    for (int i = 0; i < 75; i++) {
        numbers[i] = i + 1;
    }

    // Shuffle array of numbers using Fisher-Yates algorithm
    srand(time(NULL));
    for (int i = 74; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Start drawing numbers
    printf("Starting game...\n");
    while (drawCount < 75) {
        printf("Press ENTER to draw a number.\n");
        getchar();

        // Check for winning condition
        if (checkWon(card, numbers)) {
            printf("BINGO!\n");
            return 0;
        }

        // Draw a number and mark it on card
        randomNumber = numbers[drawCount];
        printf("The drawn number is: %d\n", randomNumber);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (card[i][j] == randomNumber) {
                    card[i][j] = 0;
                }
            }
        }

        // Print updated card
        printCard(card);
        drawCount++;
    }

    printf("All numbers have been drawn. Better luck next time!\n");
    return 0;
}

void populateCard(int card[ROWS][COLUMNS]) {
    int numbers[15];
    int used[15] = {0};
    int count = 0;

    // Initialize card with zeros
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            card[i][j] = 0;
        }
    }

    // Populate each column with random numbers
    srand(time(NULL));
    for (int i = 0; i < COLUMNS; i++) {
        // Generate array of 15 unique random numbers
        while (count < 15) {
            int num = rand() % 15 + (i * 15) + 1;
            if (!used[num - (i * 15) - 1]) {
                numbers[count] = num;
                used[num - (i * 15) - 1] = 1;
                count++;
            }
        }
        count = 0;

        // Sort array of 15 numbers in ascending order
        for (int j = 0; j < 14; j++) {
            for (int k = j + 1; k < 15; k++) {
                if (numbers[j] > numbers[k]) {
                    int temp = numbers[j];
                    numbers[j] = numbers[k];
                    numbers[k] = temp;
                }
            }
        }

        // Place each number in corresponding row of column
        for (int j = 0; j < 15; j++) {
            card[j % ROWS][(int)(i / 3) * 3 + (int)(j / 3)] = numbers[j];
        }
    }
}

void printCard(int card[ROWS][COLUMNS]) {
    printf("----------------------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (card[i][j] == 0) {
                printf("|   ");
            } else {
                printf("| %2d", card[i][j]);
            }
        }
        printf("|\n----------------------\n");
    }
}

int checkWon(int card[ROWS][COLUMNS], int numbers[75]) {
    // Check rows for winning condition
    for (int i = 0; i < ROWS; i++) {
        int fullRow = 1;
        for (int j = 0; j < COLUMNS; j++) {
            if (card[i][j] != 0) {
                fullRow = 0;
                break;
            }
        }
        if (fullRow) {
            return 1;
        }
    }

    // Check columns for winning condition
    for (int i = 0; i < COLUMNS; i++) {
        int fullColumn = 1;
        for (int j = 0; j < ROWS; j++) {
            if (card[j][i] != 0) {
                fullColumn = 0;
                break;
            }
        }
        if (fullColumn) {
            return 1;
        }
    }

    // Check diagonals for winning condition
    int fullDiagonal1 = 1, fullDiagonal2 = 1;
    for (int i = 0; i < ROWS; i++) {
        if (card[i][i] != 0) {
            fullDiagonal1 = 0;
            break;
        }
    }
    for (int i = 0; i < ROWS; i++) {
        if (card[i][COLUMNS - i - 1] != 0) {
            fullDiagonal2 = 0;
            break;
        }
    }
    if (fullDiagonal1 || fullDiagonal2) {
        return 1;
    }

    return 0;
}