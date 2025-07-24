//FormAI DATASET v1.0 Category: Matrix operations ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

// Function prototypes
void matrix_addition(int arr1[][COLS], int arr2[][COLS], int result[][COLS]);
void matrix_multiplication(int arr1[][COLS], int arr2[][COLS], int result[][COLS]);
void matrix_transpose(int arr[][COLS], int result[][ROWS]);

// Main function
int main() {
    int arr1[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int arr2[ROWS][COLS] = { {9, 8, 7}, {6, 5, 4}, {3, 2, 1} };
    int result[ROWS][COLS];

    printf("Matrix 1:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    // Adding two matrices
    matrix_addition(arr1, arr2, result);
    printf("\nAddition of two matrices:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Multiplying two matrices
    matrix_multiplication(arr1, arr2, result);
    printf("\nMultiplication of two matrices:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Transposing a matrix
    matrix_transpose(arr1, result);
    printf("\nTranspose of matrix 1:\n");
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Function to add two matrices
void matrix_addition(int arr1[][COLS], int arr2[][COLS], int result[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

// Function to multiply two matrices
void matrix_multiplication(int arr1[][COLS], int arr2[][COLS], int result[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void matrix_transpose(int arr[][COLS], int result[][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[j][i] = arr[i][j];
        }
    }
}