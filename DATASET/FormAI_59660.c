//FormAI DATASET v1.0 Category: Data mining ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 4

int main() {

    // define sample data
    float data[ROWS][COLS] = {
        {1.2, 4.5, 7.8, 2.5},
        {5.1, 2.8, 3.6, 8.3},
        {6.9, 4.3, 2.1, 1.5},
        {3.7, 6.2, 9.1, 2.4},
        {8.9, 3.8, 1.2, 4.6},
        {7.1, 1.5, 3.9, 6.2},
        {4.5, 9.2, 6.7, 2.1},
        {2.8, 5.3, 1.7, 8.6}
    };

    // compute the mean values of each column
    float means[COLS] = {0};
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            means[i] += data[j][i];
        }
        means[i] /= ROWS;
    }

    // print the mean values
    printf("Mean Values:\n");
    for (int i = 0; i < COLS; i++) {
        printf("Column %d: %f\n", i, means[i]);
    }

    // compute the standard deviation of each column
    float stdevs[COLS] = {0};
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            stdevs[i] += (data[j][i] - means[i]) * (data[j][i] - means[i]);
        }
        stdevs[i] = sqrt(stdevs[i] / ROWS);
    }

    // print the standard deviation values
    printf("\nStandard Deviation Values:\n");
    for (int i = 0; i < COLS; i++) {
        printf("Column %d: %f\n", i, stdevs[i]);
    }

    return 0;
}