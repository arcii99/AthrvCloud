//FormAI DATASET v1.0 Category: Data mining ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLUMNS 3

int main(void) {
    int data[ROWS][COLUMNS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15},
    };

    double sumOfColumn[COLUMNS];
    for (int j = 0; j < COLUMNS; j++) {
        sumOfColumn[j] = 0.0;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            sumOfColumn[j] += data[i][j];
        }
    }

    printf("Data:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Sum of Columns:\n");
    for (int j = 0; j < COLUMNS; j++) {
        printf("Column %d: %.2f\n", j+1, sumOfColumn[j]);
    }

    return 0;
}