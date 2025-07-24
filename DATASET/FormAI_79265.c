//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000 // total number of integers to sort
#define MAX_VALUE 100000 // maximum value of an integer (exclusive)

void bucketSort(int[], int); // function prototype

int main() {
    // generate random integers between 0 and MAX_VALUE - 1
    int arr[SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % MAX_VALUE;
    }

    // print unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // perform bucket sort
    bucketSort(arr, SIZE);

    // print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bucketSort(int arr[], int size) {
    // create an array of empty buckets
    int buckets[MAX_VALUE] = {0};

    // insert each element into its corresponding bucket
    for (int i = 0; i < size; i++) {
        buckets[arr[i]]++;
    }

    // overwrite the original array with the sorted values
    int index = 0;
    for (int i = 0; i < MAX_VALUE; i++) {
        for (int j = 0; j < buckets[i]; j++) {
            arr[index++] = i;
        }
    }
}