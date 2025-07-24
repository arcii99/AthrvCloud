//FormAI DATASET v1.0 Category: Data mining ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int data[] = {4, 8, 12, 16, 20, 24, 28};
    int n = sizeof(data) / sizeof(data[0]);
    int i;
    int sum = 0;

    for (i = 0; i < n; i++) {
        sum += data[i];
    }

    int mean = sum / n;
    int variance = 0;

    for (i = 0; i < n; i++) {
        variance += (data[i] - mean) * (data[i] - mean);
    }

    int sd = sqrt(variance / n);

    printf("Data: ");
    for (i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("Mean: %d\n", mean);
    printf("Variance: %d\n", variance);
    printf("Standard Deviation: %d\n", sd);

    return 0;
}