//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include<stdio.h>

// Define the maximum size of the array
#define MAX 100

// Define the size of each bucket
#define INTERVAL 10

void bucketSort(int arr[], int n) {

    int i, j;
    int count[MAX];

    // Initialize the count array to 0
    for(i = 0; i < MAX; i++) {
        count[i] = 0;
    }

    // Count the number of elements in each bucket
    for(i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Fill the sorted array
    for(i = 0, j = 0; i < MAX; i++) {
        while(count[i]--) {
            arr[j++] = i;
        }
    }
}

int main() {

    int arr[] = {23, 13, 4, 35, 12, 67, 45, 26, 7, 23};
    int n = 10, i;

    printf("Unsorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Sort the array using bucket sort
    bucketSort(arr, n);

    printf("\nSorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}