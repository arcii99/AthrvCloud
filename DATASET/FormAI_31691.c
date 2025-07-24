//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Function to sort array using bucket sort
void bucketSort(float arr[], int n) {
    // Create n empty buckets
    int i;
    int count[n];
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Increment the counter of the corresponding bucket according to the values in the array
    for (i = 0; i < n; i++) {
        int bucket = n * arr[i];
        count[bucket]++;
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < n; i++) {
        int j, k;
        float temp[n];
        for (j = 0; j < n; j++) {
            temp[j] = 0;
        }
        for (j = count[i] - 1; j >= 0; j--) {
            temp[count[i] - j - 1] = arr[i * count[i] + j];
        }
        for (j = count[i] - 1; j >= 0; j--) {
            for (k = 0; k < j; k++) {
                if (temp[k] > temp[j]) {
                    float swap = temp[k];
                    temp[k] = temp[j];
                    temp[j] = swap;
                }
            }
        }
        for (j = 0; j < count[i]; j++) {
            arr[i * count[i] + j] = temp[j];
        }
    }
}

// Driver code
int main() {
    // Declare and initialize array
    float arr[] = {0.12, 0.34, 0.56, 0.78, 0.90, 0.23, 0.45, 0.67, 0.89, 0.01};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the bucketSort function
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }

    return 0;
}