//FormAI DATASET v1.0 Category: Data mining ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 3

int main() {
    int data[NUM_ROWS][NUM_COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 14, 15}
    };
    int i, j;
    int max_value = data[0][0];
    int min_value = data[0][0];
    double sum = 0.0;

    // Find maximum and minimum value
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            if (data[i][j] > max_value) {
                max_value = data[i][j];
            }
            if (data[i][j] < min_value) {
                min_value = data[i][j];
            }
            sum += (double)data[i][j];
        }
    }
    printf("The maximum value is: %d\n", max_value);
    printf("The minimum value is: %d\n", min_value);
    printf("The average value is: %lf\n", sum/((double)NUM_ROWS*(double)NUM_COLS));

    return 0;
}