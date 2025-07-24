//FormAI DATASET v1.0 Category: Data mining ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {

    int dataset[] = { 1, 9, 2, 8, 3, 7, 4, 6, 5, 10 };
    int i, j, k, temp;

    // Bubble Sort Algorithm
    for (i = 0; i < sizeof(dataset) / sizeof(dataset[0]) - 1; i++) {
        for (j = 0; j < sizeof(dataset) / sizeof(dataset[0]) - i - 1; j++) {
            if (dataset[j] > dataset[j + 1]) {
                temp = dataset[j];
                dataset[j] = dataset[j + 1];
                dataset[j + 1] = temp;
            }
        }
    }
    
    printf("Sorted Dataset: ");
    for (k = 0; k < sizeof(dataset) / sizeof(dataset[0]); k++) {
        printf("%d ", dataset[k]);
    }
    printf("\n");
    
    // Mean Calculation
    float sum = 0, mean;
    for (i = 0; i < sizeof(dataset) / sizeof(dataset[0]); i++) {
        sum += dataset[i];
    }
    mean = sum / (sizeof(dataset) / sizeof(dataset[0]));
    printf("Mean: %.2f\n", mean);
    
    // Median Calculation
    int median;
    if (sizeof(dataset) / sizeof(dataset[0]) % 2 == 0) {
        median = (dataset[(sizeof(dataset) / sizeof(dataset[0])) / 2 - 1] + dataset[(sizeof(dataset) / sizeof(dataset[0])) / 2]) / 2;
    }
    else {
        median = dataset[(sizeof(dataset) / sizeof(dataset[0])) / 2];
    }
    printf("Median: %d\n", median);
    
    // Mode Calculation
    int mode = -1, count = 0, maxCount = 0;
    for (i = 0; i < sizeof(dataset) / sizeof(dataset[0]); i++) {
        for (j = i + 1; j < sizeof(dataset) / sizeof(dataset[0]); j++) {
            if (dataset[j] == dataset[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = dataset[i];
        }
        count = 0;
    }
    printf("Mode: %d\n", mode);

    return 0;
}