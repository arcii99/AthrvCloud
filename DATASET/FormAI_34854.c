//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10

// function to sort the array using bucket sort
void bucketSort(int *arr, int n) {

    // finding max element in the array
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }

    // creating the buckets
    int bucket[max + 1];
    for(int i = 0; i <= max; i++) {
        bucket[i] = 0;
    }

    // storing the frequency of the elements in the corresponding bucket
    for(int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    // sorting the elements
    for(int i = 0, j = 0; i <= max; i++) {
        while(bucket[i] > 0) {
            arr[j++] = i;
            bucket[i]--;
        }
    }
}

int main() {
    int arr[ARRAY_SIZE];
    printf("Enter %d numbers to sort:\n", ARRAY_SIZE);
    for(int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    bucketSort(arr, ARRAY_SIZE);
    printf("Sorted array is:\n");
    for(int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}