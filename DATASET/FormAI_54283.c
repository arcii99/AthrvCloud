//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define N 10 // number of buckets
#define ARRAY_SIZE 100 // size of initial array

// function to compare two integers
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void bucketSort(int arr[]) {
    int i, j;
    int aIndex;
    int bucketSize = 10;
    int bucket[N][bucketSize];
    int bucketCount[N] = {0};

    // Place the elements in their respective buckets
    for(i = 0; i < ARRAY_SIZE; i++) {
        aIndex = arr[i] / bucketSize;  //items are distributed in buckets of size 10
        if(bucketCount[aIndex] == bucketSize) {
            printf("Bucket overflow error!\n");
            return;
        }
        bucket[aIndex][bucketCount[aIndex]] = arr[i];
        bucketCount[aIndex]++;
    }

    // Sort each bucket individually
    for(i = 0; i < N; i++) {
        qsort(bucket[i], bucketCount[i], sizeof(int), compare);
    }

    // Merge the sorted buckets
    int index = 0;
    for(i = 0; i < N; i++) {
        for(j = 0; j < bucketCount[i]; j++) {
            arr[index++] = bucket[i][j];
        }
    }
}

// Driver function
int main() {
    int arr[ARRAY_SIZE];
    int i;

    // Initialize array with random numbers
    for(i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    printf("Unsorted Array: ");
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    // Call the bucketSort function
    bucketSort(arr);

    printf("\nSorted Array: ");
    for(i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}