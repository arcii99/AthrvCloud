//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10 // number of buckets
#define ARRAY_SIZE 100 // size of array to be sorted

// get the digit in the given position from the number
int getDigit(int number, int position) {
    int divisor = 1;
    for(int i = 0; i < position; i++) {
        divisor *= 10;
    }
    return (number / divisor) % 10;
}

// perform bucket sort
void bucketSort(int arr[]) {
    // create buckes
    int buckets[BUCKET_SIZE][ARRAY_SIZE];
    int bucketIndex[BUCKET_SIZE] = {0};

    // distribute elements into buckets based on the least significant digit
    for(int i = 0; i < ARRAY_SIZE; i++) {
        int digit = getDigit(arr[i], 0);
        buckets[digit][bucketIndex[digit]] = arr[i];
        bucketIndex[digit]++;
    }

    // sort bucket by the next digit and move elements back to original array
    int arrIndex = 0;
    for(int i = 1; i < ARRAY_SIZE; i *= 10) {
        for(int j = 0; j < BUCKET_SIZE; j++) {
            for(int k = 0; k < bucketIndex[j]; k++) {
                int digit = getDigit(buckets[j][k], i);
                buckets[digit][bucketIndex[digit]] = buckets[j][k];
                bucketIndex[digit]++;
            }
            for(int k = 0; k < bucketIndex[j]; k++) {
                arr[arrIndex] = buckets[j][k];
                arrIndex++;
            }
            bucketIndex[j] = 0;
        }
    }
}

// print the array
void printArray(int arr[]) {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[ARRAY_SIZE];
    printf("Unsorted array: ");
    for(int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr);

    printf("Sorted array: ");
    printArray(arr);

    return 0;
}