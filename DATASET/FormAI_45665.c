//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 1000
#define NUM_BUCKETS 10

// Get maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Bucket sort implementation
void bucketSort(int arr[], int n) {
    int i, j, k;
    int bucketSize = MAX_NUM / NUM_BUCKETS;

    // Create empty buckets
    int **buckets = (int **)malloc(sizeof(int *) * NUM_BUCKETS);
    for (i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = (int *)malloc(sizeof(int) * n);
    }

    // Get maximum value in arr
    int maxVal = getMax(arr, n);

    // Put elements in appropriate bucket
    for (i = 0; i < n; i++) {
        j = arr[i] / bucketSize;
        if (j == NUM_BUCKETS) {
            j--;
        }
        buckets[j][i] = arr[i];
    }

    // Sort elements in each bucket using insertion sort
    for (i = 0; i < NUM_BUCKETS; i++) {
        for (j = 0; j < n; j++) {
            for (k = j + 1; k < n; k++) {
                if (buckets[i][k] < buckets[i][j]) {
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
    }

    // Copy elements back to original array
    int pos = 0;
    for (i = 0; i < NUM_BUCKETS; i++) {
        for (j = 0; j < n; j++) {
            if (buckets[i][j] != 0) {
                arr[pos++] = buckets[i][j];
            }
        }
    }

    // Deallocate memory for buckets
    for (i = 0; i < NUM_BUCKETS; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main() {
    int arr[] = {12, 23, 38, 42, 55, 68, 72, 81, 4, 47};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Array after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}