//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function to implement Bucket Sort
void bucketSort(float arr[], int n)
{
    // Create n empty buckets
    int i, j;
    int count = 0;
    int* bucketCount = malloc(sizeof(int) * n);
    float* b[n];
    for (i = 0; i < n; ++i) {
        b[i] = NULL;
    }

    // Put elements in different buckets
    for (i = 0; i < n; ++i) {
        int bucketIndex = arr[i] * n; 

        if (bucketIndex >= n) bucketIndex = n - 1; 

        if (b[bucketIndex] == NULL) {
            b[bucketIndex] = malloc(sizeof(float) * 1);
            bucketCount[bucketIndex] = 0;
        }
        else {
            b[bucketIndex] = realloc(b[bucketIndex], sizeof(float) * (bucketCount[bucketIndex] + 1));
        }
        b[bucketIndex][bucketCount[bucketIndex]++] = arr[i];
        count++;
    }

    // Sort individual buckets
    for (i = 0; i < n; ++i) {
        for (j = 0; j < bucketCount[i]; ++j) {
            int k;
            float key = b[i][j];
            for (k = j - 1; k >= 0 && b[i][k] > key; --k) {
                b[i][k + 1] = b[i][k];
            }
            b[i][k + 1] = key;
        }
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (i = 0; i < n; ++i) {
        for (j = 0; j < bucketCount[i]; ++j) {
            arr[index++] = b[i][j];
        }
    }

    //Free memory
    for (i = 0; i < n; ++i) {
        free(b[i]);
    }
    free(bucketCount);
}

// Driver program to test above function
int main()
{
    float arr[] = { 0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("\nUnsorted array: \n");
    for (i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array is: \n");
    for (i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }

    return 0;
}