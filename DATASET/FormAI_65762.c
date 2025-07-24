//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: surprised
#include<stdio.h>

void bucket_sort(int arr[], int n)
{
    int max_value = arr[0];
    int min_value = arr[0];
    int i, j, k;

    for (i = 1; i < n; i++) {
        if (arr[i] > max_value)
            max_value = arr[i];
        if (arr[i] < min_value)
            min_value = arr[i];
    }

    int bucket_count = (max_value - min_value) / 5 + 1; 
    int buckets[bucket_count][5]; 

    int bucket_sizes[bucket_count];

    for (i = 0; i < bucket_count; i++) {
        bucket_sizes[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int bucket_index = (arr[i] - min_value) / 5;
        buckets[bucket_index][bucket_sizes[bucket_index]] = arr[i];
        bucket_sizes[bucket_index]++;
    }

    int index = 0;
    for (i = 0; i < bucket_count; i++) {
        for (j = 0; j < bucket_sizes[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

int main()
{
    printf("I am surprised to see a Bucket Sort implementation in C.\n");

    int arr[] = {25, 45, 86, 73, 10, 42, 59, 26, 99, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array: ");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\nBucket Sorted Array: ");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }

    return 0;
}