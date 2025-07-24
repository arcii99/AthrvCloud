//FormAI DATASET v1.0 Category: Data recovery tool ; Style: mathematical
#include <stdio.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

int main(void) {
    int rows, cols;
    int data[MAX_ROWS][MAX_COLS];
    int recovered_data[MAX_ROWS][MAX_COLS];

    // Get input from user
    printf("Enter number of rows and columns (separated by space): ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the data matrix (%d rows x %d cols):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &data[i][j]);
        }
    }

    // Recover data
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = 0;
            for (int k = 0; k < rows; k++) {
                sum += data[k][j];
            }
            recovered_data[i][j] = sum - data[i][j];
        }
    }

    // Print recovered data
    printf("\nRecovered data:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", recovered_data[i][j]);
        }
        printf("\n");
    }

    return 0;
}