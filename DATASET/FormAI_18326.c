//FormAI DATASET v1.0 Category: Matrix operations ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS 3
#define COLS 3

// Function to display a matrix
void display(int matrix[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to compute the sum of all elements in the matrix
int sum(int matrix[][COLS]) {
    int total = 0;
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            total += matrix[i][j];
        }
    }
    return total;
}

// Function to compute the transpose of a matrix
void transpose(int matrix[][COLS]) {
    int temp;
    for(int i=0; i<ROWS; i++) {
        for(int j=i+1; j<COLS; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

// Function to generate a random matrix with values between 0 and 9
void generate(int matrix[][COLS]) {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

int main() {
    int matrix[ROWS][COLS];
    generate(matrix);
    printf("Generated matrix:\n");
    display(matrix);
    printf("Sum of elements: %d\n", sum(matrix));
    printf("Transposed matrix:\n");
    transpose(matrix);
    display(matrix);
    return 0;
}