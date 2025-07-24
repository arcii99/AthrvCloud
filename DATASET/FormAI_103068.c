//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

void generateArray(int arr[][COLS], int rows, int cols);
void printArray(int arr[][COLS], int rows, int cols);
void visualizeArray(int arr[][COLS], int rows, int cols);

int main() {
    int arr[ROWS][COLS];

    // Generate random numbers and fill the array
    generateArray(arr, ROWS, COLS);

    // Print the array
    printArray(arr, ROWS, COLS);

    // Visualize the array in a Cyberpunk style
    visualizeArray(arr, ROWS, COLS);

    return 0;
}

// Generate random numbers and fill the array
void generateArray(int arr[][COLS], int rows, int cols) {
    srand(time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 10;
        }
    }
}

// Print the array
void printArray(int arr[][COLS], int rows, int cols) {
    printf("Array:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Visualize the array in a Cyberpunk style
void visualizeArray(int arr[][COLS], int rows, int cols) {
    printf("Visualization:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 0) {
                printf(" ");
            } else if (arr[i][j] == 1) {
                printf("_");
            } else if (arr[i][j] == 2) {
                printf("/");
            } else if (arr[i][j] == 3) {
                printf("\\");
            } else if (arr[i][j] == 4) {
                printf("|");
            } else if (arr[i][j] == 5) {
                printf("O");
            } else if (arr[i][j] == 6) {
                printf("*");
            } else if (arr[i][j] == 7) {
                printf("+");
            } else if (arr[i][j] == 8) {
                printf("-");
            } else if (arr[i][j] == 9) {
                printf("#");
            }
        }
        printf("\n");
    }
}