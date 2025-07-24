//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float array[], int n) {

    // create an array of empty buckets
    int i, j;
    int count[n];
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }

    // fill the buckets with respective elements
    for (i = 0; i < n; i++) {
        int bucketIndex = n * array[i];
        count[bucketIndex]++;
    }

    // sort individual buckets
    for (i = 0; i < n; i++) {
        for (j = 0; j < count[i]; j++) {
            printf("%.2f ", (float)i / n);
        }
    }
}

int main() {

    // create and fill an array of float numbers
    float array[] = {0.1, 0.3, 0.4, 0.6, 0.7, 0.8, 0.9, 0.2, 0.5};
    int n = sizeof(array) / sizeof(array[0]);

    // sort the array using bucket sort algorithm
    bucketSort(array, n);

    return 0;
}