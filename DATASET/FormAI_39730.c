//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 100000
#define COLS 1000

void matrix_multiply(int a[][COLS], int b[][COLS], int c[][COLS], int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            for(int k=0; k<cols; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int a[ROWS][COLS], b[ROWS][COLS], c[ROWS][COLS];

    srand(time(0));

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
            c[i][j] = 0;
        }
    }

    matrix_multiply(a, b, c, ROWS, COLS);

    // Print first and last element of resultant matrix
    printf("Resultant Matrix: \n");
    printf("%d ", c[0][0]);
    printf("%d\n", c[ROWS-1][COLS-1]);

    return 0;
}