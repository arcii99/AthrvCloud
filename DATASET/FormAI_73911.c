//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n){
    int i, j;
    float minVal = arr[0], maxVal = arr[0];
    for (i = 1; i < n; i++) {
        minVal = fmin(minVal, arr[i]);
        maxVal = fmax(maxVal, arr[i]);
    }

    const int numBuckets = n;
    const float bucketRange = (maxVal - minVal) / numBuckets;

    // Create an array of buckets
    float **buckets = malloc(sizeof(float *) * numBuckets);
    for (i = 0; i < numBuckets; i++) {
        // We add one extra element to handle collisions
        buckets[i] = malloc(sizeof(float) * (n + 1));
        buckets[i][n] = 0;
    }

    // Assign each element to the corresponding bucket
    for (i = 0; i < n; i++) {
        int j = (int)((arr[i] - minVal) / bucketRange);
        int k = ++buckets[j][n];
        buckets[j][k-1] = arr[i];
    }

    // Sort each bucket
    for (i = 0; i < numBuckets; i++) {
        for (j = 0; j < buckets[i][n]; ++j) {
            int k;
            float x;
            for (k = j + 1; k < buckets[i][n]; ++k) {
                if (buckets[i][k] < buckets[i][j]) {
                    x = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = x;
                }
            }
        }
    }

    // Merge sorted buckets into a new array
    int index = 0;
    for (i = 0; i < numBuckets; i++) {
        for (j = 0; j < buckets[i][n]; j++) {
            arr[index++] = buckets[i][j];
        }
    }

    // Free the memory managed by the buckets
    for (i = 0; i < numBuckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

int main(){
    float arr[] = {0.22,0.31,0.55,0.31,0.50,0.22,0.54,0.16,0.21,0.45};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nArray after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }

    return 0;
}