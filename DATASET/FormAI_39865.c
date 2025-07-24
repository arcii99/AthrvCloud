//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// define the maximum array size for our bucket sort implementation
#define MAX_SIZE 100000

int compare (const void * a, const void * b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[MAX_SIZE];
    int n, i;
    int max_num = 0;

    // get inputs from user
    printf("Enter the number of elements in the array:\n");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
       scanf("%d", &arr[i]);
       if (arr[i] > max_num) max_num = arr[i];
    }

    // initialize the bucket arrays
    int *bucket = (int*)calloc((max_num + 1), sizeof(int));

    // sort the elements into the respective buckets
    for (i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    // iterate through each bucket, printing the sorted elements
    for (i = 0; i <= max_num; i++) {
        if (bucket[i] != 0) {
            int j;
            for (j = 0; j < bucket[i]; j++) {
                printf("%d ", i);
            }
        }
    }

    return 0;
}