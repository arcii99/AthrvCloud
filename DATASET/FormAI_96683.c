//FormAI DATASET v1.0 Category: Data mining ; Style: safe
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROWS 5
#define MAX_COLUMNS 5

int main() {
    int data[MAX_ROWS][MAX_COLUMNS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int i, j, min;
    printf("The input array is: \n");
    // Printing the input array
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLUMNS; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Printing the minimum values from each column:\n");

    for (i = 0; i < MAX_COLUMNS; i++) {
        min = data[0][i];
        for (j = 1; j < MAX_ROWS; j++) {
            if (data[j][i] < min) {
                min = data[j][i];
            }
        }
        printf("Minimum value in column %d is %d\n", i + 1, min);
    }

    return 0;
}