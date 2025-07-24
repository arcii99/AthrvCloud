//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 1000   // Maximum value that can be in the array
#define MAX_BUCKET 10    // Maximum number of buckets

/* Function to sort the input array using bucket sort */
void bucketSort(int arr[], int n) {
    int i, j, k;
    int count[MAX_BUCKET] = {0}; // Initializing all counts to 0
    int bucket[MAX_BUCKET][MAX_VALUE]; // Initializing all buckets to 0
    
    /* Adding values to the buckets */
    for (i = 0; i < n; i++) {
        int index = arr[i]/MAX_BUCKET;
        bucket[index][count[index]] = arr[i];
        count[index]++;
    }
    
    /* Sorting each bucket */
    for (i = 0; i < MAX_BUCKET; i++) {
        for (j = 0; j < count[i]; j++) {
            int temp = bucket[i][j];
            k = j - 1;
            while (k >=0 && bucket[i][k] > temp) {
                bucket[i][k+1] = bucket[i][k];
                k--;
            }
            bucket[i][k+1] = temp;
        }
    }
    
    /* Merging all the sorted buckets into the original array */
    k = 0;
    for (i = 0; i < MAX_BUCKET; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[k++] = bucket[i][j];
        }
    }
}

/* Driver function to test the above program */
int main() {
    int arr[] = {5, 8, 1, 6, 9, 3, 2, 7, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}