//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Bucket Sort function
void bucketSort(float arr[], int n) {
    // Create an array of buckets
    int i, j;
    int count[n];
    for(i = 0; i < n; ++i) {
        count[i] = 0;
    }

    // Count the number of elements in each bucket
    for(i = 0; i < n; ++i) {
        ++count[(int)(arr[i] * n)];
    }

    // Sort the elements in each bucket using quick sort algorithm
    for(i = 0; i < n; ++i) {
        for(j = 0; j < count[i]; ++j) {
            quickSort(arr, i * n + j, (i + 1) * n - 1);
        }
    }
}

// Quick Sort function
void quickSort(float arr[], int low, int high) {
    if(low < high) {
        float pivot = arr[high];
        int i = low - 1;
        int j;
        for(j = low; j <= high - 1; ++j) {
            if(arr[j] <= pivot) {
                ++i;
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

// Swap function
void swap(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, i;
    float arr[50];

    // Obtain array size and elements from user
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i = 0; i < n; ++i) {
        scanf("%f", &arr[i]);
    }

    // Sort the array using Bucket Sort algorithm
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for(i = 0; i < n; ++i) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}