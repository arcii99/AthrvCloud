//FormAI DATASET v1.0 Category: Memory Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main(void) {
    int i, j, k, l, temp;
    int row1, col1, row2, col2;
    int matrix[ROWS][COLS];
    int used[ROWS*COLS/2];
    
    srand(time(NULL));
    
    // Initialize used array
    for (i = 0; i < ROWS*COLS/2; i++) {
        used[i] = 0;
    }
    
    // Initialize matrix
    for (i = 0; i < ROWS*COLS; i++) {
        matrix[i/COLS][i%COLS] = -1;
    }
    
    // Fill in matrix
    for (i = 0; i < ROWS*COLS/2; i++) {
        // Generate random number
        temp = rand()%(ROWS*COLS/2);
        while (used[temp]) {
            temp = rand()%(ROWS*COLS/2);
        }
        used[temp] = 1;
        // Place number twice in matrix
        for (j = 0; j < 2; j++) {
            // Find empty slot in matrix
            do {
                row1 = rand()%ROWS;
                col1 = rand()%COLS;
            } while (matrix[row1][col1] != -1);
            matrix[row1][col1] = temp;
        }
    }
    
    // Game loop
    while (1) {
        // Print current state of matrix
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (matrix[i][j] == -1) {
                    printf(" X ");
                } else if (matrix[i][j] < 10) {
                    printf(" %d ", matrix[i][j]);
                } else {
                    printf("%d ", matrix[i][j]);
                }
            }
            printf("\n");
        }
        // Get input from user
        printf("Enter two coordinates (row col): ");
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);
        // Check if coordinates are valid
        if (row1 < 0 || row1 >= ROWS || col1 < 0 || col1 >= COLS ||
            row2 < 0 || row2 >= ROWS || col2 < 0 || col2 >= COLS) {
            printf("Invalid coordinates\n");
        } else if (matrix[row1][col1] == -1 || matrix[row2][col2] == -1) {
            printf("One or both coordinates are empty\n");
        } else if (matrix[row1][col1] != matrix[row2][col2]) {
            printf("Coordinates do not match\n");
        } else {
            // Remove matched tiles
            matrix[row1][col1] = -1;
            matrix[row2][col2] = -1;
            // Check if game over
            for (i = 0; i < ROWS*COLS; i++) {
                if (matrix[i/COLS][i%COLS] != -1) {
                    break;
                }
            }
            if (i == ROWS*COLS) {
                printf("You won!\n");
                break;
            }
        }
    }
    
    return 0;
}