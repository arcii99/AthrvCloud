//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#define N 10

void bucketSort(int arr[], int n){
    // Create N buckets
    int i, j, count[N];
    for (i = 0; i < N; i++)
        count[i] = 0;

    // Increment bucket index elements
    for (i = 0; i < n; i++)
        count[arr[i]]++;

    // Set array elements to the sum of previous elements
    for (i = 1; i < N; i++)
        count[i] += count[i - 1];

    // Construct sorted array
    int output[n];
    for (i = 0; i < n; i++){
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back into the original array
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main function to test the sorting algorithm
int main(){
    int arr[N] = {9, 5, 2, 8, 4, 0, 1, 6, 3, 7};
    int i;

    printf("Before sorting:\n");
    for (i = 0; i < N; i++)
        printf("%d ", arr[i]);

    bucketSort(arr, N);

    printf("\nAfter sorting:\n");
    for (i = 0; i < N; i++)
        printf("%d ", arr[i]);

    return 0;
}