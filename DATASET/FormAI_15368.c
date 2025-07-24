//FormAI DATASET v1.0 Category: Data mining ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create an irregular-shaped array of data
    int data[3][4] = {
        {1, 2, 3, 4},
        {6, 7, 8},
        {10, 11, 12, 13}
    };

    // Print the original data
    printf("Original Data:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (data[i][j] != 0) {
                printf("%d ", data[i][j]);
            }
        }
        printf("\n");
    }

    // Flatten the data into a one-dimensional array for analysis
    int flattened[12];
    int index = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (data[i][j] != 0) {
                flattened[index] = data[i][j];
                index++;
            }
        }
    }

    // Calculate the maximum value and its index
    int max_value = flattened[0];
    int max_index = 0;
    for (int i = 1; i < 12; i++) {
        if (flattened[i] > max_value) {
            max_value = flattened[i];
            max_index = i;
        }
    }

    // Calculate the minimum value and its index
    int min_value = flattened[0];
    int min_index = 0;
    for (int i = 1; i < 12; i++) {
        if (flattened[i] < min_value) {
            min_value = flattened[i];
            min_index = i;
        }
    }

    // Calculate the mean value
    float mean_value = 0;
    for (int i = 0; i < 12; i++) {
        mean_value += flattened[i];
    }
    mean_value /= 12.0;

    // Print the results
    printf("\nAnalysis Results:\n");
    printf("Maximum value: %d (index %d)\n", max_value, max_index);
    printf("Minimum value: %d (index %d)\n", min_value, min_index);
    printf("Mean value: %f\n", mean_value);

    return 0;
}