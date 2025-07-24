//FormAI DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 20

int main() {
    int data[ROWS][COLUMNS];
    int i, j;
    float average = 0.0;
    srand(time(NULL));
    
    //populate data array with random values between 1 and 100
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            data[i][j] = rand() % 100 + 1;
        }
    }

    //print original data
    printf("Original Data:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }

    //calculate average of each row
    for (i = 0; i < ROWS; i++) {
        average = 0.0;
        for (j = 0; j < COLUMNS; j++) {
            average += data[i][j];
        }
        average /= COLUMNS;
        printf("Average of row %d: %f\n", i+1, average);
    }

    return 0;
}