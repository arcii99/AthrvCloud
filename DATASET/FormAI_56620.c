//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: mathematical
#include <stdio.h>
#define MAX_VALUE 100
#define RANGE 10

void bucketSort(int arr[], int n) {

    int bucket[RANGE];

    // Initialize all elements of bucket array to 0
    for(int i = 0; i < RANGE; i++)
        bucket[i] = 0;

    // Increment elements of bucket array based on the input array elements
    for(int i = 0; i < n; i++)
        bucket[arr[i]]++;

    // Sort the input array elements according to the elements in the bucket array
    int index = 0;
    for(int i = 0; i < RANGE; i++)
        for(int j = 0; j < bucket[i]; j++)
            arr[index++] = i;
}

int main() {

    int arr[MAX_VALUE], n;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    printf("Enter the elements:");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}