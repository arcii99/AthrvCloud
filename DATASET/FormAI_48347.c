//FormAI DATASET v1.0 Category: Matrix operations ; Style: retro
#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int matrix1[ROWS][COLS] = {{1, 2, 3}, 
                               {4, 5, 6}, 
                               {7, 8, 9}};
                               
    int matrix2[ROWS][COLS] = {{2, 4, 6}, 
                               {8, 10, 12}, 
                               {14, 16, 18}};
                               
    int result[ROWS][COLS];
    int i, j;
    
    // addition
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    printf("Addition of two matrices: \n");
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    // subtraction
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    
    printf("Subtraction of two matrices: \n");
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    // multiplication
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            result[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
    
    printf("Multiplication of two matrices: \n");
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}