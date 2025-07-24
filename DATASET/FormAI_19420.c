//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COLUMN 5
#define MAX_RAND_NUM 75

void displayCard(int card[ROW][COLUMN]) {
    printf("+-------------------+\n");
    for (int i = 0; i < ROW; i++) {
        printf("|");
        for (int j = 0; j < COLUMN; j++) {
            if (card[i][j] == 0)
                printf("   ");
            else
                printf(" %2d", card[i][j]);
        }
        printf(" |\n");
    }
    printf("+-------------------+\n");
}

void generateCard(int card[ROW][COLUMN]) {
    srand(time(NULL));
    for (int i = 0; i < ROW; i++) {
        int count = 0;
        while (count < COLUMN) {
            int randNum = rand() % MAX_RAND_NUM + 1;
            int isDuplicate = 0;
            for (int j = 0; j < COLUMN; j++) {
                if (card[i][j] == randNum) {
                    isDuplicate = 1;
                    break;
                }
            }
            if (!isDuplicate) {
                card[i][count] = randNum;
                count++;
            }
        }
    }
}

int checkBingo(int card[ROW][COLUMN], int calledNumbers[MAX_RAND_NUM]) {
    int isBingo = 0;
    // Check rows
    for (int i = 0; i < ROW; i++) {
        int count = 0;
        for (int j = 0; j < COLUMN; j++) {
            if (calledNumbers[card[i][j] - 1] == 1)
                count++;
        }
        if (count == COLUMN) {
            isBingo = 1;
            break;
        }
    }
    if (isBingo)
        return 1;

    // Check columns
    for (int i = 0; i < COLUMN; i++) {
        int count = 0;
        for (int j = 0; j < ROW; j++) {
            if (calledNumbers[card[j][i] - 1] == 1)
                count++;
        }
        if (count == ROW) {
            isBingo = 1;
            break;
        }
    }
    if (isBingo)
        return 1;

    // Check diagonals
    int count = 0;
    for (int i = 0; i < ROW; i++) {
        if (calledNumbers[card[i][i] - 1] == 1)
            count++;
    }
    if (count == ROW) {
        isBingo = 1;
        return 1;
    }

    count = 0;
    for (int i = 0; i < ROW; i++) {
        if (calledNumbers[card[i][ROW - i - 1] - 1] == 1)
            count++;
    }
    if (count == ROW) {
        isBingo = 1;
        return 1;
    }

    return 0;
}

int main() {
    int card[ROW][COLUMN] = {0};
    generateCard(card);
    int calledNumbers[MAX_RAND_NUM] = {0};
    int bingo = 0;
    int numCalled = 0;

    while (!bingo) {
        printf("\n");
        displayCard(card);
        printf("Numbers called: ");
        for (int i = 0; i < MAX_RAND_NUM; i++) {
            if (calledNumbers[i] == 1)
                printf("%d ", i + 1);
        }
        printf("\n");

        int randNum;
        while (1) {
            printf("Enter a number (1-75): ");
            scanf("%d", &randNum);
            if (randNum < 1 || randNum > 75) {
                printf("Invalid input. Please enter a number between 1-75.\n");
            }
            else if (calledNumbers[randNum - 1] == 1) {
                printf("Number has already been called. Please enter another number.\n");
            }
            else {
                calledNumbers[randNum - 1] = 1;
                numCalled++;
                break;
            }
        }

        if (checkBingo(card, calledNumbers)) {
            printf("\nBINGO! You won in %d calls.\n", numCalled);
            bingo = 1;
        }
    }

    return 0;
}