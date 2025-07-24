//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n)
{
    // Create buckets
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;

    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] * n;
        count[bucketIndex]++;
    }

    // Sort individual buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = arr[i] * n;
        float bucket[count[bucketIndex]];
        for (j = 0; j < count[bucketIndex]; j++)
            bucket[j] = 0;

        for (j = 0; j < count[bucketIndex]; j++)
            bucket[j] = arr[j];

        for (j = 1; j < count[bucketIndex]; j++) {
            float key = bucket[j];
            int k = j - 1;

            while (k >= 0 && bucket[k] > key) {
                bucket[k + 1] = bucket[k];
                k = k - 1;
            }
            bucket[k + 1] = key;
        }

        // Concatenate sorted buckets
        j = 0;
        for (int k = 0; k < n; k++) {
            if (count[k] != 0) {
                for (int l = 0; l < count[k]; l++) {
                    arr[j++] = bucket[l];
                }
            }
        }
    }
}

int main()
{
    float arr[] = { 0.54, 0.24, 0.65, 0.27, 0.91, 0.46, 0.33, 0.68 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    printf("Sorted array is \n");
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");
    return 0;
}