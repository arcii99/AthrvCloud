//FormAI DATASET v1.0 Category: Data mining ; Style: mathematical
#include <stdio.h>

int main() {
    // set up input dataset
    int dataset[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // calculate mean
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += dataset[i];
    }
    float mean = (float) sum / 10;
    printf("Mean: %.2f\n", mean);

    // calculate standard deviation
    float variance = 0;
    for (int i = 0; i < 10; i++) {
        variance += (dataset[i] - mean) * (dataset[i] - mean);
    }
    float std_dev = sqrt(variance / 10);
    printf("Standard deviation: %.2f\n", std_dev);

    // find outliers
    printf("Outliers: ");
    for (int i = 0; i < 10; i++) {
        if (dataset[i] < mean - 2 * std_dev || dataset[i] > mean + 2 * std_dev) {
            printf("%d ", dataset[i]);
        }
    }
    printf("\n");

    return 0;
}