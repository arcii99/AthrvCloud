//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUCKET_SIZE 10

/* Insertion Sort */
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* Bucket Sort */
void bucketSort(int arr[], int n)
{
    /* Step 1: Determine the range */
    int max_val = arr[0];
    int min_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val)
            max_val = arr[i];
        if (arr[i] < min_val)
            min_val = arr[i];
    }
    
    /* Step 2: Create buckets and distribute the input values */
    int num_buckets = ceil((double)(max_val - min_val + 1) / BUCKET_SIZE);
    int buckets[num_buckets][BUCKET_SIZE];
    int index[num_buckets];
    for (int i = 0; i < num_buckets; i++) {
        index[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int bucket_index = floor((double)(arr[i] - min_val) / BUCKET_SIZE);
        buckets[bucket_index][index[bucket_index]] = arr[i];
        index[bucket_index]++;
    }
    
    /* Step 3: Sort each bucket using Insertion Sort */
    for (int i = 0; i < num_buckets; i++) {
        insertionSort(buckets[i], index[i]);
    }
    
    /* Step 4: Concatenate the sorted buckets */
    int k = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < index[i]; j++) {
            arr[k] = buckets[i][j];
            k++;
        }
    }
}

/* Main Function */
int main()
{
    int arr[] = {63, 99, 16, 54, 87, 23, 10, 56, 49, 91, 35};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}