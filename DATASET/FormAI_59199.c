//FormAI DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void printTable(int table[ROWS][COLS], int visible[ROWS][COLS]) {
    printf("  ");
    for (int j = 0; j < COLS; j++) {
        printf("%d ", j + 1);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (visible[i][j]) {
                printf("%d ", table[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int winCondition(int visible[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (visible[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int pairs[ROWS * COLS / 2];
    for (int i = 0; i < ROWS * COLS / 2; i++) {
        pairs[i] = i + 1;
    }
    srand(time(NULL));
    for (int i = 0; i < ROWS * COLS / 2; i++) {
        int j = rand() % (ROWS * COLS / 2);
        int temp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = temp;
    }
    int table[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            table[i][j] = pairs[i * COLS / 2 + j / 2];
        }
    }
    int visible[ROWS][COLS] = {{0}};
    printTable(table, visible);
    int firstRow, firstCol, secondRow, secondCol;
    while (!winCondition(visible)) {
        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &firstRow, &firstCol);
        firstRow--;
        firstCol--;
        while (visible[firstRow][firstCol] == 1) {
            printf("This card is already visible. Enter the row and column of another card: ");
            scanf("%d %d", &firstRow, &firstCol);
            firstRow--;
            firstCol--;
        }
        visible[firstRow][firstCol] = 1;
        printTable(table, visible);
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &secondRow, &secondCol);
        secondRow--;
        secondCol--;
        while (visible[secondRow][secondCol] == 1) {
            printf("This card is already visible. Enter the row and column of another card: ");
            scanf("%d %d", &secondRow, &secondCol);
            secondRow--;
            secondCol--;
        }
        visible[secondRow][secondCol] = 1;
        printTable(table, visible);
        if (table[firstRow][firstCol] != table[secondRow][secondCol]) {
            visible[firstRow][firstCol] = 0;
            visible[secondRow][secondCol] = 0;
        }
    }
    printf("Congratulations! You have won the game!\n");
    return 0;
}