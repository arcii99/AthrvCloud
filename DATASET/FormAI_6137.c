//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5
#define MAX_NUMBER 25

void printCard(int card[ROWS][COLUMNS]);
int checkBingo(int card[ROWS][COLUMNS], int num);
void generateNumbers(int numbers[]);
void markNumber(int card[ROWS][COLUMNS], int num);

int main() {
    int card[ROWS][COLUMNS] = {0};
    int numbers[MAX_NUMBER] = {0};
    int num, bingo;

    srand(time(0));
    generateNumbers(numbers);

    do {
        num = numbers[rand() % MAX_NUMBER];
        markNumber(card, num);
        printCard(card);
        bingo = checkBingo(card, num);
    } while (!bingo);

    printf("BINGO! You won!\n");

    return 0;
}

void printCard(int card[ROWS][COLUMNS]) {
    printf("-----------------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (card[i][j]) {
                printf("| X ");
            } else {
                printf("| %d ", i * COLUMNS + j + 1);
            }
        }
        printf("|\n");
        printf("-----------------\n");
    }
}

int checkBingo(int card[ROWS][COLUMNS], int num) {
    int i, j, count = 0;

    // check rows
    for (i = 0; i < ROWS; i++) {
        count = 0;
        for (j = 0; j < COLUMNS; j++) {
            if (card[i][j]) {
                count++;
            }
        }
        if (count == COLUMNS) {
            return 1;
        }
    }

    // check columns
    for (i = 0; i < COLUMNS; i++) {
        count = 0;
        for (j = 0; j < ROWS; j++) {
            if (card[j][i]) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1;
        }
    }

    // check diagonal
    count = 0;
    for (i = 0; i < ROWS; i++) {
        if (card[i][i]) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1;
    }

    // check reverse diagonal
    count = 0;
    for (i = 0; i < ROWS; i++) {
        if (card[i][ROWS - i - 1]) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1;
    }

    return 0;
}

void generateNumbers(int numbers[]) {
    int i;
    for (i = 0; i < MAX_NUMBER; i++) {
        numbers[i] = i + 1;
    }
}

void markNumber(int card[ROWS][COLUMNS], int num) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            if (card[i][j] == 0 && i * COLUMNS + j + 1 == num) {
                card[i][j] = 1;
                return;
            }
        }
    }
}