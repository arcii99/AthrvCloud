//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n, int k) {
    int count[k], i, j;
    // Initializing the count array to 0
    for(i = 0; i < k; ++i) {
        count[i] = 0;
    }
    // Counting the number of elements in each bucket
    for(i = 0; i < n; ++i) {
        ++count[arr[i]];
    }
    // Sorting each bucket and placing the sorted elements back in the array
    for(i = 0, j = 0; i < k; ++i) {
        for(; count[i] > 0; --count[i]) {
            arr[j++] = i;
        }
    }
}

int main() {
    // Taking input from user
    int n, i, k = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        // Finding the maximum element in the array
        if(arr[i] > k) {
            k = arr[i];
        }
    }
    // Implementing the bucket sort
    bucketSort(arr, n, k + 1);
    // Printing the sorted array
    printf("The sorted array is: ");
    for(i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}