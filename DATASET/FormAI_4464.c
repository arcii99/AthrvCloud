//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {
    // Create n empty buckets
    int i, j;
    int bucketCount = n / 2;
    float maxVal = arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    maxVal++;

    float* buckets[bucketCount];
    for(i = 0; i < bucketCount; i++) {
        buckets[i] = NULL;
    }

    // Add elements into the buckets
    int bi;
    float biFloat;
    for(i = 0; i < n; i++) {
        biFloat = ((float)arr[i] * bucketCount) / maxVal;
        bi = (int)biFloat;
        if (bi >= bucketCount){
            bi = bucketCount - 1;
        }
        if(buckets[bi] == NULL) {
            buckets[bi] = (float*)malloc(bucketCount*sizeof(float));
            for(j = 0; j < bucketCount; j++) {
                buckets[bi][j] = 0;
            }
        }
        buckets[bi][i] = arr[i];
    }

    // Sort the elements of each bucket
    for(i = 0; i < bucketCount; i++) {
        float* bucketVals = buckets[i];
        int bucketSize = sizeof(bucketVals) / sizeof(bucketVals[0]);
        for(j = 1; j < bucketSize; j++) {
            float temp = bucketVals[j];
            int k = j - 1;
            while(k >= 0 && bucketVals[k] > temp) {
                bucketVals[k + 1] = bucketVals[k];
                k = k - 1;
            }
            bucketVals[k + 1] = temp;
        }
    }

    // Put the elements back into the original array in sorted order
    int index = 0;
    for(i = 0; i < bucketCount; i++) {
        float* bucketVals = buckets[i];
        int bucketSize = sizeof(bucketVals) / sizeof(bucketVals[0]);
        for(j = 0; j < bucketSize; j++) {
            if(bucketVals[j] > 0) {
                arr[index] = bucketVals[j];
                index++;
            }
        }
    }

    for(i = 0; i < bucketCount; i++) {
        free(buckets[i]);
    }
}

int main() {
    float arr[] = {23.4, 15.8, 10.9, 8.2, 16.6, 19.8, 20.5, 22.9, 14.7, 25.5, 30.0, 60.6, 52.3, 43.9, 40.4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int i;
    printf("Unsorted Array: ");
    for(i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted Array: ");
    for(i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }

    return 0;
}