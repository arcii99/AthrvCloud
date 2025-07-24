//FormAI DATASET v1.0 Category: Data mining ; Style: lively
#include <stdio.h>

int main() {
    int dataset[10] = {5, 6, 9, 11, 13, 14, 18, 21, 23, 26};
    int i, j, k, temp;

    // Print original dataset
    printf("Original Dataset: \n");
    for(i = 0; i < 10; i++) {
        printf("%d ", dataset[i]);
    }

    // Sort dataset in ascending order
    for(i = 0; i < 9; i++) {
        for(j = i + 1; j < 10; j++) {
            if(dataset[i] > dataset[j]) {
                temp = dataset[i];
                dataset[i] = dataset[j];
                dataset[j] = temp;
            }
        }
    }

    // Print sorted dataset
    printf("\n\nSorted Dataset: \n");
    for(i = 0; i < 10; i++) {
        printf("%d ", dataset[i]);
    }

    // Find mean of dataset
    int sum = 0;
    for(i = 0; i < 10; i++) {
        sum += dataset[i];
    }
    float mean = (float) sum / 10;

    // Print mean of dataset
    printf("\n\nMean of Dataset: %.2f", mean);

    // Find median of dataset
    int median;
    if(10 % 2 == 0) {
        median = (dataset[(10 / 2) - 1] + dataset[10 / 2]) / 2;
    } else {
        median = dataset[10 / 2];
    }

    // Print median of dataset
    printf("\n\nMedian of Dataset: %d", median);

    // Determine if any outliers exist
    int upper, lower;
    float q1, q3, iqr;
    if(10 % 2 == 0) {
        q1 = (float) (dataset[(10 / 2) - 1] + dataset[(10 / 2) - 1])/2;
        q3 = (float) (dataset[10 / 2] + dataset[10 / 2 - 1])/2;
    } else {
        q1 = (float) dataset[(10 / 2) - 1];
        q3 = (float) dataset[10 / 2 + 1];
    }
    
    iqr = q3 - q1;
    upper = (int) (q3 + 1.5 * iqr);
    lower = (int) (q1 - 1.5 * iqr);

    // Find any outliers in dataset
    int outliers[10];
    int count = 0;
    for(i = 0; i < 10; i++) {
        if(dataset[i] > upper || dataset[i] < lower) {
            outliers[count] = dataset[i];
            count++;
        }
    }

    // Print any outliers in dataset
    if(count == 0) {
        printf("\n\nNo outliers found in dataset.");
    } else {
        printf("\n\nOutliers found in dataset: ");
        for(i = 0; i < count; i++) {
            printf("%d ", outliers[i]);
        }
    }

    return 0;
}