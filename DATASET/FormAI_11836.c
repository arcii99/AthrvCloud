//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Global constants */
#define ROWS 5
#define COLS 5
#define BINGO_NUM 25

/* Function prototypes */
void generateCard(int card[ROWS][COLS]);
void printCard(int card[ROWS][COLS]);
void shuffleNumbers(int numbers[BINGO_NUM]);
int generateNumber(int numbers[BINGO_NUM], int calledNumbers[BINGO_NUM], int calledCount);

int main() {
    int card[ROWS][COLS];
    int numbers[BINGO_NUM];
    int calledNumbers[BINGO_NUM] = {0};
    int calledCount = 0;
    int number;

    /* Seed the random number generator */
    srand(time(NULL));

    /* Shuffle the numbers */
    shuffleNumbers(numbers);

    /* Generate the card */
    generateCard(card);

    /* Print the card */
    printf("Your bingo card:\n");
    printCard(card);
    printf("\n");

    /* Play the game */
    printf("Let's play bingo!\n");
    while (1) {
        /* Generate a random number */
        number = generateNumber(numbers, calledNumbers, calledCount);
        calledNumbers[calledCount] = number;
        calledCount++;

        /* Print the number */
        printf("The number is: %d\n", number);

        /* Check if the number is on the card */
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] == number) {
                    /* Mark the number as called on the card */
                    card[i][j] = 0;

                    /* Print the updated card */
                    printf("Your updated bingo card:\n");
                    printCard(card);
                    printf("\n");

                    /* Check if the player has won */
                    if (i == j || i + j + 1 == ROWS) {
                        /* Diagonal win */
                        int hasWon = 1;
                        for (int k = 0; k < ROWS; k++) {
                            if (card[k][k] != 0 || card[k][ROWS - k - 1] != 0) {
                                hasWon = 0;
                                break;
                            }
                        }
                        if (hasWon) {
                            printf("Bingo! You won with a diagonal line!\n");
                            return 0;
                        }
                    } else {
                        /* Horizontal or vertical win */
                        int hasWon = 1;
                        for (int k = 0; k < ROWS; k++) {
                            if (card[i][k] != 0 || card[k][j] != 0) {
                                hasWon = 0;
                                break;
                            }
                        }
                        if (hasWon) {
                            printf("Bingo! You won with a horizontal or vertical line!\n");
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

void generateCard(int card[ROWS][COLS]) {
    int numbers[BINGO_NUM];
    int usedNumbers[BINGO_NUM] = {0};
    int row, col, index;

    /* Generate a list of numbers */
    for (int i = 0; i < BINGO_NUM; i++) {
        numbers[i] = i + 1;
    }

    /* Shuffle the numbers */
    shuffleNumbers(numbers);

    /* Fill the card */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            /* Find the next unused number */
            do {
                index = rand() % BINGO_NUM;
            } while (usedNumbers[index]);
            usedNumbers[index] = 1;

            /* Place the number on the card */
            card[i][j] = numbers[index];
        }
    }
}

void printCard(int card[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%3d ", card[i][j]);
        }
        printf("\n");
    }
}

void shuffleNumbers(int numbers[BINGO_NUM]) {
    int temp, index;

    for (int i = 0; i < BINGO_NUM; i++) {
        /* Find a random index */
        index = rand() % BINGO_NUM;

        /* Swap the number with the random index */
        temp = numbers[i];
        numbers[i] = numbers[index];
        numbers[index] = temp;
    }
}

int generateNumber(int numbers[BINGO_NUM], int calledNumbers[BINGO_NUM], int calledCount) {
    int index, number;

    /* Find a number that has not been called */
    do {
        index = rand() % BINGO_NUM;
        number = numbers[index];
    } while (calledNumbers[index]);

    return number;
}